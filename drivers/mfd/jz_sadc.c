#include <linux/init.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/input.h>
#include <linux/slab.h>
#include <linux/interrupt.h>
#include <linux/clk.h>
#include <linux/platform_device.h>
#include <linux/io.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/kthread.h>
#include <linux/freezer.h>

#include <linux/jz_sadc.h>

#include <asm/irq.h>
#include <asm/gpio.h>
#include <asm/jzsoc.h>

#define TS_NAME "jz-sdac"

#define SAMPLE_TIMES		5
#define DROP_SAMPLE_TIMES   1  /* min drop 1 sample */
#define CAL_SAMPLE_TIMES (SAMPLE_TIMES - DROP_SAMPLE_TIMES)
#define VIRTUAL_SAMPLE      3 /* min >= 2 */

#define INIT_BAT_INTERVAL 8 //15
#define INIT_BAT_VALUE 1
#define BAT_FULL_VALUE 4500

static unsigned int battery_mv_usb = 0;
static unsigned int ts_key_data = 0;
static spinlock_t sadc_lock;

void sadc_init_clock(void)
{
	unsigned int val;
    int div;
	div = 120 - 1;	/* working at 200 KHz */
	val = div  | (1 << 8) | (199 << 16);
	printk("val = 0x%x\n",val);
	OUTREG32(SADC_ADCLK, val);
	//CMSREG32(SADC_ADCLK, div, ADCLK_CLKDIV_MASK);
	//*(unsigned int *)0xb0070028 = val;

}
static inline void sadc_start_aux(void)
{
	SETREG8(SADC_ADENA, ADENA_AUXEN);
}

static inline void sadc_start_pbat(void)
{
	SETREG8(SADC_ADENA, ADENA_VBATEN);      /* Enable pbat adc */
}

static inline void sadc_enable_ts(void)
{
	SETREG8(SADC_ADENA, ADENA_TCHEN);
}

static inline void sadc_disable_ts(void)
{
	CLRREG8(SADC_ADENA, ADENA_TCHEN);
}

static inline void sadc_start_ts(void)
{
    unsigned int tmp;

    OUTREG16(SADC_ADSAME, 1);       /* about 0.02 ms,you can change it */
    OUTREG16(SADC_ADWAIT, 1000);     /* about 3.33 ms,you can change it */

    /* set ts mode and sample times */
    //tmp = ADCFG_SPZZ | ADCFG_XYZ_XYZ1Z2 | ADCFG_SNUM(SAMPLE_TIMES);
    tmp = REG32(SADC_ADCFG);
    tmp |= ADCFG_SNUM(SAMPLE_TIMES);
    OUTREG32(SADC_ADCFG, tmp);

    /* mask all the intr except PEN-DOWN */
    tmp = ADCTRL_SLPENDM | ADCTRL_PENUM | ADCTRL_DTCHM | ADCTRL_VRDYM | ADCTRL_ARDYM;
    OUTREG8(SADC_ADCTRL, tmp);

    /* clear all the intr status if needed*/
    OUTREG8(SADC_ADSTATE, INREG8(SADC_ADSTATE));

    sadc_enable_ts();
}

//==============================================
/**
 * Read the battery voltage
 */
unsigned int jz_read_battery1(void)
{
	unsigned int timeout = 0x3fff;
	u16 pbat;
	
	sadc_start_pbat();
	udelay(300);

	while(!(INREG8(SADC_ADSTATE) & ADSTATE_VRDY) && --timeout);

    if (!timeout){
        //printk(KERN_ERR "Reading battery timeout!");
    	return 0;
    }

	pbat = INREG16(SADC_ADVDAT) & ADVDAT_VDATA_MASK;

	OUTREG8(SADC_ADSTATE, ADSTATE_VRDY);
	CLRREG8(SADC_ADENA, ADENA_VBATEN); // hardware may not shut down really

	return pbat;
}

/**
 * Read the aux voltage
 */
unsigned short jz_read_aux(int index)
{
	unsigned int timeout = 0x3ff;
	u16 val;

	CMSREG32(SADC_ADCFG, index, ADCFG_CMD_MASK);
	sadc_start_aux();
	udelay(300);

	while(!(INREG8(SADC_ADSTATE) & ADSTATE_ARDY) && --timeout);

    if (!timeout)
        printk(KERN_ERR "Reading aux timeout!");

	val = INREG16(SADC_ADADAT) & ADADAT_ADATA_MASK;

	OUTREG8(SADC_ADSTATE, ADSTATE_ARDY);
	CLRREG8(SADC_ADENA, ADENA_AUXEN); // hardware may not shut down really

	//printk("read aux val=%d\n", val);    
 	return val;
}

#define UP_KEY_0 0x01
#define DOWN_KEY_0 0x02
#define LEFT_KEY_0 0x04
#define RIGHT_KEY_0 0x08

//#define MAX_VALUE 3480
//#define MIN_VALUE 250
//#define MID_VALUE 1839
//#define ADJUST_VALUE 600

#define MAX_VALUE 4096
#define MID_VALUE 2048
#define ADJUST_VALUE 800

/*
 * Device file operations
 */
static int sadc_open(struct inode *inode, struct file *filp);
static int sadc_release(struct inode *inode, struct file *filp);
static int sadc_ioctl(struct inode *inode, struct file *file, unsigned int cmd, unsigned long arg);

static struct file_operations sadc_fops = 
{
	open:		sadc_open,
	release:	sadc_release,
	ioctl:		sadc_ioctl
};

static int sadc_open(struct inode *inode, struct file *filp)
{
 	try_module_get(THIS_MODULE);
	return 0;
}

static int sadc_release(struct inode *inode, struct file *filp)
{
 	module_put(THIS_MODULE);
	return 0;
}

static int sadc_ioctl(struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg)
{
	switch (cmd) {
	default:
		printk("Not supported command: 0x%x\n", cmd);
		return -EINVAL;
		break;
	}
	return 0;
}

/*
 * procfs interface file operations
 */

static int proc_sadc_battery_open(struct inode *inode, struct file *file);

static const struct file_operations proc_sadc_battery_fops = {
	.open		= proc_sadc_battery_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};
static unsigned int battery_mv = 4150;//default full power
static unsigned int usb_old_state ;

static int proc_sadc_battery_show(struct seq_file *m, void *v)
{
	//unsigned int mv = (battery_mv-180)/4;// = (jz4740_read_battery() * 7500 + 2048) / 4096;
	unsigned int mv = battery_mv;
	unsigned int value = 0;
	unsigned int usb_tmp_state = __gpio_get_pin(GPIO_USB_DETE);
	
	
	if (usb_tmp_state != usb_old_state)
	{
		if (usb_tmp_state == 0)
		{
			value = jz_read_battery1();
			if (value != 0){
				mv = (value*2500/4096)*4;
				
				battery_mv = mv;
			//	printk("usb canel mv is %d\n\n",mv);
			}
		}
		usb_old_state = usb_tmp_state;
	}

	if(__gpio_get_pin(GPIO_USB_DETE))
	{
		if (mv > battery_mv_usb)
			battery_mv_usb = mv;
		else
			mv = battery_mv_usb;
		
		mv |= 0x80000000;
	}
	else
	{
		if (mv > battery_mv_usb)
			mv = battery_mv_usb;
		else
			battery_mv_usb = mv;
#ifndef CHARGE_DET
		if(mv > BAT_FULL_VALUE)
			mv = BAT_FULL_VALUE;
#endif

	}

#ifdef CHARGE_DET
	__gpio_as_input(CHARGE_DET);
	__gpio_disable_pull(CHARGE_DET);

	if(__gpio_get_pin(CHARGE_DET))
		mv = BAT_FULL_VALUE;
#endif
	
	//printk("mv is %u \n",mv);
	
	//udc_pnp_set_gpio();
	seq_printf(m, "%u\n", mv);
	return 0;
}

static int proc_sadc_battery_open(struct inode *inode, struct file *file)
{
	return single_open(file, proc_sadc_battery_show, NULL);
}

static struct task_struct * battery_monitor;


#define POWEROFF_VOL 3550 //3620
#ifdef CONFIG_PM
extern int jz_pm_hibernate(void);
#endif
extern void run_sbin_poweroff();

static void battery_track_timer(unsigned long data)
{
	//printk("%s %d \n",__FILE__,__LINE__);

	int over_time = 0;
	unsigned int value = 0;
	unsigned int mv;

  	while(1)
  	{
	    value = jz_read_battery1();
	    if (value != 0)
		    battery_mv = value;
   
	    mv = (battery_mv*2500/4096)*4;//battery_mv*4+250;
	    battery_mv = mv;

	    if (battery_mv_usb == INIT_BAT_VALUE)
		{
		    battery_mv_usb = mv;
		    printk("first get battery value is %d\n",battery_mv_usb);
	    }
		
		//printk("battery is %u \n",mv);
		
    	if(battery_mv < POWEROFF_VOL)
	    {
			over_time++;
			if(over_time > 1)//3
			{
				printk("...............low power !\n");
				if(!__gpio_get_pin(OTG_HOTPLUG_PIN))
				{
					printk("the power is too low do hibernate!!!!!\n");
					run_sbin_poweroff();
#ifdef CONFIG_PM
					jz_pm_hibernate();
#endif
				}
				printk("------- %s %d \n",__func__,__LINE__);
			}
	    }
    	else
    	{
			over_time = 0;
	  		  	
		#ifdef BATTERY_LOW_LED
			if(battery_mv < POWEROFF_VOL+100)//less battery
			{
				__gpio_as_output(BATTERY_LOW_LED);
				__gpio_set_pin(BATTERY_LOW_LED);
			}
			else
			{
				__gpio_as_output(BATTERY_LOW_LED);
				__gpio_clear_pin(BATTERY_LOW_LED);
			}
		#endif
    	}

		set_current_state(TASK_INTERRUPTIBLE);
	    schedule_timeout(HZ*INIT_BAT_INTERVAL);  //10
	    
  	}
	
}

unsigned int   jz_read_ts_data(void)
{
	return ts_key_data;
}

static void jz_cal_ts_data(unsigned int value)
{
	int tsdata_x;
	int tsdata_y;
	unsigned int val = 0;

	tsdata_x = value & 0xfff;
	tsdata_y = (value & 0xfff0000) >> 16;
	printk("\n medive printk : tsdata_x = %d tsdata_y = %d \n",tsdata_x,tsdata_y);
		
	if (((tsdata_x > (MAX_VALUE-ADJUST_VALUE)) && (tsdata_x < (MAX_VALUE)))  &&  (tsdata_y >= 0 && tsdata_y < ADJUST_VALUE ))
	{
		printk("\n up   left   \n");
		val |= 	UP_KEY_0 | LEFT_KEY_0;
	} else if (((tsdata_x > (MAX_VALUE-ADJUST_VALUE)) && (tsdata_x < (MAX_VALUE)))  &&  (tsdata_y >= (MAX_VALUE - ADJUST_VALUE) && tsdata_y < MAX_VALUE ))
	{
		printk("\n down  left   \n");
		val |= 	DOWN_KEY_0 | LEFT_KEY_0;
	} else if (((tsdata_x >= 0) && (tsdata_x < (ADJUST_VALUE)))  &&  (tsdata_y >= 0 && tsdata_y < ADJUST_VALUE ))
	{
		printk("\n up   right   \n");
		val |= 	UP_KEY_0 | RIGHT_KEY_0;
	} else if (((tsdata_x > 0) && (tsdata_x < (ADJUST_VALUE)))  &&  (tsdata_y >= (MAX_VALUE - ADJUST_VALUE) && tsdata_y < MAX_VALUE ))
	{
		printk("\n down   right   \n");
		val |= 	DOWN_KEY_0 | RIGHT_KEY_0;
	} else 	if (((tsdata_x > (MID_VALUE-ADJUST_VALUE)) && (tsdata_x < (MID_VALUE+ADJUST_VALUE)))  &&  (tsdata_y >= 0 && tsdata_y < ADJUST_VALUE ))
	{
		val |= 	UP_KEY_0;
	}else if (((tsdata_x > (MID_VALUE-ADJUST_VALUE)) && (tsdata_x < (MID_VALUE+ADJUST_VALUE)))  &&  (tsdata_y > (MAX_VALUE - ADJUST_VALUE) && tsdata_y < MAX_VALUE ))
	{
		val |= 	DOWN_KEY_0;
	}else if (((tsdata_x > (MAX_VALUE-ADJUST_VALUE)) && (tsdata_x < MAX_VALUE))  &&  (tsdata_y > (MID_VALUE - ADJUST_VALUE) && tsdata_y < (MID_VALUE + ADJUST_VALUE) ))
	{
		val |= 	LEFT_KEY_0;
	}else if (((tsdata_x >= 0) && (tsdata_x < ADJUST_VALUE))  &&  (tsdata_y > (MID_VALUE - ADJUST_VALUE) && tsdata_y < (MID_VALUE + ADJUST_VALUE )))
	{
		val |= 	RIGHT_KEY_0;
	}else
		val = 0;

	ts_key_data = val;
}

static void print_reg(void)
{
	printk("ADENA:%x\n",REG32(SADC_ADENA));
	printk("ADCFG:%x\n",REG32(SADC_ADCFG));
	printk("ADCTRL:%x\n",REG32(SADC_ADCTRL));
	printk("ADSTATE:%x\n",REG32(SADC_ADSTATE));
	printk("ADSAME:%x\n",REG32(SADC_ADSAME));
	printk("ADWAIT:%x\n",REG32(SADC_ADWAIT));
	printk("ADTCH:%x\n",REG32(SADC_ADTCH));
	printk("ADVDAT:%x\n",REG32(SADC_ADVDAT));
	printk("ADADAT:%x\n",REG32(SADC_ADADAT));
	printk("ADCLK:%x\n",REG32(SADC_ADCLK));
//	printk("ADCMD:%x\n",REG32(SADC_ADCMD));  // NOTE:This register couldn't Read.
}

irqreturn_t sadc_interrupt(int irq, void * dev_id)
{
	unsigned int state;
	unsigned char tmp;
	static int pen_is_down = 0;
	unsigned int val;

	printk("+++++++++++sadc irq \n");
	
	spin_lock_irq(&sadc_lock);
	
    state = INREG8(SADC_ADSTATE) & (~INREG8(SADC_ADCTRL));
    printk("\n %s: state=%x \n",__func__,state);
	//print_reg();
#if 1	
	if(state & ADSTATE_PENU)
	{
		printk("---- %s %d pen_is_down = %d\n",__func__,__LINE__,pen_is_down);
		
		/*  mask pen up and wait pen down */
		tmp = INREG8(SADC_ADCTRL);
		tmp = (tmp | ADCTRL_PENUM) & ~ADCTRL_PENDM;
		OUTREG8(SADC_ADCTRL, tmp);
		
		if(pen_is_down == 1)
		{
		    SETREG8(SADC_ADCTRL, ADCTRL_DTCHM);
			{
				printk("---- %s %d \n",__func__,__LINE__);
			}
		}
		
		pen_is_down = 0;
	}
	else if(state & ADSTATE_PEND)
	{
		printk("---- %s %d \n",__func__,__LINE__);
		
		/* REG_SADC_CTRL used in pendown & penup mutex */
		tmp = INREG8(SADC_ADCTRL);
		tmp = (tmp | ADCTRL_PENDM) & ~(ADCTRL_PENUM | ADCTRL_DTCHM);
		OUTREG8(SADC_ADCTRL, tmp);
		
		printk("---- %s %d pen_is_down = %d\n",__func__,__LINE__,pen_is_down);

		if(pen_is_down == 0)
		{
			/*  mask pen down and wait pen up */
			pen_is_down = 1;
			printk("---- %s %d \n",__func__,__LINE__);
		}
		
		state |= ADSTATE_PENU;
		state |= ADSTATE_SLPEND;
	}
	else if(state & ADSTATE_DTCH)
#else
	if(state & ADSTATE_DTCH)
#endif
	{
		val = INREG32(SADC_ADTCH);
		printk("---- %s %d val = %x pen_is_down=%d \n",__func__,__LINE__,val,pen_is_down);

		/* alone here clear state */
		OUTREG8(SADC_ADSTATE, ADSTATE_DTCH);

		//if(pen_is_down)
		//	handle_touch(ts,fifo,2);
	}
	else if(state & ADSTATE_SLPEND)
	{
		printk("---- %s %d \n",__func__,__LINE__);
		SETREG8(SADC_ADCTRL, ADSTATE_SLPEND);
	}
	
	//when data count not is set_count penup is not clear;
	if(!(state & ADSTATE_DTCH))
		OUTREG8(SADC_ADSTATE, state);
	
	/*if(state & ADSTATE_DTCH){
		printk("---- %s %d \n",__func__,__LINE__);
        jz_cal_ts_data(INREG32(SADC_ADTCH));
		OUTREG8(SADC_ADSTATE, ADSTATE_DTCH);
    }*/
	printk("---- %s %d state=%x \n",__func__,__LINE__,state);
	//print_reg();
	spin_unlock_irq(&sadc_lock);

    return IRQ_HANDLED;
}


/************************************************************************/
/*	init sadc							*/
/************************************************************************/
static int __init sadc_init(void)
{
	struct proc_dir_entry *res;
    int	error;
	
	cpm_start_clock(CGM_SADC);                               //start sadc clock
	udelay(1);
	
#if defined(CONFIG_SOC_JZ4760)
	CLRREG8(SADC_ADENA, ADENA_POWER);
	CLRREG32(CPM_LCR, LCR_VBATIR);
	mdelay(50);
#elif defined(CONFIG_SOC_JZ4760B) || defined(CONFIG_SOC_JZ4770)
	CLRREG8(SADC_ADENA, ADENA_POWER);           //sadc power on
	mdelay(50);                                 //wait sadc power on
	SETREG8(SADC_ADENA, ADENA_PENDEN);         //enable pen down detect
#endif
    
	sadc_init_clock();                        //init sadc clock
	OUTREG8(SADC_ADCTRL, ADCTRL_MASK_ALL);    //mask all interrupt
	
	usb_old_state = 0;

	battery_mv_usb = INIT_BAT_VALUE;
	res = create_proc_entry("jz/battery", 0, NULL);
	if (res) {
		res->proc_fops = &proc_sadc_battery_fops;
	}

#if 1
    battery_monitor = kthread_run(battery_track_timer, NULL, "battery _monitor");
    if(IS_ERR(battery_monitor))
    {
      printk("Kernel battery _monitor thread start error!\n");
      return 0;
    }
#endif

#if 0  //allen del  
	error = request_irq(IRQ_SADC, sadc_interrupt, IRQF_DISABLED, TS_NAME, NULL);
	if (error) {
		printk("unable to get PenDown IRQ %d\n", IRQ_SADC);
		goto err_free_irq;
	}
	
	spin_lock_init(&sadc_lock);
	sadc_start_ts();
	
    return 0;
    
err_free_irq:
	free_irq(IRQ_SADC,NULL);
#endif
    
	printk("JZ4760b SAR-ADC driver registered\n");
    return 0;
}
static void __exit sadc_exit(void)
{
	remove_proc_entry("jz/battery", NULL);	
}
//subsys_initcall(sadc_init);
module_init(sadc_init);
module_exit(sadc_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("JZ SADC Core Driver");
MODULE_AUTHOR(" <@ingenic.com>");

