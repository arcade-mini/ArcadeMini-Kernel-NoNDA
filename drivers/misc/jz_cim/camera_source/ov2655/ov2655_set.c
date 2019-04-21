#include "../../jz_cim_core.h"
#include "../../jz_sensor.h"
#include <linux/i2c.h>
#include <asm/jzsoc.h>

#define ov2655_DEBUG
#ifdef ov2655_DEBUG
#define dprintk(x...)   do{printk("ov2655-\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

void preview_set(struct i2c_client *client)                   
{
	sensor_write_reg16(client,0x300e,0x34);
	sensor_write_reg16(client,0x3011,0x01);
	sensor_write_reg16(client,0x3012,0x10);
	sensor_write_reg16(client,0x302A,0x02);
	sensor_write_reg16(client,0x302B,0x6a);
	sensor_write_reg16(client,0x306f,0x14);
	sensor_write_reg16(client,0x3020,0x01);
	sensor_write_reg16(client,0x3021,0x18);
	sensor_write_reg16(client,0x3022,0x00);
	sensor_write_reg16(client,0x3023,0x06);
	sensor_write_reg16(client,0x3024,0x06);
	sensor_write_reg16(client,0x3025,0x58);
	sensor_write_reg16(client,0x3026,0x02);
	sensor_write_reg16(client,0x3027,0x61);
	sensor_write_reg16(client,0x3088,0x03);
	sensor_write_reg16(client,0x3089,0x20);
	sensor_write_reg16(client,0x308a,0x02);
	sensor_write_reg16(client,0x308b,0x58);
	sensor_write_reg16(client,0x3316,0x64);
	sensor_write_reg16(client,0x3317,0x25);
	sensor_write_reg16(client,0x3318,0x80);
	sensor_write_reg16(client,0x3319,0x08);
	sensor_write_reg16(client,0x331a,0x64);
	sensor_write_reg16(client,0x331b,0x4b);
	sensor_write_reg16(client,0x3302,0x11);
	sensor_write_reg16(client,0x302c,0x00);
	sensor_write_reg16(client,0x3071,0x00);
	sensor_write_reg16(client,0x3070,0x5d);
	sensor_write_reg16(client,0x301c,0x05);
	sensor_write_reg16(client,0x3073,0x00);
	sensor_write_reg16(client,0x3072,0x4d);
	sensor_write_reg16(client,0x301d,0x07);
	sensor_write_reg16(client,0x3013,0xf7);

}    //===preview setting end===


void capture_reg_set(struct i2c_client *client)
{
	sensor_write_reg16(client,0x3012,0x00);
	sensor_write_reg16(client,0x302A,0x04);
	sensor_write_reg16(client,0x302B,0xd4);
	sensor_write_reg16(client,0x306f,0x54);
	sensor_write_reg16(client,0x3020,0x01);
	sensor_write_reg16(client,0x3021,0x18);
	sensor_write_reg16(client,0x3022,0x00);
	sensor_write_reg16(client,0x3023,0x0a);
	sensor_write_reg16(client,0x3024,0x06);
	sensor_write_reg16(client,0x3025,0x58);
	sensor_write_reg16(client,0x3026,0x04);
	sensor_write_reg16(client,0x3027,0xbc);
	sensor_write_reg16(client,0x3088,0x06);
	sensor_write_reg16(client,0x3089,0x40);
	sensor_write_reg16(client,0x308a,0x04);
	sensor_write_reg16(client,0x308b,0xb0);
	sensor_write_reg16(client,0x3316,0x64);
	sensor_write_reg16(client,0x3317,0x4b);
	sensor_write_reg16(client,0x3318,0x00);
	sensor_write_reg16(client,0x3319,0x2c);
	sensor_write_reg16(client,0x331a,0x64);
	sensor_write_reg16(client,0x331b,0x4b);
	sensor_write_reg16(client,0x3302,0x01);
	sensor_write_reg16(client,0x300e,0x38);
	sensor_write_reg16(client,0x3011,0x00);
	sensor_write_reg16(client,0x302c,0x00);
	sensor_write_reg16(client,0x3071,0x00);
	sensor_write_reg16(client,0x3070,0x5d);
	sensor_write_reg16(client,0x301c,0x0d);
	sensor_write_reg16(client,0x3073,0x00);
	sensor_write_reg16(client,0x3072,0x4e);
	sensor_write_reg16(client,0x301d,0x0f);
}

void set_size_1600x1200(struct i2c_client *client,int mode)
{
	if(mode == CAMERA_MODE_CAPTURE)
	{
		//doing nothing
	}
}

void set_size_1280x1024(struct i2c_client *client,int mode)
{
	if(mode == CAMERA_MODE_CAPTURE)
	{
		sensor_write_reg16(client,0x3302,0x11);
		sensor_write_reg16(client,0x3088,0x05);
		sensor_write_reg16(client,0x3089,0x00);
		sensor_write_reg16(client,0x308a,0x04);
		sensor_write_reg16(client,0x308b,0x00);
		sensor_write_reg16(client,0x331a,0x50);
		sensor_write_reg16(client,0x331b,0x40);
		sensor_write_reg16(client,0x331c,0x00);
	}

	dprintk("UXGA-> SXGA;1280x1024");
} 

void set_size_1024x768(struct i2c_client *client,int mode)
{
	if(mode == CAMERA_MODE_CAPTURE)
	{
		sensor_write_reg16(client,0x3011,0x01);
		sensor_write_reg16(client,0x3088,0x04);
		sensor_write_reg16(client,0x3089,0x00);
		sensor_write_reg16(client,0x308a,0x03);
		sensor_write_reg16(client,0x308b,0x00);
		sensor_write_reg16(client,0x331a,0x50);
		sensor_write_reg16(client,0x331b,0x40);
		sensor_write_reg16(client,0x3302,0x11);
	}

}

void set_size_800x600(struct i2c_client *client,int mode)
{
	if(mode == CAMERA_MODE_PREVIEW)
	{
		sensor_write_reg16(client,0x3302,0x11);
		sensor_write_reg16(client,0x3088,0x03);
		sensor_write_reg16(client,0x3089,0x20);
		sensor_write_reg16(client,0x308a,0x02);
		sensor_write_reg16(client,0x308b,0x58);
		sensor_write_reg16(client,0x331a,0x64);
		sensor_write_reg16(client,0x331b,0x4b);
		sensor_write_reg16(client,0x331c,0x00);
	}
	else if(mode == CAMERA_MODE_CAPTURE)
	{
		sensor_write_reg16(client,0x3302,0x11);
		sensor_write_reg16(client,0x3088,0x03);
		sensor_write_reg16(client,0x3089,0x20);
		sensor_write_reg16(client,0x308a,0x02);
		sensor_write_reg16(client,0x308b,0x58);
		sensor_write_reg16(client,0x331a,0x32);
		sensor_write_reg16(client,0x331b,0x25);
		sensor_write_reg16(client,0x331c,0x80);
	}

	dprintk(" UXGA>SVGA 800x600");
} 

void set_size_640x480(struct i2c_client *client,int mode)
{
	if(mode == CAMERA_MODE_PREVIEW)
	{
		sensor_write_reg16(client,0x3302,0x11);
		sensor_write_reg16(client,0x3088,0x02);
		sensor_write_reg16(client,0x3089,0x80);
		sensor_write_reg16(client,0x308a,0x01);
		sensor_write_reg16(client,0x308b,0xe0);
		sensor_write_reg16(client,0x331a,0x28);
		sensor_write_reg16(client,0x331b,0x1e);
		sensor_write_reg16(client,0x331c,0x00);
		sensor_write_reg16(client,0x3302,0x11);
	}
	else if(mode == CAMERA_MODE_CAPTURE)
	{
		sensor_write_reg16(client,0x3302,0x11);
		sensor_write_reg16(client,0x3088,0x02);
		sensor_write_reg16(client,0x3089,0x80);
		sensor_write_reg16(client,0x308a,0x01);
		sensor_write_reg16(client,0x308b,0xe0);
		sensor_write_reg16(client,0x331a,0x28);
		sensor_write_reg16(client,0x331b,0x1e);
		sensor_write_reg16(client,0x331c,0x00);
	}

	dprintk(" UXGA->VGA 640x480");
}  

void set_size_352x288(struct i2c_client *client,int mode)
{
	if(mode == CAMERA_MODE_PREVIEW)
	{
		sensor_write_reg16(client,0x3302,0x11);
		sensor_write_reg16(client,0x3088,0x01);
		sensor_write_reg16(client,0x3089,0x60);
		sensor_write_reg16(client,0x308a,0x01);
		sensor_write_reg16(client,0x308b,0x20);
		sensor_write_reg16(client,0x331a,0x16);
		sensor_write_reg16(client,0x331b,0x12);
		sensor_write_reg16(client,0x331c,0x00);

	}

	dprintk(" UXGA->CIF 352x288");
}  

void set_size_176x144(struct i2c_client *client,int mode)
{
	if(mode == CAMERA_MODE_PREVIEW)
	{
		sensor_write_reg16(client,0x3302,0x11);
		sensor_write_reg16(client,0x3088,0x00);
		sensor_write_reg16(client,0x3089,0xb0);
		sensor_write_reg16(client,0x308a,0x00);
		sensor_write_reg16(client,0x308b,0x90);
		sensor_write_reg16(client,0x331a,0x0b);
		sensor_write_reg16(client,0x331b,0x09);
		sensor_write_reg16(client,0x331c,0x00);
	}

	dprintk(" UXGA->QCIF 176x144");
} 

void size_switch(struct i2c_client *client,int width,int height,int setmode)
{
	dprintk("%dx%d - mode(%d)",width,height,setmode);

	if(width == 1600 && height == 1200)
	{
		set_size_1600x1200(client,setmode);
	}
	else if(width == 1280 && height == 1024)
	{
		set_size_1280x1024(client,setmode);
	}  
	else if(width == 1024 && height == 768)
	{
		set_size_1024x768(client,setmode);
	}
	else if(width == 800 && height == 600)
	{
		set_size_800x600(client,setmode);
	}
	else if(width == 640 && height == 480)
	{
		set_size_640x480(client,setmode);
	} 
	else if(width == 352 && height == 288)
	{
		set_size_352x288(client,setmode);
	}  
	else if(width == 176 && height == 144)
	{
		set_size_176x144(client,setmode);
	}  
	else
		return;
	//	mdelay(500);
}


void ov2655_init_setting(struct i2c_client *client)
{
	sensor_write_reg16(client,0x3012,0x80);
	mdelay(10);
	sensor_write_reg16(client,0x308c,0x80);
	sensor_write_reg16(client,0x308d,0x0e);
	sensor_write_reg16(client,0x360b,0x00);
	sensor_write_reg16(client,0x30b0,0xff);
	sensor_write_reg16(client,0x30b1,0xff);
	sensor_write_reg16(client,0x30b2,0x24);
	sensor_write_reg16(client,0x300e,0x34);
	sensor_write_reg16(client,0x300f,0xa6);
	sensor_write_reg16(client,0x3010,0x81);
	sensor_write_reg16(client,0x3082,0x01);
	sensor_write_reg16(client,0x30f4,0x01);
	sensor_write_reg16(client,0x3090,0x33);
	sensor_write_reg16(client,0x3091,0xc0);
	sensor_write_reg16(client,0x30ac,0x42);
	sensor_write_reg16(client,0x30d1,0x08);
	sensor_write_reg16(client,0x30a8,0x56);
	sensor_write_reg16(client,0x3015,0x03);
	sensor_write_reg16(client,0x3093,0x00);
	sensor_write_reg16(client,0x307e,0xe5);
	sensor_write_reg16(client,0x3079,0x00);
	sensor_write_reg16(client,0x30aa,0x42);
	sensor_write_reg16(client,0x3017,0x40);
	sensor_write_reg16(client,0x30f3,0x82);
	sensor_write_reg16(client,0x306a,0x0c);
	sensor_write_reg16(client,0x306d,0x00);
	sensor_write_reg16(client,0x336a,0x3c);
	sensor_write_reg16(client,0x3076,0x6a);
	sensor_write_reg16(client,0x30d9,0x95);
	sensor_write_reg16(client,0x3016,0x82);
	sensor_write_reg16(client,0x3601,0x30);
	sensor_write_reg16(client,0x304e,0x88);
	sensor_write_reg16(client,0x30f1,0x82);
	sensor_write_reg16(client,0x306f,0x14);
	sensor_write_reg16(client,0x302a,0x02);
	sensor_write_reg16(client,0x302b,0x6a);
	sensor_write_reg16(client,0x3012,0x10);
	sensor_write_reg16(client,0x3011,0x01);
	sensor_write_reg16(client,0x3013,0xf7);
	sensor_write_reg16(client,0x301c,0x13);
	sensor_write_reg16(client,0x301d,0x17);
	sensor_write_reg16(client,0x3070,0x5d);
	sensor_write_reg16(client,0x3072,0x4d);
	sensor_write_reg16(client,0x30af,0x00);
	sensor_write_reg16(client,0x3048,0x1f);
	sensor_write_reg16(client,0x3049,0x4e);
	sensor_write_reg16(client,0x304a,0x20);
	sensor_write_reg16(client,0x304f,0x20);
	sensor_write_reg16(client,0x304b,0x02);
	sensor_write_reg16(client,0x304c,0x00);
	sensor_write_reg16(client,0x304d,0x02);
	sensor_write_reg16(client,0x304f,0x20);
	sensor_write_reg16(client,0x30a3,0x10);
	sensor_write_reg16(client,0x3013,0xf7);
	sensor_write_reg16(client,0x3014,0x44);
	sensor_write_reg16(client,0x3071,0x00);
	sensor_write_reg16(client,0x3070,0x5d);
	sensor_write_reg16(client,0x3073,0x00);
	sensor_write_reg16(client,0x3072,0x4d);
	sensor_write_reg16(client,0x301c,0x05);
	sensor_write_reg16(client,0x301d,0x06);
	sensor_write_reg16(client,0x304d,0x42);
	sensor_write_reg16(client,0x304a,0x40);
	sensor_write_reg16(client,0x304f,0x40);
	sensor_write_reg16(client,0x3095,0x07);
	sensor_write_reg16(client,0x3096,0x16);
	sensor_write_reg16(client,0x3097,0x1d);
	sensor_write_reg16(client,0x300e,0x38);
	sensor_write_reg16(client,0x3020,0x01);
	sensor_write_reg16(client,0x3021,0x18);
	sensor_write_reg16(client,0x3022,0x00);
	sensor_write_reg16(client,0x3023,0x06);
	sensor_write_reg16(client,0x3024,0x06);
	sensor_write_reg16(client,0x3025,0x58);
	sensor_write_reg16(client,0x3026,0x02);
	sensor_write_reg16(client,0x3027,0x61);
	sensor_write_reg16(client,0x3088,0x03);
	sensor_write_reg16(client,0x3089,0x20);
	sensor_write_reg16(client,0x308a,0x02);
	sensor_write_reg16(client,0x308b,0x58);
	sensor_write_reg16(client,0x3316,0x64);
	sensor_write_reg16(client,0x3317,0x25);
	sensor_write_reg16(client,0x3318,0x80);
	sensor_write_reg16(client,0x3319,0x08);
	sensor_write_reg16(client,0x331a,0x64);
	sensor_write_reg16(client,0x331b,0x4b);
	sensor_write_reg16(client,0x331c,0x00);
	sensor_write_reg16(client,0x331d,0x38);
	sensor_write_reg16(client,0x3100,0x00);
	sensor_write_reg16(client,0x3320,0xfa);
	sensor_write_reg16(client,0x3321,0x11);
	sensor_write_reg16(client,0x3322,0x92);
	sensor_write_reg16(client,0x3323,0x01);
	sensor_write_reg16(client,0x3324,0x97);
	sensor_write_reg16(client,0x3325,0x02);
	sensor_write_reg16(client,0x3326,0xff);
	sensor_write_reg16(client,0x3327,0x0c);
	sensor_write_reg16(client,0x3328,0x10);
	sensor_write_reg16(client,0x3329,0x10);
	sensor_write_reg16(client,0x332a,0x58);
	sensor_write_reg16(client,0x332b,0x50);
	sensor_write_reg16(client,0x332c,0xbe);
	sensor_write_reg16(client,0x332d,0xe1);
	sensor_write_reg16(client,0x332e,0x43);
	sensor_write_reg16(client,0x332f,0x36);
	sensor_write_reg16(client,0x3330,0x4d);
	sensor_write_reg16(client,0x3331,0x44);
	sensor_write_reg16(client,0x3332,0xf8);
	sensor_write_reg16(client,0x3333,0x0a);
	sensor_write_reg16(client,0x3334,0xf0);
	sensor_write_reg16(client,0x3335,0xf0);
	sensor_write_reg16(client,0x3336,0xf0);
	sensor_write_reg16(client,0x3337,0x40);
	sensor_write_reg16(client,0x3338,0x40);
	sensor_write_reg16(client,0x3339,0x40);
	sensor_write_reg16(client,0x333a,0x00);
	sensor_write_reg16(client,0x333b,0x00);
	sensor_write_reg16(client,0x3380,0x28);
	sensor_write_reg16(client,0x3381,0x48);
	sensor_write_reg16(client,0x3382,0x10);
	sensor_write_reg16(client,0x3383,0x23);
	sensor_write_reg16(client,0x3384,0xc0);
	sensor_write_reg16(client,0x3385,0xe5);
	sensor_write_reg16(client,0x3386,0xc2);
	sensor_write_reg16(client,0x3387,0xb3);
	sensor_write_reg16(client,0x3388,0x0e);
	sensor_write_reg16(client,0x3389,0x98);
	sensor_write_reg16(client,0x338a,0x01);
	sensor_write_reg16(client,0x3340,0x0e);
	sensor_write_reg16(client,0x3341,0x1a);
	sensor_write_reg16(client,0x3342,0x31);
	sensor_write_reg16(client,0x3343,0x45);
	sensor_write_reg16(client,0x3344,0x5a);
	sensor_write_reg16(client,0x3345,0x69);
	sensor_write_reg16(client,0x3346,0x75);
	sensor_write_reg16(client,0x3347,0x7e);
	sensor_write_reg16(client,0x3348,0x88);
	sensor_write_reg16(client,0x3349,0x96);
	sensor_write_reg16(client,0x334a,0xa3);
	sensor_write_reg16(client,0x334b,0xaf);
	sensor_write_reg16(client,0x334c,0xc4);
	sensor_write_reg16(client,0x334d,0xd7);
	sensor_write_reg16(client,0x334e,0xe8);
	sensor_write_reg16(client,0x334f,0x20);
	sensor_write_reg16(client,0x3350,0x32);
	sensor_write_reg16(client,0x3351,0x25);
	sensor_write_reg16(client,0x3352,0x80);
	sensor_write_reg16(client,0x3353,0x1e);
	sensor_write_reg16(client,0x3354,0x00);
	sensor_write_reg16(client,0x3355,0x85);
	sensor_write_reg16(client,0x3356,0x32);
	sensor_write_reg16(client,0x3357,0x25);
	sensor_write_reg16(client,0x3358,0x80);
	sensor_write_reg16(client,0x3359,0x1b);
	sensor_write_reg16(client,0x335a,0x00);
	sensor_write_reg16(client,0x335b,0x85);
	sensor_write_reg16(client,0x335c,0x32);
	sensor_write_reg16(client,0x335d,0x25);
	sensor_write_reg16(client,0x335e,0x80);
	sensor_write_reg16(client,0x335f,0x1b);
	sensor_write_reg16(client,0x3360,0x00);
	sensor_write_reg16(client,0x3361,0x85);
	sensor_write_reg16(client,0x3363,0x70);
	sensor_write_reg16(client,0x3364,0x7f);
	sensor_write_reg16(client,0x3365,0x00);
	sensor_write_reg16(client,0x3366,0x00);
	sensor_write_reg16(client,0x3301,0xff);
	sensor_write_reg16(client,0x338b,0x11);
	sensor_write_reg16(client,0x338c,0x10);
	sensor_write_reg16(client,0x338d,0x40);
	sensor_write_reg16(client,0x3370,0xd0);
	sensor_write_reg16(client,0x3371,0x00);
	sensor_write_reg16(client,0x3372,0x00);
	sensor_write_reg16(client,0x3373,0x40);
	sensor_write_reg16(client,0x3374,0x10);
	sensor_write_reg16(client,0x3375,0x10);
	sensor_write_reg16(client,0x3376,0x04);
	sensor_write_reg16(client,0x3377,0x00);
	sensor_write_reg16(client,0x3378,0x04);
	sensor_write_reg16(client,0x3379,0x80);
	sensor_write_reg16(client,0x3069,0x84);
	sensor_write_reg16(client,0x307c,0x10);
	sensor_write_reg16(client,0x3087,0x02);
	sensor_write_reg16(client,0x3300,0xfc);
	sensor_write_reg16(client,0x3302,0x11);
	sensor_write_reg16(client,0x3400,0x03);
	sensor_write_reg16(client,0x3606,0x20);
	sensor_write_reg16(client,0x3601,0x30);
	sensor_write_reg16(client,0x300e,0x34);
	sensor_write_reg16(client,0x3011,0x00);
	sensor_write_reg16(client,0x30f3,0x83);
	sensor_write_reg16(client,0x304e,0x88);
	sensor_write_reg16(client,0x3090,0x03);
	sensor_write_reg16(client,0x30aa,0x32);
	sensor_write_reg16(client,0x30a3,0x80);
	sensor_write_reg16(client,0x30a1,0x41);
	sensor_write_reg16(client,0x363b,0x01);
	sensor_write_reg16(client,0x363c,0xf2);
	sensor_write_reg16(client,0x3086,0x0f);
	sensor_write_reg16(client,0x3086,0x00);
}

uint32_t stop_ae(struct i2c_client *client)
{
	uint32_t Reg0x3013;
	Reg0x3013 = sensor_read_reg16(client,0x3013);
	Reg0x3013 = Reg0x3013 & 0xfa;
	sensor_write_reg16(client,0x3013,Reg0x3013);
	return 0;
}


uint32_t read_shutter(struct i2c_client *client)
{
	uint32_t Reg0x3002,Reg0x3003;
	Reg0x3002 = sensor_read_reg16(client,0x3002);
	Reg0x3003 = sensor_read_reg16(client,0x3003);
	return (Reg0x3002 << 8) + Reg0x3003;
}

uint32_t read_exter_line(struct i2c_client *client)
{
	uint32_t Reg0x302d,Reg0x302e;
	Reg0x302d = sensor_read_reg16(client,0x302d);
	Reg0x302e = sensor_read_reg16(client,0x302e);
	return Reg0x302e + (Reg0x302d << 8);
}

uint32_t read_gain(struct i2c_client *client)
{
	uint32_t Reg0x3000;
	Reg0x3000 = sensor_read_reg16(client,0x3000);
	dprintk("read_gain - %x\n",Reg0x3000);
	return (((Reg0x3000>>4) & 0x0f) + 1) * (16 + (Reg0x3000 & 0x0f));
}

uint32_t read_dummy_pixels(struct i2c_client *client)
{
#define Default_Reg0x3028 0x07
#define Default_Reg0x3029 0x93
	uint8_t Reg0x3028,Reg0x3029;
	Reg0x3028 = sensor_read_reg16(client,0x3028);
	Reg0x3029 = sensor_read_reg16(client,0x3029);
	return (((Reg0x3028 - Default_Reg0x3028) & 0xf0)<<8) + Reg0x3029-Default_Reg0x3029; 
}

void capture_set(struct i2c_client *client)
{
	uint32_t Shutter,
		 Extra_lines,

		 Preview_Gain16,
		 Preview_Exposure,
		 Preview_dummy_pixel,
		 Preview_Line_width,
		 Preview_PCLK_Frequency,

		 Capture_dummy_pixel,
		 Capture_dummy_line,
		 Capture_PCLK_Frequency,
		 Capture_Line_Width,
		 Capture_Maximum_Shutter,
		 Capture_Exposure,

		 Capture_Gain,
		 Capture_Banding_Filter,

		 Default_SVGA_Line_Width = 970,
		 Default_UXGA_Line_Width = 1940,
		 Default_Capture_Max_Gain16 = 31 * 16,
		 Default_UXGA_maximum_shutter = 1236,
		 Default_Reg0x302b = 0xd4,
		 Default_Reg0x302a = 0x04,

		 Reg0x3029,
		 Reg0x3028,
		 Reg0x302b,
		 Reg0x302a,
		 Reg0x3003,
		 Reg0x3002,
		 Reg0x302e,
		 Reg0x302d,

		 Gain_Exposure;

	stop_ae(client);
	Shutter = read_shutter(client);
	Extra_lines = read_exter_line(client); 
	Preview_Gain16 = read_gain(client);
	Preview_dummy_pixel = read_dummy_pixels(client); 

	dprintk("read_exter_line : %u\n",Extra_lines);
	dprintk("read_dummy_pixels : %u\n\n",Preview_dummy_pixel); 

	dprintk("read_gain : %u\n",Preview_Gain16);
	dprintk("read_shutter : %u\n",Shutter);

	Preview_Exposure = Shutter + Extra_lines;

	Capture_dummy_pixel = 0;
	Capture_dummy_line = 0;
	Preview_PCLK_Frequency = 18;
	Capture_PCLK_Frequency = 36;

	Preview_Line_width = Default_SVGA_Line_Width + Preview_dummy_pixel ;
	Capture_Line_Width = Default_UXGA_Line_Width + Capture_dummy_pixel;
	Capture_Maximum_Shutter = Default_UXGA_maximum_shutter + Capture_dummy_line;

	Capture_Exposure = 
		Preview_Exposure * Capture_PCLK_Frequency/Preview_PCLK_Frequency *
		Preview_Line_width/Capture_Line_Width;

	Capture_Banding_Filter = Capture_PCLK_Frequency * 5000/ (Capture_Line_Width);
	//Capture_Banding_Filter = Capture_PCLK_Frequency * 1000000 / 120 /(2*Capture_Line_Width);

	Gain_Exposure = Preview_Gain16 * Capture_Exposure;

	dprintk("Capture_Exposure : %u\n",Capture_Exposure);
	dprintk("Gain_Exposure : %u\n",Gain_Exposure);
	dprintk("Capture_Banding_Filter : %u | %u\n",Capture_Banding_Filter,Capture_Banding_Filter * 16);
	if (Gain_Exposure < Capture_Banding_Filter * 16)
	{
		// Exposure < 1/100
		Capture_Exposure = Gain_Exposure /16;
		Capture_Gain = (Gain_Exposure*2 + 1)/Capture_Exposure/2;
		dprintk("--------------------- %d\n",__LINE__);
	}
	else
	{
		dprintk("--------------------- %d\n",__LINE__);
		if (Gain_Exposure > Capture_Maximum_Shutter * 16)
		{
			dprintk("--------------------- %d\n",__LINE__);
			// // Exposure > Capture_Maximum_Shutter
			Capture_Exposure = Capture_Maximum_Shutter;
			Capture_Gain = (Gain_Exposure*2 + 1)/Capture_Maximum_Shutter/2;
			if (Capture_Gain > Default_Capture_Max_Gain16)
			{
				dprintk("--------------------- %d\n",__LINE__);
				// // gain reach maximum, insert extra line
				Capture_Exposure = Gain_Exposure*1.1/Default_Capture_Max_Gain16;
				// For 50Hz, Exposure = n/100; For 60Hz, Exposure = n/120
				Capture_Exposure = Gain_Exposure/16/Capture_Banding_Filter;
				Capture_Exposure = Capture_Exposure * Capture_Banding_Filter;
				Capture_Gain = (Gain_Exposure *2+1)/ Capture_Exposure/2;
			}
			else
			{
				Capture_Exposure = Capture_Exposure/Capture_Banding_Filter;
				dprintk("--------------------- %d\n",__LINE__);
				Capture_Exposure = Capture_Exposure * Capture_Banding_Filter;
				Capture_Gain = (Gain_Exposure*2 + 1)/Capture_Maximum_Shutter/2;
			}
		}
		else
		{
			//1/100(120) < Exposure < Capture_Maximum_Shutter, Exposure = n/100(120)
			Capture_Exposure = Gain_Exposure/16/Capture_Banding_Filter;
			Capture_Exposure = Capture_Exposure * Capture_Banding_Filter;
			Capture_Gain = (Gain_Exposure*2 +1) / Capture_Exposure/2;
			dprintk("--------------------- %d\n",__LINE__);
		}
	}

	capture_reg_set(client);

#if 1
	//write dummy pixels
	Reg0x3029 = Capture_dummy_pixel & 0x00ff;
	Reg0x3028 = sensor_read_reg16(client,0x3028);
	Reg0x3028 = (Reg0x3028 & 0x0f) | ((Capture_dummy_pixel & 0x0f00)>>4);
	sensor_write_reg16(client,0x3028, Reg0x3028);
	sensor_write_reg16(client,0x302b, Reg0x3029);
	dprintk("dummy pixels\n");
	dprintk("Reg0x3028 : %x\n",Reg0x3028);
	dprintk("Reg0x3029 : %x\n",Reg0x3029);
	dprintk("\n");
	////Write Dummy Lines
	Reg0x302b = (Capture_dummy_line & 0x00ff) + Default_Reg0x302b;
	Reg0x302a = (Capture_dummy_line >>8) + Default_Reg0x302a;
	sensor_write_reg16(client,0x302a, Reg0x302a);
	sensor_write_reg16(client,0x302b, Reg0x302b);
	dprintk("dummy lines\n");
	dprintk("Reg0x302a : %x\n",Reg0x302a);
	dprintk("Reg0x302b : %x\n",Reg0x302b);
	dprintk("\n");
#endif
	////Write Exposure
	if (Capture_Exposure > Capture_Maximum_Shutter)
	{
		Shutter = Capture_Maximum_Shutter;
		Extra_lines = Capture_Exposure - Capture_Maximum_Shutter;
		dprintk("--------------------- %d\n",__LINE__);
	}
	else
	{
		dprintk("--------------------- %d\n",__LINE__);
		Shutter = Capture_Exposure;
		Extra_lines = 0;
	}

	Reg0x3003 = Shutter & 0x00ff;
	Reg0x3002 = (Shutter >>8) & 0x00ff;
	sensor_write_reg16(client,0x3003, Reg0x3003);
	sensor_write_reg16(client,0x3002, Reg0x3002);
	dprintk("Exposure\n");
	dprintk("Reg0x3003 : %x\n",Reg0x3003);
	dprintk("Reg0x3002 : %x\n",Reg0x3002);
	dprintk("\n");
	//// Write extra line
	Reg0x302e = Extra_lines & 0x00ff;
	Reg0x302d = Extra_lines >> 8;
	sensor_write_reg16(client,0x302d, Reg0x302d);
	sensor_write_reg16(client,0x302e, Reg0x302e);
	dprintk("extra line\n");
	dprintk("Reg0x302d : %x\n",Reg0x302d);
	dprintk("Reg0x302e : %x\n",Reg0x302e);
	dprintk("\n");

	// Write Gain
	uint8_t Gain = Capture_Gain & 0x0f;
	dprintk("Capture_Gain : %x\n",Capture_Gain);
	dprintk("gain : %x\n",Gain);

	if (Capture_Gain > 15) 
	{ 
		Capture_Gain = Capture_Gain /2; 
		Gain = 0x10; 
	} 
	if (Capture_Gain > 15) 
	{ 
		Capture_Gain = Capture_Gain /2; 
		Gain = Gain| 0x20; 
	} 
	if (Capture_Gain > 15) 
	{ 
		Capture_Gain = Capture_Gain /2; 
		Gain = Gain | 0x40; 
	} 
	if (Capture_Gain > 15) 
	{ 
		Capture_Gain = Capture_Gain /2; 
		Gain = Gain | 0x80; 
	} 
	if (Capture_Gain > 16) 
	{ 
		Gain = Gain | ((uint32_t)Capture_Gain -16); 
	} 

	sensor_write_reg16(client,0x3000, Gain);
	dprintk("Reg0x3000 : %x\n",Gain);
}

