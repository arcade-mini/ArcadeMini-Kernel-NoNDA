#include <asm/jzsoc.h>
#include <linux/i2c.h>
#include "f2655_camera.h"
#include "f2655_set.h"
#include "f2655_set_mode.h"
#include <asm/jzsoc.h>

#define f2655_DEBUG
#ifdef f2655_DEBUG
#define dprintk(x...)   do{printk("f2655_f---\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

/* gpio init */
#define GPIO_CAMERA_RST         (32*4+13) /*GPE13*/ 

struct f2655_sensor f2655;

void f2655_power_down(void)
{
	__gpio_as_output(4*32+24);     /*PE24*/
	__gpio_set_pin(4*32+24);
}    

void f2655_power_up(void)
{ 
	__gpio_as_output(4*32+24);     /*PE24*/
	__gpio_clear_pin(4*32+24);
}

void f2655_reset(void)
{
	__gpio_as_output(GPIO_CAMERA_RST);
	mdelay(50);
	__gpio_clear_pin(GPIO_CAMERA_RST);
	mdelay(50);
	__gpio_set_pin(GPIO_CAMERA_RST);
	mdelay(50);
}


int f2655_set_balance(balance_flag_t balance_flag,int arg)
{
	dprintk("f2655_set_balance");
	switch(balance_flag)
	{
		case WHITE_BALANCE_AUTO:
			f2655_set_wb_auto_mode(f2655.client);
			dprintk("wb_auto ");
			break;
		case WHITE_BALANCE_DAYLIGHT ://ri guang
			f2655_set_wb_sunny_mode(f2655.client);
			dprintk("wb_daylight ");
			break;
		case WHITE_BALANCE_CLOUDY_DAYLIGHT ://ying tian
			f2655_set_wb_cloudy_mode(f2655.client);
			dprintk("wb_cloudy daylight ");
			break;
		case WHITE_BALANCE_INCANDESCENT :
			f2655_set_wb_office_mode(f2655.client);
			dprintk("wb_incandenscent ");
			break;
		case WHITE_BALANCE_TUNGSTEN :
			f2655_set_wb_home_mode(f2655.client);
			dprintk("wb_tungsten ");
			break;
	}
	return 0;
}

int f2655_set_effect(effect_flag_t effect_flag,int arg)
{
	dprintk("f2655_set_effect");
	switch(effect_flag)
	{
		case EFFECT_NONE:
			f2655_set_effect_normal(f2655.client);
			dprintk("effect_none");
			break;
		case EFFECT_MONO :
			f2655_set_effect_blackwhite(f2655.client);  
			dprintk("effect_mono ");
			break;
		case EFFECT_NEGATIVE :
			f2655_set_effect_negative(f2655.client);
			dprintk("effect_negative ");
			break;
		case EFFECT_SOLARIZE ://bao guang
			dprintk("effect_solarize ");
			break;
		case EFFECT_SEPIA :
			f2655_set_effect_sepia(f2655.client);
			dprintk("effect_sepia ");
			break;
		case EFFECT_POSTERIZE ://se diao fen li
			dprintk("effect_posterize ");
			break;
		case EFFECT_WHITEBOARD :
			dprintk("effect_whiteboard ");
			break;
		case EFFECT_BLACKBOARD :
			dprintk("effect_blackboard ");
			break;
		case EFFECT_AQUA ://qian lv se
			f2655_set_effect_greenish(f2655.client);
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

int f2655_set_antibanding(antibanding_flag_t antibanding_flag,int arg)
{
	dprintk("f2655_set_antibanding");
	switch(antibanding_flag)
	{
		case ANTIBANDING_AUTO :
			f2655_ab_auto(f2655.client);
			dprintk("ANTIBANDING_AUTO ");
			break;
		case ANTIBANDING_50HZ :
			f2655_ab_50hz(f2655.client);
			dprintk("ANTIBANDING_50HZ ");
			break;
		case ANTIBANDING_60HZ :
			f2655_ab_60hz(f2655.client);
			dprintk("ANTIBANDING_60HZ ");
			break;
		case ANTIBANDING_OFF :
			f2655_ab_off(f2655.client);
			dprintk("ANTIBANDING_OFF ");
			break;
	}
	return 0;
}


int f2655_set_flash_mode(flash_mode_flag_t flash_mode_flag,int arg)
{
	return 0;
}

int f2655_set_scene_mode(scene_mode_flag_t scene_mode_flag,int arg)
{
	return 0;
}

int f2655_set_focus_mode(focus_mode_flag_t flash_mode_flag,int arg)
{
	return 0;
}


int f2655_set_fps(int fps)
{
	dprintk("set fps : %d",fps);
	return 0;
}

int f2655_set_luma_adaptation(int arg)
{
	dprintk("luma_adaptation : %d",arg);
	return 0;
}

int f2655_set_parameter(int cmd, int mode, int arg)
{
	switch(cmd)
	{
		case CPCMD_SET_BALANCE :
			f2655_set_balance(mode,arg);
			break;
		case CPCMD_SET_EFFECT :
			f2655_set_effect(mode,arg);
			break;
		case CPCMD_SET_ANTIBANDING :
			f2655_set_antibanding(mode,arg);
			break;
		case CPCMD_SET_FLASH_MODE :
			f2655_set_flash_mode(mode,arg);
			break;
		case CPCMD_SET_SCENE_MODE :
			f2655_set_scene_mode(mode,arg);
			break;
		case CPCMD_SET_PIXEL_FORMAT :
			break;
		case CPCMD_SET_FOCUS_MODE :
			f2655_set_focus_mode(mode,arg);
			break;
		case CPCMD_SET_PREVIEW_FPS:
			f2655_set_fps(arg);
			break;
		case CPCMD_SET_NIGHTSHOT_MODE:
			break;
		case CPCMD_SET_LUMA_ADAPTATION:
			f2655_set_luma_adaptation(arg);
			break;
	}
	return 0;
}

int f2655_set_power(int state)
{
	switch (state)
	{
		case 0:           
			/* hardware power up first */
			f2655_power_up();
			/* software power up later if it implemented */
			break;
		case 1:
			f2655_power_down();
			break;
		case 2:
			break;
		default:
			printk("%s : EINVAL! \n",__FUNCTION__);
	}
	return 0;
}

int f2655_sensor_init(void)
{
	//f2655_reset();
	f2655_init_setting(f2655.client);
	return 0;
}

int f2655_sensor_probe(void)
{
	f2655_power_up();
	f2655_reset();

//  sensor_write_reg16(f2655.client,0x308f,0x55);
//  int sensor_id = sensor_read_reg16(f2655.client,0x30e8);

	int sensor_id = sensor_read_reg16(f2655.client,0x300a);
	f2655_power_down();

	if(sensor_id == 0x26)
		return 0; 
	return -1;
}

/* sensor_set_function use for init preview or capture.there may be some difference between preview and capture.
 * so we divided it into two sequences.param: function indicated which function
 * 0: preview
 * 1: capture
 * 2: recording
 */
int f2655_set_function(int function)
{
	switch (function)
	{
		case 0:
			f2655_preview_set(f2655.client);
			break;
		case 1:
			f2655_capture_set(f2655.client);
			break;
		case 2:		
			break;
	}
	return 0;
}

int f2655_set_resolution(int width,int height,int bpp,pixel_format_flag_t fmt,camera_mode_t mode)
{
	f2655_size_switch(f2655.client,width,height,mode);
	return 0;         
}

static int f2655_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	f2655.client = client;
	return camera_sensor_register(&f2655.desc);
}

struct camera_sensor_ops f2655_sensor_ops = {
	.sensor_init = f2655_sensor_init,
	.camera_sensor_probe = f2655_sensor_probe,
	.sensor_set_function = f2655_set_function,
	.sensor_set_resolution = f2655_set_resolution, 
	.sensor_set_parameter = f2655_set_parameter, 
	.sensor_set_power = f2655_set_power,
};

struct resolution_info f2655_resolution_table[] = {	
	{1600,1200,16,PIXEL_FORMAT_YUV422I},
	{1280,1024,16,PIXEL_FORMAT_YUV422I},
	{1024,768,16,PIXEL_FORMAT_YUV422I},
	{800,600,16,PIXEL_FORMAT_YUV422I},
//	{640,480,16,PIXEL_FORMAT_YUV422I},
	{352,288,16,PIXEL_FORMAT_YUV422I},  //must be included
	{176,144,16,PIXEL_FORMAT_YUV422I},  //must be included in order to recording 

};

struct f2655_sensor f2655 = {
	.desc = {
		.name = "f2655",
		.wait_frames = 3,

		.ops = &f2655_sensor_ops,

		.resolution_table = f2655_resolution_table,
		.resolution_table_nr=ARRAY_SIZE(f2655_resolution_table),

		.capture_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},
		.max_capture_parm = {1600,1200, 16,PIXEL_FORMAT_YUV422I},

		.preview_parm = {800,600, 16,PIXEL_FORMAT_YUV422I}, 
		.max_preview_parm = {800,600, 16,PIXEL_FORMAT_YUV422I},

		.cfg_info = {
			.configure_register= 0x0
				|CIM_CFG_PACK_3			/* pack mode : 4 3 2 1 */
				|CIM_CFG_BYPASS			/* Bypass Mode */	
				|CIM_CFG_VSP             	/* VSYNC Polarity:1-falling edge active */
                	//        |CIM_CFG_HSP 
				|CIM_CFG_PCP             	/* PCLK working edge:1-falling */
				|CIM_CFG_DSM_GCM,		/* Gated Clock Mode */
		},

		.flags = {
			.effect_flag = 0
				|EFFECT_NONE
				|EFFECT_MONO
				|EFFECT_SEPIA
				|EFFECT_NEGATIVE 
				|EFFECT_AQUA,
			.balance_flag = 0
				| WHITE_BALANCE_AUTO 
				| WHITE_BALANCE_DAYLIGHT 
				| WHITE_BALANCE_CLOUDY_DAYLIGHT 
				| WHITE_BALANCE_INCANDESCENT 
				| WHITE_BALANCE_FLUORESCENT,
			.antibanding_flag = ~0x0,
			.flash_mode_flag = 0,
			.scene_mode_flag = 0,
			.pixel_format_flag = 0,
			.focus_mode_flag = 0,
		},

	},
};

static const struct i2c_device_id f2655_id[] = {
	{ "f2655", 0 },
	{ }	/* Terminating entry */
};
MODULE_DEVICE_TABLE(i2c, f2655_id);

static struct i2c_driver f2655_driver = {
	.probe		= f2655_i2c_probe,
	.id_table	= f2655_id,
	.driver	= {
		.name = "f2655",
	},
};

static int __init f2655_i2c_register(void)
{
	return i2c_add_driver(&f2655_driver);
}

module_init(f2655_i2c_register);
