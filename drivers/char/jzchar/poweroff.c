/*
 * linux/drivers/char/jzchar/poweroff.c
 *
 * Power off handling.
 *
 * Copyright (C) 2005-2007  Ingenic Semiconductor Inc.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 */
#include <linux/kthread.h>
#include <linux/errno.h>
#include <linux/err.h>

#include <linux/module.h>
#include <linux/sched.h>
#include <linux/timer.h>
#include <linux/major.h>
#include <linux/fcntl.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/spinlock.h>
#include <linux/pm.h>
//#include <linux/pm_legacy.h>
#include <linux/proc_fs.h>

#include <asm/io.h>
#include <asm/uaccess.h>
#include <asm/jzsoc.h>

#include "jzchars.h"

MODULE_AUTHOR("Jianli Wei <jlwei@ingenic.cn>");
MODULE_DESCRIPTION("Poweroff handling");
MODULE_LICENSE("GPL");

#undef DEBUG
//#define DEBUG 
#ifdef DEBUG
#define dprintk(x...)	printk(x)
#else
#define dprintk(x...)
#endif

#define POWEROFF_PIN   GPIO_PW_I
#define POWEROFF_IRQ   (IRQ_GPIO_0 + POWEROFF_PIN)
//#define USE_SUSPEND_HOTPLUG


#define GPIO_PW_I               GPIO_WAKEUP
#define POWEROFF_PIN_DOWN       0
#define SET_POWEROFF_PIN_AS_IRQ __gpio_as_irq_fall_edge(POWEROFF_PIN)

#ifndef CONFIG_PM
#define DO_SHUTDOWN_SYSTEM
#else
#define DO_SHUTDOWN_SYSTEM      jz_pm_hibernate()
#endif

#if 0
#define DO_SUSPEND { \
	    jz_pm_sleep();\
	    suspend_flag = 0;\
	    SET_POWEROFF_PIN_AS_IRQ;\
	}
#endif


#define POWEROFF_PERIOD         1000    /* unit: ms */
#define POWEROFF_DELAY          100     /* unit: ms */
//KJH ADD 
static struct task_struct *poweroff_task;
static struct timer_list poweroff_timer;
static struct timer_list poweroff_delaytimer;
static struct timer_list poweroff_checktimer;
static struct work_struct suspend_work;

static int poweroff_flag = 0; 
static int suspend_flag = 0;
static int num_seconds = 0;

#ifdef CONFIG_JZ_UDC_HOTPLUG
extern int jz_udc_active;
#endif

#ifdef CONFIG_PM
extern void jz_pm_suspend(void);
extern int jz_pm_hibernate(void);
extern int jz_pm_sleep(void);
#endif

extern unsigned int medive_flag;

void run_sbin_poweroff()
{
	int i;
	char *argv[3], *envp[8];
    int ret;

    i = 0;
    argv[i++] = "/boot/local/sbin/ne_inform";
    //argv[i++] = "/boot/local/sbin/ne_inform.sh";
    //argv[i++] = "/usr/bin/udc_connect.sh";

    argv[i++] = "poweroff";

    argv[i] = 0;

    /* minimal command environment */
    i = 0;
    envp[i++] = "HOME=/";
    envp[i++] = "PATH=/sbin:/bin:/usr/sbin:/usr/bin:/boot/local/sbin";

    envp[i] = 0;
	
    ret = call_usermodehelper (argv[0], argv, envp, -1);
    if(ret != 0)
    {
	    printk("call user helper error, errno = %d\n",ret);
	    SET_POWEROFF_PIN_AS_IRQ;
	    __gpio_unmask_irq(POWEROFF_PIN);
	    return;
    }
    else
    {
	    printk("%s %d  %s call user helper ok..!\n",__FILE__,__LINE__,argv[0]);
    }
	
	__lcd_set_backlight_level(60); //allen add to draw off os picture
	
    msleep(5*1000);
    printk("\n Medive pintk: rerun jz pm hibernate!\n");
    msleep(10*1000);

    //jz_pm_hibernate();
}
EXPORT_SYMBOL(run_sbin_poweroff);


static void poweroff_timer_routine(unsigned long dummy)
{
#if 0
	if (__gpio_get_pin(POWEROFF_PIN) == POWEROFF_PIN_DOWN) {
		if (++num_seconds > 3)
		{
			printk("\nShutdown system now ..\n");
                 
#ifndef USE_SUSPEND_HOTPLUG
                        /* Turn off LCD to inform user that the system is shutting down.
                         * But the information of shutting down system will be shown 
                         * by userspace program if hotplug is used.
                         */
			__lcd_close_backlight();
#endif

                        /*
                         * Wait until the power key is up, or the system will reset with
                         * power key down after entering hibernate. 
                         */
			while(__gpio_get_pin(POWEROFF_PIN)==POWEROFF_PIN_DOWN);

			poweroff_flag = 1;
			schedule_work(&suspend_work); /* inform user to poweroff */
		}
		else {
			del_timer(&poweroff_timer);
			init_timer(&poweroff_timer);
			poweroff_timer.expires = jiffies + POWEROFF_PERIOD/10;
			poweroff_timer.data = 0;
			poweroff_timer.function = poweroff_timer_routine;
			add_timer(&poweroff_timer);
		}
	}
	else
	{
		printk("\nSuspend system now ..\n");
		num_seconds = 0;
		suspend_flag = 1;
		poweroff_flag = 0;
		schedule_work(&suspend_work); /* we are entering suspend */
	}
#endif
//maddrone add
printk("\nShutdown system now ..\n");
mdelay(280);
while(__gpio_get_pin(POWEROFF_PIN)==POWEROFF_PIN_DOWN);
poweroff_flag = 1;
schedule_work(&suspend_work); /* inform user to poweroff */
}

static void poweroff_timer_check(unsigned long dummy)
{
	//long 2s down,then up key to power-off
#if 0 //allen del
	if (__gpio_get_pin(POWEROFF_PIN)!=POWEROFF_PIN_DOWN) 
	{
		del_timer(&poweroff_checktimer);
		wake_up_process(poweroff_task);
	}
	else
	{
		mod_timer(&poweroff_checktimer, jiffies + POWEROFF_PERIOD / 100);
	}
#else
	del_timer(&poweroff_checktimer);
	wake_up_process(poweroff_task);
#endif
}

//extern int is_powerkey_coming_now;
static void poweroff_delaytimer_routine(unsigned long dummy)
{
	__gpio_as_input(POWEROFF_PIN);
	if (__gpio_get_pin(POWEROFF_PIN)==POWEROFF_PIN_DOWN) {
		if (suspend_flag) {
			suspend_flag = 0;
			del_timer(&poweroff_delaytimer);
			SET_POWEROFF_PIN_AS_IRQ;
			__gpio_unmask_irq(POWEROFF_PIN);
			printk("\n--- 1 ---\n");
			return;
		}
		//maddrone add
		printk("\n--- 2 ---\n");
		//wake_up_process(poweroff_task);
		//run_sbin_poweroff();
		init_timer(&poweroff_checktimer);
		poweroff_checktimer.expires = jiffies + POWEROFF_PERIOD/100;
		poweroff_checktimer.data = 0;
		poweroff_checktimer.function = poweroff_timer_check;
		add_timer(&poweroff_checktimer);
#if 0
		del_timer(&poweroff_delaytimer);
		del_timer(&poweroff_timer);
		init_timer(&poweroff_timer);
		poweroff_timer.expires = jiffies + POWEROFF_PERIOD/100;
		poweroff_timer.data = 0;
		poweroff_timer.function = poweroff_timer_routine;
		add_timer(&poweroff_timer);
#endif
	}
	else {

		del_timer(&poweroff_delaytimer);
		SET_POWEROFF_PIN_AS_IRQ;
		__gpio_unmask_irq(POWEROFF_PIN);

		printk("This is a dummy key\n");
	}
}

/*
 * Poweroff pin interrupt handler
 */
static irqreturn_t poweroff_irq(int irq, void *dev_id)
{
	//printk("poweroff irq even coming now!\n");
	
#if 1 //allen add
	del_timer(&poweroff_checktimer);
	init_timer(&poweroff_checktimer);
	poweroff_checktimer.expires = jiffies + HZ*2;
	poweroff_checktimer.data = 0;
	poweroff_checktimer.function = poweroff_timer_check;
	add_timer(&poweroff_checktimer);
#else
	__gpio_ack_irq(POWEROFF_PIN);
	__gpio_mask_irq(POWEROFF_PIN);
	__gpio_as_input(POWEROFF_PIN);

	if (__gpio_get_pin(POWEROFF_PIN)==POWEROFF_PIN_DOWN)
	{
		printk("power off pin is low!\n");
		del_timer(&poweroff_delaytimer);
		init_timer(&poweroff_delaytimer);
		poweroff_delaytimer.expires = jiffies + POWEROFF_DELAY;
		//poweroff_delaytimer.expires = jiffies + 2 * HZ;
		poweroff_delaytimer.data = 0;
		poweroff_delaytimer.function = poweroff_delaytimer_routine;
		add_timer(&poweroff_delaytimer);
	}
	else 
	{
		SET_POWEROFF_PIN_AS_IRQ;
		__gpio_unmask_irq(POWEROFF_PIN);
	}
#endif

	return IRQ_HANDLED;
}

#ifndef CONFIG_PM
/*
static struct pm_dev *poweroff_dev;

static int poweroff_suspend(int *poweroff , int state)
{
	suspend_flag = 1;
	poweroff_flag = 0;

	return 0;
}

static int poweroff_resume(int *poweroff)
{
	suspend_flag = 0;
	SET_POWEROFF_PIN_AS_IRQ;
	__gpio_unmask_irq(POWEROFF_PIN);

	return 0;
}

static int poweroff_pm_callback(struct pm_dev *pm_dev, pm_request_t rqst, void *data)
{
	int ret;
	int *poweroff_info = pm_dev->data;

	if (!poweroff_info) 
		return -EINVAL;

	switch (rqst) {
	case PM_SUSPEND:
		ret = poweroff_suspend(poweroff_info, (int)data);
		break;
	case PM_RESUME:
		ret = poweroff_resume(poweroff_info);
		break;

	default:
		ret = -EINVAL;
		break;
	}

	return ret;
}
*/
#endif /* CONFIG_PM */

#ifdef USE_SUSPEND_HOTPLUG
static void run_sbin_hotplug(int state)
{
        int i;
        char *argv[3], *envp[8];
        char media[64], slotnum[16];
        if (!uevent_helper[0])
                return;

        i = 0;
	argv[i++] = uevent_helper;
 	//argv[i++] = "home/lhhuang/hotplug";

	if ( poweroff_flag ==  1 )
        	argv[i++] = "poweroff";
	else
        	argv[i++] = "suspend";

        argv[i] = 0;

        /* minimal command environment */
        i = 0;
        envp[i++] = "HOME=/";
        envp[i++] = "PATH=/sbin:/bin:/usr/sbin:/usr/bin";

        /* other stuff we want to pass to /sbin/hotplug */
        sprintf(slotnum, "SLOT=0");

	if ( poweroff_flag ==  1 )
        	sprintf(media, "MEDIA=poweroff");
	else
        	sprintf(media, "MEDIA=suspend");

        envp[i++] = slotnum;
        envp[i++] = media;
                    
       	if (state)
               	envp[i++] = "ACTION=enter";
       	else
               	envp[i++] = "ACTION=exit";
        
        envp[i] = 0;

        dprintk("SUSPEND: hotplug path=%s state=%d\n", argv[0], state);

	SET_POWEROFF_PIN_AS_IRQ; 
	__gpio_unmask_irq(POWEROFF_PIN); /* set it because call hotplug with call_usermodehelper() \
                                           might failed, especially when using nfsroot */

	call_usermodehelper (argv [0], argv, envp, -1);
}
#endif

static void suspend_handler(struct work_struct *work)
{

#ifdef USE_SUSPEND_HOTPLUG
        int state = 1;
        run_sbin_hotplug(state);
#else
//maddrone changed
#if 0
	if (poweroff_flag) {
		dprintk("DO_SHUTDOWN_SYSTEM\n");
		DO_SHUTDOWN_SYSTEM;
	} else {
		dprintk("DO_SUSPEND\n");
		DO_SUSPEND;
	}
#endif

	DO_SHUTDOWN_SYSTEM;
#endif
}

static int poweroff_thread(void *unused)
{
	while(1)
	{
		set_current_state(TASK_UNINTERRUPTIBLE);
		schedule();
		printk("poweroff wakeup\n");
		run_sbin_poweroff();
	}
}

static unsigned int shutdown_flag = 0;
static int proc_power_read_proc(
			char *page, char **start, off_t off,
			int count, int *eof, void *data)
{
	return sprintf(page, "%u\n", shutdown_flag);
}

static int proc_power_write_proc(
		struct file *file, const char *buffer,
		unsigned long count, void *data)
{
	shutdown_flag =  simple_strtoul(buffer, 0, 10);
	if (shutdown_flag == 1){
		printk("\n medive  write  power proc \n");
		shutdown_flag = 0;
		//jz_pm_hibernate();
	}
	return count;
}

static int __init poweroff_init(void)
{
	int retval;
	struct proc_dir_entry *res;

	poweroff_task = kthread_run(poweroff_thread, NULL, "poweroff");
	if (IS_ERR(poweroff_task)) {
		printk(KERN_ERR "jz_poweroff: FAIL.\n");
		return PTR_ERR(poweroff_task);
	}

	__gpio_as_input(POWEROFF_PIN);
	__gpio_disable_pull(POWEROFF_PIN);

	retval = request_irq(POWEROFF_IRQ, poweroff_irq,
			     IRQF_DISABLED, "poweroff", NULL);

	SET_POWEROFF_PIN_AS_IRQ;

	if (retval) {
		printk("Could not get poweroff irq %d\n", POWEROFF_IRQ);
		return retval;
	}

#ifndef CONFIG_PM
	/*poweroff_dev = pm_register(PM_SYS_DEV, PM_SYS_UNKNOWN, poweroff_pm_callback);
	if (poweroff_dev) {
		poweroff_dev->data = &poweroff_dev;
	}*/
#endif
	/* medive change */
	res = create_proc_entry("jz/poweroff", 0, NULL);
	if(res)
	{
		res->read_proc = proc_power_read_proc;
		res->write_proc = proc_power_write_proc;	
		res->data = NULL;
	}


	INIT_WORK(&suspend_work, suspend_handler);

	return 0;
}
 
static void __exit poweroff_exit(void)
{
	free_irq(POWEROFF_IRQ, NULL);
}

module_init(poweroff_init);
module_exit(poweroff_exit);

