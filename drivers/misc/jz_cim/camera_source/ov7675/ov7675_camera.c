#include <asm/jzsoc.h>
#include <linux/i2c.h>
#include "ov7675_camera.h"
#include "ov7675_set.h"

#define ov7675_DEBUG
//#undef DEBUG

#ifdef ov7675_DEBUG
#define dprintk(x...)   do{printk("ov7675---\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

/* gpio init */
#define GPIO_CAMERA_RST         (32*4+13) /*GPE13*/

struct ov7675_sensor ov7675;

void ov7675_power_down(void)
{ 
	__gpio_as_output(4*32+12);
	__gpio_set_pin(4*32+12);
	mdelay(5);
	dprintk("-----------------------------ov7675_power_down\n");
}   

void ov7675_power_up(void)
{
	__gpio_as_output(4*32+12);            /*PE12*/
	__gpio_clear_pin(4*32+12);
	mdelay(5);
	dprintk("-----------------------------ov7675_power_up\n");
}

void ov7675_reset(void)
{
}

int ov7675_set_balance(balance_flag_t balance_flag,int arg)
{
	dprintk("--------------------------------ov7675_set_balance");
	switch(balance_flag)
	{
		case WHITE_BALANCE_AUTO:
			ov7675_set_wb_auto(ov7675.client);
			break;
		case WHITE_BALANCE_INCANDESCENT :
			ov7675_set_wb_incandescence(ov7675.client);
			dprintk("WHITE_BALANCE_INCANDESCENT ");
			break;
		case WHITE_BALANCE_FLUORESCENT ://ying guang
			ov7675_set_wb_fluorescent(ov7675.client);
			dprintk("WHITE_BALANCE_FLUORESCENT ");
			break;
		case WHITE_BALANCE_WARM_FLUORESCENT :
			dprintk("WHITE_BALANCE_WARM_FLUORESCENT ");
			break;
		case WHITE_BALANCE_DAYLIGHT ://ri guang
			ov7675_set_wb_daylight(ov7675.client);
			dprintk("WHITE_BALANCE_DAYLIGHT ");
			break;
		case WHITE_BALANCE_CLOUDY_DAYLIGHT ://ying tian
			ov7675_set_wb_cloud(ov7675.client);
			dprintk("WHITE_BALANCE_CLOUDY_DAYLIGHT ");
			break;
		case WHITE_BALANCE_TWILIGHT :
			dprintk("WHITE_BALANCE_TWILIGHT ");
			break;
		case WHITE_BALANCE_SHADE :
			dprintk("WHITE_BALANCE_SHADE ");
			break;
	}
	return 0;
}

int ov7675_set_antibanding(antibanding_flag_t antibanding_flag,int arg)
{
	dprintk("------------------------------ov7675_set_antibanding");
	switch(antibanding_flag)
	{
		case ANTIBANDING_AUTO :
			break;
		case ANTIBANDING_50HZ :
			ov7675_set_ab_50hz(ov7675.client);
			dprintk("ANTIBANDING_50HZ ");
			break;
		case ANTIBANDING_60HZ :
			ov7675_set_ab_60hz(ov7675.client);
			dprintk("ANTIBANDING_60HZ ");
			break;
		case ANTIBANDING_OFF :
			dprintk("ANTIBANDING_OFF ");
			break;
	}
	return 0;
}

int ov7675_set_flash_mode(flash_mode_flag_t flash_mode_flag,int arg)
{
    return 0;
}

int ov7675_set_scene_mode(scene_mode_flag_t scene_mode_flag,int arg)
{
	return 0;
}

int ov7675_set_focus_mode(focus_mode_flag_t flash_mode_flag,int arg)
{
	return 0;
}

int ov7675_set_power(int state)
{
	switch (state)
	{
		case 0:           
			/* hardware power up first */
			ov7675_power_up();
			/* software power up later if it implemented */
			break;
		case 1:
			ov7675_power_down();
			break;
		case 2:
			break;
		default:
			printk("%s : EINVAL! \n",__FUNCTION__);
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
int ov7675_set_effect(effect_flag_t effect_flag,int arg)
{
	dprintk("ov7675_set_effect");
	switch(effect_flag)
	{
		case EFFECT_NONE:
			ov7675_set_effect_normal(ov7675.client);
			break;
		case EFFECT_MONO :
			ov7675_set_effect_grayscale(ov7675.client);
			dprintk("EFFECT_MONO ");
			break;
		case EFFECT_NEGATIVE :
			ov7675_set_effect_colorinv(ov7675.client);
			dprintk("EFFECT_NEGATIVE ");
			break;
		case EFFECT_SOLARIZE ://bao guang
			dprintk("EFFECT_SOLARIZE ");
			break;
		case EFFECT_SEPIA :
			ov7675_set_effect_sepia(ov7675.client);
			dprintk("EFFECT_SEPIA ");
			break;
		case EFFECT_POSTERIZE ://se diao fen li
			dprintk("EFFECT_POSTERIZE ");
			break;
		case EFFECT_WHITEBOARD :
			dprintk("EFFECT_WHITEBOARD ");
			break;
		case EFFECT_BLACKBOARD :
			dprintk("EFFECT_BLACKBOARD ");
			break;
		case EFFECT_AQUA  ://qian lv se
			ov7675_set_effect_sepiagreen(ov7675.client);
			dprintk("EFFECT_AQUA  ");
			break;
		case EFFECT_PASTEL:
			dprintk("EFFECT_PASTEL");
			break;
		case EFFECT_MOSAIC:
			dprintk("EFFECT_MOSAIC");
			break;
		case EFFECT_RESIZE:
			dprintk("EFFECT_RESIZE");
			break;
	}
	return 0;
}

int ov7675_set_output_format(pixel_format_flag_t pixel_format_flag,int arg)
{
	return 0;
}

int ov7675_set_function(int function, void *cookie)
{
	switch (function)
	{
		case 0:
			ov7675_set_preview_mode(ov7675.client);
			break;
		case 1:
			ov7675_set_capture_mode(ov7675.client);
			break;
		case 2:		
			break;
		case 3:		
			dprintk("---- do focus ---");
			break;
	}
	return 0;
}

int ov7675_set_fps(int fps)
{
	return 0;
}

int ov7675_set_night_mode(int disable)
{
	ov7675_set_nightmode(ov7675.client,disable);
	return 0;
}

int ov7675_set_luma_adaptation(int arg)
{
	return 0;
}

int ov7675_set_parameter(int cmd, int mode, int arg)
{
	switch(cmd)
	{
		case CPCMD_SET_BALANCE :
			ov7675_set_balance(mode,arg);
			break;
		case CPCMD_SET_EFFECT :
			ov7675_set_effect(mode,arg);
			break;
		case CPCMD_SET_ANTIBANDING :
			ov7675_set_antibanding(mode,arg);
			break;
		case CPCMD_SET_FLASH_MODE :
			ov7675_set_flash_mode(mode,arg);
			break;
		case CPCMD_SET_SCENE_MODE :
			ov7675_set_scene_mode(mode,arg);
			break;
		case CPCMD_SET_PIXEL_FORMAT :
			ov7675_set_output_format(mode,arg);
			break;
		case CPCMD_SET_FOCUS_MODE :
			ov7675_set_focus_mode(mode,arg);
			break;
		case CPCMD_SET_PREVIEW_FPS:
			ov7675_set_fps(arg);
			break;
		case CPCMD_SET_NIGHTSHOT_MODE:
			ov7675_set_night_mode(arg);
			break;
		case CPCMD_SET_LUMA_ADAPTATION:
			ov7675_set_luma_adaptation(arg);
			break;
	}
	return 0;
}

int ov7675_sensor_init(void)
{
//	ov7675_reset();
	ov7675_init_setting(ov7675.client);
	return 0;
}

int ov7675_sensor_probe(void)
{
	dprintk("------------------------------------------ov7675_sensor_probe \n");
	int sensor_id=0;

	mdelay(10);
	ov7675_power_up();	

	mdelay(10);
	sensor_write_reg(ov7675.client,0x12,0x80);

	mdelay(10);
	sensor_id = sensor_read_reg(ov7675.client,0x0a);
	dprintk("---------------------------ov7675 sensor read is %d",sensor_id);

	ov7675_power_down();

	if(sensor_id == 0x76)
		return 0; 

	dprintk("---------------------------sensor read is %d",sensor_id);
	return -1;
}

int ov7675_set_resolution(int width,int height,int bpp,pixel_format_flag_t fmt,camera_mode_t mode)
{
	ov7675_set_switch(ov7675.client,width,height);
	return 0;
}

struct camera_sensor_ops ov7675_sensor_ops = {
	.sensor_init = 			ov7675_sensor_init,
	.camera_sensor_probe = 		ov7675_sensor_probe,
	.sensor_set_function =  	ov7675_set_function,
	.sensor_set_resolution = 	ov7675_set_resolution, 
	.sensor_set_parameter = 	ov7675_set_parameter, 
	.sensor_set_power = 		ov7675_set_power,
};

struct resolution_info ov7675_resolution_table[] = {
	{640,480,16,PIXEL_FORMAT_YUV422I},
	{352,288,16,PIXEL_FORMAT_YUV422I},
	{176,144,16,PIXEL_FORMAT_YUV422I},
};

struct ov7675_sensor ov7675 = {
	.desc = {
		.name = "ov7675",
		.wait_frames = 4,

		.ops = &ov7675_sensor_ops,

		.resolution_table = ov7675_resolution_table,
		.resolution_table_nr=ARRAY_SIZE(ov7675_resolution_table),

		.capture_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},
		.max_capture_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},

		.preview_parm = {640,480, 16,PIXEL_FORMAT_YUV422I}, 
		.max_preview_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},

		.cfg_info = {
			.configure_register= 0x0
				|CIM_CFG_PACK_4			/* pack mode : 4 3 2 1 */
				|CIM_CFG_BYPASS			/* Bypass Mode */	
				|CIM_CFG_VSP             	/* VSYNC Polarity:1-falling edge active */
			//  |CIM_CFG_HSP
			//	|CIM_CFG_PCP             	/* PCLK working edge:1-falling */
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

static int ov7675_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	ov7675.client = client;
	sensor_set_i2c_speed(client,300*1000);
	return camera_sensor_register(&ov7675.desc);
}

static const struct i2c_device_id ov7675_id[] = {
	{ "ov7675", 0 },
	{ }	/* Terminating entry */
};
MODULE_DEVICE_TABLE(i2c, ov7675_id);

static struct i2c_driver ov7675_driver = {
	.probe		= ov7675_i2c_probe,
	.id_table	= ov7675_id,
	.driver	= {
		.name = "ov7675",
	},
};

static int __init ov7675_i2c_register(void)
{
	return i2c_add_driver(&ov7675_driver);
}

module_init(ov7675_i2c_register);


