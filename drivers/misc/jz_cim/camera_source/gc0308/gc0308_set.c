#include "../../jz_cim_core.h"
#include "../../jz_sensor.h"
#include <linux/i2c.h>
#include <asm/jzsoc.h>

#define gc0308_DEBUG
#ifdef gc0308_DEBUG
#define dprintk(x...)   do{printk("gc0308-\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

void gc0308_preview_set(struct i2c_client *client)
{
}

void gc0308_capture_set(struct i2c_client *client)
{
}

void gc0308_set_nightmode(struct i2c_client *client,int enable)
{
	if (!enable)
	{
	dprintk("---------------------------------gc0308_set_nightmode disable");
	}
	else
	{
	dprintk("-------------------------------gc0308_set_nightmode enable");
	}
}   /* gc0308_NightMode */

void gc0308_set_ab_50hz(struct i2c_client *client)
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

void gc0308_set_ab_60hz(struct i2c_client *client)
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

void gc0308_set_effect_normal(struct i2c_client *client)
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

void gc0308_set_effect_grayscale(struct i2c_client *client)
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

void gc0308_set_effect_sepia(struct i2c_client *client)
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

void gc0308_set_effect_colorinv(struct i2c_client *client)
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

void gc0308_set_effect_sepiagreen(struct i2c_client *client)
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

void gc0308_set_effect_sepiablue(struct i2c_client *client)
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

void gc0308_set_wb_auto(struct i2c_client *client)
{       
	sensor_write_reg(client,0x5a,0x56);
	sensor_write_reg(client,0x5b,0x40);
	sensor_write_reg(client,0x5c,0x4a);
	sensor_write_reg(client,0x22,0x57);
	dprintk("-------------------------------wb_auto");		
}

void gc0308_set_wb_cloud(struct i2c_client *client)
{                                              
	sensor_write_reg(client,0x22,0x55);
	sensor_write_reg(client,0x5a,0x8c);
	sensor_write_reg(client,0x5b,0x50);
	sensor_write_reg(client,0x5c,0x40);
	dprintk("-------------------------------wb_cloud");
}

void gc0308_set_wb_daylight(struct i2c_client *client)
{                                               
	sensor_write_reg(client,0x22,0x55);
	sensor_write_reg(client,0x5a,0x74);
	sensor_write_reg(client,0x5b,0x52);
	sensor_write_reg(client,0x5c,0x40);	
	dprintk("-------------------------------wb_daylight");
}

void gc0308_set_wb_incandescence(struct i2c_client *client)
{     
	sensor_write_reg(client,0x22,0x55);
	sensor_write_reg(client,0x5a,0x48);
	sensor_write_reg(client,0x5b,0x40);
	sensor_write_reg(client,0x5c,0x5c);	
	dprintk("-------------------------------wb_incandescence");                               
}

void gc0308_set_wb_fluorescent(struct i2c_client *client)
{                 
	sensor_write_reg(client,0x22,0x55);
	sensor_write_reg(client,0x5a,0x40);
	sensor_write_reg(client,0x5b,0x42);
	sensor_write_reg(client,0x5c,0x50);	
	dprintk("-------------------------------wb_fluorescent");                        
}

void gc0308_set_wb_tungsten(struct i2c_client *client)
{                                                 
	sensor_write_reg(client,0x22,0x55);
	sensor_write_reg(client,0x5a,0x40);
	sensor_write_reg(client,0x5b,0x54);
	sensor_write_reg(client,0x5c,0x70);	
	dprintk("-------------------------------wb_tungsten");
}

void gc0308_init_setting(struct i2c_client *client)
{
	
	sensor_write_reg(client,0xfe , 0x80);	
	
	sensor_write_reg(client,0xfe , 0x00);	// set page0
	
	sensor_write_reg(client,0xd2 , 0x10);	// close AEC
	sensor_write_reg(client,0x22 , 0x55);	// close AWB
	
	sensor_write_reg(client,0x03 , 0x01);								   
	sensor_write_reg(client,0x04 , 0x2c);								   
	sensor_write_reg(client,0x5a , 0x56);
	sensor_write_reg(client,0x5b , 0x40);
	sensor_write_reg(client,0x5c , 0x4a);			

	sensor_write_reg(client,0x22 , 0x57);	// Open AWB
	
	sensor_write_reg(client,0x01 , 0xfa);									 
	sensor_write_reg(client,0x02 , 0x70);								   
	sensor_write_reg(client,0x0f , 0x01);								   
																  
																  
	sensor_write_reg(client,0xe2 , 0x00);	//anti-flicker step [11:8]	   
	sensor_write_reg(client,0xe3 , 0x64);	//anti-flicker step [7:0]	   
																 
	sensor_write_reg(client,0xe4 , 0x02);	//exp level 1  16.67fps 	   
	sensor_write_reg(client,0xe5 , 0x58);								   
	sensor_write_reg(client,0xe6 , 0x03);	//exp level 2  12.5fps		   
	sensor_write_reg(client,0xe7 , 0x20);								   
	sensor_write_reg(client,0xe8 , 0x04);	//exp level 3  8.33fps		   
	sensor_write_reg(client,0xe9 , 0xb0);								   
	sensor_write_reg(client,0xea , 0x09);	//exp level 4  4.00fps		   
	sensor_write_reg(client,0xeb , 0xc4);								   
	  
	sensor_write_reg(client,0x05 , 0x00);								   
	sensor_write_reg(client,0x06 , 0x00);								   
	sensor_write_reg(client,0x07 , 0x00);								   
	sensor_write_reg(client,0x08 , 0x00);								   
	sensor_write_reg(client,0x09 , 0x01);								   
	sensor_write_reg(client,0x0a , 0xe8);								   
	sensor_write_reg(client,0x0b , 0x02);								   
	sensor_write_reg(client,0x0c , 0x88);								   
	sensor_write_reg(client,0x0d , 0x02);								   
	sensor_write_reg(client,0x0e , 0x02);								   
	sensor_write_reg(client,0x10 , 0x22);								   
	sensor_write_reg(client,0x11 , 0xfd);								   
	sensor_write_reg(client,0x12 , 0x2a);								   
	sensor_write_reg(client,0x13 , 0x00);								   
						   
	sensor_write_reg(client,0x15 , 0x0a);								   
	sensor_write_reg(client,0x16 , 0x05);								   
	sensor_write_reg(client,0x17 , 0x01);								   
	sensor_write_reg(client,0x18 , 0x44);								   
	sensor_write_reg(client,0x19 , 0x44);								   
	sensor_write_reg(client,0x1a , 0x1e);								   
	sensor_write_reg(client,0x1b , 0x00);								   
	sensor_write_reg(client,0x1c , 0xc1);								   
	sensor_write_reg(client,0x1d , 0x08);								   
	sensor_write_reg(client,0x1e , 0x60);								   
	sensor_write_reg(client,0x1f , 0x16);								   
																	
																	
	sensor_write_reg(client,0x20 , 0xff);								   
	sensor_write_reg(client,0x21 , 0xf8);								   
	sensor_write_reg(client,0x22 , 0x57);								   
	sensor_write_reg(client,0x24 , 0xa2);								   
	sensor_write_reg(client,0x25 , 0x0f);								   
																   
											 
	sensor_write_reg(client,0x26 , 0x03);								   
	sensor_write_reg(client,0x2f , 0x01);								   
	sensor_write_reg(client,0x30 , 0xf7);								   
	sensor_write_reg(client,0x31 , 0x50);
	sensor_write_reg(client,0x32 , 0x00);
	sensor_write_reg(client,0x39 , 0x04);
	sensor_write_reg(client,0x3a , 0x18);
	sensor_write_reg(client,0x3b , 0x20);								   
	sensor_write_reg(client,0x3c , 0x00);								   
	sensor_write_reg(client,0x3d , 0x00);								   
	sensor_write_reg(client,0x3e , 0x00);								   
	sensor_write_reg(client,0x3f , 0x00);								   
	sensor_write_reg(client,0x50 , 0x10);								   
	sensor_write_reg(client,0x53 , 0x82);								   
	sensor_write_reg(client,0x54 , 0x80);								   
	sensor_write_reg(client,0x55 , 0x80);								   
	sensor_write_reg(client,0x56 , 0x82);								   
	sensor_write_reg(client,0x8b , 0x40);								   
	sensor_write_reg(client,0x8c , 0x40);								   
	sensor_write_reg(client,0x8d , 0x40);								   
	sensor_write_reg(client,0x8e , 0x2e);								   
	sensor_write_reg(client,0x8f , 0x2e);								   
	sensor_write_reg(client,0x90 , 0x2e);								   
	sensor_write_reg(client,0x91 , 0x3c);								   
	sensor_write_reg(client,0x92 , 0x50);								   
	sensor_write_reg(client,0x5d , 0x12);								   
	sensor_write_reg(client,0x5e , 0x1a);								   
	sensor_write_reg(client,0x5f , 0x24);								   
	sensor_write_reg(client,0x60 , 0x07);								   
	sensor_write_reg(client,0x61 , 0x15);								   
	sensor_write_reg(client,0x62 , 0x08);								   
	sensor_write_reg(client,0x64 , 0x03);								   
	sensor_write_reg(client,0x66 , 0xe8);								   
	sensor_write_reg(client,0x67 , 0x86);								   
	sensor_write_reg(client,0x68 , 0xa2);								   
	sensor_write_reg(client,0x69 , 0x18);								   
	sensor_write_reg(client,0x6a , 0x0f);								   
	sensor_write_reg(client,0x6b , 0x00);								   
	sensor_write_reg(client,0x6c , 0x5f);								   
	sensor_write_reg(client,0x6d , 0x8f);								   
	sensor_write_reg(client,0x6e , 0x55);								   
	sensor_write_reg(client,0x6f , 0x38);								   
	sensor_write_reg(client,0x70 , 0x15);								   
	sensor_write_reg(client,0x71 , 0x33);								   
	sensor_write_reg(client,0x72 , 0xdc);								   
	sensor_write_reg(client,0x73 , 0x80);								   
	sensor_write_reg(client,0x74 , 0x02);								   
	sensor_write_reg(client,0x75 , 0x3f);								   
	sensor_write_reg(client,0x76 , 0x02);								   
	sensor_write_reg(client,0x77 , 0x36);								   
	sensor_write_reg(client,0x78 , 0x88);								   
	sensor_write_reg(client,0x79 , 0x81);								   
	sensor_write_reg(client,0x7a , 0x81);								   
	sensor_write_reg(client,0x7b , 0x22);								   
	sensor_write_reg(client,0x7c , 0xff);								   
	sensor_write_reg(client,0x93 , 0x48);								   
	sensor_write_reg(client,0x94 , 0x00);								   
	sensor_write_reg(client,0x95 , 0x05);								   
	sensor_write_reg(client,0x96 , 0xe8);								   
	sensor_write_reg(client,0x97 , 0x40);								   
	sensor_write_reg(client,0x98 , 0xf0);								   
	sensor_write_reg(client,0xb1 , 0x38);								   
	sensor_write_reg(client,0xb2 , 0x38);								   
	sensor_write_reg(client,0xbd , 0x38);								   
	sensor_write_reg(client,0xbe , 0x36);								   
	sensor_write_reg(client,0xd0 , 0xc9);								   
	sensor_write_reg(client,0xd1 , 0x10);								   
								
	sensor_write_reg(client,0xd3 , 0x80);								   
	sensor_write_reg(client,0xd5 , 0xf2);								   
	sensor_write_reg(client,0xd6 , 0x16);								   
	sensor_write_reg(client,0xdb , 0x92);								   
	sensor_write_reg(client,0xdc , 0xa5);								   
	sensor_write_reg(client,0xdf , 0x23);								   
	sensor_write_reg(client,0xd9 , 0x00);								   
	sensor_write_reg(client,0xda , 0x00);								   
	sensor_write_reg(client,0xe0 , 0x09);								   
						  
	sensor_write_reg(client,0xed , 0x04);								   
	sensor_write_reg(client,0xee , 0xa0);								   
	sensor_write_reg(client,0xef , 0x40);								   
	sensor_write_reg(client,0x80 , 0x03);								   
	sensor_write_reg(client,0x80 , 0x03);								   
	sensor_write_reg(client,0x9F , 0x10);								   
	sensor_write_reg(client,0xA0 , 0x20);								   
	sensor_write_reg(client,0xA1 , 0x38);								   
	sensor_write_reg(client,0xA2 , 0x4E);								   
	sensor_write_reg(client,0xA3 , 0x63);								   
	sensor_write_reg(client,0xA4 , 0x76);								   
	sensor_write_reg(client,0xA5 , 0x87);								   
	sensor_write_reg(client,0xA6 , 0xA2);								   
	sensor_write_reg(client,0xA7 , 0xB8);								   
	sensor_write_reg(client,0xA8 , 0xCA);								   
	sensor_write_reg(client,0xA9 , 0xD8);								   
	sensor_write_reg(client,0xAA , 0xE3);								   
	sensor_write_reg(client,0xAB , 0xEB);								   
	sensor_write_reg(client,0xAC , 0xF0);								   
	sensor_write_reg(client,0xAD , 0xF8);								   
	sensor_write_reg(client,0xAE , 0xFD);								   
	sensor_write_reg(client,0xAF , 0xFF);								   
	sensor_write_reg(client,0xc0 , 0x00);								   
	sensor_write_reg(client,0xc1 , 0x10);								   
	sensor_write_reg(client,0xc2 , 0x1C);								   
	sensor_write_reg(client,0xc3 , 0x30);								   
	sensor_write_reg(client,0xc4 , 0x43);								   
	sensor_write_reg(client,0xc5 , 0x54);								   
	sensor_write_reg(client,0xc6 , 0x65);								   
	sensor_write_reg(client,0xc7 , 0x75);								   
	sensor_write_reg(client,0xc8 , 0x93);								   
	sensor_write_reg(client,0xc9 , 0xB0);								   
	sensor_write_reg(client,0xca , 0xCB);								   
	sensor_write_reg(client,0xcb , 0xE6);								   
	sensor_write_reg(client,0xcc , 0xFF);								   
	sensor_write_reg(client,0xf0 , 0x02);								   
	sensor_write_reg(client,0xf1 , 0x01);								   
	sensor_write_reg(client,0xf2 , 0x01);								   
	sensor_write_reg(client,0xf3 , 0x30);								   
	sensor_write_reg(client,0xf9 , 0x9f);								   
	sensor_write_reg(client,0xfa , 0x78);								   
																
	//---------------------------------------------------------------
	sensor_write_reg(client,0xfe , 0x01);// set page1											 
																  
	sensor_write_reg(client,0x00 , 0xf5);								   
	sensor_write_reg(client,0x02 , 0x1a);								   
	sensor_write_reg(client,0x0a , 0xa0);								   
	sensor_write_reg(client,0x0b , 0x60);								   
	sensor_write_reg(client,0x0c , 0x08);								   
	sensor_write_reg(client,0x0e , 0x4c);								   
	sensor_write_reg(client,0x0f , 0x39);								   
	sensor_write_reg(client,0x11 , 0x3f);								   
	sensor_write_reg(client,0x12 , 0x72);								   
	sensor_write_reg(client,0x13 , 0x13);								   
	sensor_write_reg(client,0x14 , 0x42);								   
	sensor_write_reg(client,0x15 , 0x43);								   
	sensor_write_reg(client,0x16 , 0xc2);								   
	sensor_write_reg(client,0x17 , 0xa8);								   
	sensor_write_reg(client,0x18 , 0x18);								   
	sensor_write_reg(client,0x19 , 0x40);								   
	sensor_write_reg(client,0x1a , 0xd0);								   
	sensor_write_reg(client,0x1b , 0xf5);								   
	sensor_write_reg(client,0x70 , 0x40);								   
	sensor_write_reg(client,0x71 , 0x58);								   
	sensor_write_reg(client,0x72 , 0x30);								   
	sensor_write_reg(client,0x73 , 0x48);								   
	sensor_write_reg(client,0x74 , 0x20);								   
	sensor_write_reg(client,0x75 , 0x60);								   
	sensor_write_reg(client,0x77 , 0x20);								   
	sensor_write_reg(client,0x78 , 0x32);								   
	sensor_write_reg(client,0x30 , 0x03);								   
	sensor_write_reg(client,0x31 , 0x40);								   
	sensor_write_reg(client,0x32 , 0xe0);								   
	sensor_write_reg(client,0x33 , 0xe0);								   
	sensor_write_reg(client,0x34 , 0xe0);								   
	sensor_write_reg(client,0x35 , 0xb0);								   
	sensor_write_reg(client,0x36 , 0xc0);								   
	sensor_write_reg(client,0x37 , 0xc0);								   
	sensor_write_reg(client,0x38 , 0x04);								   
	sensor_write_reg(client,0x39 , 0x09);								   
	sensor_write_reg(client,0x3a , 0x12);								   
	sensor_write_reg(client,0x3b , 0x1C);								   
	sensor_write_reg(client,0x3c , 0x28);								   
	sensor_write_reg(client,0x3d , 0x31);								   
	sensor_write_reg(client,0x3e , 0x44);								   
	sensor_write_reg(client,0x3f , 0x57);								   
	sensor_write_reg(client,0x40 , 0x6C);								   
	sensor_write_reg(client,0x41 , 0x81);								   
	sensor_write_reg(client,0x42 , 0x94);								   
	sensor_write_reg(client,0x43 , 0xA7);								   
	sensor_write_reg(client,0x44 , 0xB8);								   
	sensor_write_reg(client,0x45 , 0xD6);								   
	sensor_write_reg(client,0x46 , 0xEE);								   
	sensor_write_reg(client,0x47 , 0x0d);								   
	sensor_write_reg(client,0xfe , 0x00); // set page0
	
	//-----------Update the registers 2010/07/06-------------//
	//Registers of Page0
	sensor_write_reg(client,0xfe , 0x00); // set page0
	sensor_write_reg(client,0x10 , 0x26);								  
	sensor_write_reg(client,0x11 , 0x0d);  // fd,modified by mormo 2010/07/06								
	sensor_write_reg(client,0x1a , 0x2a);  // 1e,modified by mormo 2010/07/06								   
	
	sensor_write_reg(client,0x1c , 0x49); // c1,modified by mormo 2010/07/06								 
	sensor_write_reg(client,0x1d , 0x9a); // 08,modified by mormo 2010/07/06								 
	sensor_write_reg(client,0x1e , 0x61); // 60,modified by mormo 2010/07/06								 
	
	sensor_write_reg(client,0x3a , 0x20);
	
	sensor_write_reg(client,0x50 , 0x14);  // 10,modified by mormo 2010/07/06								
	sensor_write_reg(client,0x53 , 0x80);								   
	sensor_write_reg(client,0x56 , 0x80);
	
	sensor_write_reg(client,0x8b , 0x20); //LSC 								
	sensor_write_reg(client,0x8c , 0x20);								   
	sensor_write_reg(client,0x8d , 0x20);								   
	sensor_write_reg(client,0x8e , 0x14);								   
	sensor_write_reg(client,0x8f , 0x10);								   
	sensor_write_reg(client,0x90 , 0x14);								   
	
	sensor_write_reg(client,0x94 , 0x02);								   
	sensor_write_reg(client,0x95 , 0x07);								   
	sensor_write_reg(client,0x96 , 0xe0);								   
	
	sensor_write_reg(client,0xb1 , 0x40); // YCPT								  
	sensor_write_reg(client,0xb2 , 0x40);								   
	sensor_write_reg(client,0xb3 , 0x40);
	sensor_write_reg(client,0xb6 , 0xe0);
	
	sensor_write_reg(client,0xd0 , 0xcb); // AECT  c9,modifed by mormo 2010/07/06								 
	sensor_write_reg(client,0xd3 , 0x48); // 80,modified by mormor 2010/07/06							
	
	sensor_write_reg(client,0xf2 , 0x02);								   
	sensor_write_reg(client,0xf7 , 0x12);
	sensor_write_reg(client,0xf8 , 0x0a);
	
	//Registers of Page1
	sensor_write_reg(client,0xfe , 0x01);// set page1	 
	sensor_write_reg(client,0x02 , 0x20);
	sensor_write_reg(client,0x04 , 0x10);
	sensor_write_reg(client,0x05 , 0x08);
	sensor_write_reg(client,0x06 , 0x20);
	sensor_write_reg(client,0x08 , 0x0a);
	
	sensor_write_reg(client,0x0e , 0x44);								   
	sensor_write_reg(client,0x0f , 0x32);
	sensor_write_reg(client,0x10 , 0x41);								   
	sensor_write_reg(client,0x11 , 0x37);								   
	sensor_write_reg(client,0x12 , 0x22);								   
	sensor_write_reg(client,0x13 , 0x19);								   
	sensor_write_reg(client,0x14 , 0x44);								   
	sensor_write_reg(client,0x15 , 0x44);  
	
	sensor_write_reg(client,0x19 , 0x50);								   
	sensor_write_reg(client,0x1a , 0xd8); 
	
	sensor_write_reg(client,0x32 , 0x10); 
	
	sensor_write_reg(client,0x35 , 0x00);								   
	sensor_write_reg(client,0x36 , 0x80);								   
	sensor_write_reg(client,0x37 , 0x00); 
	//-----------Update the registers end---------//
	
	sensor_write_reg(client,0xfe , 0x00); // set page0
	sensor_write_reg(client,0xd2 , 0x90);
	
	//-----------GAMMA Select(3)---------------//
	sensor_write_reg(client,0x9F , 0x10);
	sensor_write_reg(client,0xA0 , 0x20);
	sensor_write_reg(client,0xA1 , 0x38);
	sensor_write_reg(client,0xA2 , 0x4E);
	sensor_write_reg(client,0xA3 , 0x63);
	sensor_write_reg(client,0xA4 , 0x76);
	sensor_write_reg(client,0xA5 , 0x87);
	sensor_write_reg(client,0xA6 , 0xA2);
	sensor_write_reg(client,0xA7 , 0xB8);
	sensor_write_reg(client,0xA8 , 0xCA);
	sensor_write_reg(client,0xA9 , 0xD8);
	sensor_write_reg(client,0xAA , 0xE3);
	sensor_write_reg(client,0xAB , 0xEB);
	sensor_write_reg(client,0xAC , 0xF0);
	sensor_write_reg(client,0xAD , 0xF8);
	sensor_write_reg(client,0xAE , 0xFD);
	sensor_write_reg(client,0xAF , 0xFF);
	
	/*GC0308_GAMMA_Select,
	1:											   //smallest gamma curve
	sensor_write_reg(client,0x9F , 0x0B);
	sensor_write_reg(client,0xA0 , 0x16);
	sensor_write_reg(client,0xA1 , 0x29);
	sensor_write_reg(client,0xA2 , 0x3C);
	sensor_write_reg(client,0xA3 , 0x4F);
	sensor_write_reg(client,0xA4 , 0x5F);
	sensor_write_reg(client,0xA5 , 0x6F);
	sensor_write_reg(client,0xA6 , 0x8A);
	sensor_write_reg(client,0xA7 , 0x9F);
	sensor_write_reg(client,0xA8 , 0xB4); 
	sensor_write_reg(client,0xA9 , 0xC6);
	sensor_write_reg(client,0xAA , 0xD3);
	sensor_write_reg(client,0xAB , 0xDD);
	sensor_write_reg(client,0xAC , 0xE5);
	sensor_write_reg(client,0xAD , 0xF1);
	sensor_write_reg(client,0xAE , 0xFA);
	sensor_write_reg(client,0xAF , 0xFF);	
	2:			
	sensor_write_reg(client,0x9F , 0x0E);
	sensor_write_reg(client,0xA0 , 0x1C);
	sensor_write_reg(client,0xA1 , 0x34);
	sensor_write_reg(client,0xA2 , 0x48);
	sensor_write_reg(client,0xA3 , 0x5A);
	sensor_write_reg(client,0xA4 , 0x6B);
	sensor_write_reg(client,0xA5 , 0x7B);
	sensor_write_reg(client,0xA6 , 0x95);
	sensor_write_reg(client,0xA7 , 0xAB);
	sensor_write_reg(client,0xA8 , 0xBF);
	sensor_write_reg(client,0xA9 , 0xCE);
	sensor_write_reg(client,0xAA , 0xD9);
	sensor_write_reg(client,0xAB , 0xE4);
	sensor_write_reg(client,0xAC , 0xEC);
	sensor_write_reg(client,0xAD , 0xF7);
	sensor_write_reg(client,0xAE , 0xFD);
	sensor_write_reg(client,0xAF , 0xFF);
	3:
	sensor_write_reg(client,0x9F , 0x10);
	sensor_write_reg(client,0xA0 , 0x20);
	sensor_write_reg(client,0xA1 , 0x38);
	sensor_write_reg(client,0xA2 , 0x4E);
	sensor_write_reg(client,0xA3 , 0x63);
	sensor_write_reg(client,0xA4 , 0x76);
	sensor_write_reg(client,0xA5 , 0x87);
	sensor_write_reg(client,0xA6 , 0xA2);
	sensor_write_reg(client,0xA7 , 0xB8);
	sensor_write_reg(client,0xA8 , 0xCA);
	sensor_write_reg(client,0xA9 , 0xD8);
	sensor_write_reg(client,0xAA , 0xE3);
	sensor_write_reg(client,0xAB , 0xEB);
	sensor_write_reg(client,0xAC , 0xF0);
	sensor_write_reg(client,0xAD , 0xF8);
	sensor_write_reg(client,0xAE , 0xFD);
	sensor_write_reg(client,0xAF , 0xFF);
	4:
	sensor_write_reg(client,0x9F , 0x14);
	sensor_write_reg(client,0xA0 , 0x28);
	sensor_write_reg(client,0xA1 , 0x44);
	sensor_write_reg(client,0xA2 , 0x5D);
	sensor_write_reg(client,0xA3 , 0x72);
	sensor_write_reg(client,0xA4 , 0x86);
	sensor_write_reg(client,0xA5 , 0x95);
	sensor_write_reg(client,0xA6 , 0xB1);
	sensor_write_reg(client,0xA7 , 0xC6);
	sensor_write_reg(client,0xA8 , 0xD5);
	sensor_write_reg(client,0xA9 , 0xE1);
	sensor_write_reg(client,0xAA , 0xEA);
	sensor_write_reg(client,0xAB , 0xF1);
	sensor_write_reg(client,0xAC , 0xF5);
	sensor_write_reg(client,0xAD , 0xFB);
	sensor_write_reg(client,0xAE , 0xFE);
	sensor_write_reg(client,0xAF , 0xFF);
	5:								//largest gamma curve
	sensor_write_reg(client,0x9F , 0x15);
	sensor_write_reg(client,0xA0 , 0x2A);
	sensor_write_reg(client,0xA1 , 0x4A);
	sensor_write_reg(client,0xA2 , 0x67);
	sensor_write_reg(client,0xA3 , 0x79);
	sensor_write_reg(client,0xA4 , 0x8C);
	sensor_write_reg(client,0xA5 , 0x9A);
	sensor_write_reg(client,0xA6 , 0xB3);
	sensor_write_reg(client,0xA7 , 0xC5);
	sensor_write_reg(client,0xA8 , 0xD5);
	sensor_write_reg(client,0xA9 , 0xDF);
	sensor_write_reg(client,0xAA , 0xE8);
	sensor_write_reg(client,0xAB , 0xEE);
	sensor_write_reg(client,0xAC , 0xF3);
	sensor_write_reg(client,0xAD , 0xFA);
	sensor_write_reg(client,0xAE , 0xFD);
	sensor_write_reg(client,0xAF , 0xFF); */
		//-----------GAMMA Select End--------------//
	sensor_write_reg(client,0x14 , 0x10);
	

}

void gc0308_init_setting___(struct i2c_client *client)
{	
	dprintk("---------------------------------gc0308_init  1");
	sensor_write_reg(client,0xfe,0x80);   		
	sensor_write_reg(client,0xfe,0x00);       // set page0
	sensor_write_reg(client,0x1a,0x16);   	
	sensor_write_reg(client,0xd2,0x10);   // close AEC
	sensor_write_reg(client,0x22,0x55);   //close AWB	//daniel 100209
	sensor_write_reg(client,0x5a,0x56); 
	sensor_write_reg(client,0x5b,0x40);
	sensor_write_reg(client,0x5c,0x4a);		
	sensor_write_reg(client,0x22,0x57); 	
	sensor_write_reg(client,0x01,0xfa); 
	sensor_write_reg(client,0x02,0xd4); 
	sensor_write_reg(client,0x0f,0x01);
	sensor_write_reg(client,0x03,0x01); 
	sensor_write_reg(client,0x04,0x90); 
	sensor_write_reg(client,0xe2,0x00); 
	sensor_write_reg(client,0xe3,0x64); 	
	sensor_write_reg(client,0xe4,0x02); 
	sensor_write_reg(client,0xe5,0xbc); 
	sensor_write_reg(client,0xe6,0x02); 
	sensor_write_reg(client,0xe7,0xbc); 
	sensor_write_reg(client,0xe8,0x02); 
	sensor_write_reg(client,0xe9,0xbc); 
	sensor_write_reg(client,0xea,0x09); 
	sensor_write_reg(client,0xeb,0xc4); 
	sensor_write_reg(client,0x05,0x00);
	sensor_write_reg(client,0x06,0x00);
	sensor_write_reg(client,0x07,0x00); 
	sensor_write_reg(client,0x08,0x00); 
	sensor_write_reg(client,0x09,0x01); 
	sensor_write_reg(client,0x0a,0xe8); 
	sensor_write_reg(client,0x0b,0x02); 
	sensor_write_reg(client,0x0c,0x88); 
	sensor_write_reg(client,0x0d,0x02); 
	sensor_write_reg(client,0x0e,0x02); 
	sensor_write_reg(client,0x10,0x22); 
	sensor_write_reg(client,0x11,0x0d); 
	sensor_write_reg(client,0x12,0x2a); 
	sensor_write_reg(client,0x13,0x00); 
	sensor_write_reg(client,0x15,0x0a); 
	sensor_write_reg(client,0x16,0x05); 
	sensor_write_reg(client,0x17,0x01); 
	sensor_write_reg(client,0x1b,0x03); 
	sensor_write_reg(client,0x1c,0xc1); 
	sensor_write_reg(client,0x1d,0x08); 
	sensor_write_reg(client,0x1e,0x20); //0x60
	sensor_write_reg(client,0x1f,0x16); 
	sensor_write_reg(client,0x20,0xff); 
	sensor_write_reg(client,0x21,0xf8); 
	sensor_write_reg(client,0x24,0xa2); 
	sensor_write_reg(client,0x25,0x0f);
//output sync_mode
	sensor_write_reg(client,0x26,0x03); 
	sensor_write_reg(client,0x2f,0x01); 
// grab_t
	sensor_write_reg(client,0x30,0xf7); // a7  //daniel 100209
	sensor_write_reg(client,0x31,0x40);
	sensor_write_reg(client,0x32,0x00); 
	sensor_write_reg(client,0x39,0x04);   //daniel 100209
	sensor_write_reg(client,0x3a,0x20); //10 
	sensor_write_reg(client,0x3b,0x20); // 20 //daniel 100209
	sensor_write_reg(client,0x3c,0x02); 
	sensor_write_reg(client,0x3d,0x02); 
	sensor_write_reg(client,0x3e,0x02);
	sensor_write_reg(client,0x3f,0x02); 
	dprintk("---------------------------------gc0308_init  2");
//gain
	sensor_write_reg(client,0x50,0x24); 
	sensor_write_reg(client,0x53,0x82); 
	sensor_write_reg(client,0x54,0x80); 
	sensor_write_reg(client,0x55,0x80); 
	sensor_write_reg(client,0x56,0x82); 
// LSC_t
	sensor_write_reg(client,0x8b,0x20); 
	sensor_write_reg(client,0x8c,0x20); 
	sensor_write_reg(client,0x8d,0x20); 
	sensor_write_reg(client,0x8e,0x10); 
	sensor_write_reg(client,0x8f,0x10); 
	sensor_write_reg(client,0x90,0x10); 
	sensor_write_reg(client,0x91,0x3c); 
	sensor_write_reg(client,0x92,0x50); 
	sensor_write_reg(client,0x5d,0x12); 
	sensor_write_reg(client,0x5e,0x1a); 
	sensor_write_reg(client,0x5f,0x24); 
// DNDD_t
	sensor_write_reg(client,0x60,0x07); 
	sensor_write_reg(client,0x61,0x0e); 
	sensor_write_reg(client,0x62,0x0c); 
	sensor_write_reg(client,0x64,0x03); 
	sensor_write_reg(client,0x66,0xe8); 
	sensor_write_reg(client,0x67,0x86); 
	sensor_write_reg(client,0x68,0xa2); 
// asde_t
	sensor_write_reg(client,0x69,0x20); 
	sensor_write_reg(client,0x6a,0x0f); 
	sensor_write_reg(client,0x6b,0x00); //daniel 100209
	sensor_write_reg(client,0x6c,0x53); 
	sensor_write_reg(client,0x6d,0x83); 
	sensor_write_reg(client,0x6e,0xac); 
	sensor_write_reg(client,0x6f,0xac); 
	sensor_write_reg(client,0x70,0x15); 
	sensor_write_reg(client,0x71,0x33); 
// eeintp_t
	sensor_write_reg(client,0x72,0xdc);  //daniel 100209
	sensor_write_reg(client,0x73,0x80);  
	//for high resolution in light scene
	sensor_write_reg(client,0x74,0x02); 
	sensor_write_reg(client,0x75,0x3f); 
	sensor_write_reg(client,0x76,0x02); 
	sensor_write_reg(client,0x77,0x54); //daniel 100209
	sensor_write_reg(client,0x78,0x88); 
	sensor_write_reg(client,0x79,0x81); 
	sensor_write_reg(client,0x7a,0x81); 
	sensor_write_reg(client,0x7b,0x22); 
	sensor_write_reg(client,0x7c,0xff);	
//CC_t
	sensor_write_reg(client,0x93,0x45); //daniel 100209
	sensor_write_reg(client,0x94,0x00); 
	sensor_write_reg(client,0x95,0x00); //daniel 100209
	sensor_write_reg(client,0x96,0x00); 
	sensor_write_reg(client,0x97,0x45); 
	sensor_write_reg(client,0x98,0xf0); 
	sensor_write_reg(client,0x9c,0x00); 
	sensor_write_reg(client,0x9d,0x03); 
	sensor_write_reg(client,0x9e,0x00); 	
//YCP_t
	sensor_write_reg(client,0xb1,0x40); 
	sensor_write_reg(client,0xb2,0x40); 
	sensor_write_reg(client,0xb8,0x20); 
	sensor_write_reg(client,0xbe,0x36); 
	sensor_write_reg(client,0xbf,0x00); 
//AEC_t
	sensor_write_reg(client,0xd0,0xc9);  //daniel 100209
	sensor_write_reg(client,0xd1,0x10);  
	sensor_write_reg(client,0xd3,0x80);  //daniel 100209
	sensor_write_reg(client,0xd5,0xf2); 
	sensor_write_reg(client,0xd6,0x16);    //daniel 100209
	sensor_write_reg(client,0xdb,0x92); 
	sensor_write_reg(client,0xdc,0xa5);  
	sensor_write_reg(client,0xdf,0x23);   
	sensor_write_reg(client,0xd9,0x00);  
	sensor_write_reg(client,0xda,0x00);  
	sensor_write_reg(client,0xe0,0x09);
	sensor_write_reg(client,0xec,0x20);  
	sensor_write_reg(client,0xed,0x04);  
	sensor_write_reg(client,0xee,0xa0);  
	sensor_write_reg(client,0xef,0x40);  
	dprintk("---------------------------------gc0308_init  3");
//GAMMA	
	sensor_write_reg(client,0x9F,0x10);           
	sensor_write_reg(client,0xA0,0x20);  
	sensor_write_reg(client,0xA1,0x38);
	sensor_write_reg(client,0xA2,0x4e);
	sensor_write_reg(client,0xA3,0x63);
	sensor_write_reg(client,0xA4,0x76);
	sensor_write_reg(client,0xA5,0x87);
	sensor_write_reg(client,0xA6,0xa2);
	sensor_write_reg(client,0xA7,0xb8);
	sensor_write_reg(client,0xA8,0xca);
	sensor_write_reg(client,0xA9,0xd8);
	sensor_write_reg(client,0xAA,0xe3);
	sensor_write_reg(client,0xAB,0xeb);
	sensor_write_reg(client,0xAC,0xf0);
	sensor_write_reg(client,0xAD,0xf8);
	sensor_write_reg(client,0xAE,0xfd);
	sensor_write_reg(client,0xAF,0xff);
//Y_gamma
	sensor_write_reg(client,0xc0,0x00);
	sensor_write_reg(client,0xc1,0x0B);
	sensor_write_reg(client,0xc2,0x15);
	sensor_write_reg(client,0xc3,0x27);
	sensor_write_reg(client,0xc4,0x39);
	sensor_write_reg(client,0xc5,0x49);
	sensor_write_reg(client,0xc6,0x5A);
	sensor_write_reg(client,0xc7,0x6A);
	sensor_write_reg(client,0xc8,0x89);
	sensor_write_reg(client,0xc9,0xA8);
	sensor_write_reg(client,0xca,0xC6);
	sensor_write_reg(client,0xcb,0xE3);
	sensor_write_reg(client,0xcc,0xFF);
// ABS_t
	sensor_write_reg(client,0xf0,0x02);
	sensor_write_reg(client,0xf1,0x01);
	sensor_write_reg(client,0xf2,0x00);  //0x04
	sensor_write_reg(client,0xf3,0x30); 
// Measure Window
	sensor_write_reg(client,0xf7,0x04); 
	sensor_write_reg(client,0xf8,0x02); 
	sensor_write_reg(client,0xf9,0x9f);
	sensor_write_reg(client,0xfa,0x78);
	sensor_write_reg(client,0xfe,0x01);
//AWB
	sensor_write_reg(client,0x00,0xf5); 
//	sensor_write_reg(client,0x01,0x0a);  
	sensor_write_reg(client,0x02,0x1a); 
	sensor_write_reg(client,0x0a,0xa0); 
	sensor_write_reg(client,0x0b,0x60); 
	sensor_write_reg(client,0x0c,0x08);
	sensor_write_reg(client,0x0e,0x4c); 
	sensor_write_reg(client,0x0f,0x39); 
	sensor_write_reg(client,0x11,0x3f); 
	sensor_write_reg(client,0x13,0x72); 
	sensor_write_reg(client,0x14,0x42);  
	sensor_write_reg(client,0x15,0x43); 
	sensor_write_reg(client,0x16,0xc2); 
	sensor_write_reg(client,0x17,0xa8); 
	sensor_write_reg(client,0x18,0x18);  
	sensor_write_reg(client,0x19,0x40);  
	sensor_write_reg(client,0x1a,0xd0); 
	sensor_write_reg(client,0x1b,0xf5);  
	sensor_write_reg(client,0x70,0x40); 
	sensor_write_reg(client,0x71,0x58);  
	sensor_write_reg(client,0x72,0x30);  
	sensor_write_reg(client,0x73,0x48);  
	sensor_write_reg(client,0x74,0x20);  
	sensor_write_reg(client,0x75,0x60);  
	sensor_write_reg(client,0xfe,0x00);
	sensor_write_reg(client,0xd2,0x90);  // Open AEC
	sensor_write_reg(client,0x23,0x00);   // effect normal mode
	sensor_write_reg(client,0x2d,0x0a); 
	sensor_write_reg(client,0x20,0xff); 
	sensor_write_reg(client,0xd2,0x90); 
	sensor_write_reg(client,0x73,0x00); 
	sensor_write_reg(client,0x77,0x38);
	sensor_write_reg(client,0xb3,0x40);
	sensor_write_reg(client,0xb5,0x00);
	sensor_write_reg(client,0xb4,0x80); 
	sensor_write_reg(client,0xba,0x00); 
	sensor_write_reg(client,0xbb,0x00); 
	sensor_write_reg(client,0x14,0x11);  // Mirror UpsideDown 
	mdelay(100);
	sensor_write_reg(client, 0xff,0xff);
	dprintk("---------------------------------gc0308_init  4");
}

void gc0308_windows_switch(struct i2c_client *client,int width,int height)
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





