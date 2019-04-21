#include <asm/jzsoc.h>
#include <linux/i2c.h>
#include "hi253_camera.h"
#include "hi253_set.h"

#define hi253_DEBUG

#ifdef hi253_DEBUG
#define dprintk(x...)   do{printk("hi253---\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

/* gpio init */
#if defined(CONFIG_JZ4760_LYNX) || defined(CONFIG_JZ4760B_LYNX)
#define GPIO_CAMERA_RST         (32*4+18) /*GPE18*/
#define GPIO_CAMERA_POWER	(32*4+19)  /*GPE19*/
#elif defined(CONFIG_JZ4770_MAPLE)
#define GPIO_CAMERA_RST         	(32*4+3) /*GPE18*/ 
#define GPIO_CAMERA_PDN   		(32*4+4) /*GPE19*/
#else
#error "hi253/hi253_camera.c , please define camera gpio for your board."
#endif

struct hi253_sensor hi253;

void hi253_power_down(void)
{ 
	__gpio_as_output(GPIO_CAMERA_POWER);
	__gpio_set_pin(GPIO_CAMERA_POWER);
	mdelay(5);
	dprintk("--------------------power_down\n");
}   

void hi253_power_up(void)
{
	__gpio_as_output(GPIO_CAMERA_POWER);
	__gpio_clear_pin(GPIO_CAMERA_POWER);
	mdelay(5);
	dprintk("--------------------power_up\n");
}

void hi253_reset(void)
{
	__gpio_as_output(GPIO_CAMERA_RST);
	mdelay(50);
	__gpio_clear_pin(GPIO_CAMERA_RST);
	mdelay(50);
	__gpio_set_pin(GPIO_CAMERA_RST);
	mdelay(50);
}

int hi253_set_balance(balance_flag_t balance_flag,int arg)
{
	dprintk("--------------------hi253_set_balance\n");
	switch(balance_flag)
	{
		case WHITE_BALANCE_AUTO:
		hi253_set_wb_auto(hi253.client);
		dprintk("--------------------WHITE_BALANCE_AUTO\n");
		break;
		
		case WHITE_BALANCE_INCANDESCENT :
		hi253_set_wb_incandescence(hi253.client);
		dprintk("--------------------WHITE_BALANCE_INCANDESCENT\n");
		break;
		
		case WHITE_BALANCE_FLUORESCENT ://ying guang
		hi253_set_wb_fluorescent(hi253.client);
		dprintk("--------------------WHITE_BALANCE_FLUORESCENT\n");
		break;
		
		case WHITE_BALANCE_WARM_FLUORESCENT :
		dprintk("--------------------WHITE_BALANCE_WARM_FLUORESCENT\n");
		break;
		
		case WHITE_BALANCE_DAYLIGHT ://ri guang
		hi253_set_wb_daylight(hi253.client);
		dprintk("--------------------WHITE_BALANCE_DAYLIGHT\n");
		break;
		
		case WHITE_BALANCE_CLOUDY_DAYLIGHT ://ying tian
		hi253_set_wb_cloud(hi253.client);
		dprintk("--------------------WHITE_BALANCE_CLOUDY_DAYLIGHT\n");
		break;
		
		case WHITE_BALANCE_TWILIGHT :
		dprintk("--------------------WHITE_BALANCE_TWILIGHT\n");
		break;
		
		case WHITE_BALANCE_SHADE :
		dprintk("--------------------WHITE_BALANCE_SHADE\n");
		break;
	}
	return 0;
}

int hi253_set_antibanding(antibanding_flag_t antibanding_flag,int arg)
{
	dprintk("--------------------hi253_set_antibanding\n");
	switch(antibanding_flag)
	{
		case ANTIBANDING_AUTO :
		dprintk("--------------------ANTIBANDING_AUTO\n");
		break;
		
		case ANTIBANDING_50HZ :
		hi253_set_ab_50hz(hi253.client);
		dprintk("--------------------ANTIBANDING_50HZ\n");
		break;
		
		case ANTIBANDING_60HZ :
		hi253_set_ab_60hz(hi253.client);
		dprintk("--------------------ANTIBANDING_60HZ\n");
		break;
		
		case ANTIBANDING_OFF :
		dprintk("--------------------ANTIBANDING_OFF\n");
		break;
	}
	return 0;
}

int hi253_set_flash_mode(flash_mode_flag_t flash_mode_flag,int arg)
{
	dprintk("--------------------hi253_set_flash_mode\n");
	switch(flash_mode_flag)
	{
		case FLASH_MODE_OFF :
		dprintk("--------------------FLASH_MODE_OFF\n");
		break;
		
		case FLASH_MODE_AUTO :
		dprintk("--------------------FLASH_MODE_AUTO\n");
		break;
		
		case FLASH_MODE_ON :
		dprintk("--------------------FLASH_MODE_ON\n");
		break;
		
		case FLASH_MODE_RED_EYE:
		dprintk("--------------------FLASH_MODE_RED_EYE\n");
		break;
		
		case FLASH_MODE_TORCH:
		dprintk("--------------------FLASH_MODE_TORCH\n");
		break;
		
	}
	return 0;
}

int hi253_set_scene_mode(scene_mode_flag_t scene_mode_flag,int arg)
{
	switch(scene_mode_flag)
	{
		case SCENE_MODE_AUTO:
		dprintk("--------------------SCENE_MODE_AUTO\n");
		break;
		
		case SCENE_MODE_ACTION:
		dprintk("--------------------SCENE_MODE_ACTION\n");
		break;
		
		case SCENE_MODE_PORTRAIT:
		dprintk("--------------------SCENE_MODE_PORTRAIT\n");
		break;
		
		case SCENE_MODE_LANDSCAPE:
		dprintk("--------------------SCENE_MODE_LANDSCAPE\n");
		break;
		
		case SCENE_MODE_NIGHT:
		dprintk("--------------------SCENE_MODE_NIGHT\n");
		break;
		
		case SCENE_MODE_NIGHT_PORTRAIT:
		dprintk("--------------------SCENE_MODE_NIGHT_PORTRAIT\n");
		break;
		
		case SCENE_MODE_THEATRE:
		dprintk("--------------------SCENE_MODE_THEATRE\n");
		break;
		
		case SCENE_MODE_BEACH:
		dprintk("--------------------SCENE_MODE_BEACH\n");
		break;
		
		case SCENE_MODE_SNOW:
		dprintk("--------------------SCENE_MODE_SNOW\n");
		break;
		
		case SCENE_MODE_SUNSET:
		dprintk("--------------------SCENE_MODE_SUNSET\n");	
		break;
		
		case SCENE_MODE_STEADYPHOTO:
		dprintk("--------------------SCENE_MODE_STEADYPHOTO\n");
		break;
		
		case SCENE_MODE_FIREWORKS:
		dprintk("--------------------SCENE_MODE_FIREWORKS\n");
		break;
		
		case SCENE_MODE_SPORTS:
		dprintk("--------------------SCENE_MODE_SPORTS\n");
		break;
		
		case SCENE_MODE_PARTY:
		dprintk("--------------------SCENE_MODE_PARTY\n");
		break;
		
		case SCENE_MODE_CANDLELIGHT:
		dprintk("--------------------SCENE_MODE_CANDLELIGHT\n");
		break;
	}
	return 0;
}

int hi253_set_focus_mode(focus_mode_flag_t flash_mode_flag,int arg)
{
	dprintk("--------------------hi253_set_focus_mode\n");
	switch(flash_mode_flag)
	{
		case FOCUS_MODE_AUTO:
		dprintk("--------------------FOCUS_MODE_AUTO\n");
		break;
		
		case FOCUS_MODE_INFINITY:  
		dprintk("--------------------FOCUS_MODE_INFINITY\n");
		break;
		
		case FOCUS_MODE_MACRO: 
		dprintk("--------------------FOCUS_MODE_MACRO\n");
		break;
		
		case FOCUS_MODE_FIXED:
		dprintk("--------------------FOCUS_MODE_FIXED\n");
		break;
	}

	return 0;
}

int hi253_set_power(int state)
{
	dprintk("--------------------hi253_set_power\n");

	switch (state)
	{
		case 0:           
		hi253_power_up();
		dprintk("--------------------hi253 set power case 0 : power up\n");
		break;
		
		case 1:
		hi253_power_down();
		dprintk("--------------------hi253 set power case 1 : power down\n");
		break;
		
		case 2:
		break;
	}
	return 0;
}

/* sensor_set_function use for init preview or capture.
 * there may be some difference between preview and capture.
 * so we divided it into two sequences.
 * param: function indicated which function
 * 0: preview
 * 1: capture
 * 2: recording
 */
int hi253_set_effect(effect_flag_t effect_flag,int arg)
{
	dprintk("--------------------hi253_set_effect\n");
	switch(effect_flag)
	{
		case EFFECT_NONE:
		hi253_set_effect_normal(hi253.client);
		dprintk("--------------------EFFECT_NONE\n");
		break;
		
		case EFFECT_MONO:
		hi253_set_effect_grayscale(hi253.client);
		dprintk("--------------------EFFECT_MONO\n");
		break;
		
		case EFFECT_NEGATIVE:
		hi253_set_effect_colorinv(hi253.client);
		dprintk("--------------------EFFECT_NEGATIVE\n");
		break;
		
		case EFFECT_SOLARIZE:
		dprintk("--------------------EFFECT_SOLARIZE\n");
		break;
		
		case EFFECT_SEPIA:
		hi253_set_effect_sepia(hi253.client);
		dprintk("--------------------EFFECT_SEPIA\n");
		break;
		
		case EFFECT_POSTERIZE:
		dprintk("--------------------EFFECT_POSTERIZE\n");
		break;
		
		case EFFECT_WHITEBOARD:
		dprintk("--------------------EFFECT_WHITEBOARD\n");
		break;
		
		case EFFECT_BLACKBOARD:
		dprintk("--------------------EFFECT_BLACKBOARD\n");
		break;
		
		case EFFECT_AQUA:
		hi253_set_effect_sepiagreen(hi253.client);
		dprintk("--------------------EFFECT_AQUA\n");
		break;
		
		case EFFECT_PASTEL:
		dprintk("--------------------EFFECT_PASTEL\n");
		break;
		
		case EFFECT_MOSAIC:
		dprintk("--------------------EFFECT_MOSAIC\n");
		break;
		
		case EFFECT_RESIZE:
		dprintk("--------------------EFFECT_RESIZE\n");
		break;
	}
	return 0;
}

int hi253_set_output_format(pixel_format_flag_t pixel_format_flag,int arg)
{
	dprintk("--------------------hi253_set_output_format\n");

	switch(pixel_format_flag)
	{
		case PIXEL_FORMAT_JPEG:
		dprintk("--------------------PIXEL_FORMAT_JPEG\n");
		break;
		
		case PIXEL_FORMAT_YUV422SP:
		dprintk("--------------------PIXEL_FORMAT_YUV422SP\n");
		break;
		
		case PIXEL_FORMAT_YUV420SP:
		dprintk("--------------------PIXEL_FORMAT_YUV420SP\n");
		break;
		
		case PIXEL_FORMAT_YUV422I:
		dprintk("--------------------PIXEL_FORMAT_YUV422I\n");
		break;
		
		case PIXEL_FORMAT_RGB565:
		dprintk("--------------------PIXEL_FORMAT_RGB565\n");
		break;
	}
	return 0;
}

int hi253_set_fps(int fps)
{
	dprintk("--------------------hi253_set_fps: %d",fps);
	return 0;
}

int hi253_set_night_mode(int enable)
{
	dprintk("--------------------hi253_set_night_mode\n");

	hi253_set_night_reg(hi253.client,enable);
	return 0;
}

int hi253_set_luma_adaptation(int arg)
{
	dprintk("--------------------hi253_set_luma_adaptation: %d",arg);
	return 0;
}

int hi253_set_parameter(int cmd, int mode, int arg)
{
	switch(cmd)
	{
		case CPCMD_SET_BALANCE :
		hi253_set_balance(mode,arg);
		dprintk("--------------------CPCMD_SET_BALANCE\n");
		break;

		case CPCMD_SET_EFFECT :
		hi253_set_effect(mode,arg);
		dprintk("--------------------CPCMD_SET_EFFECT\n");
		break;

		case CPCMD_SET_ANTIBANDING :
		hi253_set_antibanding(mode,arg);
		dprintk("--------------------CPCMD_SET_ANTIBANDING\n");
		break;

		case CPCMD_SET_FLASH_MODE :
		hi253_set_flash_mode(mode,arg);
		dprintk("--------------------CPCMD_SET_FLASH_MODE\n");
		break;

		case CPCMD_SET_SCENE_MODE :
		hi253_set_scene_mode(mode,arg);
		dprintk("--------------------CPCMD_SET_SCENE_MODE\n");
		break;

		case CPCMD_SET_PIXEL_FORMAT :
		hi253_set_output_format(mode,arg);
		dprintk("--------------------CPCMD_SET_PIXEL_FORMAT\n");
		break;

		case CPCMD_SET_FOCUS_MODE :
		hi253_set_focus_mode(mode,arg);
		dprintk("--------------------CPCMD_SET_FOCUS_MODE\n");
		break;

		case CPCMD_SET_PREVIEW_FPS:
		hi253_set_fps(arg);
		dprintk("--------------------CPCMD_SET_PREVIEW_FPS\n");
		break;

		case CPCMD_SET_NIGHTSHOT_MODE:
		hi253_set_night_mode(arg);
		dprintk("--------------------CPCMD_SET_NIGHTSHOT_MODE\n");
		break;

		case CPCMD_SET_LUMA_ADAPTATION:
		hi253_set_luma_adaptation(arg);
		dprintk("--------------------CPCMD_SET_LUMA_ADAPTATION\n");
		break;
	}
	return 0;
}

int hi253_sensor_init(void)
{
//	hi253_reset();
	dprintk("--------------------hi253_sensor_init\n");

	hi253_init_setting(hi253.client);
	return 0;
}

int hi253_sensor_probe(void)
{
	dprintk("--------------------hi253_sensor_probe\n");
	int sensor_id=0;
	
	mdelay(2);
	hi253_power_up();	

	mdelay(120);
	hi253_reset();

	mdelay(5);
	sensor_write_reg(hi253.client,0x03, 0x00);
	sensor_id = sensor_read_reg(hi253.client,0x04);
	dprintk("--------------------sensor read is %d",sensor_id);

	hi253_power_down();

	if(sensor_id == 0x92)
		return 0; 

	dprintk("--------------------sensor read is %d",sensor_id);
	return -1;
}

/* sensor_set_function use for init preview or capture.there may be some difference between preview and capture.
 * so we divided it into two sequences.param: function indicated which function
 * 0: preview
 * 1: capture
 * 2: recording
 */
int hi253_set_function(int function)
{
	dprintk("--------------------hi253_set_function\n");

	switch (function)
	{
		case 0:
		hi253_preview_set_reg(hi253.client);
		dprintk("--------------------hi253 set function case 0 : preview_set_reg\n");
		break;
		
		case 1:
		hi253_capture_set_reg(hi253.client);
		dprintk("--------------------hi253 set function case 0 : capture_set_reg\n");
		break;
		
		case 2:		
		break;
	}
	return 0;
}

int hi253_set_resolution(int width,int height,int bpp,pixel_format_flag_t fmt,camera_mode_t mode)
{
	dprintk("--------------------hi253_set_resolution\n");

	hi253_size_switch(hi253.client,width,height,mode);
	return 0;
}

struct camera_sensor_ops hi253_sensor_ops = 
{
	.sensor_init = 			hi253_sensor_init,
	.camera_sensor_probe = 		hi253_sensor_probe,
	.sensor_set_function =  	hi253_set_function,
	.sensor_set_resolution = 	hi253_set_resolution, 
	.sensor_set_parameter = 	hi253_set_parameter, 
	.sensor_set_power = 		hi253_set_power,
};

struct resolution_info hi253_resolution_table[] = 
{
	{1600,1200,16,PIXEL_FORMAT_YUV422I},
	{1280,1024,16,PIXEL_FORMAT_YUV422I},
	{1024,768,16,PIXEL_FORMAT_YUV422I},
	{800,600,16,PIXEL_FORMAT_YUV422I},
	{640,480,16,PIXEL_FORMAT_YUV422I},
	{352,288,16,PIXEL_FORMAT_YUV422I},  //must be included
	{176,144,16,PIXEL_FORMAT_YUV422I},  //must be included in order to recording 
};

struct hi253_sensor hi253 = 
{
	.desc = {
		.name = "hi253",
		.wait_frames = 2,

		.ops = &hi253_sensor_ops,

		.resolution_table = hi253_resolution_table,
		.resolution_table_nr=ARRAY_SIZE(hi253_resolution_table),

		.capture_parm = {1600,1200, 16,PIXEL_FORMAT_YUV422I},
		.max_capture_parm = {1600,1200, 16,PIXEL_FORMAT_YUV422I},

		.preview_parm = {640,480, 16,PIXEL_FORMAT_YUV422I}, 
		.max_preview_parm = {800,600, 16,PIXEL_FORMAT_YUV422I},

		.cfg_info = {
			.configure_register= 0x0
			        |CIM_CFG_PACK_2 		 /* pack mode : 4 3 2 1 */
				|CIM_CFG_BYPASS			/* Bypass Mode */	
//				|CIM_CFG_VSP             	/* VSYNC Polarity:1-falling edge active */
				|CIM_CFG_PCP             	/* PCLK working edge:1-falling */
//			        |CIM_CFG_HSP
			        |CIM_CFG_DSM_GCM,		/* Gated Clock Mode */
		},

		.flags = {
			.pixel_format_flag = PIXEL_FORMAT_YUV422SP,

			.scene_mode_flag = 0,

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

			.antibanding_flag = 0
				|ANTIBANDING_50HZ
				|ANTIBANDING_60HZ,
		},
	},
};

static int hi253_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	hi253.client = client;
//	sensor_set_i2c_speed(client,350*1000);
	return camera_sensor_register(&hi253.desc);
}

static const struct i2c_device_id hi253_id[] = 
{
	{ "hi253", 0 },
	{ }	/* Terminating entry */
};

MODULE_DEVICE_TABLE(i2c, hi253_id);

static struct i2c_driver hi253_driver = 
{
	.probe		= hi253_i2c_probe,
	.id_table	= hi253_id,
	.driver	= {
		.name = "hi253",
	},
};

static int __init hi253_i2c_register(void)
{
	return i2c_add_driver(&hi253_driver);
}

module_init(hi253_i2c_register);

