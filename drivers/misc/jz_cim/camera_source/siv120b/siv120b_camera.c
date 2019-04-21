#include <asm/jzsoc.h>
#include <linux/i2c.h>
#include "siv120b_camera.h"
#include "siv120b_set.h"
#include "siv120b_set_mode.h"
#include <asm/jzsoc.h>

#define siv120b_DEBUG
#ifdef siv120b_DEBUG
#define dprintk(x...)   do{printk("siv120b---\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

struct siv120b_sensor siv120b;

void siv120b_power_down(void)
{
	__gpio_as_output(GPIO_CAMERA_CS);
	__gpio_as_output(GPIO_CAMERA_RST);
	__gpio_clear_pin(GPIO_CAMERA_CS);
	mdelay(5);
	__gpio_clear_pin(GPIO_CAMERA_RST);
	mdelay(5);	
}

void siv120b_power_up(void)
{ 
	//siv120b_power_on later
	__gpio_as_output(GPIO_CAMERA_CS);
	__gpio_as_output(GPIO_CAMERA_RST);
	__gpio_set_pin(GPIO_CAMERA_CS);
	mdelay(5);
	__gpio_set_pin(GPIO_CAMERA_RST);
	msleep(5);
}

void siv120b_reset(void)
{
	__gpio_as_output(GPIO_CAMERA_RST);
	__gpio_clear_pin(GPIO_CAMERA_RST);
	mdelay(25);
	__gpio_set_pin(GPIO_CAMERA_RST);
	mdelay(25);
}


int siv120b_set_balance(balance_flag_t balance_flag,int arg)
{
	dprintk("siv120b_set_balance");
	switch(balance_flag)
	{
		case WHITE_BALANCE_AUTO:
			siv120b_set_wb_auto_mode(siv120b.client);
			dprintk("wb_auto ");
			break;
		case WHITE_BALANCE_DAYLIGHT ://ri guang
			siv120b_set_wb_sunny_mode(siv120b.client);
			dprintk("wb_daylight ");
			break;
		case WHITE_BALANCE_CLOUDY_DAYLIGHT ://ying tian
			siv120b_set_wb_cloudy_mode(siv120b.client);
			dprintk("wb_cloudy daylight ");
			break;
		case WHITE_BALANCE_INCANDESCENT :
			siv120b_set_wb_office_mode(siv120b.client);
			dprintk("wb_incandenscent ");
			break;
		case WHITE_BALANCE_FLUORESCENT :
			siv120b_set_wb_fluorescent_mode(siv120b.client);
			dprintk("wb_incandenscent ");
			break;
	}
	return 0;
}

int siv120b_set_effect(effect_flag_t effect_flag,int arg)
{
	dprintk("siv120b_set_effect");
	switch(effect_flag)
	{
		case EFFECT_NONE:
			siv120b_set_effect_normal(siv120b.client);
			dprintk("effect_none");
			break;
		case EFFECT_MONO :
			siv120b_set_effect_blackwhite(siv120b.client);  
			dprintk("effect_mono ");
			break;
		case EFFECT_NEGATIVE :
			siv120b_set_effect_negative(siv120b.client);
			dprintk("effect_negative ");
			break;
		case EFFECT_SOLARIZE ://bao guang
			dprintk("effect_solarize ");
			break;
		case EFFECT_SEPIA :
			siv120b_set_effect_sepia(siv120b.client);
			dprintk("effect_sepia ");
			break;
		case EFFECT_POSTERIZE ://se diao fen li
			dprintk("effect_posterize ");
			break;
		case EFFECT_WHITEBOARD :
			dprintk("effect_whiteboard ");
			break;
		case EFFECT_BLACKBOARD :
			siv120b_set_effect_blackboard(siv120b.client);  
			dprintk("effect_blackboard ");
			break;
		case EFFECT_AQUA ://qian lv se
			siv120b_set_effect_sepia(siv120b.client);
			dprintk("effect_aqua  ");
			break;
		case EFFECT_PASTEL:
			dprintk("effect_pastel");
			break;
		case EFFECT_MOSAIC:
			dprintk("effect_mosaic");
			break;
		case EFFECT_RESIZE:
			dprintk("effect_resize");
			break;
	}
	return 0;
}

int siv120b_set_antibanding(antibanding_flag_t antibanding_flag,int arg)
{
	dprintk("siv120b_set_antibanding");
	switch(antibanding_flag)
	{
		case ANTIBANDING_AUTO :
			siv120b_ab_auto(siv120b.client);
			dprintk("ANTIBANDING_AUTO ");
			break;
	}
	return 0;
}


int siv120b_set_flash_mode(flash_mode_flag_t flash_mode_flag,int arg)
{
	return 0;
}

int siv120b_set_scene_mode(scene_mode_flag_t scene_mode_flag,int arg)
{
	return 0;
}

int siv120b_set_focus_mode(focus_mode_flag_t flash_mode_flag,int arg)
{
	return 0;
}


int siv120b_set_fps(int fps)
{
	return 0;
}

int siv120b_set_luma_adaptation(int arg)
{
	return 0;
}

int siv120b_set_parameter(int cmd, int mode, int arg)
{
	switch(cmd)
	{
		case CPCMD_SET_BALANCE :
			siv120b_set_balance(mode,arg);
			break;
		case CPCMD_SET_EFFECT :
			siv120b_set_effect(mode,arg);
			break;
		case CPCMD_SET_ANTIBANDING :
			siv120b_set_antibanding(mode,arg);
			break;
		case CPCMD_SET_FLASH_MODE :
			siv120b_set_flash_mode(mode,arg);
			break;
		case CPCMD_SET_SCENE_MODE :
			siv120b_set_scene_mode(mode,arg);
			break;
		case CPCMD_SET_PIXEL_FORMAT :
			break;
		case CPCMD_SET_FOCUS_MODE :
			siv120b_set_focus_mode(mode,arg);
			break;
		case CPCMD_SET_PREVIEW_FPS:
			siv120b_set_fps(arg);
			break;
		case CPCMD_SET_NIGHTSHOT_MODE:
			break;
		case CPCMD_SET_LUMA_ADAPTATION:
			siv120b_set_luma_adaptation(arg);
			break;
	}
	return 0;
}

int siv120b_set_power(int state)
{
	switch (state)
	{
		case 0:           
			/* hardware power up first */
			siv120b_power_up();
			/* software power up later if it implemented */
			break;
		case 1:
			siv120b_power_down();
			break;
		case 2:
			break;
		default:
			printk("%s : EINVAL! \n",__FUNCTION__);
	}
	return 0;
}

int siv120b_sensor_init(void)
{
	siv120b_init_setting(siv120b.client);
	return 0;
}

int siv120b_sensor_probe(void)
{
	int retval = 0;

	siv120b_power_up();
	siv120b_reset();
	retval = sensor_write_reg(siv120b.client,0x00,0x00);
	siv120b_power_down();

	if(retval == 0)
		return 0; 
	return -1;
}

/* sensor_set_function use for init preview or capture.there may be some difference between preview and capture.
 * so we divided it into two sequences.param: function indicated which function
 * 0: preview
 * 1: capture
 * 2: recording
 */
int siv120b_set_function(int function)
{
	switch (function)
	{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
	}
	return 0;
}

int siv120b_set_resolution(int width,int height,int bpp,pixel_format_flag_t fmt,camera_mode_t mode)
{
	size_switch(siv120b.client,width,height,mode);
	return 0;         
}

static ssize_t ov2655_read_store(struct device *dev,
				   struct device_attribute *attr,
				   const char *buf, size_t count)
{
	uint32_t reg;
	sscanf(buf,"%x",&reg);
	printk("read reg 0x%x = 0x%x\n",reg&0xff,sensor_read_reg(siv120b.client,reg&0xff));

	return count;
}

static ssize_t ov2655_write_store(struct device *dev,
				   struct device_attribute *attr,
				   const char *buf, size_t count)
{
	uint32_t reg,val;
	sscanf(buf,"%x,%x",&reg,&val);
	printk("write reg : %x | value : %x\n",reg&0xff,val&0xff);
	sensor_write_reg(siv120b.client,reg&0xff,val&0xff);

	return count;
}

static DEVICE_ATTR(write, 0664, NULL, ov2655_write_store);
static DEVICE_ATTR(read, 0664, NULL, ov2655_read_store);

static struct attribute *ov2655_attributes[] = {
	&dev_attr_write.attr,
	&dev_attr_read.attr,
	NULL
};

static const struct attribute_group ov2655_attr_group = {
	.attrs = ov2655_attributes,
};

static int siv120b_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	siv120b.client = client;
	sysfs_create_group(&client->dev.kobj, &ov2655_attr_group);
	return camera_sensor_register(&siv120b.desc);
}

struct camera_sensor_ops siv120b_sensor_ops = {
	.sensor_init = siv120b_sensor_init,
	.camera_sensor_probe = siv120b_sensor_probe,
	.sensor_set_function = (int (*)(int ,void *))siv120b_set_function,
	.sensor_set_resolution = siv120b_set_resolution, 
	.sensor_set_parameter = siv120b_set_parameter, 
	.sensor_set_power = siv120b_set_power,
};

struct resolution_info siv120b_resolution_table[] = {	
	{640,480,16,PIXEL_FORMAT_YUV422I},	//
	//{352,288,16,PIXEL_FORMAT_YUV422I},
	{320,240,16,PIXEL_FORMAT_YUV422I},	//
	//{176,144,16,PIXEL_FORMAT_YUV422I}, 
};

struct siv120b_sensor siv120b = {
	.desc = {
		.name = "siv120b",
		.wait_frames = 2,

		.ops = &siv120b_sensor_ops,

		.resolution_table = siv120b_resolution_table,
		.resolution_table_nr=ARRAY_SIZE(siv120b_resolution_table),

		.capture_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},
		.max_capture_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},

		.preview_parm = {640,480, 16,PIXEL_FORMAT_YUV422I}, 
		.max_preview_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},

		.cfg_info = {
			.configure_register= 0x0
				|CIM_CFG_PACK_2			/* pack mode : 4 3 2 1 */
				|CIM_CFG_BYPASS			/* Bypass Mode */	
			//	|CIM_CFG_VSP             	/* VSYNC Polarity:1-falling edge active */
                	//      |CIM_CFG_HSP 
				|CIM_CFG_PCP             	/* PCLK working edge:1-falling */
				|CIM_CFG_DSM_GCM,		/* Gated Clock Mode */
		},

		.flags = {
			.effect_flag = 0
				|EFFECT_NONE
				|EFFECT_MONO
				|EFFECT_SEPIA
				|EFFECT_NEGATIVE 
				|EFFECT_AQUA
				|EFFECT_BLACKBOARD,
			.balance_flag = 0
				| WHITE_BALANCE_AUTO
				|WHITE_BALANCE_INCANDESCENT
				|WHITE_BALANCE_DAYLIGHT
				|WHITE_BALANCE_CLOUDY_DAYLIGHT
				|WHITE_BALANCE_FLUORESCENT,
			.antibanding_flag = ~0x0,
			.flash_mode_flag = 0,
			.scene_mode_flag = 0,
			.pixel_format_flag = 0,
			.focus_mode_flag = 0,
		},
	},
};

#define CAMERA_NAME "siv120b"
static const struct i2c_device_id siv120b_id[] = {
	{CAMERA_NAME, 0 },
	{ }	/* Terminating entry */
};
MODULE_DEVICE_TABLE(i2c, siv120b_id);

static struct i2c_driver siv120b_driver = {
	.probe		= siv120b_i2c_probe,
	.id_table	= siv120b_id,
	.driver	= {
		.name = CAMERA_NAME,
	},
};

static int __init siv120b_i2c_register(void)
{
	return i2c_add_driver(&siv120b_driver);
}

module_init(siv120b_i2c_register);
