#include "../../jz_cim_core.h"
#include "../../jz_sensor.h"
#include <linux/i2c.h>
#include <asm/jzsoc.h>

#define hi704_DEBUG
//#undef DEBUG

#ifdef hi704_DEBUG
#define dprintk(x...)   do{printk("hi704---\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

void hi704_set_preview_mode(struct i2c_client *client)
{
}

void hi704_set_capture_mode(struct i2c_client *client)
{
}

void hi704_set_nightmode(struct i2c_client *client,int enable)
{
	if (!enable)
	{
	dprintk("---------------------------------HI704_set_nightmode disable");
	}
	else
	{
	dprintk("-------------------------------HI704_set_nightmode enable");
	}
}   /* hi704_NightMode */

void hi704_set_ab_50hz(struct i2c_client *client)
{
	sensor_write_reg(client,0x01,0xfa);
	sensor_write_reg(client,0x02,0x70); 
	sensor_write_reg(client,0x0f,0x01); 
	sensor_write_reg(client,0xe2,0x00); 
	sensor_write_reg(client,0xe3,0x64); 
	sensor_write_reg(client,0xe4,0x02);
	sensor_write_reg(client,0xe5,0x58); 
	sensor_write_reg(client,0xe6,0x03); 
	sensor_write_reg(client,0xe7,0x20); 
	sensor_write_reg(client,0xe8,0x04);
	sensor_write_reg(client,0xe9,0xb0); 
	sensor_write_reg(client,0xea,0x09); 
	sensor_write_reg(client,0xeb,0xc4);
	dprintk("--------------------------ab_50hz ");
}

void hi704_set_ab_60hz(struct i2c_client *client)
{
	sensor_write_reg(client,0x01,0x2c);
	sensor_write_reg(client,0x02,0x98); 
	sensor_write_reg(client,0x0f,0x02); 
	sensor_write_reg(client,0xe2,0x00); 
	sensor_write_reg(client,0xe3,0x50); 
	sensor_write_reg(client,0xe4,0x02);
	sensor_write_reg(client,0xe5,0x80); 
	sensor_write_reg(client,0xe6,0x03); 
	sensor_write_reg(client,0xe7,0xc0); 
	sensor_write_reg(client,0xe8,0x05);
	sensor_write_reg(client,0xe9,0x00); 
	sensor_write_reg(client,0xea,0x09); 
	sensor_write_reg(client,0xeb,0x60);
	dprintk("--------------------------ab_60hz ");
}

void hi704_set_effect_normal(struct i2c_client *client)
{
	sensor_write_reg(client,0x23,0x00);
	sensor_write_reg(client,0x2d,0x0a); 
	sensor_write_reg(client,0x20,0x7f); 
	sensor_write_reg(client,0xd2,0x90); 
	sensor_write_reg(client,0x73,0x00); 
	sensor_write_reg(client,0x77,0x38);
	sensor_write_reg(client,0xb3,0x40); 
	sensor_write_reg(client,0xb4,0x80); 
	sensor_write_reg(client,0xba,0x00); 
	sensor_write_reg(client,0xbb,0x00); 
	dprintk("--------------------------effect_normal ");
}

void hi704_set_effect_grayscale(struct i2c_client *client)
{
	sensor_write_reg(client,0x23,0x02);
	sensor_write_reg(client,0x2d,0x0a); 
	sensor_write_reg(client,0x20,0xff); 
	sensor_write_reg(client,0xd2,0x90); 
	sensor_write_reg(client,0x73,0x00); 
	sensor_write_reg(client,0xb3,0x40); 
	sensor_write_reg(client,0xb4,0x80); 
	sensor_write_reg(client,0xba,0x00); 
	sensor_write_reg(client,0xbb,0x00); 
	dprintk("--------------------------effect_grayscale ");
}

void hi704_set_effect_sepia(struct i2c_client *client)
{
	sensor_write_reg(client,0x23,0x02);
	sensor_write_reg(client,0x2d,0x0a); 
	sensor_write_reg(client,0x20,0xff); 
	sensor_write_reg(client,0xd2,0x90); 
	sensor_write_reg(client,0x73,0x00); 
	sensor_write_reg(client,0xb3,0x40); 
	sensor_write_reg(client,0xb4,0x80); 
	sensor_write_reg(client,0xba,0xd0); 
	sensor_write_reg(client,0xbb,0x28); 
	dprintk("--------------------------effect_sepia ");
}

void hi704_set_effect_colorinv(struct i2c_client *client)
{
	sensor_write_reg(client,0x23,0x01);
	sensor_write_reg(client,0x2d,0x0a);		
	sensor_write_reg(client,0x20,0xff); 
	sensor_write_reg(client,0xd2,0x90); 
	sensor_write_reg(client,0x73,0x00); 
	sensor_write_reg(client,0xb3,0x40); 
	sensor_write_reg(client,0xb4,0x80); 
	sensor_write_reg(client,0xba,0x00); 
	sensor_write_reg(client,0xbb,0x00); 
	dprintk("--------------------------effect_colorinv ");
}

void hi704_set_effect_sepiagreen(struct i2c_client *client)
{
	sensor_write_reg(client,0x23,0x02);
	sensor_write_reg(client,0x2d,0x0a);
	sensor_write_reg(client,0x20,0x7f);
	sensor_write_reg(client,0xd2,0x90);
	sensor_write_reg(client,0x77,0x88);
	sensor_write_reg(client,0xb3,0x40);
	sensor_write_reg(client,0xb4,0x80);
	sensor_write_reg(client,0xba,0xc0);
	sensor_write_reg(client,0xbb,0xc0);
	dprintk("--------------------------effect_sepiagreen ");
}

void hi704_set_effect_sepiablue(struct i2c_client *client)
{
	sensor_write_reg(client,0x23,0x02);
	sensor_write_reg(client,0x2d,0x0a);
	sensor_write_reg(client,0x20,0x7f);
	sensor_write_reg(client,0xd2,0x90);
	sensor_write_reg(client,0x73,0x00);
	sensor_write_reg(client,0xb3,0x40);
	sensor_write_reg(client,0xb4,0x80);
	sensor_write_reg(client,0xba,0x50);
	sensor_write_reg(client,0xbb,0xe0);
	dprintk("--------------------------effect_sepiablue ");
}

void hi704_set_wb_auto(struct i2c_client *client)
{
	sensor_write_reg(client,0x5a,0x56);
	sensor_write_reg(client,0x5b,0x40);
	sensor_write_reg(client,0x5c,0x4a);
	sensor_write_reg(client,0x22,0x57);
	dprintk("-------------------------------wb_auto");		
}

void hi704_set_wb_cloud(struct i2c_client *client)
{
	sensor_write_reg(client,0x22,0x55);
	sensor_write_reg(client,0x5a,0x8c);
	sensor_write_reg(client,0x5b,0x50);
	sensor_write_reg(client,0x5c,0x40);
	dprintk("-------------------------------wb_cloud");
}

void hi704_set_wb_daylight(struct i2c_client *client)
{
	sensor_write_reg(client,0x22,0x55);
	sensor_write_reg(client,0x5a,0x74);
	sensor_write_reg(client,0x5b,0x52);
	sensor_write_reg(client,0x5c,0x40);	
	dprintk("-------------------------------wb_daylight");
}

void hi704_set_wb_incandescence(struct i2c_client *client)
{
	sensor_write_reg(client,0x22,0x55);
	sensor_write_reg(client,0x5a,0x48);
	sensor_write_reg(client,0x5b,0x40);
	sensor_write_reg(client,0x5c,0x5c);	
	dprintk("-------------------------------wb_incandescence");                               
}

void hi704_set_wb_fluorescent(struct i2c_client *client)
{
	sensor_write_reg(client,0x22,0x55);
	sensor_write_reg(client,0x5a,0x40);
	sensor_write_reg(client,0x5b,0x42);
	sensor_write_reg(client,0x5c,0x50);	
	dprintk("-------------------------------wb_fluorescent");                        
}

void hi704_set_wb_tungsten(struct i2c_client *client)
{
	sensor_write_reg(client,0x22,0x55);
	sensor_write_reg(client,0x5a,0x40);
	sensor_write_reg(client,0x5b,0x54);
	sensor_write_reg(client,0x5c,0x70);	
	dprintk("-------------------------------wb_tungsten");
}

void hi704_init_setting(struct i2c_client *client)
{	
	dprintk("---------------------------------hi704_init  1");

	//PAGE 0
	//Image Size/Windowing/HSYNC/VSYNC[Type1]
	sensor_write_reg(client,0x03, 0x00);   //PAGEMODE(0x03)
	sensor_write_reg(client,0x01, 0xf1);
	sensor_write_reg(client,0x01, 0xf3);   //PWRCTL(0x01[P0])Bit[1]:Software Reset.
	sensor_write_reg(client,0x01, 0xf1);
	
	sensor_write_reg(client,0x11, 0x90);   //For No Fixed Framerate Bit[2]
	sensor_write_reg(client,0x12, 0x00);
	
	sensor_write_reg(client,0x20, 0x00);
	sensor_write_reg(client,0x21, 0x04);
	sensor_write_reg(client,0x22, 0x00);
	sensor_write_reg(client,0x23, 0x04);
	
	sensor_write_reg(client,0x24, 0x01);
	sensor_write_reg(client,0x25, 0xe0);
	sensor_write_reg(client,0x26, 0x02);
	sensor_write_reg(client,0x27, 0x80);
	
	sensor_write_reg(client,0x40, 0x00);   //HBLANK: 0x70 = 112
	sensor_write_reg(client,0x41, 0x70);
	sensor_write_reg(client,0x42, 0x00);   //VBLANK: 0x40 = 64
	sensor_write_reg(client,0x43, 0x40);   //0x04 -> 0x40: For Max Framerate = 30fps
	
	//BLC
	sensor_write_reg(client,0x80, 0x2e);
	sensor_write_reg(client,0x81, 0x7e);
	sensor_write_reg(client,0x82, 0x90);
	sensor_write_reg(client,0x83, 0x30);
	sensor_write_reg(client,0x84, 0x2c);
	sensor_write_reg(client,0x85, 0x4b);
	sensor_write_reg(client,0x89, 0x48);
	
	sensor_write_reg(client,0x90, 0x0b);
	sensor_write_reg(client,0x91, 0x0b);    
	sensor_write_reg(client,0x92, 0x48);
	sensor_write_reg(client,0x93, 0x48);
	sensor_write_reg(client,0x98, 0x38);
	sensor_write_reg(client,0x99, 0x40);
	sensor_write_reg(client,0xa0, 0x00);
	sensor_write_reg(client,0xa8, 0x40);
	
	//PAGE 2
	//Analog Circuit
	sensor_write_reg(client,0x03, 0x02);      
	sensor_write_reg(client,0x13, 0x40);
	sensor_write_reg(client,0x14, 0x04);
	sensor_write_reg(client,0x1a, 0x00);
	sensor_write_reg(client,0x1b, 0x08);
	
	sensor_write_reg(client,0x20, 0x33);
	sensor_write_reg(client,0x21, 0xaa);
	sensor_write_reg(client,0x22, 0xa7);
	sensor_write_reg(client,0x23, 0xb1);       //For Sun Pot
	
	sensor_write_reg(client,0x3b, 0x48);
	
	sensor_write_reg(client,0x50, 0x21);
	sensor_write_reg(client,0x52, 0xa2);
	sensor_write_reg(client,0x53, 0x0a);
	sensor_write_reg(client,0x54, 0x30);
	sensor_write_reg(client,0x55, 0x10);
	sensor_write_reg(client,0x56, 0x0c);
	sensor_write_reg(client,0x59, 0x0F);
	
	sensor_write_reg(client,0x60, 0x54);
	sensor_write_reg(client,0x61, 0x5d);
	sensor_write_reg(client,0x62, 0x56);
	sensor_write_reg(client,0x63, 0x5c);
	sensor_write_reg(client,0x64, 0x56);
	sensor_write_reg(client,0x65, 0x5c);
	sensor_write_reg(client,0x72, 0x57);
	sensor_write_reg(client,0x73, 0x5b);
	sensor_write_reg(client,0x74, 0x57);
	sensor_write_reg(client,0x75, 0x5b);
	sensor_write_reg(client,0x80, 0x02);
	sensor_write_reg(client,0x81, 0x46);
	sensor_write_reg(client,0x82, 0x07);
	sensor_write_reg(client,0x83, 0x10);
	sensor_write_reg(client,0x84, 0x07);
	sensor_write_reg(client,0x85, 0x10);
	sensor_write_reg(client,0x92, 0x24);
	sensor_write_reg(client,0x93, 0x30);
	sensor_write_reg(client,0x94, 0x24);
	sensor_write_reg(client,0x95, 0x30);
	sensor_write_reg(client,0xa0, 0x03);
	sensor_write_reg(client,0xa1, 0x45);
	sensor_write_reg(client,0xa4, 0x45);
	sensor_write_reg(client,0xa5, 0x03);
	sensor_write_reg(client,0xa8, 0x12);
	sensor_write_reg(client,0xa9, 0x20);
	sensor_write_reg(client,0xaa, 0x34);
	sensor_write_reg(client,0xab, 0x40);
	sensor_write_reg(client,0xb8, 0x55);
	sensor_write_reg(client,0xb9, 0x59);
	sensor_write_reg(client,0xbc, 0x05);
	sensor_write_reg(client,0xbd, 0x09);
	sensor_write_reg(client,0xc0, 0x5f);
	sensor_write_reg(client,0xc1, 0x67);
	sensor_write_reg(client,0xc2, 0x5f);
	sensor_write_reg(client,0xc3, 0x67);
	sensor_write_reg(client,0xc4, 0x60);
	sensor_write_reg(client,0xc5, 0x66);
	sensor_write_reg(client,0xc6, 0x60);
	sensor_write_reg(client,0xc7, 0x66);
	sensor_write_reg(client,0xc8, 0x61);
	sensor_write_reg(client,0xc9, 0x65);
	sensor_write_reg(client,0xca, 0x61);
	sensor_write_reg(client,0xcb, 0x65);
	sensor_write_reg(client,0xcc, 0x62);
	sensor_write_reg(client,0xcd, 0x64);
	sensor_write_reg(client,0xce, 0x62);
	sensor_write_reg(client,0xcf, 0x64);
	sensor_write_reg(client,0xd0, 0x53);
	sensor_write_reg(client,0xd1, 0x68);
	
	//PAGE 10
	//Image Format, Image Effect
	sensor_write_reg(client,0x03, 0x10);
	sensor_write_reg(client,0x10, 0x03);
	sensor_write_reg(client,0x11, 0x43);
	sensor_write_reg(client,0x12, 0x30);
	
	sensor_write_reg(client,0x40, 0x80);
	sensor_write_reg(client,0x41, 0x02);
	sensor_write_reg(client,0x48, 0x98);
	
	sensor_write_reg(client,0x50, 0x48);
	
	sensor_write_reg(client,0x60, 0x7f);
	sensor_write_reg(client,0x61, 0x00);
	sensor_write_reg(client,0x62, 0xa0);// 80
	sensor_write_reg(client,0x63, 0xa0);// 70
	sensor_write_reg(client,0x64, 0x48);
	sensor_write_reg(client,0x66, 0x90);
	sensor_write_reg(client,0x67, 0x36); //wht_gain  Dark (0.4x), Normal (0.75x)
	
	//PAGE 11
	//Z-LPF
	sensor_write_reg(client,0x03, 0x11);
	sensor_write_reg(client,0x10, 0x25);   
	sensor_write_reg(client,0x11, 0x1f);   
	
	sensor_write_reg(client,0x20, 0x00);   
	sensor_write_reg(client,0x21, 0x38);   
	sensor_write_reg(client,0x23, 0x0a);
	
	sensor_write_reg(client,0x60, 0x10);   
	sensor_write_reg(client,0x61, 0x82);
	sensor_write_reg(client,0x62, 0x00);   
	sensor_write_reg(client,0x63, 0x83);   
	sensor_write_reg(client,0x64, 0x83);      
	sensor_write_reg(client,0x67, 0xF0);   
	sensor_write_reg(client,0x68, 0x30);   
	sensor_write_reg(client,0x69, 0x10);   
	
	//PAGE 12
	//2D
	sensor_write_reg(client,0x03, 0x12);
	
	sensor_write_reg(client,0x40, 0xe9);
	sensor_write_reg(client,0x41, 0x09);
	
	sensor_write_reg(client,0x50, 0x18);
	sensor_write_reg(client,0x51, 0x24);
	
	sensor_write_reg(client,0x70, 0x1f);
	sensor_write_reg(client,0x71, 0x00);
	sensor_write_reg(client,0x72, 0x00);
	sensor_write_reg(client,0x73, 0x00);
	sensor_write_reg(client,0x74, 0x10);
	sensor_write_reg(client,0x75, 0x10);
	sensor_write_reg(client,0x76, 0x20);
	sensor_write_reg(client,0x77, 0x80);
	sensor_write_reg(client,0x78, 0x88);
	sensor_write_reg(client,0x79, 0x18);
	
	sensor_write_reg(client,0xb0, 0x7d);
	
	//PAGE 13
	//Edge Enhancement
	sensor_write_reg(client,0x03, 0x13);
	sensor_write_reg(client,0x10, 0x01);	
	sensor_write_reg(client,0x11, 0x89);	
	sensor_write_reg(client,0x12, 0x14);	
	sensor_write_reg(client,0x13, 0x19);	
	sensor_write_reg(client,0x14, 0x08);	//Test Setting
	sensor_write_reg(client,0x20, 0x06);	//SHARP_Negative
	sensor_write_reg(client,0x21, 0x03);	//SHARP_Positive
	sensor_write_reg(client,0x23, 0x30);	//SHARP_DY_CTL
	sensor_write_reg(client,0x24, 0x33);	//40->33
	sensor_write_reg(client,0x25, 0x08);	//SHARP_PGA_TH
	sensor_write_reg(client,0x26, 0x18);	//Test Setting
	sensor_write_reg(client,0x27, 0x00);	//Test Setting
	sensor_write_reg(client,0x28, 0x08);	//Test Setting
	sensor_write_reg(client,0x29, 0x50);	//AG_TH
	sensor_write_reg(client,0x2a, 0xe0);	//region ratio
	sensor_write_reg(client,0x2b, 0x10);	//Test Setting
	sensor_write_reg(client,0x2c, 0x28);	//Test Setting
	sensor_write_reg(client,0x2d, 0x40);	//Test Setting
	sensor_write_reg(client,0x2e, 0x00);	//Test Setting
	sensor_write_reg(client,0x2f, 0x00);	//Test Setting
	sensor_write_reg(client,0x30, 0x11);	//Test Setting
	sensor_write_reg(client,0x80, 0x03);	//SHARP2D_CTL
	sensor_write_reg(client,0x81, 0x07);	//Test Setting
	sensor_write_reg(client,0x90, 0x04);	//SHARP2D_SLOPE
	sensor_write_reg(client,0x91, 0x02);	//SHARP2D_DIFF_CTL
	sensor_write_reg(client,0x92, 0x00);	//SHARP2D_HI_CLIP
	sensor_write_reg(client,0x93, 0x20);	//SHARP2D_DY_CTL
	sensor_write_reg(client,0x94, 0x42);	//Test Setting
	sensor_write_reg(client,0x95, 0x60);	//Test Setting
	
	//PAGE 11
	sensor_write_reg(client,0x30, 0x11);
	
	sensor_write_reg(client,0x80, 0x03);
	sensor_write_reg(client,0x81, 0x07);
	
	sensor_write_reg(client,0x90, 0x04);
	sensor_write_reg(client,0x91, 0x02);
	sensor_write_reg(client,0x92, 0x00);
	sensor_write_reg(client,0x93, 0x20);
	sensor_write_reg(client,0x94, 0x42);
	sensor_write_reg(client,0x95, 0x60);
	
	//PAGE 14
	//Lens Shading Correction
	sensor_write_reg(client,0x03, 0x14);
	sensor_write_reg(client,0x10, 0x01);
	
	sensor_write_reg(client,0x20, 0x80);   //For Y decay
	sensor_write_reg(client,0x21, 0x80);   //For Y decay
	sensor_write_reg(client,0x22, 0x78);
	sensor_write_reg(client,0x23, 0x4d);
	sensor_write_reg(client,0x24, 0x46);
	
	//PAGE 15 
	//Color Correction
	sensor_write_reg(client,0x03, 0x15); 
	sensor_write_reg(client,0x10, 0x03);         
	sensor_write_reg(client,0x14, 0x3c);
	sensor_write_reg(client,0x16, 0x2c);
	sensor_write_reg(client,0x17, 0x2f);
	
	sensor_write_reg(client,0x30, 0xc4);
	sensor_write_reg(client,0x31, 0x5b);
	sensor_write_reg(client,0x32, 0x1f);
	sensor_write_reg(client,0x33, 0x2a);
	sensor_write_reg(client,0x34, 0xce);
	sensor_write_reg(client,0x35, 0x24);
	sensor_write_reg(client,0x36, 0x0b);
	sensor_write_reg(client,0x37, 0x3f);
	sensor_write_reg(client,0x38, 0x8a);
	
	sensor_write_reg(client,0x40, 0x87);
	sensor_write_reg(client,0x41, 0x18);
	sensor_write_reg(client,0x42, 0x91);
	sensor_write_reg(client,0x43, 0x94);
	sensor_write_reg(client,0x44, 0x9f);
	sensor_write_reg(client,0x45, 0x33);
	sensor_write_reg(client,0x46, 0x00);
	sensor_write_reg(client,0x47, 0x94);
	sensor_write_reg(client,0x48, 0x14);
	
	//Gamma
	//normal
	sensor_write_reg(client,0x03,0x16);
	sensor_write_reg(client,0x30,0x00);
	sensor_write_reg(client,0x31,0x0a);
	sensor_write_reg(client,0x32,0x1b);
	sensor_write_reg(client,0x33,0x2e);
	sensor_write_reg(client,0x34,0x5c);
	sensor_write_reg(client,0x35,0x79);
	sensor_write_reg(client,0x36,0x95);
	sensor_write_reg(client,0x37,0xa4);
	sensor_write_reg(client,0x38,0xb1);
	sensor_write_reg(client,0x39,0xbd);
	sensor_write_reg(client,0x3a,0xc8);
	sensor_write_reg(client,0x3b,0xd9);
	sensor_write_reg(client,0x3c,0xe8);
	sensor_write_reg(client,0x3d,0xf5);
	sensor_write_reg(client,0x3e,0xff);
	
	//PAGE 17 
	//Auto Flicker Cancellation 
	sensor_write_reg(client,0x03, 0x17);
	
	sensor_write_reg(client,0xc4, 0x3c);
	sensor_write_reg(client,0xc5, 0x32);
	
	//PAGE 20 
	//AE 
	sensor_write_reg(client,0x03, 0x20);
	
	sensor_write_reg(client,0x10, 0x0c);
	sensor_write_reg(client,0x11, 0x04);
	
	sensor_write_reg(client,0x20, 0x01);
	sensor_write_reg(client,0x28, 0x27);
	sensor_write_reg(client,0x29, 0xa1);   
	sensor_write_reg(client,0x2a, 0xf0);
	sensor_write_reg(client,0x2b, 0x34);
	sensor_write_reg(client,0x2c, 0x2b);
	
	sensor_write_reg(client,0x30, 0xf8);
	sensor_write_reg(client,0x39, 0x22);
	sensor_write_reg(client,0x3a, 0xde);
	sensor_write_reg(client,0x3b, 0x22);
	sensor_write_reg(client,0x3c, 0xde);
	
	sensor_write_reg(client,0x60, 0x95);
	sensor_write_reg(client,0x68, 0x3c);
	sensor_write_reg(client,0x69, 0x64);
	sensor_write_reg(client,0x6A, 0x28);
	sensor_write_reg(client,0x6B, 0xc8);
	
	sensor_write_reg(client,0x70, 0x42);   //For Y decay   
	sensor_write_reg(client,0x76, 0x22);
	sensor_write_reg(client,0x77, 0x02);   
	sensor_write_reg(client,0x78, 0x12);
	sensor_write_reg(client,0x79, 0x27);
	sensor_write_reg(client,0x7a, 0x23);  
	sensor_write_reg(client,0x7c, 0x1d);
	sensor_write_reg(client,0x7d, 0x22);
	
	sensor_write_reg(client,0x83, 0x00);
	sensor_write_reg(client,0x84, 0xaf);
	sensor_write_reg(client,0x85, 0x80); 
	
	sensor_write_reg(client,0x86, 0x00);
	sensor_write_reg(client,0x87, 0xc0);
	
	sensor_write_reg(client,0x88, 0x02);
	sensor_write_reg(client,0x89, 0x49);
	sensor_write_reg(client,0x8a, 0x00);    
	
	sensor_write_reg(client,0x8b, 0x3a);
	sensor_write_reg(client,0x8c, 0x80);  
	
	sensor_write_reg(client,0x8d, 0x30);
	sensor_write_reg(client,0x8e, 0xc0);
	
	sensor_write_reg(client,0x91, 0x02);
	sensor_write_reg(client,0x92, 0xdc);
	sensor_write_reg(client,0x93, 0x6c);   
	sensor_write_reg(client,0x94, 0x01);
	sensor_write_reg(client,0x95, 0xb7);
	sensor_write_reg(client,0x96, 0x74);   
	sensor_write_reg(client,0x98, 0x8C);
	sensor_write_reg(client,0x99, 0x23);  
	
	sensor_write_reg(client,0x9c, 0x08);   //For Y decay: Exposure Time
	sensor_write_reg(client,0x9d, 0xa0);   //For Y decay: Exposure Time
	sensor_write_reg(client,0x9e, 0x00);
	sensor_write_reg(client,0x9f, 0xc0);
	
	sensor_write_reg(client,0xb1, 0x14);
	sensor_write_reg(client,0xb2, 0x50);
	sensor_write_reg(client,0xb4, 0x14);
	sensor_write_reg(client,0xb5, 0x38);
	sensor_write_reg(client,0xb6, 0x26);
	sensor_write_reg(client,0xb7, 0x20);
	sensor_write_reg(client,0xb8, 0x1d);
	sensor_write_reg(client,0xb9, 0x1b);
	sensor_write_reg(client,0xba, 0x1a);
	sensor_write_reg(client,0xbb, 0x19);
	sensor_write_reg(client,0xbc, 0x19);
	sensor_write_reg(client,0xbd, 0x18);
	
	sensor_write_reg(client,0xc0, 0x16);   //0x1a->0x16
	sensor_write_reg(client,0xc3, 0x48);
	sensor_write_reg(client,0xc4, 0x48); 
	
	//PAGE 22 
	//AWB
	sensor_write_reg(client,0x03, 0x22);
	sensor_write_reg(client,0x10, 0xf2);
	sensor_write_reg(client,0x11, 0x2e);
	
	sensor_write_reg(client,0x21, 0x40);
	
	sensor_write_reg(client,0x30, 0x80);
	sensor_write_reg(client,0x31, 0x80);
	sensor_write_reg(client,0x38, 0x12);
	sensor_write_reg(client,0x39, 0x33);
	
	sensor_write_reg(client,0x40, 0xf0);
	sensor_write_reg(client,0x41, 0x44);// 33
	sensor_write_reg(client,0x42, 0x33);
	sensor_write_reg(client,0x43, 0xf3);
	sensor_write_reg(client,0x44, 0x55);
	sensor_write_reg(client,0x45, 0x44);
	sensor_write_reg(client,0x46, 0x02);
	
	sensor_write_reg(client,0x80, 0x25);
	sensor_write_reg(client,0x81, 0x20);// 0x17->0x20 [20110810 update]
	sensor_write_reg(client,0x82, 0x48);
	sensor_write_reg(client,0x83, 0x5e);
	sensor_write_reg(client,0x84, 0x24);
	sensor_write_reg(client,0x85, 0x59);
	sensor_write_reg(client,0x86, 0x24);
	sensor_write_reg(client,0x87, 0x4d);
	sensor_write_reg(client,0x88, 0x38);
	sensor_write_reg(client,0x89, 0x3e);
	sensor_write_reg(client,0x8a, 0x29);
	sensor_write_reg(client,0x8b, 0x02);
	sensor_write_reg(client,0x8d, 0x22);
	sensor_write_reg(client,0x8e, 0x71);  
	sensor_write_reg(client,0x8f, 0x63);
	
	sensor_write_reg(client,0x90, 0x60);
	sensor_write_reg(client,0x91, 0x5c);
	sensor_write_reg(client,0x92, 0x56);
	sensor_write_reg(client,0x93, 0x52);
	sensor_write_reg(client,0x94, 0x4c);
	sensor_write_reg(client,0x95, 0x36);
	sensor_write_reg(client,0x96, 0x31);
	sensor_write_reg(client,0x97, 0x2e);
	sensor_write_reg(client,0x98, 0x2a);
	sensor_write_reg(client,0x99, 0x29);
	sensor_write_reg(client,0x9a, 0x26);
	sensor_write_reg(client,0x9b, 0x09);
	
	//PAGE 22
	sensor_write_reg(client,0x03, 0x22);
	sensor_write_reg(client,0x10, 0xfb);
	
	//PAGE 20
	sensor_write_reg(client,0x03, 0x20);
	sensor_write_reg(client,0x10, 0x9c);
	
	sensor_write_reg(client,0x01, 0xf0);
	
	//PAGE 0
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x01, 0xf0);   //0xf1 ->0x41 : For Preview Green/Red Line. // 0x90->0xf0 [20110916 update]
	
	sensor_write_reg(client,0xff, 0xff);    //End of Initial Setting

	dprintk("---------------------------------hi704_init  4");
}

int hi704_set_switch(struct i2c_client *client,int width,int height)
{
	if(width == 352 && height == 288)
	{  
	    dprintk("--------------------------------------- preview 352x288!");
		sensor_write_reg(client,0xfe,0x01);
		sensor_write_reg(client,0x54,0x55);  
		sensor_write_reg(client,0x55,0x03);  
		sensor_write_reg(client,0x56,0x02); 
		sensor_write_reg(client,0x57,0x04); 
		sensor_write_reg(client,0x58,0x02); 
		sensor_write_reg(client,0x59,0x04); 
		sensor_write_reg(client,0xfe,0x00);
		sensor_write_reg(client,0x46,0x80);
		sensor_write_reg(client,0x47,0x00);  
		sensor_write_reg(client,0x48,0x00);  
		sensor_write_reg(client,0x49,0x01); 
		sensor_write_reg(client,0x4a,0x20);
		sensor_write_reg(client,0x4b,0x01);  
		sensor_write_reg(client,0x4c,0x60);
	} 
	else if(width == 176 && height == 144)
	{
		dprintk("--------------------------------------- preview 176x144!");
		sensor_write_reg(client,0xfe,0x01);
		sensor_write_reg(client,0x54,0x33);  
		sensor_write_reg(client,0x55,0x03);  
		sensor_write_reg(client,0x56,0x00); 
		sensor_write_reg(client,0x57,0x00); 
		sensor_write_reg(client,0x58,0x00); 
		sensor_write_reg(client,0x59,0x00); 
		sensor_write_reg(client,0xfe,0x00);
		sensor_write_reg(client,0x46,0x80);
		sensor_write_reg(client,0x47,0x00);  
		sensor_write_reg(client,0x48,0x00);  
		sensor_write_reg(client,0x49,0x00); 
		sensor_write_reg(client,0x4a,0x90);
		sensor_write_reg(client,0x4b,0x00);  
		sensor_write_reg(client,0x4c,0xb0);
	}
	else
	{
		dprintk("--------------------------------------- preview 640x480!");
		sensor_write_reg(client,0xfe,0x01);
		sensor_write_reg(client,0x54,0x11);  
		sensor_write_reg(client,0x55,0x03);  
		sensor_write_reg(client,0x56,0x00); 
		sensor_write_reg(client,0x57,0x00); 
		sensor_write_reg(client,0x58,0x00); 
		sensor_write_reg(client,0x59,0x00); 
		sensor_write_reg(client,0xfe,0x00);
		sensor_write_reg(client,0x46,0x00);
	}		
}





