
#include <asm/jzsoc.h>
#include "../../jz_sensor.h"
#include <linux/i2c.h>

#include "ov7675_set.h"

#define ov7675_DEBUG
//#undef DEBUG

#ifdef ov7675_DEBUG
#define dprintk(x...)   do{printk("ov7675---\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

void ov7675_set_preview_mode(struct i2c_client *client)
{
//	dprintk("------------------------------------preview!");		

}

void ov7675_set_capture_mode(struct i2c_client *client)
{
//	dprintk("------------------------------------capture!");		

}

void ov7675_set_nightmode(struct i2c_client *client,int enable)
{
	if(!enable)
	{
	  sensor_write_reg(client,0x3b,0x00);  
	  sensor_write_reg(client,0x2d,0x00);  
	  sensor_write_reg(client,0x2e,0x00);
	  sensor_write_reg(client,0x14,0x28);
	}
	else
	{
	  sensor_write_reg(client,0x3b,0xc0);  
	  sensor_write_reg(client,0x2d,0x00);  
	  sensor_write_reg(client,0x2e,0x00);
	  sensor_write_reg(client,0x14,0x28);
	}
	return 0;
}   /* ov7675_NightMode */

void ov7675_set_ab_50hz(struct i2c_client *client)
{
	int temp = sensor_read_reg(client,0x3b);
	sensor_write_reg(client,0x3b,temp|0x08);	    /* 50 Hz */	
	sensor_write_reg(client,0x9d,0x4c);  
	sensor_write_reg(client,0xa5,0x06);  
	dprintk("--------------------------ab_50hz ");
}

void ov7675_set_ab_60hz(struct i2c_client *client)
{
	int temp = sensor_read_reg(client,0x3b);
	sensor_write_reg(client,0x3b,temp&0xf7);	    /* 60 Hz */
	sensor_write_reg(client,0x9e,0x3f);  
	sensor_write_reg(client,0xab,0x07);  
	dprintk("--------------------------ab_60hz ");
}

void ov7675_set_effect_normal(struct i2c_client *client)
{
   sensor_write_reg(client,0x3A,0x0C);  
   sensor_write_reg(client,0x67,0x80);  
   sensor_write_reg(client,0x68,0x80);
   sensor_write_reg(client,0x56,0x40);  
   dprintk("--------------------------effect_normal ");
}

void ov7675_set_effect_grayscale(struct i2c_client *client)
{
   sensor_write_reg(client,0x3A,0x1C);  
   sensor_write_reg(client,0x67,0x80);  
   sensor_write_reg(client,0x68,0x80);
   sensor_write_reg(client,0x56,0x40); 
   dprintk("--------------------------effect_grayscale ");
}

void ov7675_set_effect_sepia(struct i2c_client *client)
{
   sensor_write_reg(client,0x3A,0x1C);  
   sensor_write_reg(client,0x67,0x40);  
   sensor_write_reg(client,0x68,0xa0);
   sensor_write_reg(client,0x56,0x40);  
   dprintk("--------------------------effect_sepia ");
}

void ov7675_set_effect_colorinv(struct i2c_client *client)
{
   sensor_write_reg(client,0x3A,0x2C);  
   sensor_write_reg(client,0x67,0x80);  
   sensor_write_reg(client,0x68,0x80);
   sensor_write_reg(client,0x56,0x40); 
   dprintk("--------------------------effect_colorinv ");
}

void ov7675_set_effect_sepiagreen(struct i2c_client *client)
{
   sensor_write_reg(client,0x3A,0x1C);  
   sensor_write_reg(client,0x67,0x40);  
   sensor_write_reg(client,0x68,0x40);
   sensor_write_reg(client,0x56,0x40);  
   dprintk("--------------------------effect_sepiagreen ");

}

void ov7675_set_effect_sepiablue(struct i2c_client *client)
{
   sensor_write_reg(client,0x3A,0x1C);  
   sensor_write_reg(client,0x67,0xc0);  
   sensor_write_reg(client,0x68,0x80);
   sensor_write_reg(client,0x56,0x40);  
   dprintk("--------------------------effect_sepiablue ");
}

void ov7675_set_wb_auto(struct i2c_client *client)
{       
  int temp = sensor_read_reg(client,0x13);
  sensor_write_reg(client,0x13,temp|0x02);   // Enable AWB	
  sensor_write_reg(client,0x01,0x56);
  sensor_write_reg(client,0x02,0x44);
  dprintk("-------------------------------wb_auto");		
}

void ov7675_set_wb_cloud(struct i2c_client *client)
{       
  int temp = sensor_read_reg(client,0x13);
  sensor_write_reg(client,0x13,temp&~0x02);   // Disable AWB	
  sensor_write_reg(client,0x01,0x58);
  sensor_write_reg(client,0x02,0x60);
  sensor_write_reg(client,0x6a,0x40);
  dprintk("-------------------------------wb_cloud");
}

void ov7675_set_wb_daylight(struct i2c_client *client)
{              
  int temp = sensor_read_reg(client,0x13);
  sensor_write_reg(client,0x13,temp&~0x02);   // Disable AWB	
  sensor_write_reg(client,0x01,0x56);
  sensor_write_reg(client,0x02,0x5c);
  sensor_write_reg(client,0x6a,0x42);
  dprintk("-------------------------------wb_daylight");
}


void ov7675_set_wb_incandescence(struct i2c_client *client)
{    
  int temp = sensor_read_reg(client,0x13);
  sensor_write_reg(client,0x13,temp&~0x02);   // Disable AWB	
  sensor_write_reg(client,0x01,0x9a);
  sensor_write_reg(client,0x02,0x40);
  sensor_write_reg(client,0x6a,0x48);
  dprintk("-------------------------------wb_incandescence");                               
}

void ov7675_set_wb_fluorescent(struct i2c_client *client)
{
  int temp = sensor_read_reg(client,0x13);
  sensor_write_reg(client,0x13,temp&~0x02);   // Disable AWB	
  sensor_write_reg(client,0x01,0x8b);
  sensor_write_reg(client,0x02,0x42);
  sensor_write_reg(client,0x6a,0x40);
  dprintk("-------------------------------wb_fluorescent");                        
}

void ov7675_set_wb_tungsten(struct i2c_client *client)
{   
  int temp = sensor_read_reg(client,0x13);
  sensor_write_reg(client,0x13,temp&~0x02);   // Disable AWB	
  sensor_write_reg(client,0x01,0xb8);
  sensor_write_reg(client,0x02,0x40);
  sensor_write_reg(client,0x6a,0x4f);
  dprintk("-------------------------------wb_tungsten");
}


void ov7675_init_setting(struct i2c_client *client)
{
  //	int sensor_id=0;
  // 	dprintk("-------------------------------ov7675 init 1");
		sensor_write_reg(client,0x12,0x80);

		mdelay(10);

	//	sensor_write_reg(client,0x09,0x10);
		sensor_write_reg(client,0xc1,0x7f);
		sensor_write_reg(client,0x11,0x00);
		sensor_write_reg(client,0x3a,0x0c);
		sensor_write_reg(client,0x3d,0xc0);
		sensor_write_reg(client,0x12,0x00);
		sensor_write_reg(client,0x15,0x02);//42
		sensor_write_reg(client,0x17,0x13);//13
		sensor_write_reg(client,0x18,0x01);//01
		sensor_write_reg(client,0x32,0xbf);
		sensor_write_reg(client,0x19,0x02);
		sensor_write_reg(client,0x1a,0x7a);
		sensor_write_reg(client,0x03,0x0a);
		sensor_write_reg(client,0x0c,0x00);
		sensor_write_reg(client,0x3e,0x00);
		sensor_write_reg(client,0x70,0x3a);
		sensor_write_reg(client,0x71,0x35);
		sensor_write_reg(client,0x72,0x11);
		sensor_write_reg(client,0x73,0xf0);
		sensor_write_reg(client,0xa2,0x02);

	//	sensor_write_reg(client,0x1b,0x40);
		//gamma
		sensor_write_reg(client,0x7a,0x20);
		sensor_write_reg(client,0x7b,0x03);
		sensor_write_reg(client,0x7c,0x0a);
		sensor_write_reg(client,0x7d,0x1a);
		sensor_write_reg(client,0x7e,0x3f);
		sensor_write_reg(client,0x7f,0x4e);
		sensor_write_reg(client,0x80,0x5b);
		sensor_write_reg(client,0x81,0x68);
		sensor_write_reg(client,0x82,0x75);
		sensor_write_reg(client,0x83,0x7f);
		sensor_write_reg(client,0x84,0x89);
		sensor_write_reg(client,0x85,0x9a);
		sensor_write_reg(client,0x86,0xa6);
		sensor_write_reg(client,0x87,0xbd);
		sensor_write_reg(client,0x88,0xd3);
		sensor_write_reg(client,0x89,0xe8);
		sensor_write_reg(client,0x13,0xe0);
		sensor_write_reg(client,0x00,0x00);
		sensor_write_reg(client,0x10,0x00);
		sensor_write_reg(client,0x0d,0x40);
		sensor_write_reg(client,0x14,0x28);
		sensor_write_reg(client,0xa5,0x02);
		sensor_write_reg(client,0xab,0x02);
		//bright
		sensor_write_reg(client,0x24,0x68);
		sensor_write_reg(client,0x25,0x58);
		sensor_write_reg(client,0x26,0xc2);
		sensor_write_reg(client,0x9f,0x78);
		sensor_write_reg(client,0xa0,0x68);
		sensor_write_reg(client,0xa1,0x03);
		sensor_write_reg(client,0xa6,0xd8);
		sensor_write_reg(client,0xa7,0xd8);
		sensor_write_reg(client,0xa8,0xf0);
		sensor_write_reg(client,0xa9,0x90);
		sensor_write_reg(client,0xaa,0x14);
		sensor_write_reg(client,0x13,0xe5);
		sensor_write_reg(client,0x0e,0x61);
		sensor_write_reg(client,0x0f,0x4b);
		sensor_write_reg(client,0x16,0x02);
		sensor_write_reg(client,0x1e,0x27);
		sensor_write_reg(client,0x21,0x02);
		sensor_write_reg(client,0x22,0x91);
		sensor_write_reg(client,0x29,0x07);
		sensor_write_reg(client,0x33,0x0b);
		sensor_write_reg(client,0x35,0x0b);
		sensor_write_reg(client,0x37,0x1d);
		sensor_write_reg(client,0x38,0x71);
		sensor_write_reg(client,0x39,0x2a);
		sensor_write_reg(client,0x3c,0x78);
		sensor_write_reg(client,0x4d,0x40);
		sensor_write_reg(client,0x4e,0x20);
		sensor_write_reg(client,0x69,0x00);
		sensor_write_reg(client,0x6b,0x0a);
		sensor_write_reg(client,0x74,0x10);
		sensor_write_reg(client,0x8d,0x4f);
		sensor_write_reg(client,0x8e,0x00);
		sensor_write_reg(client,0x8f,0x00);
		sensor_write_reg(client,0x90,0x00);
		sensor_write_reg(client,0x91,0x00);
		sensor_write_reg(client,0x96,0x00);
		sensor_write_reg(client,0x9a,0x80);
		sensor_write_reg(client,0xb0,0x84);
		sensor_write_reg(client,0xb1,0x0c);
		sensor_write_reg(client,0xb2,0x0e);
		sensor_write_reg(client,0xb3,0x82);
		sensor_write_reg(client,0xb8,0x0a);
		sensor_write_reg(client,0x43,0x0a);
		sensor_write_reg(client,0x44,0xf2);
		sensor_write_reg(client,0x45,0x39);
		sensor_write_reg(client,0x46,0x62);
		sensor_write_reg(client,0x47,0x3d);
		sensor_write_reg(client,0x48,0x55);
		sensor_write_reg(client,0x59,0x83);
		sensor_write_reg(client,0x5a,0x0d);
		sensor_write_reg(client,0x5b,0xcd);
		sensor_write_reg(client,0x5c,0x8c);
		sensor_write_reg(client,0x5d,0x77);
		sensor_write_reg(client,0x5e,0x16);
		sensor_write_reg(client,0x6c,0x0a);
		sensor_write_reg(client,0x6d,0x65);
		sensor_write_reg(client,0x6e,0x11);
		sensor_write_reg(client,0x6a,0x40);
		sensor_write_reg(client,0x01,0x56);
		sensor_write_reg(client,0x02,0x44);
		sensor_write_reg(client,0x13,0xe7); //8f
		//	dprintk("-------------------------------ov7675 init 2");
		//cmx
		sensor_write_reg(client,0x4f,0x88);
		sensor_write_reg(client,0x50,0x8b);
		sensor_write_reg(client,0x51,0x04);
		sensor_write_reg(client,0x52,0x11);
		sensor_write_reg(client,0x53,0x8c);
		sensor_write_reg(client,0x54,0x9d);
		sensor_write_reg(client,0x55,0x00);
		sensor_write_reg(client,0x56,0x40);
		sensor_write_reg(client,0x57,0x80);
		sensor_write_reg(client,0x58,0x9a);
		//sharpness
		sensor_write_reg(client,0x41,0x08);
		sensor_write_reg(client,0x3f,0x00);
		sensor_write_reg(client,0x75,0x23);
		sensor_write_reg(client,0x76,0xe1);
		sensor_write_reg(client,0x4c,0x00);
		sensor_write_reg(client,0x77,0x01);
		sensor_write_reg(client,0x3d,0xc2);
		sensor_write_reg(client,0x4b,0x09);
		sensor_write_reg(client,0xc9,0x30);
		sensor_write_reg(client,0x41,0x38);

		sensor_write_reg(client,0x56,0x40);
		sensor_write_reg(client,0x34,0x11);
		sensor_write_reg(client,0x3b,0x00);
		sensor_write_reg(client,0xa4,0x88);
		sensor_write_reg(client,0x96,0x00);
		sensor_write_reg(client,0x97,0x30);
		sensor_write_reg(client,0x98,0x20);
		sensor_write_reg(client,0x99,0x30);
		sensor_write_reg(client,0x9a,0x84);
		sensor_write_reg(client,0x9b,0x29);
		sensor_write_reg(client,0x9c,0x03);
		sensor_write_reg(client,0x9d,0x99);
		sensor_write_reg(client,0x9e,0x7f);
		sensor_write_reg(client,0x78,0x04);
		sensor_write_reg(client,0x79,0x01);
		sensor_write_reg(client,0xc8,0xf0);
		sensor_write_reg(client,0x79,0x0f);
		sensor_write_reg(client,0xc8,0x00);
		sensor_write_reg(client,0x79,0x10);
		sensor_write_reg(client,0xc8,0x7e);
		sensor_write_reg(client,0x79,0x0a);
		sensor_write_reg(client,0xc8,0x80);
		sensor_write_reg(client,0x79,0x0b);
		sensor_write_reg(client,0xc8,0x01);
		sensor_write_reg(client,0x79,0x0c);
		sensor_write_reg(client,0xc8,0x0f);
		sensor_write_reg(client,0x79,0x0d);
		sensor_write_reg(client,0xc8,0x20);
		sensor_write_reg(client,0x79,0x09);
		sensor_write_reg(client,0xc8,0x80);
		sensor_write_reg(client,0x79,0x02);
		sensor_write_reg(client,0xc8,0xc0);
		sensor_write_reg(client,0x79,0x03);
		sensor_write_reg(client,0xc8,0x40);
		sensor_write_reg(client,0x79,0x05);
		sensor_write_reg(client,0xc8,0x30);
		sensor_write_reg(client,0x79,0x26);
		sensor_write_reg(client,0x94,0x05);
		sensor_write_reg(client,0x95,0x09);
	//	sensor_write_reg(client,0x3a,0x0d);
	//	sensor_write_reg(client,0x3d,0xc3);
	//	sensor_write_reg(client,0x19,0x03);
	//	sensor_write_reg(client,0x1a,0x7b);
		sensor_write_reg(client,0x2a,0x00);
		sensor_write_reg(client,0x2b,0x00);
	//	sensor_write_reg(client,0x18,0x01);
		//lens
		sensor_write_reg(client,0x66,0x05);
		sensor_write_reg(client,0x62,0x10);
		sensor_write_reg(client,0x63,0x0b);
		sensor_write_reg(client,0x65,0x07);
		sensor_write_reg(client,0x64,0x0f);
		sensor_write_reg(client,0x94,0x0e);
		sensor_write_reg(client,0x95,0x10);
		sensor_write_reg(client,0x09,0x00);

		//		dprintk("-------------------------------ov7675 init 3");
}

int ov7675_set_switch(struct i2c_client *client,int width,int height)
{
	if(width == 352 && height == 288)
	{  
		sensor_write_reg(client,0x92,0x00);              
		sensor_write_reg(client,0x93,0x00);
		sensor_write_reg(client,0xb9,0x00);
		sensor_write_reg(client,0x19,0x02);
		sensor_write_reg(client,0x1a,0x7a);
		sensor_write_reg(client,0x17,0x13);
		sensor_write_reg(client,0x18,0x01);              
		sensor_write_reg(client,0x03,0x0a);
		sensor_write_reg(client,0xe6,0x00);
		sensor_write_reg(client,0xd2,0x1c);

		sensor_write_reg(client,0x19,0x17);         
		sensor_write_reg(client,0x1a,0x5f);
		sensor_write_reg(client,0x17,0x1d);
		sensor_write_reg(client,0x18,0x49);
		sensor_write_reg(client,0x03,0x0a);
		sensor_write_reg(client,0x32,0xbf);

//for 320x240
//		sensor_write_reg(client,0x92,0x88);              
//		sensor_write_reg(client,0x93,0x00);
//		sensor_write_reg(client,0xb9,0x30);
//		sensor_write_reg(client,0x19,0x02);
//		sensor_write_reg(client,0x1a,0x3e);
//		sensor_write_reg(client,0x17,0x13);
//		sensor_write_reg(client,0x18,0x3b);              
//		sensor_write_reg(client,0x03,0x0a);
//		sensor_write_reg(client,0xe6,0x05);
//		sensor_write_reg(client,0xd2,0x1c);
    	dprintk("---------------------------------------ov7675 preview 352x288!");
	} 

	else if(width == 176 && height == 144)
	{
		sensor_write_reg(client,0x92,0x88);              
		sensor_write_reg(client,0x93,0x00);
		sensor_write_reg(client,0xb9,0x30);
		sensor_write_reg(client,0x19,0x02);
		sensor_write_reg(client,0x1a,0x3e);
		sensor_write_reg(client,0x17,0x13);
		sensor_write_reg(client,0x18,0x3b);              
		sensor_write_reg(client,0x03,0x0a);
		sensor_write_reg(client,0xe6,0x05);
		sensor_write_reg(client,0xd2,0x1c);

		sensor_write_reg(client,0x19,0x17);              
		sensor_write_reg(client,0x1a,0x3b);
		sensor_write_reg(client,0x17,0x1d);
		sensor_write_reg(client,0x18,0x33);
		sensor_write_reg(client,0x03,0x0a);
		sensor_write_reg(client,0x32,0xbf);
		dprintk("---------------------------------------ov7675 preview 176x144!");
	}
	else
	{
//		sensor_write_reg(client,0x19,0x02);
//		sensor_write_reg(client,0x1a,0x7a);
//		sensor_write_reg(client,0x17,0x13);//13
//		sensor_write_reg(client,0x18,0x01);//01
//		sensor_write_reg(client,0x03,0x0a);
//		sensor_write_reg(client,0x32,0xbf);

		sensor_write_reg(client,0x92,0x00);              
		sensor_write_reg(client,0x93,0x00);
		sensor_write_reg(client,0xb9,0x00);
		sensor_write_reg(client,0x19,0x02);
		sensor_write_reg(client,0x1a,0x7a);
		sensor_write_reg(client,0x17,0x13);
		sensor_write_reg(client,0x18,0x01);              
		sensor_write_reg(client,0x03,0x0a);
		sensor_write_reg(client,0xe6,0x00);
		sensor_write_reg(client,0xd2,0x1c);
		dprintk("---------------------------------------ov7675 preview 640x480!");
	}

	return 0;
}


