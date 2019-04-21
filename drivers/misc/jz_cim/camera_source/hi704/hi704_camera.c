#include <asm/jzsoc.h>
#include <linux/i2c.h>
#include "hi704_camera.h"
#include "hi704_set.h"

#define hi704_DEBUG
#undef DEBUG

#ifdef hi704_DEBUG
#define dprintk(x...)   do{printk("hi704---\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

/* gpio init */
#define GPIO_CAMERA_RST         (32*4+18) /*GPE18*/ 
#define GPIO_CAMERA_PDN   		(32*4+19) /*GPE19*/
#define GPIO_CAMERA_VCC_EN   	(32*4+26) /*GPE19*/



struct hi704_sensor hi704;

void hi704_power_down(void)
{ 
	__gpio_as_output(GPIO_CAMERA_VCC_EN);
	__gpio_clear_pin(GPIO_CAMERA_VCC_EN);
	mdelay(5);
	__gpio_as_output(GPIO_CAMERA_PDN); //allen
	__gpio_set_pin(GPIO_CAMERA_PDN); //allen
	mdelay(5);   //allen
	printk("hi704_power_down\n");
}    

void hi704_power_up(void)
{
	__gpio_as_output(GPIO_CAMERA_VCC_EN); 
	__gpio_set_pin(GPIO_CAMERA_VCC_EN);
	mdelay(5);
	__gpio_as_output(GPIO_CAMERA_PDN); //allen add
	__gpio_clear_pin(GPIO_CAMERA_PDN); //allen add
    mdelay(5); //allen add
	printk("hi704_power_up\n");
}

void hi704_reset(void)
{
	__gpio_as_output(GPIO_CAMERA_RST);
	mdelay(50);
	__gpio_clear_pin(GPIO_CAMERA_RST);
	mdelay(50);
	__gpio_set_pin(GPIO_CAMERA_RST);
	mdelay(50);
	//__gpio_clear_pin(GPIO_CAMERA_RST); //allen del
	//mdelay(50);  //allen del
}

int hi704_set_balance(balance_flag_t balance_flag,int arg)
{
	dprintk("hi704_set_balance");
	switch(balance_flag)
	{
		case WHITE_BALANCE_AUTO:
			hi704_set_wb_auto(hi704.client);
			break;
		case WHITE_BALANCE_INCANDESCENT :
			hi704_set_wb_incandescence(hi704.client);
			dprintk("WHITE_BALANCE_INCANDESCENT ");
			break;
		case WHITE_BALANCE_FLUORESCENT ://ying guang
			hi704_set_wb_fluorescent(hi704.client);
			dprintk("WHITE_BALANCE_FLUORESCENT ");
			break;
		case WHITE_BALANCE_WARM_FLUORESCENT :
			dprintk("WHITE_BALANCE_WARM_FLUORESCENT ");
			break;
		case WHITE_BALANCE_DAYLIGHT ://ri guang
			hi704_set_wb_daylight(hi704.client);
			dprintk("WHITE_BALANCE_DAYLIGHT ");
			break;
		case WHITE_BALANCE_CLOUDY_DAYLIGHT ://ying tian
			hi704_set_wb_cloud(hi704.client);
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

int hi704_set_antibanding(antibanding_flag_t antibanding_flag,int arg)
{
	dprintk("hi704_set_antibanding");
	switch(antibanding_flag)
	{
		case ANTIBANDING_AUTO :
			break;
		case ANTIBANDING_50HZ :
			hi704_set_ab_50hz(hi704.client);
			dprintk("ANTIBANDING_50HZ ");
			break;
		case ANTIBANDING_60HZ :
			hi704_set_ab_60hz(hi704.client);
			dprintk("ANTIBANDING_60HZ ");
			break;
		case ANTIBANDING_OFF :
			dprintk("ANTIBANDING_OFF ");
			break;
	}
	return 0;
}

int hi704_set_flash_mode(flash_mode_flag_t flash_mode_flag,int arg)
{
	dprintk("hi704_set_flash_mode");
	switch(flash_mode_flag)
	{
		case FLASH_MODE_OFF :
			dprintk("FLASH_MODE_OFF");
			break;
		case FLASH_MODE_AUTO :
			dprintk("FLASH_MODE_AUTO  ");
			break;
		case FLASH_MODE_ON :
			dprintk("FLASH_MODE_ON ");
			break;
		case FLASH_MODE_RED_EYE:
			dprintk("FLASH_MODE_RED_EYE ");
			break;
		case FLASH_MODE_TORCH:
			dprintk("FLASH_MODE_TORCH ");
			break;
	}
	return 0;

}

int hi704_set_scene_mode(scene_mode_flag_t scene_mode_flag,int arg)
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

int hi704_set_focus_mode(focus_mode_flag_t flash_mode_flag,int arg)
{
	dprintk("hi704_set_focus_mode");
	switch(flash_mode_flag)
	{
		case FOCUS_MODE_AUTO:
			dprintk("FOCUS_MODE_AUTO");
			break;
		case FOCUS_MODE_INFINITY:  
			dprintk("FOCUS_MODE_INFINITY");
			break;
		case FOCUS_MODE_MACRO: 
			dprintk("FOCUS_MODE_MACRO");
			break;
		case FOCUS_MODE_FIXED:
			dprintk("FOCUS_MODE_FIXED");
			break;
	}

	return 0;
}

int hi704_set_power(int state)
{
	switch (state)
	{
		case 0:           
			/* hardware power up first */
			hi704_power_up();
//	dprintk("11111----------------------------------hi704_power_up\n");

			/* software power up later if it implemented */
			break;
		case 1:
			hi704_power_down();
//	dprintk("11111----------------------------------hi704_power_down\n");

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
int hi704_set_effect(effect_flag_t effect_flag,int arg)
{
	dprintk("hi704_set_effect");
	switch(effect_flag)
	{
		case EFFECT_NONE:
			hi704_set_effect_normal(hi704.client);
			break;
		case EFFECT_MONO :
			hi704_set_effect_grayscale(hi704.client);
			dprintk("EFFECT_MONO ");
			break;
		case EFFECT_NEGATIVE :
			hi704_set_effect_colorinv(hi704.client);
			dprintk("EFFECT_NEGATIVE ");
			break;
		case EFFECT_SOLARIZE ://bao guang
			dprintk("EFFECT_SOLARIZE ");
			break;
		case EFFECT_SEPIA :
			hi704_set_effect_sepia(hi704.client);
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
			hi704_set_effect_sepiagreen(hi704.client);
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

int hi704_set_output_format(pixel_format_flag_t pixel_format_flag,int arg)
{
	switch(pixel_format_flag)
	{
		case PIXEL_FORMAT_JPEG:
			printk("hi704 set output format to jepg");
			break;
		case PIXEL_FORMAT_YUV422SP:
			printk("hi704 set output format to yuv422sp");
			break;
		case PIXEL_FORMAT_YUV420SP:
			printk("hi704 set output format to yuv420sp");
			break;
		case PIXEL_FORMAT_YUV422I:
			printk("hi704 set output format to yuv422i");
			break;
		case PIXEL_FORMAT_RGB565:
			printk("hi704 set output format to rgb565");
			break;
	}
	return 0;
}

int hi704_set_function(int function, void *cookie)
{
	switch (function)
	{
		case 0:
			hi704_set_preview_mode(hi704.client);
			break;
		case 1:
			hi704_set_capture_mode(hi704.client);
			break;
		case 2:		
			break;
		case 3:		
			dprintk("---- do focus ---");
			break;
	}

	return 0;
}

int hi704_set_fps(int fps)
{
	dprintk("set fps : %d",fps);
	return 0;
}

int hi704_set_night_mode(int enable)
{
	hi704_set_nightmode(hi704.client,enable);
	return 0;
}

int hi704_set_luma_adaptation(int arg)
{
	dprintk("luma_adaptation : %d",arg);
	return 0;
}

int hi704_set_parameter(int cmd, int mode, int arg)
{
	switch(cmd)
	{
		case CPCMD_SET_BALANCE :
			hi704_set_balance(mode,arg);
			break;
		case CPCMD_SET_EFFECT :
			hi704_set_effect(mode,arg);
			break;
		case CPCMD_SET_ANTIBANDING :
			hi704_set_antibanding(mode,arg);
			break;
		case CPCMD_SET_FLASH_MODE :
			hi704_set_flash_mode(mode,arg);
			break;
		case CPCMD_SET_SCENE_MODE :
			hi704_set_scene_mode(mode,arg);
			break;
		case CPCMD_SET_PIXEL_FORMAT :
			hi704_set_output_format(mode,arg);
			break;
		case CPCMD_SET_FOCUS_MODE :
			hi704_set_focus_mode(mode,arg);
			break;
		case CPCMD_SET_PREVIEW_FPS:
			hi704_set_fps(arg);
			break;
		case CPCMD_SET_NIGHTSHOT_MODE:
			hi704_set_night_mode(arg);
			break;
		case CPCMD_SET_LUMA_ADAPTATION:
			hi704_set_luma_adaptation(arg);
			break;
	}
	return 0;
}

int hi704_sensor_init(void)
{
//	hi704_reset();

	hi704_init_setting(hi704.client);
	return 0;
}

int hi704_sensor_probe(void)
{
	//dprintk("------------------------------------------hi704_sensor_probe \n");
	int sensor_id=0;
	
	mdelay(10);
	hi704_power_up();	

	mdelay(10);
	sensor_write_reg(hi704.client,0x03, 0x00);
	sensor_id = sensor_read_reg(hi704.client,0x04);
	//dprintk("---------------------------hi704 sensor read is %d",sensor_id);

	hi704_power_down();

	if(sensor_id == 0x96)
		return 0; 

	//dprintk("---------------------------sensor read is %d",sensor_id);
	return -1;
}

int hi704_set_resolution(int width,int height,int bpp,pixel_format_flag_t fmt,camera_mode_t mode)
{
	hi704_set_switch(hi704.client,width,height);
	return 0;
}

struct camera_sensor_ops hi704_sensor_ops = {
	.sensor_init = 			hi704_sensor_init,
	.camera_sensor_probe = 		hi704_sensor_probe,
	.sensor_set_function =  	hi704_set_function,
	.sensor_set_resolution = 	hi704_set_resolution, 
	.sensor_set_parameter = 	hi704_set_parameter, 
	.sensor_set_power = 		hi704_set_power,
};

struct resolution_info hi704_resolution_table[] = {
	{640,480,16,PIXEL_FORMAT_YUV422I},
	{352,288,16,PIXEL_FORMAT_YUV422I},
	{176,144,16,PIXEL_FORMAT_YUV422I},
};

struct hi704_sensor hi704 = {
	.desc = {
		.name = "hi704",
		.wait_frames = 4,

		.ops = &hi704_sensor_ops,

		.resolution_table = hi704_resolution_table,
		.resolution_table_nr=ARRAY_SIZE(hi704_resolution_table),

		.capture_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},
		.max_capture_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},

		.preview_parm = {640,480, 16,PIXEL_FORMAT_YUV422I}, 
		.max_preview_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},

		.cfg_info = {
			.configure_register= 0x0
				|CIM_CFG_PACK_2			/* pack mode : 4 3 2 1 */
				|CIM_CFG_BYPASS			/* Bypass Mode */	
			//	|CIM_CFG_VSP             	/* VSYNC Polarity:1-falling edge active */
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

static int hi704_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	hi704.client = client;

//	sensor_set_i2c_speed(client,350*1000);
	
	return camera_sensor_register(&hi704.desc);
}

static const struct i2c_device_id hi704_id[] = {
	{ "hi704", 0 },
	{ }	/* Terminating entry */
};
MODULE_DEVICE_TABLE(i2c, hi704_id);

static struct i2c_driver hi704_driver = {
	.probe		= hi704_i2c_probe,
	.id_table	= hi704_id,
	.driver	= {
		.name = "hi704",
	},
};

static int __init hi704_i2c_register(void)
{
	printk("\n\nhi704 i2c init\n\n");
	return i2c_add_driver(&hi704_driver);
}

module_init(hi704_i2c_register);


