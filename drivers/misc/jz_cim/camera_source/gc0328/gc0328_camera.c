#include <asm/jzsoc.h>
#include <linux/i2c.h>
#include "gc0328_camera.h"
#include "gc0328_set.h"

#define gc0328_DEBUG
#ifdef gc0328_DEBUG
#define dprintk(x...)   do{printk("gc0328---\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

/* gpio init */
#if defined(CONFIG_JZ4760_LYNX) || defined(CONFIG_JZ4760B_LYNX)
#define GPIO_CAMERA_RST         (32*4+18) /*GPE18*/ 
#define GPIO_CAMERA_PDN   		(32*4+19) /*GPE19*/

#elif defined(CONFIG_SOC_JZ4760) || defined(CONFIG_SOC_JZ4760B)
#define GPIO_CAMERA_RST         	(32*4+18) /*GPE18*/ 
#define GPIO_CAMERA_PDN   		(32*4+19) /*GPE19*/
#define GPIO_CAMERA_VCC_EN   	(32*4+26) /*GPE26*/
#else
#error "gc0328/gc0328_camera.c , please define camera gpio for your board."
#endif

struct gc0328_sensor gc0328;

void gc0328_power_down(void)
{
	__gpio_as_output(GPIO_CAMERA_VCC_EN);
	__gpio_clear_pin(GPIO_CAMERA_VCC_EN); //io set 0
	mdelay(5);
	__gpio_as_output(GPIO_CAMERA_PDN);
	__gpio_set_pin(GPIO_CAMERA_PDN);//io set 1
	mdelay(5);
	printk("gc0328_power_down\n");
}    

void gc0328_power_up(void)
{ 
	__gpio_as_output(GPIO_CAMERA_VCC_EN);
	__gpio_set_pin(GPIO_CAMERA_VCC_EN);
	mdelay(5);
	__gpio_as_output(GPIO_CAMERA_PDN);            /*PE19*/
	__gpio_clear_pin(GPIO_CAMERA_PDN);
	mdelay(5);
	printk("gc0328_power_up\n");
}

void gc0328_reset(void)
{
	__gpio_as_output(GPIO_CAMERA_RST);
	mdelay(50);
	__gpio_clear_pin(GPIO_CAMERA_RST);
	mdelay(50);
	__gpio_set_pin(GPIO_CAMERA_RST);
	mdelay(50);

}

int gc0328_set_balance(balance_flag_t balance_flag,int arg)
{
	dprintk("gc0328_set_balance");
	switch(balance_flag)
	{
		case WHITE_BALANCE_AUTO:
			gc0328_set_wb_auto(gc0328.client);
			break;
		case WHITE_BALANCE_INCANDESCENT :
			gc0328_set_wb_incandescence(gc0328.client);
			dprintk("WHITE_BALANCE_INCANDESCENT ");
			break;
		case WHITE_BALANCE_FLUORESCENT ://ying guang
			gc0328_set_wb_fluorescent(gc0328.client);
			dprintk("WHITE_BALANCE_FLUORESCENT ");
			break;
		case WHITE_BALANCE_WARM_FLUORESCENT :
			dprintk("WHITE_BALANCE_WARM_FLUORESCENT ");
			break;
		case WHITE_BALANCE_DAYLIGHT ://ri guang
			gc0328_set_wb_daylight(gc0328.client);
			dprintk("WHITE_BALANCE_DAYLIGHT ");
			break;
		case WHITE_BALANCE_CLOUDY_DAYLIGHT ://ying tian
			gc0328_set_wb_cloud(gc0328.client);
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

int gc0328_set_effect(effect_flag_t effect_flag,int arg)
{
	dprintk("gc0328_set_effect");
	switch(effect_flag)
	{
		case EFFECT_NONE:
			gc0328_set_effect_normal(gc0328.client);
			break;
		case EFFECT_MONO :
			gc0328_set_effect_grayscale(gc0328.client);
			dprintk("EFFECT_MONO ");
			break;
		case EFFECT_NEGATIVE :
			gc0328_set_effect_colorinv(gc0328.client);
			dprintk("EFFECT_NEGATIVE ");
			break;
		case EFFECT_SOLARIZE ://bao guang
			dprintk("EFFECT_SOLARIZE ");
			break;
		case EFFECT_SEPIA :
			gc0328_set_effect_sepia(gc0328.client);
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
			gc0328_set_effect_sepiagreen(gc0328.client);
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

int gc0328_set_antibanding(antibanding_flag_t antibanding_flag,int arg)
{
	dprintk("gc0328_set_antibanding");
	switch(antibanding_flag)
	{
		case ANTIBANDING_AUTO :
			break;
		case ANTIBANDING_50HZ :
			gc0328_set_ab_50hz(gc0328.client);
			dprintk("ANTIBANDING_50HZ ");
			break;
		case ANTIBANDING_60HZ :
			gc0328_set_ab_60hz(gc0328.client);
			dprintk("ANTIBANDING_60HZ ");
			break;
		case ANTIBANDING_OFF :
			dprintk("ANTIBANDING_OFF ");
			break;
	}
	return 0;
}

int gc0328_set_flash_mode(flash_mode_flag_t flash_mode_flag,int arg)
{
	return 0;
}

int gc0328_set_scene_mode(scene_mode_flag_t scene_mode_flag,int arg)
{
	switch(scene_mode_flag)
	{
		case SCENE_MODE_AUTO :
			dprintk("SCENE_MODE_AUTO ");
			break;
		case SCENE_MODE_ACTION :
			dprintk("SCENE_MODE_ACTION ");
			break;
		case SCENE_MODE_PORTRAIT   :
			dprintk("SCENE_MODE_PORTRAIT   ");
			break;
		case SCENE_MODE_LANDSCAPE  :
			dprintk("SCENE_MODE_LANDSCAPE  ");
			break;
		case SCENE_MODE_NIGHT     :
			dprintk("SCENE_MODE_NIGHT     ");
			break;
		case SCENE_MODE_NIGHT_PORTRAIT   :
			dprintk("SCENE_MODE_NIGHT_PORTRAIT   ");
			break;
		case SCENE_MODE_THEATRE  :
			dprintk("SCENE_MODE_THEATRE  ");
			break;
		case SCENE_MODE_BEACH   :
			dprintk("SCENE_MODE_BEACH   ");
			break;
		case SCENE_MODE_SNOW    :
			dprintk("SCENE_MODE_SNOW    ");
			break;
		case SCENE_MODE_SUNSET    :
			dprintk("SCENE_MODE_SUNSET    ");
			break;
		case SCENE_MODE_STEADYPHOTO   :
			dprintk("SCENE_MODE_STEADYPHOTO   ");
			break;
		case SCENE_MODE_FIREWORKS    :
			dprintk("SCENE_MODE_FIREWORKS    ");
			break;
		case SCENE_MODE_SPORTS    :
			dprintk("SCENE_MODE_SPORTS    ");
			break;
		case SCENE_MODE_PARTY   :
			dprintk("SCENE_MODE_PARTY   ");
			break;
		case SCENE_MODE_CANDLELIGHT    :
			dprintk("SCENE_MODE_CANDLELIGHT    ");
			break;
	}
	return 0;
}

int gc0328_set_focus_mode(focus_mode_flag_t flash_mode_flag,int arg)
{
	return 0;
}

int gc0328_set_night_mode(int enable)
{
	gc0328_set_nightmode(gc0328.client,enable);
	return 0;
}

int gc0328_set_parameter(int cmd, int mode, int arg)
{
	switch(cmd)
	{
		case CPCMD_SET_BALANCE :
			gc0328_set_balance(mode,arg);
			break;
		case CPCMD_SET_EFFECT :
			gc0328_set_effect(mode,arg);
			break;
		case CPCMD_SET_ANTIBANDING :
			gc0328_set_antibanding(mode,arg);
			break;
		case CPCMD_SET_FLASH_MODE :
			gc0328_set_flash_mode(mode,arg);
			break;
		case CPCMD_SET_SCENE_MODE :
			gc0328_set_scene_mode(mode,arg);
			break;
		case CPCMD_SET_PIXEL_FORMAT :
			break;
		case CPCMD_SET_FOCUS_MODE :
			break;
		case CPCMD_SET_PREVIEW_FPS:
			break;
		case CPCMD_SET_NIGHTSHOT_MODE:
			gc0328_set_nightmode(mode,arg);
			break;
		case CPCMD_SET_LUMA_ADAPTATION:
			break;
	}
	return 0;
}

int gc0328_set_power(int state)
{
	switch (state)
	{
		case 0:           
			/* hardware power up first */
			gc0328_power_up();
			/* software power up later if it implemented */
			break;
		case 1:
			gc0328_power_down();
			break;
		case 2:
			break;
		default:
			printk("%s : EINVAL! \n",__FUNCTION__);
	}
	return 0;
}

int gc0328_sensor_init(void)
{
	//gc0328_reset();
	gc0328_init_setting(gc0328.client);
	return 0;
}

int gc0328_sensor_probe(void)
{
    gc0328_power_up();
	gc0328_reset();

	int sensor_id =  sensor_read_reg(gc0328.client,0xf0);
	printk("---- gc0328 read is %d\n",sensor_id);
	gc0328_power_down();
	if(sensor_id == 0x9d)
		return 0; 
	
	return -1;
}

/* sensor_set_function use for init preview or capture.there may be some difference between preview and capture.
 * so we divided it into two sequences.param: function indicated which function
 * 0: preview
 * 1: capture
 * 2: recording
 */
int gc0328_set_function(int function)
{
	switch (function)
	{
		case 0:
			gc0328_preview_set(gc0328.client);
			break;
		case 1:
			gc0328_capture_set(gc0328.client);
			break;
		case 2:		
			break;
	}
	return 0;
}

int gc0328_set_resolution(int width,int height,int bpp,pixel_format_flag_t fmt,camera_mode_t mode)
{
  	gc0328_windows_switch(gc0328.client,width,height);
	return 0;         
}

static int gc0328_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	gc0328.client = client;
//	sensor_set_i2c_speed(client,300000);//set i2c speed : 300khz
	return camera_sensor_register(&gc0328.desc);
}

struct camera_sensor_ops gc0328_sensor_ops = {
	.sensor_init = gc0328_sensor_init,
	.camera_sensor_probe = gc0328_sensor_probe,
	.sensor_set_function = gc0328_set_function,
	.sensor_set_resolution = gc0328_set_resolution, 
	.sensor_set_parameter = gc0328_set_parameter, 
	.sensor_set_power = gc0328_set_power,
};

struct resolution_info gc0328_resolution_table[] = {	
    {640,480,16,PIXEL_FORMAT_YUV422I},
	{352,288,16,PIXEL_FORMAT_YUV422I},  //must be included
	{176,144,16,PIXEL_FORMAT_YUV422I},  //must be included in order to recording 
};

struct gc0328_sensor gc0328 = {
	.desc = {
		.name = "gc0328",
		.wait_frames = 2,
		.ops = &gc0328_sensor_ops,
		.resolution_table = gc0328_resolution_table,
		.resolution_table_nr=ARRAY_SIZE(gc0328_resolution_table),
		.capture_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},
		.max_capture_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},
		.preview_parm = {640,480, 16,PIXEL_FORMAT_YUV422I}, 
		.max_preview_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},
		.cfg_info = {
			.configure_register= 0x0
				|CIM_CFG_PACK_4			/* pack mode : 4 3 2 1 */
				|CIM_CFG_BYPASS			/* Bypass Mode */	
				|CIM_CFG_DF_YUV422		/* Bypass Mode */	
		//		|CIM_CFG_ORDER_3
			//			|CIM_CFG_VSP             	/* VSYNC Polarity:1-falling edge active */
			//     |CIM_CFG_HSP 
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

static const struct i2c_device_id gc0328_id[] = {
	{ "gc0328", 0 },
	{ }	/* Terminating entry */
};
MODULE_DEVICE_TABLE(i2c, gc0328_id);

static struct i2c_driver gc0328_driver = {
	.probe		= gc0328_i2c_probe,
	.id_table	= gc0328_id,
	.driver	= {
		.name = "gc0328",
	},
};

static int __init gc0328_i2c_register(void)
{
	printk("\n\ngc0328 i2c init\n\n");
	return i2c_add_driver(&gc0328_driver);
}

module_init(gc0328_i2c_register);
