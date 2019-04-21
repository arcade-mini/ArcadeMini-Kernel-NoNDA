
#include <asm/jzsoc.h>
#include "../../jz_sensor.h"
#include <linux/i2c.h>

#include "n200pc20_set.h"

#define n200pc20_DEBUG
#ifdef n200pc20_DEBUG
#define dprintk(x...)   do{printk("n200pc20---\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

void n200pc20_set_preview_mode(struct i2c_client *client)
{
}

void n200pc20_set_capture_mode(struct i2c_client *client)
{
}

void n200pc20_set_nightmode(struct i2c_client *client,int enable)
{
	if (!enable)
	{
	}
	else
	{
	}
}   /* n200pc20_NightMode */

void n200pc20_set_ab_50hz(struct i2c_client *client)
{
}

void n200pc20_set_ab_60hz(struct i2c_client *client)
{
}

void n200pc20_set_effect_normal(struct i2c_client *client)
{
}

void n200pc20_set_effect_grayscale(struct i2c_client *client)
{
}

void n200pc20_set_effect_sepia(struct i2c_client *client)
{
}

void n200pc20_set_effect_colorinv(struct i2c_client *client)
{
}

void n200pc20_set_effect_sepiagreen(struct i2c_client *client)
{
}

void n200pc20_set_effect_sepiablue(struct i2c_client *client)
{
}

void n200pc20_set_effect_grayinv(struct i2c_client *client)
{
}

void n200pc20_set_effect_embossment(struct i2c_client *client)
{
}

void n200pc20_set_effect_sketch(struct i2c_client *client)
{
}


void n200pc20_set_wb_auto(struct i2c_client *client)
{    
}

void n200pc20_set_wb_cloud(struct i2c_client *client)
{                                                         
}


void n200pc20_set_wb_daylight(struct i2c_client *client)
{                                                         
}


void n200pc20_set_wb_incandescence(struct i2c_client *client)
{                                                      
}


void n200pc20_set_wb_fluorescent(struct i2c_client *client)
{                                                      
}


void n200pc20_set_wb_tungsten(struct i2c_client *client)
{                                                      
}


void n200pc20_init_setting(struct i2c_client *client)
{

	dprintk("---------------------------------------------------sensor init!");
	
sensor_write_reg(client,0x01,0x01); 
sensor_write_reg(client,0x01,0x03);
sensor_write_reg(client,0x01,0x01);

sensor_write_reg(client,0x03,0x00);  //page0
sensor_write_reg(client,0x02,0x0b);
sensor_write_reg(client,0x10,0x00);
sensor_write_reg(client,0x11,0x93);
sensor_write_reg(client,0x12,0x00);
sensor_write_reg(client,0x13,0x00);
sensor_write_reg(client,0x14,0x01);
sensor_write_reg(client,0x15,0x00);
sensor_write_reg(client,0x16,0x05);
sensor_write_reg(client,0x17,0x04);
sensor_write_reg(client,0x18,0xb0);
sensor_write_reg(client,0x19,0x06);
sensor_write_reg(client,0x1a,0x40);
sensor_write_reg(client,0x1b,0x01);
//sensor_write_reg(client,0x1c,0x20);
sensor_write_reg(client,0x1c,0xa0);
sensor_write_reg(client,0x1d,0x00);
sensor_write_reg(client,0x1e,0x02);
sensor_write_reg(client,0x20,0xaf);
sensor_write_reg(client,0x21,0x01);
sensor_write_reg(client,0x22,0x03);
sensor_write_reg(client,0x23,0x03);
sensor_write_reg(client,0x24,0x03);
sensor_write_reg(client,0x40,0x33);
sensor_write_reg(client,0x41,0x77);
sensor_write_reg(client,0x42,0x43);
sensor_write_reg(client,0x43,0x30);
sensor_write_reg(client,0x4b,0x41);
sensor_write_reg(client,0x85,0x16);
sensor_write_reg(client,0x87,0x16);
sensor_write_reg(client,0x8f,0x2c);
sensor_write_reg(client,0x90,0xae);
sensor_write_reg(client,0x91,0xaf);
sensor_write_reg(client,0x92,0xb0);
sensor_write_reg(client,0x95,0x3c);
sensor_write_reg(client,0x96,0x6e);
sensor_write_reg(client,0x99,0x05);
sensor_write_reg(client,0x9a,0x37);
sensor_write_reg(client,0x9b,0x73);
sensor_write_reg(client,0x9c,0xa5);
sensor_write_reg(client,0xa2,0x0c);
sensor_write_reg(client,0xa3,0xc3);

sensor_write_reg(client,0x03,0x01);   //page1
sensor_write_reg(client,0x10,0x03);
sensor_write_reg(client,0x11,0x03);
sensor_write_reg(client,0x20,0x0f);
sensor_write_reg(client,0x21,0xa4);
sensor_write_reg(client,0x22,0xa4);
sensor_write_reg(client,0x33,0x30);
sensor_write_reg(client,0x35,0x20);
sensor_write_reg(client,0x36,0x3f);
sensor_write_reg(client,0x38,0x6f);
sensor_write_reg(client,0x39,0x2f);
sensor_write_reg(client,0x3a,0x00);
sensor_write_reg(client,0x3b,0x1a);
sensor_write_reg(client,0x3c,0x75);
sensor_write_reg(client,0x3d,0x1a);
sensor_write_reg(client,0x3e,0x0e);
sensor_write_reg(client,0x3f,0x38);
sensor_write_reg(client,0x40,0x86);
sensor_write_reg(client,0x41,0x00);
sensor_write_reg(client,0x42,0x0f);
sensor_write_reg(client,0x43,0x8f);
sensor_write_reg(client,0x44,0x03);
sensor_write_reg(client,0x45,0x00);
sensor_write_reg(client,0x46,0x84);
sensor_write_reg(client,0x47,0x97);
sensor_write_reg(client,0x48,0xa2);
sensor_write_reg(client,0x49,0x3a);
sensor_write_reg(client,0x60,0x01);
sensor_write_reg(client,0x61,0x00);
sensor_write_reg(client,0x62,0x0d);
sensor_write_reg(client,0x63,0x15);
sensor_write_reg(client,0x64,0x24);
sensor_write_reg(client,0x65,0x40);
sensor_write_reg(client,0x66,0x59);
sensor_write_reg(client,0x67,0x71);
sensor_write_reg(client,0x68,0x87);
sensor_write_reg(client,0x69,0x9b);
sensor_write_reg(client,0x6a,0xad);
sensor_write_reg(client,0x6b,0xbc);
sensor_write_reg(client,0x6c,0xca);
sensor_write_reg(client,0x6d,0xd6);
sensor_write_reg(client,0x6e,0xe0);
sensor_write_reg(client,0x6f,0xe9);
sensor_write_reg(client,0x70,0xf0);
sensor_write_reg(client,0x71,0xf6);
sensor_write_reg(client,0x72,0xfb);
sensor_write_reg(client,0x73,0xff);
sensor_write_reg(client,0x90,0x80);
sensor_write_reg(client,0x91,0x9d);
sensor_write_reg(client,0x93,0x53);
sensor_write_reg(client,0x95,0xff);
sensor_write_reg(client,0x9b,0x0c);
sensor_write_reg(client,0xa0,0x6d);
sensor_write_reg(client,0xa1,0x00);
sensor_write_reg(client,0xa2,0x1e);
sensor_write_reg(client,0xa3,0x4f);
sensor_write_reg(client,0xa4,0x03);
sensor_write_reg(client,0xa5,0x30);
sensor_write_reg(client,0xa6,0x10);
sensor_write_reg(client,0xa7,0x28);
sensor_write_reg(client,0xb4,0x06);
sensor_write_reg(client,0xc0,0xc3);
sensor_write_reg(client,0xc6,0x10);
sensor_write_reg(client,0xd0,0x07);
sensor_write_reg(client,0xd3,0x50);
sensor_write_reg(client,0xd4,0x38);
sensor_write_reg(client,0xd5,0x38);
sensor_write_reg(client,0xd6,0x40);
sensor_write_reg(client,0xd7,0x50);
sensor_write_reg(client,0xe3,0xe9);
sensor_write_reg(client,0xe4,0x88);
sensor_write_reg(client,0xe5,0xf0);

sensor_write_reg(client,0x03,0x02);  //page 2
sensor_write_reg(client,0x10,0x00);
sensor_write_reg(client,0x30,0x00);
sensor_write_reg(client,0x51,0x30);
sensor_write_reg(client,0x52,0x28);
sensor_write_reg(client,0x60,0xf3);
sensor_write_reg(client,0x61,0x07);
sensor_write_reg(client,0x64,0x44);
sensor_write_reg(client,0x7d,0xd4);
sensor_write_reg(client,0x7e,0x2a);
sensor_write_reg(client,0x85,0x14);

sensor_write_reg(client,0x03,0x03);  //page 3
sensor_write_reg(client,0x10,0x9c);
sensor_write_reg(client,0x11,0xc5);
sensor_write_reg(client,0x14,0x40);
sensor_write_reg(client,0x15,0x57);
sensor_write_reg(client,0x16,0x0b);
sensor_write_reg(client,0x17,0x05);
sensor_write_reg(client,0x18,0x02);
sensor_write_reg(client,0x19,0x71);
sensor_write_reg(client,0x1a,0x5c);
sensor_write_reg(client,0x1c,0x50);
sensor_write_reg(client,0x1d,0x34);
sensor_write_reg(client,0x1e,0x20);
sensor_write_reg(client,0x23,0x92);
sensor_write_reg(client,0x25,0x93);
sensor_write_reg(client,0x26,0x95);
sensor_write_reg(client,0x33,0x01);
sensor_write_reg(client,0x34,0x5f);
sensor_write_reg(client,0x35,0x90);
sensor_write_reg(client,0x36,0x01);
sensor_write_reg(client,0x37,0xc8);
sensor_write_reg(client,0x38,0x09);
sensor_write_reg(client,0x39,0x27);
sensor_write_reg(client,0x3a,0xc0);
sensor_write_reg(client,0x3b,0x75);
sensor_write_reg(client,0x3c,0x30);
sensor_write_reg(client,0x3d,0x61);
sensor_write_reg(client,0x3e,0xa8);
sensor_write_reg(client,0x3f,0x09);
sensor_write_reg(client,0x40,0x27);
sensor_write_reg(client,0x41,0x02);
sensor_write_reg(client,0x42,0x57);
sensor_write_reg(client,0x43,0x00);
sensor_write_reg(client,0x4c,0x09);
sensor_write_reg(client,0x4d,0xc4);
sensor_write_reg(client,0x4e,0x00);
sensor_write_reg(client,0x50,0x15);
sensor_write_reg(client,0x51,0x15);
sensor_write_reg(client,0x52,0x60);
sensor_write_reg(client,0x53,0x15);
sensor_write_reg(client,0x54,0x15);
sensor_write_reg(client,0x55,0x3b);
sensor_write_reg(client,0x56,0x60);
sensor_write_reg(client,0x57,0x60);
sensor_write_reg(client,0x58,0x60);
sensor_write_reg(client,0x59,0x28);
sensor_write_reg(client,0x5a,0x21);
sensor_write_reg(client,0x5b,0x1e);
sensor_write_reg(client,0x5c,0x1c);
sensor_write_reg(client,0x5d,0x1b);
sensor_write_reg(client,0x5e,0x20);
sensor_write_reg(client,0x60,0x44);
sensor_write_reg(client,0x61,0x88);
sensor_write_reg(client,0x64,0x0c);
sensor_write_reg(client,0x80,0x41);
sensor_write_reg(client,0x82,0x3f);
sensor_write_reg(client,0x84,0x3f);

sensor_write_reg(client,0x03,0x04);  //page 4
sensor_write_reg(client,0x10,0xe9);
sensor_write_reg(client,0x11,0x2c);
sensor_write_reg(client,0x12,0x72);
sensor_write_reg(client,0x13,0x00);
sensor_write_reg(client,0x14,0x0d);
sensor_write_reg(client,0x19,0xff);
sensor_write_reg(client,0x1f,0x54);
sensor_write_reg(client,0x20,0x12);
sensor_write_reg(client,0x21,0x6a);
sensor_write_reg(client,0x22,0x88);
sensor_write_reg(client,0x23,0xe3);
sensor_write_reg(client,0x24,0xaa);
sensor_write_reg(client,0x25,0x88);
sensor_write_reg(client,0x26,0x88);
sensor_write_reg(client,0x27,0x66);
sensor_write_reg(client,0x2a,0x88);
sensor_write_reg(client,0x2b,0x66);
sensor_write_reg(client,0x2c,0x02);
sensor_write_reg(client,0x2d,0x08);
sensor_write_reg(client,0x2e,0x04);
sensor_write_reg(client,0x2f,0x88);
sensor_write_reg(client,0x30,0x50);
sensor_write_reg(client,0x31,0xa1);
sensor_write_reg(client,0x32,0xa4);
sensor_write_reg(client,0x33,0xc8);
sensor_write_reg(client,0x34,0x0a);
sensor_write_reg(client,0x35,0x03);
sensor_write_reg(client,0x36,0x43);
sensor_write_reg(client,0x37,0x44);
sensor_write_reg(client,0x38,0x44);
sensor_write_reg(client,0x39,0x44);
sensor_write_reg(client,0x3a,0x0a);
sensor_write_reg(client,0x3b,0x44);
sensor_write_reg(client,0x40,0x38);
sensor_write_reg(client,0x41,0x20);
sensor_write_reg(client,0x42,0x30);
sensor_write_reg(client,0x43,0x38);
sensor_write_reg(client,0x44,0x17);
sensor_write_reg(client,0x45,0x47);
sensor_write_reg(client,0x46,0x1f);
sensor_write_reg(client,0x47,0x44);
sensor_write_reg(client,0x48,0x34);
sensor_write_reg(client,0x49,0x28);
sensor_write_reg(client,0x4a,0x1e);
sensor_write_reg(client,0x4b,0x04);
sensor_write_reg(client,0x4c,0x04);
sensor_write_reg(client,0x4d,0x04);
sensor_write_reg(client,0x4e,0x40);
sensor_write_reg(client,0x4f,0x58);
sensor_write_reg(client,0x50,0x78);
sensor_write_reg(client,0x51,0x48);
sensor_write_reg(client,0x52,0x40);
sensor_write_reg(client,0x53,0x38);
sensor_write_reg(client,0x54,0x32);
sensor_write_reg(client,0x55,0x2c);
sensor_write_reg(client,0x56,0x28);
sensor_write_reg(client,0x57,0x22);
sensor_write_reg(client,0x58,0x22);
sensor_write_reg(client,0x59,0x20);
sensor_write_reg(client,0x5a, 0x20);
sensor_write_reg(client,0x5b, 0x23);
sensor_write_reg(client,0x5c, 0x43);
sensor_write_reg(client,0x5d, 0x40);
sensor_write_reg(client,0x5e, 0x30);
sensor_write_reg(client,0x5f, 0x20);
sensor_write_reg(client,0x60, 0x80);
sensor_write_reg(client,0x61, 0x80);
sensor_write_reg(client,0x62, 0x00);
sensor_write_reg(client,0x63, 0x00);
sensor_write_reg(client,0x64, 0x26);
sensor_write_reg(client,0x65, 0x48);
//page1
//sensor_write_reg(client,0x03,0x01);
//sensor_write_reg(client,0x14,0x40);
//sensor_write_reg(client,0x03,0x00);
//sensor_write_reg(client,0x71,0x10);

sensor_write_reg(client,0x01, 0x00); 

}   /* n200pc20_Write_Sensor_Initial_Setting */

int n200pc20_set_r(struct i2c_client *client,int width,int height)
{
	if(width == 352 && height == 288)
	{
	}  //fish mark that trim size is 352x280 

	else if(width == 176 && height == 144)
	{
	}
	else
		n200pc20_init_setting(client);
}


