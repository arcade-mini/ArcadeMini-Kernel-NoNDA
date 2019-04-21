
#include <asm/jzsoc.h>
#include "../../jz_sensor.h"
#include <linux/i2c.h>

#include "hi704_set.h"

#define hi704_DEBUG
//#undef DEBUG

#ifdef hi704_DEBUG
#define dprintk(x...)   do{printk("hi704---\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

void hi704_set_preview_mode(struct i2c_client *client)
{
//	dprintk("------------------------------------preview!");		

}

void hi704_set_capture_mode(struct i2c_client *client)
{
//	dprintk("------------------------------------capture!");		

}

void hi704_set_nightmode(struct i2c_client *client,int enable)
{
	if (!enable)
	{
		sensor_write_reg(client,0x01, 0xf1);
		sensor_write_reg(client,0x03, 0x20);
		sensor_write_reg(client,0x10, 0x1c);
		sensor_write_reg(client,0x18, 0x38);
		sensor_write_reg(client,0x83, 0x01);//20fps
		sensor_write_reg(client,0x84, 0x24);
		sensor_write_reg(client,0x85, 0xf8);
		sensor_write_reg(client,0x88, 0x01);//10fps
		sensor_write_reg(client,0x89, 0x24);
		sensor_write_reg(client,0x8a, 0xf8);
		sensor_write_reg(client,0x70, 0x42);
		sensor_write_reg(client,0xb2, 0xd0);//AGMAX
		sensor_write_reg(client,0x01, 0xf0);
		sensor_write_reg(client,0x03, 0x20);
		sensor_write_reg(client,0x10, 0x9c);
		sensor_write_reg(client,0x18, 0x30);
	dprintk("---------------------------------hi704_set_nightmode disable");
	}
	else
	{
		sensor_write_reg(client,0x01, 0xf1);
		sensor_write_reg(client,0x03, 0x20);
		sensor_write_reg(client,0x10, 0x1c);
		sensor_write_reg(client,0x18, 0x38);
		sensor_write_reg(client,0x83, 0x01);//20fps
		sensor_write_reg(client,0x84, 0x24);
		sensor_write_reg(client,0x85, 0xf8);
		sensor_write_reg(client,0x88, 0x06); // 3.333fps
		sensor_write_reg(client,0x89, 0xdd);
		sensor_write_reg(client,0x8a, 0xd0);
		sensor_write_reg(client,0x70, 0x48);
		sensor_write_reg(client,0xb2, 0xd0);//AGMAX
		sensor_write_reg(client,0x01, 0xf0);
		sensor_write_reg(client,0x03, 0x20);
		sensor_write_reg(client,0x10, 0x9c);
		sensor_write_reg(client,0x18, 0x30);
	dprintk("-------------------------------hi704_set_nightmode enable");
	}
}   /* hi704_NightMode */

void hi704_set_ab_50hz(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x20);
	sensor_write_reg(client,0x10, 0x9c);
	dprintk("--------------------------ab_50hz ");
}

void hi704_set_ab_60hz(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x20);
	sensor_write_reg(client,0x10, 0x8c);
	dprintk("--------------------------ab_60hz ");
}

void hi704_set_effect_normal(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x10);
	sensor_write_reg(client,0x11, 0x03);
	sensor_write_reg(client,0x12, 0x30);
	sensor_write_reg(client,0x13, 0x00);
	sensor_write_reg(client,0x44, 0x80);
	sensor_write_reg(client,0x45, 0x80);
	sensor_write_reg(client,0x47, 0x7f);
	sensor_write_reg(client,0x03, 0x13);
	sensor_write_reg(client,0x20, 0x06);
	sensor_write_reg(client,0x21, 0x04);
	sensor_write_reg(client,0xff, 0xff);
	dprintk("--------------------------effect_normal ");
}

void hi704_set_effect_grayscale(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x10);
	sensor_write_reg(client,0x11, 0x03);
	sensor_write_reg(client,0x12, 0x23);
	sensor_write_reg(client,0x13, 0x00);
	sensor_write_reg(client,0x44, 0x80);
	sensor_write_reg(client,0x45, 0x80);
	sensor_write_reg(client,0x47, 0x7f);
	sensor_write_reg(client,0x03, 0x13);
	sensor_write_reg(client,0x20, 0x07);
	sensor_write_reg(client,0x21, 0x03);
	sensor_write_reg(client,0xff, 0xff);
       dprintk("--------------------------effect_grayscale ");
}

void hi704_set_effect_sepia(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x10);
	sensor_write_reg(client,0x11, 0x03);
	sensor_write_reg(client,0x12, 0x23);
	sensor_write_reg(client,0x13, 0x00);
	sensor_write_reg(client,0x44, 0x70);
	sensor_write_reg(client,0x45, 0x98);
	sensor_write_reg(client,0x47, 0x7f);
	sensor_write_reg(client,0x03, 0x13);
	sensor_write_reg(client,0x20, 0x07);
	sensor_write_reg(client,0x21, 0x03);
	sensor_write_reg(client,0xff, 0xff);
       dprintk("--------------------------effect_sepia ");
}

void hi704_set_effect_colorinv(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x10);
	sensor_write_reg(client,0x11, 0x03);
	sensor_write_reg(client,0x12, 0x28);
	sensor_write_reg(client,0x13, 0x00);
	sensor_write_reg(client,0x44, 0x80);
	sensor_write_reg(client,0x45, 0x80);
	sensor_write_reg(client,0x03, 0x13);
	sensor_write_reg(client,0x47, 0x7f);
	sensor_write_reg(client,0x20, 0x07);
	sensor_write_reg(client,0x21, 0x03);
	sensor_write_reg(client,0xff, 0xff);
       dprintk("--------------------------effect_colorinv ");
}

void hi704_set_effect_sepiagreen(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x10);
	sensor_write_reg(client,0x11, 0x03);
	sensor_write_reg(client,0x12, 0x23);
	sensor_write_reg(client,0x13, 0x00);
	sensor_write_reg(client,0x44, 0x60);
	sensor_write_reg(client,0x45, 0x60);
	sensor_write_reg(client,0x47, 0x7f);
	sensor_write_reg(client,0x03, 0x13);
	sensor_write_reg(client,0x20, 0x07);
	sensor_write_reg(client,0x21, 0x03);
	sensor_write_reg(client,0xff, 0xff);
       dprintk("--------------------------effect_sepiagreen ");

}

void hi704_set_effect_sepiablue(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x10);
	sensor_write_reg(client,0x11, 0x03);
	sensor_write_reg(client,0x12, 0x23);
	sensor_write_reg(client,0x13, 0x00);
	sensor_write_reg(client,0x44, 0xb0);
	sensor_write_reg(client,0x45, 0x40);
	sensor_write_reg(client,0x47, 0x7f);
	sensor_write_reg(client,0x03, 0x13);
	sensor_write_reg(client,0x20, 0x07);
	sensor_write_reg(client,0x21, 0x03);
	sensor_write_reg(client,0xff, 0xff);
       dprintk("--------------------------effect_sepiablue ");
}



void hi704_set_wb_auto(struct i2c_client *client)
{
	sensor_write_reg(client,0x03,0x22);  // AUTO 3000K~7000K                        
	sensor_write_reg(client,0x10,0x7b);                 
	sensor_write_reg(client,0x83,0x62);	        
	sensor_write_reg(client,0x84,0x20);	       
	sensor_write_reg(client,0x85,0x60);	       
	sensor_write_reg(client,0x86,0x30);              
	sensor_write_reg(client,0x03,0x22);          
	sensor_write_reg(client,0x10,0xfb);        
	dprintk("-------------------------------wb_auto");		
}

void hi704_set_wb_cloud(struct i2c_client *client)
{
	// NOON130PC20_reg_WB_cloudy
	sensor_write_reg(client,0x03,0x22);   //7000K                                     
	sensor_write_reg(client,0x10,0x7b);                                            
	sensor_write_reg(client,0x80,0x50);                                               
	sensor_write_reg(client,0x81,0x20);	                                             
	sensor_write_reg(client,0x82,0x24);                                                       
	sensor_write_reg(client,0x83,0x6d);		                                     
	sensor_write_reg(client,0x84,0x65);		                                         
	sensor_write_reg(client,0x85,0x24);                                                       
	sensor_write_reg(client,0x86,0x1c);                                               
	//sensor_write_reg(client,0x03,0x22);                                                
	//sensor_write_reg(client,0x10,0xea);                                                 
	dprintk("-------------------------------wb_cloud");
}


void hi704_set_wb_daylight(struct i2c_client *client)
{
	// NOON130PC20_reg_WB_daylight  °×Ìì 
	sensor_write_reg(client,0x03,0x22);  //6500K                                     
	sensor_write_reg(client,0x10,0x7b);                                                  
	sensor_write_reg(client,0x80,0x40);                                                  
	sensor_write_reg(client,0x81,0x20);		                                     
	sensor_write_reg(client,0x82,0x28);                                                    
	sensor_write_reg(client,0x83,0x45);    	                                             
	sensor_write_reg(client,0x84,0x35);		                                      
	sensor_write_reg(client,0x85,0x2d);	                                                  
	sensor_write_reg(client,0x86,0x1c);                                                 
	dprintk("-------------------------------wb_daylight");
}


void hi704_set_wb_incandescence(struct i2c_client *client)
{
	sensor_write_reg(client,0x03,0x22);  //2800K~3000K                                     
	sensor_write_reg(client,0x10,0x7b);                                                  
	sensor_write_reg(client,0x80,0x25);                                                 
	sensor_write_reg(client,0x81,0x20);                                                       
	sensor_write_reg(client,0x82,0x44);		                                       
	sensor_write_reg(client,0x83,0x24);		                                     
	sensor_write_reg(client,0x84,0x1e);                                                       
	sensor_write_reg(client,0x85,0x50);		                                     
	sensor_write_reg(client,0x86,0x45);       
	dprintk("-------------------------------wb_incandescence");                               
}


void hi704_set_wb_fluorescent(struct i2c_client *client)
{
	sensor_write_reg(client,0x03,0x22);  //4200K~5000K                                     
	sensor_write_reg(client,0x10,0x7b);                                                   
	sensor_write_reg(client,0x80,0x35);                                                  
	sensor_write_reg(client,0x81,0x20);		                                          
	sensor_write_reg(client,0x82,0x32);                                                    
	sensor_write_reg(client,0x83,0x3c);		                                     
	sensor_write_reg(client,0x84,0x2c);		                                          
	sensor_write_reg(client,0x85,0x45);                                                       
	sensor_write_reg(client,0x86,0x35);                     
	dprintk("-------------------------------wb_fluorescent");                        
}


void hi704_set_wb_tungsten(struct i2c_client *client)
{
	sensor_write_reg(client,0x03,0x22);  //4000K                                   
	sensor_write_reg(client,0x10,0x6a);                                                   
	sensor_write_reg(client,0x80,0x33);                                                  
	sensor_write_reg(client,0x81,0x20);		                                        
	sensor_write_reg(client,0x82,0x3d);                                                       
	sensor_write_reg(client,0x83,0x2e);		                                          
	sensor_write_reg(client,0x84,0x24);		                                      
	sensor_write_reg(client,0x85,0x43);	                                                  
	sensor_write_reg(client,0x86,0x3d);                                                    
	dprintk("-------------------------------wb_tungsten");
}


void hi704_init_setting(struct i2c_client *client)
{
//	dprintk("1------------------------------------hi704 sensor init!");
	sensor_write_reg(client,0x01, 0xf1);
	sensor_write_reg(client,0x01, 0xf3);
	sensor_write_reg(client,0x01, 0xf1);
	sensor_write_reg(client,0x03, 0x00);//Page 0
	sensor_write_reg(client,0x10, 0x00);
	sensor_write_reg(client,0x12, 0x00);
	sensor_write_reg(client,0x20, 0x00);
	sensor_write_reg(client,0x21, 0x04);
	sensor_write_reg(client,0x22, 0x00);
	sensor_write_reg(client,0x23, 0x04);
	sensor_write_reg(client,0x40, 0x01);
	sensor_write_reg(client,0x41, 0x58);
	sensor_write_reg(client,0x42, 0x00);
	sensor_write_reg(client,0x43, 0x04);
//	dprintk("2------------------------------------hi704 sensor init!");
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
	sensor_write_reg(client,0x03, 0x02 );//Page 2
	sensor_write_reg(client,0x13, 0x40 );
	sensor_write_reg(client,0x14, 0x04 );
	sensor_write_reg(client,0x1a, 0x00 );
	sensor_write_reg(client,0x1b, 0x08 );
	sensor_write_reg(client,0x20, 0x33 );
	sensor_write_reg(client,0x21, 0xaa );
	sensor_write_reg(client,0x22, 0xa7 );
	sensor_write_reg(client,0x23, 0x32 );
	sensor_write_reg(client,0x3b, 0x48 );
	sensor_write_reg(client,0x50, 0x21 );
	sensor_write_reg(client,0x52, 0xa2 );
	sensor_write_reg(client,0x53, 0x0a );
	sensor_write_reg(client,0x54, 0x30 );
	sensor_write_reg(client,0x55, 0x10 );
	sensor_write_reg(client,0x56, 0x0c );
	sensor_write_reg(client,0x59, 0x0f );
	sensor_write_reg(client,0x60, 0xca );
	sensor_write_reg(client,0x61, 0xdb );
	sensor_write_reg(client,0x62, 0xca );
	sensor_write_reg(client,0x63, 0xda );
	sensor_write_reg(client,0x64, 0xca );
	sensor_write_reg(client,0x65, 0xda );
//	dprintk("3------------------------------------hi704 sensor init!");
	sensor_write_reg(client,0x72, 0xcb );
	sensor_write_reg(client,0x73, 0xd8 );
	sensor_write_reg(client,0x74, 0xcb );
	sensor_write_reg(client,0x75, 0xd8 );
	sensor_write_reg(client,0x80, 0x02 );
	sensor_write_reg(client,0x81, 0xbd );
	sensor_write_reg(client,0x82, 0x24 );
	sensor_write_reg(client,0x83, 0x3e );
	sensor_write_reg(client,0x84, 0x24 );
	sensor_write_reg(client,0x85, 0x3e );
	sensor_write_reg(client,0x92, 0x72 );
	sensor_write_reg(client,0x93, 0x8c );
	sensor_write_reg(client,0x94, 0x72 );
	sensor_write_reg(client,0x95, 0x8c );
	sensor_write_reg(client,0xa0, 0x03 );
	sensor_write_reg(client,0xa1, 0xbb );
	sensor_write_reg(client,0xa4, 0xbb );
	sensor_write_reg(client,0xa5, 0x03 );
	sensor_write_reg(client,0xa8, 0x44 );
	sensor_write_reg(client,0xa9, 0x6a );
	sensor_write_reg(client,0xaa, 0x92 );
	sensor_write_reg(client,0xab, 0xb7 );
	sensor_write_reg(client,0xb8, 0xc9 );
	sensor_write_reg(client,0xb9, 0xd0 );
	sensor_write_reg(client,0xbc, 0x20 );
	sensor_write_reg(client,0xbd, 0x28 );
	sensor_write_reg(client,0xc0, 0xde );
	sensor_write_reg(client,0xc1, 0xec );
	sensor_write_reg(client,0xc2, 0xde );
	sensor_write_reg(client,0xc3, 0xec );
	sensor_write_reg(client,0xc4, 0xe0 );
	sensor_write_reg(client,0xc5, 0xea );
	sensor_write_reg(client,0xc6, 0xe0 );
	sensor_write_reg(client,0xc7, 0xea );
	sensor_write_reg(client,0xc8, 0xe1 );
	sensor_write_reg(client,0xc9, 0xe8 );
	sensor_write_reg(client,0xca, 0xe1 );
	sensor_write_reg(client,0xcb, 0xe8 );
	sensor_write_reg(client,0xcc, 0xe2 );
	sensor_write_reg(client,0xcd, 0xe7 );
	sensor_write_reg(client,0xce, 0xe2 );
	sensor_write_reg(client,0xcf, 0xe7 );
	sensor_write_reg(client,0xd0, 0xc8 );
	sensor_write_reg(client,0xd1, 0xef );
//	dprintk("4------------------------------------hi704 sensor init!");
	sensor_write_reg(client,0x03, 0x10 );//Page 10
	sensor_write_reg(client,0x10, 0x03);//ISPCTL1(Control the format of image data) : YUV order for Lot51 by NHJ
	sensor_write_reg(client,0x11, 0x43);
	sensor_write_reg(client,0x12, 0x30);
	sensor_write_reg(client,0x40, 0x80);//brightness
	sensor_write_reg(client,0x41, 0x10);
	sensor_write_reg(client,0x48, 0x84);
	sensor_write_reg(client,0x50, 0x48);
	sensor_write_reg(client,0x60, 0x7f);
	sensor_write_reg(client,0x61, 0x00);
	sensor_write_reg(client,0x62, 0xa0);
	sensor_write_reg(client,0x63, 0x90);// 50
	sensor_write_reg(client,0x64, 0x48);
	sensor_write_reg(client,0x66, 0x90);
	sensor_write_reg(client,0x67, 0x36);
//	dprintk("5------------------------------------hi704 sensor init!");
	sensor_write_reg(client,0x03, 0x11);//Page 11  LPF
	sensor_write_reg(client,0x10, 0x25);
	sensor_write_reg(client,0x11, 0x1f); //open LPF in dark, 0x0a close
	sensor_write_reg(client,0x20, 0x00);
	sensor_write_reg(client,0x21, 0x38);
	sensor_write_reg(client,0x23, 0x0a);
	sensor_write_reg(client,0x60, 0x10);
	sensor_write_reg(client,0x61, 0x82);
	sensor_write_reg(client,0x62, 0x00);
	sensor_write_reg(client,0x63, 0x83);
	sensor_write_reg(client,0x64, 0x83);
	sensor_write_reg(client,0x67, 0xf0);
	sensor_write_reg(client,0x68, 0x30);
	sensor_write_reg(client,0x69, 0x10);
//	dprintk("6------------------------------------hi704 sensor init!");
	sensor_write_reg(client,0x03, 0x12);//Page 12  2D
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
	sensor_write_reg(client,0x03, 0x13);//Page 13
	sensor_write_reg(client,0x10, 0x01);
	sensor_write_reg(client,0x11, 0x89);
	sensor_write_reg(client,0x12, 0x14);
	sensor_write_reg(client,0x13, 0x19);
	sensor_write_reg(client,0x14, 0x08);
	sensor_write_reg(client,0x20, 0x06);
	sensor_write_reg(client,0x21, 0x03);
	sensor_write_reg(client,0x23, 0x30);
	sensor_write_reg(client,0x24, 0x33);
	sensor_write_reg(client,0x25, 0x08);
	sensor_write_reg(client,0x26, 0x18);
	sensor_write_reg(client,0x27, 0x00);
	sensor_write_reg(client,0x28, 0x08);
	sensor_write_reg(client,0x29, 0x50);
	sensor_write_reg(client,0x2a, 0xe0);
	sensor_write_reg(client,0x2b, 0x10);
	sensor_write_reg(client,0x2c, 0x28);
	sensor_write_reg(client,0x2d, 0x40);
	sensor_write_reg(client,0x2e, 0x00);
	sensor_write_reg(client,0x2f, 0x00);
	sensor_write_reg(client,0x30, 0x11);
	sensor_write_reg(client,0x80, 0x03);
	sensor_write_reg(client,0x81, 0x07);
	sensor_write_reg(client,0x90, 0x04);
	sensor_write_reg(client,0x91, 0x02);
	sensor_write_reg(client,0x92, 0x00);
	sensor_write_reg(client,0x93, 0x20);
	sensor_write_reg(client,0x94, 0x42);
	sensor_write_reg(client,0x95, 0x60);
//	dprintk("7------------------------------------hi704 sensor init!");
	sensor_write_reg(client,0x03, 0x14);//Page 14
	sensor_write_reg(client,0x10, 0x01);
	sensor_write_reg(client,0x20, 0x60);
	sensor_write_reg(client,0x21, 0x80);
	sensor_write_reg(client,0x22, 0x66);
	sensor_write_reg(client,0x23, 0x50);
	sensor_write_reg(client,0x24, 0x44);
	sensor_write_reg(client,0x03, 0x15);//Page 15
	sensor_write_reg(client,0x10, 0x03);
	sensor_write_reg(client,0x14, 0x3c);
	sensor_write_reg(client,0x16, 0x2c);
	sensor_write_reg(client,0x17, 0x2f);
	sensor_write_reg(client,0x30, 0xcb);
	sensor_write_reg(client,0x31, 0x61);
	sensor_write_reg(client,0x32, 0x16);
	sensor_write_reg(client,0x33, 0x23);
	sensor_write_reg(client,0x34, 0xce);
	sensor_write_reg(client,0x35, 0x2b);
	sensor_write_reg(client,0x36, 0x01);
	sensor_write_reg(client,0x37, 0x34);
	sensor_write_reg(client,0x38, 0x75);
	sensor_write_reg(client,0x40, 0x87);
	sensor_write_reg(client,0x41, 0x18);
	sensor_write_reg(client,0x42, 0x91);
	sensor_write_reg(client,0x43, 0x94);
	sensor_write_reg(client,0x44, 0x9f);
	sensor_write_reg(client,0x45, 0x33);
	sensor_write_reg(client,0x46, 0x00);
	sensor_write_reg(client,0x47, 0x94);
	sensor_write_reg(client,0x48, 0x14);
//	dprintk("8------------------------------------hi704 sensor init!");
	sensor_write_reg(client,0x03, 0x16);//Page 16
	sensor_write_reg(client,0x30, 0x00);// original
	sensor_write_reg(client,0x31, 0x0a);
	sensor_write_reg(client,0x32, 0x1b);
	sensor_write_reg(client,0x33, 0x2e);
	sensor_write_reg(client,0x34, 0x5c);
	sensor_write_reg(client,0x35, 0x79);
	sensor_write_reg(client,0x36, 0x95);
	sensor_write_reg(client,0x37, 0xa4);
	sensor_write_reg(client,0x38, 0xb1);
	sensor_write_reg(client,0x39, 0xbd);
	sensor_write_reg(client,0x3a, 0xc8);
	sensor_write_reg(client,0x3b, 0xd9);
	sensor_write_reg(client,0x3c, 0xe8);
	sensor_write_reg(client,0x3d, 0xf5);
	sensor_write_reg(client,0x3e, 0xff);
	sensor_write_reg(client,0x03, 0x17);//page 17
	sensor_write_reg(client,0xc4, 0x3c);
	sensor_write_reg(client,0xc5, 0x32);
//	dprintk("9------------------------------------hi704 sensor init!");
	sensor_write_reg(client,0x03, 0x20);//page 20
	sensor_write_reg(client,0x10, 0x0c);
	sensor_write_reg(client,0x11, 0x04);
	sensor_write_reg(client,0x20, 0x01);
	sensor_write_reg(client,0x28, 0x27);//
	sensor_write_reg(client,0x29, 0xa1);
	sensor_write_reg(client,0x2a, 0xf0);
	sensor_write_reg(client,0x2b, 0x34);
	sensor_write_reg(client,0x2c, 0x2b);
	sensor_write_reg(client,0x30, 0xf8); //new add by peter
	sensor_write_reg(client,0x39, 0x22);
	sensor_write_reg(client,0x3a, 0xde);
	sensor_write_reg(client,0x3b, 0x22);
	sensor_write_reg(client,0x3c, 0xde);
	sensor_write_reg(client,0x60, 0x95);
	sensor_write_reg(client,0x68, 0x3c);
	sensor_write_reg(client,0x69, 0x64);
	sensor_write_reg(client,0x6a, 0x28);
	sensor_write_reg(client,0x6b, 0xc8);
	sensor_write_reg(client,0x70, 0x42);
	sensor_write_reg(client,0x76, 0x22);
	sensor_write_reg(client,0x77, 0x02);
	sensor_write_reg(client,0x78, 0x12);
	sensor_write_reg(client,0x79, 0x27);
	sensor_write_reg(client,0x7a, 0x23);
	sensor_write_reg(client,0x7c, 0x1d);
	sensor_write_reg(client,0x7d, 0x22);
//50Hz
	sensor_write_reg(client,0x83, 0x00); //;;ExpNormal 30Fps
	sensor_write_reg(client,0x84, 0xc3);
	sensor_write_reg(client,0x85, 0x4b);
	sensor_write_reg(client,0x86, 0x00);//ExpMin
	sensor_write_reg(client,0x87, 0xfa);
//50Hz 8fps
	//sensor_write_reg(client,0x88, 0x02);
	//sensor_write_reg(client,0x89, 0x49);
	//sensor_write_reg(client,0x8a, 0xf0);
//    sensor_write_reg(client,0x88, 0x01);//ExpMin 10Fps
//	sensor_write_reg(client,0x89, 0x24);
//	sensor_write_reg(client,0x8a, 0xf8);
	sensor_write_reg(client,0x8b, 0x3a);//EXP100
	sensor_write_reg(client,0x8c, 0x98);
	sensor_write_reg(client,0x8d, 0x30);//EXP120
	sensor_write_reg(client,0x8e, 0xd4);
	sensor_write_reg(client,0x91, 0x02);
	sensor_write_reg(client,0x92, 0xdc);
	sensor_write_reg(client,0x93, 0x6c);
	sensor_write_reg(client,0x94, 0x01);
	sensor_write_reg(client,0x95, 0xb7);
	sensor_write_reg(client,0x96, 0x74);
	sensor_write_reg(client,0x98, 0x8c);
	sensor_write_reg(client,0x99, 0x23);
	sensor_write_reg(client,0x9c, 0x0b);//new add by peter
	sensor_write_reg(client,0x9d, 0x3b);
	sensor_write_reg(client,0x9e, 0x00);
	sensor_write_reg(client,0x9f, 0xfa);
//	sensor_write_reg(client,0xb0, 0x1a);//AG
	sensor_write_reg(client,0xb1, 0x14);//AGMIN
	sensor_write_reg(client,0xb2, 0x50);//AGMAX 80
//	sensor_write_reg(client,0xb3, 0x1a);//AGLVL
	sensor_write_reg(client,0xb4, 0x14);//AGTH1
	sensor_write_reg(client,0xb5, 0x38);//AGTH2
	sensor_write_reg(client,0xb6, 0x26);//AGBTH1
	sensor_write_reg(client,0xb7, 0x20);//AGBTH2
	sensor_write_reg(client,0xb8, 0x1d);//AGBTH3
	sensor_write_reg(client,0xb9, 0x1b);//AGBTH4
	sensor_write_reg(client,0xba, 0x1a);//AGBTH5
	sensor_write_reg(client,0xbb, 0x19);//AGBTH6
	sensor_write_reg(client,0xbc, 0x19);//AGBTH7
	sensor_write_reg(client,0xbd, 0x18);//AGBTH8
	sensor_write_reg(client,0xc0, 0x1a);//PGA_Sky_gain
	sensor_write_reg(client,0xc3, 0x48);// 60
	sensor_write_reg(client,0xc4, 0x48);// 58
	sensor_write_reg(client,0x03, 0x22);//page 22
	sensor_write_reg(client,0x10, 0xe2);
	sensor_write_reg(client,0x11, 0x26);
	sensor_write_reg(client,0x21, 0x40);
	sensor_write_reg(client,0x30, 0x80);
	sensor_write_reg(client,0x31, 0x80);
	sensor_write_reg(client,0x38, 0x12);
	sensor_write_reg(client,0x39, 0x33);
	sensor_write_reg(client,0x40, 0xf0);
	sensor_write_reg(client,0x41, 0x33);
	sensor_write_reg(client,0x42, 0x33);
	sensor_write_reg(client,0x43, 0xf3);
	sensor_write_reg(client,0x44, 0x55);
	sensor_write_reg(client,0x45, 0x44);
	sensor_write_reg(client,0x46, 0x02);
	sensor_write_reg(client,0x80, 0x45);//R Gain
	sensor_write_reg(client,0x81, 0x20);//G Gain
	sensor_write_reg(client,0x82, 0x48);//B Gain
	sensor_write_reg(client,0x83, 0x52);//RMAX
	sensor_write_reg(client,0x84, 0x1b);//RMIN
	sensor_write_reg(client,0x85, 0x50);//BMAX
	sensor_write_reg(client,0x86, 0x25);//BMIN
	sensor_write_reg(client,0x87, 0x4d);//RMAXB
	sensor_write_reg(client,0x88, 0x38);//RMINB
	sensor_write_reg(client,0x89, 0x3e);//BMAXB
	sensor_write_reg(client,0x8a, 0x02);//BMINB
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
	sensor_write_reg(client,0x03, 0x22);
	sensor_write_reg(client,0x10, 0xfb);
//	sensor_write_reg(client,0x10, 0xea);//AWB ON
//	sensor_write_reg(client,0x03, 0x20);//page 20
//	sensor_write_reg(client,0x10, 0x9c);//AE ON
//	sensor_write_reg(client,0x01, 0xf0);
//      sensor_write_reg(client,0x03,0x13);
//      sensor_write_reg(client,0x20,0x02);
//      sensor_write_reg(client,0x21,0x02);
//      sensor_write_reg(client,0x90,0x02);
//      sensor_write_reg(client,0x91,0x02);
	sensor_write_reg(client,0x03, 0x00);//Page 0
	sensor_write_reg(client,0x11, 0x91);//rotate
	//sensor_write_reg(client,0x03, 0x02);//Page 2
	//sensor_write_reg(client,0x1a, 0x21);
	sensor_write_reg(client,0x03,0x20);
	sensor_write_reg(client,0x10,0x9c);
	sensor_write_reg(client,0x01,0xf0);
//	dprintk("10-----------------------------------hi704 sensor init!");
}   /* hi704_Write_Sensor_Initial_Setting */

int hi704_set_switch(struct i2c_client *client,int width,int height)
{

//	dprintk("----------------------------------------------------hi704 set switch");

	if(width == 352 && height == 288)
	{  
		sensor_write_reg(client,0x03, 0x00);
		sensor_write_reg(client,0x01, 0xf1);
		sensor_write_reg(client,0x12, 0x04);
		sensor_write_reg(client,0x20, 0x00);
		sensor_write_reg(client,0x21, 0x00);
		sensor_write_reg(client,0x22, 0x00);
		sensor_write_reg(client,0x23, 0x1a);
		sensor_write_reg(client,0x24, 0x01);
		sensor_write_reg(client,0x25, 0xe0);
		sensor_write_reg(client,0x26, 0x02);
		sensor_write_reg(client,0x27, 0x4c);
		sensor_write_reg(client,0x03, 0x18);
      	sensor_write_reg(client,0x10, 0x03);
		sensor_write_reg(client,0x11, 0x00);
		sensor_write_reg(client,0x12, 0x00);
		sensor_write_reg(client,0x13, 0x00);
		sensor_write_reg(client,0x14, 0x02);
		sensor_write_reg(client,0x15, 0x58);
		sensor_write_reg(client,0x16, 0x48);
		sensor_write_reg(client,0x17, 0x0d);
		sensor_write_reg(client,0x18, 0x11);
		sensor_write_reg(client,0x19, 0x0d);
		sensor_write_reg(client,0x1a, 0x55);
		sensor_write_reg(client,0x03, 0x00);
		sensor_write_reg(client,0x01, 0xf0);
	dprintk("---------------------------------------hi704 preview 352x288!");
	}  //fish mark that trim size is 352x280 

	else if(width == 176 && height == 144)
	{
		sensor_write_reg(client,0x03, 0x00);
		sensor_write_reg(client,0x01, 0xf1);
		sensor_write_reg(client,0x12, 0x04);
		sensor_write_reg(client,0x20, 0x00);
		sensor_write_reg(client,0x21, 0x00);
		sensor_write_reg(client,0x22, 0x00);
		sensor_write_reg(client,0x23, 0x1a);
		sensor_write_reg(client,0x24, 0x01);
		sensor_write_reg(client,0x25, 0xe0);
		sensor_write_reg(client,0x26, 0x02);
		sensor_write_reg(client,0x27, 0x4c);
		sensor_write_reg(client,0x03, 0x18);
      	sensor_write_reg(client,0x10, 0x03);
		sensor_write_reg(client,0x11, 0x00);
		sensor_write_reg(client,0x12, 0x00);
		sensor_write_reg(client,0x13, 0x00);
		sensor_write_reg(client,0x14, 0x02);
		sensor_write_reg(client,0x15, 0x2c);
		sensor_write_reg(client,0x16, 0x24);
		sensor_write_reg(client,0x17, 0x19);
		sensor_write_reg(client,0x18, 0x90);
		sensor_write_reg(client,0x19, 0x1a);
		sensor_write_reg(client,0x1a, 0xaa);
		sensor_write_reg(client,0x03, 0x00);
		sensor_write_reg(client,0x01, 0xf0);
		dprintk("---------------------------------------hi704 preview 176x144!");
	}
	else
	{
//		hi704_init_setting(client);
//		hi704_set_preview_mode(client);
		sensor_write_reg(client,0x03, 0x00);//Page 0
		sensor_write_reg(client,0x01, 0xf1);
		sensor_write_reg(client,0x12, 0x00);
		sensor_write_reg(client,0x20, 0x00);
		sensor_write_reg(client,0x21, 0x04);
		sensor_write_reg(client,0x22, 0x00);
		sensor_write_reg(client,0x23, 0x04);
		sensor_write_reg(client,0x24, 0x01);
		sensor_write_reg(client,0x25, 0xe0);
		sensor_write_reg(client,0x26, 0x02);
		sensor_write_reg(client,0x27, 0x80);
		sensor_write_reg(client,0x03, 0x18);
		sensor_write_reg(client,0x10, 0x00);
		sensor_write_reg(client,0x03, 0x00);
		sensor_write_reg(client,0x01, 0xf0);

//		sensor_write_reg(client,0x03, 0x00);
//		sensor_write_reg(client,0x11, 0x91);
		dprintk("---------------------------------------hi704 preview 640x480!");
	}

	return 0;
}


