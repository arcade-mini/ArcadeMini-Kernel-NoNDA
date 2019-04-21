#include <asm/jzsoc.h>
#include <linux/i2c.h>
#include "n200pc20_camera.h"
#include "n200pc20_set.h"
#include "../../jz_sensor.h"

#define n200pc20_DEBUG
//#undef DEBUG

#ifdef n200pc20_DEBUG
#define dprintk(x...)   do{printk("n200pc20---\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

extern unsigned char n200pc20_read_reg(struct i2c_client *client,unsigned char reg);
// extern void I2C_ReadReg_ADP5588(unsigned char dab, unsigned char rab, unsigned char *data);


/* gpio init */
#define GPIO_CAMERA_RST         (32*4+13) /*GPE13*/ 

struct n200pc20_sensor n200pc20;

void n200pc20_power_down(void)
{
	__gpio_as_output(4*32+24);     /*PE24*/
	__gpio_clear_pin(4*32+24);
	dprintk("--------------------------------n200pc20 power down \n");
}    

void n200pc20_power_up(void)
{ 
	__gpio_as_output(4*32+24);     /*PE24*/
	__gpio_set_pin(4*32+24);
	dprintk("--------------------------------n200pc20 power down \n");
}

void n200pc20_reset(void)
{
	__gpio_as_output(GPIO_CAMERA_RST);
	mdelay(50);
	__gpio_clear_pin(GPIO_CAMERA_RST);
	mdelay(50);
	__gpio_set_pin(GPIO_CAMERA_RST);
	mdelay(50);
}

int n200pc20_set_mclk(unsigned int mclk)
{
	return 0;//in this board use the extra osc - -20MHZ
}

int n200pc20_set_balance(balance_flag_t balance_flag,int arg)
{
	dprintk("n200pc20_set_balance");
	switch(balance_flag)
	{
		case WHITE_BALANCE_AUTO:
			n200pc20_set_wb_auto(n200pc20.client);
			dprintk("WHITE_BALANCE_AUTO");
			break;
		case WHITE_BALANCE_INCANDESCENT :
			n200pc20_set_wb_incandescence(n200pc20.client);
			dprintk("WHITE_BALANCE_INCANDESCENT ");
			break;
		case WHITE_BALANCE_FLUORESCENT ://ying guang
			n200pc20_set_wb_fluorescent(n200pc20.client);
			dprintk("WHITE_BALANCE_FLUORESCENT ");
			break;
		case WHITE_BALANCE_WARM_FLUORESCENT :
			dprintk("WHITE_BALANCE_WARM_FLUORESCENT ");
			break;
		case WHITE_BALANCE_DAYLIGHT ://ri guang
			n200pc20_set_wb_daylight(n200pc20.client);
			dprintk("WHITE_BALANCE_DAYLIGHT ");
			break;
		case WHITE_BALANCE_CLOUDY_DAYLIGHT ://ying tian
			n200pc20_set_wb_cloud(n200pc20.client);
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

int n200pc20_set_antibanding(antibanding_flag_t antibanding_flag,int arg)
{
	dprintk("n200pc20_set_antibanding");
	switch(antibanding_flag)
	{
		case ANTIBANDING_AUTO :
			dprintk("ANTIBANDING_AUTO ");
			break;
		case ANTIBANDING_50HZ :
			n200pc20_set_ab_50hz(n200pc20.client);
			dprintk("ANTIBANDING_50HZ ");
			break;
		case ANTIBANDING_60HZ :
			n200pc20_set_ab_60hz(n200pc20.client);
			dprintk("ANTIBANDING_60HZ ");
			break;
		case ANTIBANDING_OFF :
			dprintk("ANTIBANDING_OFF ");
			break;
	}
	return 0;
}

int n200pc20_set_flash_mode(flash_mode_flag_t flash_mode_flag,int arg)
{
	dprintk("n200pc20_set_flash_mode");
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

int n200pc20_set_scene_mode(scene_mode_flag_t scene_mode_flag,int arg)
{
	dprintk("n200pc20_set_scene_mode");
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

int n200pc20_set_focus_mode(focus_mode_flag_t flash_mode_flag,int arg)
{
	dprintk("n200pc20_set_focus_mode");
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

int n200pc20_set_power(int state)
{
	switch (state)
	{
		case 0:           
			/* hardware power up first */
			n200pc20_power_up();
			/* software power up later if it implemented */
			break;
		case 1:
			n200pc20_power_down();
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
int n200pc20_set_effect(effect_flag_t effect_flag,int arg)
{
	dprintk("n200pc20_set_effect");
	switch(effect_flag)
	{
		case EFFECT_NONE:
			n200pc20_set_effect_normal(n200pc20.client);
			dprintk("EFFECT_NONE");
			break;
		case EFFECT_MONO :
			n200pc20_set_effect_grayscale(n200pc20.client);
			dprintk("EFFECT_MONO ");
			break;
		case EFFECT_NEGATIVE :
			n200pc20_set_effect_colorinv(n200pc20.client);
			dprintk("EFFECT_NEGATIVE ");
			break;
		case EFFECT_SOLARIZE ://bao guang
			dprintk("EFFECT_SOLARIZE ");
			break;
		case EFFECT_SEPIA :
			n200pc20_set_effect_sepia(n200pc20.client);
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
			n200pc20_set_effect_sepiagreen(n200pc20.client);
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

int n200pc20_set_output_format(pixel_format_flag_t pixel_format_flag,int arg)
{
	switch(pixel_format_flag)
	{
		case PIXEL_FORMAT_JPEG:
			printk("n200pc20 set output format to jepg");
			break;
		case PIXEL_FORMAT_YUV422SP:
			printk("n200pc20 set output format to yuv422sp");
			break;
		case PIXEL_FORMAT_YUV420SP:
			printk("n200pc20 set output format to yuv420sp");
			break;
		case PIXEL_FORMAT_YUV422I:
			printk("n200pc20 set output format to yuv422i");
			break;
		case PIXEL_FORMAT_RGB565:
			printk("n200pc20 set output format to rgb565");
			break;
	}
	return 0;
}

int n200pc20_set_function(int function)
{
	switch (function)
	{
		case 0:
			n200pc20_set_preview_mode(n200pc20.client);
			break;
		case 1:
			n200pc20_set_capture_mode(n200pc20.client);
			break;
		case 2:		
			break;
		case 3:		
			dprintk("---- do focus ---");
			break;
	}

	return 0;
}

int n200pc20_set_fps(int fps)
{
	dprintk("set fps : %d",fps);
	return 0;
}

int n200pc20_set_night_mode(int enable)
{
	if(enable)
		dprintk("nightshot_mode enable!");
	else
		dprintk("nightshot_mode disable!");

	n200pc20_set_nightmode(n200pc20.client,enable);
	return 0;
}

int n200pc20_set_luma_adaptation(int arg)
{
	dprintk("luma_adaptation : %d",arg);
	return 0;
}

int n200pc20_set_parameter(int cmd, int mode, int arg)
{
	return 0;
	switch(cmd)
	{
		case CPCMD_SET_BALANCE :
			n200pc20_set_balance(mode,arg);
			break;
		case CPCMD_SET_EFFECT :
			n200pc20_set_effect(mode,arg);
			break;
		case CPCMD_SET_ANTIBANDING :
			n200pc20_set_antibanding(mode,arg);
			break;
		case CPCMD_SET_FLASH_MODE :
			n200pc20_set_flash_mode(mode,arg);
			break;
		case CPCMD_SET_SCENE_MODE :
			n200pc20_set_scene_mode(mode,arg);
			break;
		case CPCMD_SET_PIXEL_FORMAT :
			n200pc20_set_output_format(mode,arg);
			break;
		case CPCMD_SET_FOCUS_MODE :
			n200pc20_set_focus_mode(mode,arg);
			break;
		case CPCMD_SET_PREVIEW_FPS:
			n200pc20_set_fps(arg);
			break;
		case CPCMD_SET_NIGHTSHOT_MODE:
			n200pc20_set_night_mode(arg);
			break;
		case CPCMD_SET_LUMA_ADAPTATION:
			n200pc20_set_luma_adaptation(arg);
			break;
	}
	return 0;
}

int n200pc20_sensor_init(void)
{
//	n200pc20_set_mclk(0);
	n200pc20_reset();

	n200pc20_init_setting(n200pc20.client);
	return 0;
}

int n200pc20_sensor_probe(struct i2c_client *client)
{
dprintk("-------------------------------------------------------sensor_probe");

	int sensor_id=0;
        unsigned char data;

	n200pc20_power_up();
	n200pc20_reset();

	sensor_write_reg(n200pc20.client,0x03,0x00);
	mdelay(50);
//	I2C_ReadReg_ADP5588(0x40,0x04,&data);
	sensor_id = n200pc20_read_reg(n200pc20.client,0x04);
	dprintk("------------------------------n200pc20 sensor_0x04 read is %d",sensor_id);
        mdelay(1000);

	n200pc20_power_down();	
	if(data == 0x63)
		return 0; 

	dprintk("----------------------------sensor read error is %d",sensor_id);
	return -1;
}

int n200pc20_set_resolution(int width,int height,int bpp,pixel_format_flag_t fmt,camera_mode_t mode)
{
	n200pc20_set_r(n200pc20.client,width,height);
	return 0;
}

struct camera_sensor_ops n200pc20_sensor_ops = {
	.sensor_init = 			n200pc20_sensor_init,
	.camera_sensor_probe = 		n200pc20_sensor_probe,
	.sensor_set_function =  	n200pc20_set_function,
	.sensor_set_resolution = 	n200pc20_set_resolution, 
	.sensor_set_parameter = 	n200pc20_set_parameter, 
	.sensor_set_power = 		n200pc20_set_power,
};

struct resolution_info n200pc20_resolution_table[] = {
	{640,480,16,PIXEL_FORMAT_YUV422I},
	{352,288,16,PIXEL_FORMAT_YUV422I},
	{176,144,16,PIXEL_FORMAT_YUV422I},
};

struct n200pc20_sensor n200pc20 = {
	.desc = {
		.name = "n200pc20",
		.wait_frames = 4,

		.ops = &n200pc20_sensor_ops,

		.resolution_table = n200pc20_resolution_table,
		.resolution_table_nr=ARRAY_SIZE(n200pc20_resolution_table),

		.capture_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},
		.max_capture_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},

		.preview_parm = {640,480, 16,PIXEL_FORMAT_YUV422I}, 
		.max_preview_parm = {640,480, 16,PIXEL_FORMAT_YUV422I},

		.cfg_info = {
			.configure_register= 0x0
				|CIM_CFG_PACK_4			/* pack mode : 4 3 2 1 */
				|CIM_CFG_BYPASS			/* Bypass Mode */	
			//	|CIM_CFG_VSP             	/* VSYNC Polarity:1-falling edge active */
			//	|CIM_CFG_PCP             	/* PCLK working edge:1-falling */
				|CIM_CFG_DSM_GCM,		/* Gated Clock Mode */
		},

		.flags = {
			.pixel_format_flag = PIXEL_FORMAT_YUV422SP,

			.scene_mode_flag = ~0,

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

static int n200pc20_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	dprintk("n200pc20_i2c_probe!---------------------------------\n");
	n200pc20.client = client;
	return camera_sensor_register(&n200pc20.desc);
}

static const struct i2c_device_id n200pc20_id[] = {
	{ "n200pc20", 0 },
	{ }	/* Terminating entry */
};
MODULE_DEVICE_TABLE(i2c, n200pc20_id);

static struct i2c_driver n200pc20_driver = {
	.probe		= n200pc20_i2c_probe,
	.id_table	= n200pc20_id,
	.driver	= {
	           .name = "n200pc20",
	},
};

static int __init n200pc20_i2c_register(void)
{
	return i2c_add_driver(&n200pc20_driver);
}

module_init(n200pc20_i2c_register);

