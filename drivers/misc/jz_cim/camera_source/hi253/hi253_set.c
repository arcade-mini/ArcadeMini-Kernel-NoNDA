#include "../../jz_cim_core.h"
#include <asm/jzsoc.h>
#include "../../jz_sensor.h"
#include <linux/i2c.h>

#include "hi253_set.h"

#define hi253_DEBUG
//#undef DEBUG

#ifdef hi253_DEBUG
#define dprintk(x...)   do{printk("hi253---\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

void hi253_preview_set_reg(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x01, 0xf1);
	sensor_write_reg(client,0x10, 0x11); // 800*600 
	sensor_write_reg(client,0x01, 0x50);
	dprintk("--------------------hi253_preview_set_reg 800x600\n");
}

void hi253_capture_set_reg(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x01, 0xf1);
	sensor_write_reg(client,0x10, 0x00); // 1600*1200 
	sensor_write_reg(client,0x01, 0x50);
	dprintk("--------------------hi253_capture_set_reg 1600x1200\n");
}

void hi253_capture_set(struct i2c_client *client)
{
	dprintk("--------------------hi253_capture_set\n");
}

void hi253_size_switch(struct i2c_client *client,int width,int height,int mode)
{
	dprintk("--------------------size_switch\n");

	if(width == 1600 && height == 1200)
	{
		sensor_write_reg(client,0x03, 0x00);
		sensor_write_reg(client,0x10, 0x00);
		sensor_write_reg(client,0x03, 0x18);
		sensor_write_reg(client,0x10, 0x00); //close scaling
	}	
	else if(width == 1280 && height == 1024)
	{
		sensor_write_reg(client,0x03, 0x00);
		sensor_write_reg(client,0x10, 0x00);
		sensor_write_reg(client,0x03, 0x18);
		sensor_write_reg(client,0x12, 0x20);
		sensor_write_reg(client,0x10, 0x07);
		sensor_write_reg(client,0x11, 0x00);
		sensor_write_reg(client,0x20, 0x06);
		sensor_write_reg(client,0x21, 0x40);
		sensor_write_reg(client,0x22, 0x04);
		sensor_write_reg(client,0x23, 0xb0);
		sensor_write_reg(client,0x24, 0x00);
		sensor_write_reg(client,0x25, 0xa0);
		sensor_write_reg(client,0x26, 0x00);
		sensor_write_reg(client,0x27, 0x58);
		sensor_write_reg(client,0x28, 0x05);
		sensor_write_reg(client,0x29, 0xa0);
		sensor_write_reg(client,0x2a, 0x04);
		sensor_write_reg(client,0x2b, 0x58);
		sensor_write_reg(client,0x2c, 0x08);
		sensor_write_reg(client,0x2d, 0x00);
		sensor_write_reg(client,0x2e, 0x08);
		sensor_write_reg(client,0x2f, 0x00);
		sensor_write_reg(client,0x30, 0x2c);
		dprintk("--------------------size_switch 1280x1024\n");
	}  
	else if(width == 1024 && height == 768)
	{
		sensor_write_reg(client,0x03, 0x00);
		sensor_write_reg(client,0x10, 0x00);
		sensor_write_reg(client,0x03, 0x18);
		sensor_write_reg(client,0x12, 0x20);
		sensor_write_reg(client,0x10, 0x07);
		sensor_write_reg(client,0x11, 0x00);
		sensor_write_reg(client,0x20, 0x05);
		sensor_write_reg(client,0x21, 0x20);
		sensor_write_reg(client,0x22, 0x03);
		sensor_write_reg(client,0x23, 0xd8);
		sensor_write_reg(client,0x24, 0x00);
		sensor_write_reg(client,0x25, 0x90);
		sensor_write_reg(client,0x26, 0x00);
		sensor_write_reg(client,0x27, 0x6c);
		sensor_write_reg(client,0x28, 0x04);
		sensor_write_reg(client,0x29, 0x90);
		sensor_write_reg(client,0x2a, 0x03);
		sensor_write_reg(client,0x2b, 0x6c);
		sensor_write_reg(client,0x2c, 0x09);
		sensor_write_reg(client,0x2d, 0xc1);
		sensor_write_reg(client,0x2e, 0x09);
		sensor_write_reg(client,0x2f, 0xc1);
		sensor_write_reg(client,0x30, 0x56);
		dprintk("--------------------size_switch 1024x768\n");
	}
	else if(width == 800 && height == 600)
	{
		sensor_write_reg(client,0x03, 0x00);
		sensor_write_reg(client,0x10, 0x11);
		sensor_write_reg(client,0x03, 0x18);
		sensor_write_reg(client,0x10, 0x00);
		dprintk("--------------------size_switch 800x600\n");
	}
	else if(width == 640 && height == 480)
	{
		sensor_write_reg(client,0x03, 0x00);
		sensor_write_reg(client,0x10, 0x00);
		sensor_write_reg(client,0x03, 0x18);
		sensor_write_reg(client,0x10, 0x07);
		sensor_write_reg(client,0x11, 0x00);
		sensor_write_reg(client,0x12, 0x20);
		sensor_write_reg(client,0x20, 0x02);
		sensor_write_reg(client,0x21, 0x84); //80);
		sensor_write_reg(client,0x22, 0x01);
		sensor_write_reg(client,0x23, 0xe0);
		sensor_write_reg(client,0x24, 0x00);
		sensor_write_reg(client,0x25, 0x04); //00);
		sensor_write_reg(client,0x26, 0x00);
		sensor_write_reg(client,0x27, 0x00);
		sensor_write_reg(client,0x28, 0x02);
		sensor_write_reg(client,0x29, 0x84); //80);
		sensor_write_reg(client,0x2a, 0x01);
		sensor_write_reg(client,0x2b, 0xe0);
		sensor_write_reg(client,0x2c, 0x14);
		sensor_write_reg(client,0x2d, 0x00);
		sensor_write_reg(client,0x2e, 0x14);
		sensor_write_reg(client,0x2f, 0x00);
		sensor_write_reg(client,0x30, 0x66);
		dprintk("--------------------size_switch 640x480\n");
	}
	else if(width == 352 && height == 288)
	{
		sensor_write_reg(client,0x03, 0x00);
		sensor_write_reg(client,0x10, 0x00);
		sensor_write_reg(client,0x03, 0x18);
		sensor_write_reg(client,0x12, 0x20);
		sensor_write_reg(client,0x10, 0x07);
		sensor_write_reg(client,0x11, 0x00);
		sensor_write_reg(client,0x20, 0x01);
		sensor_write_reg(client,0x21, 0x80);
		sensor_write_reg(client,0x22, 0x01);
		sensor_write_reg(client,0x23, 0x20);
		sensor_write_reg(client,0x24, 0x00);
		sensor_write_reg(client,0x25, 0x10);
		sensor_write_reg(client,0x26, 0x00);
		sensor_write_reg(client,0x27, 0x00);
		sensor_write_reg(client,0x28, 0x01);
		sensor_write_reg(client,0x29, 0x70);
		sensor_write_reg(client,0x2a, 0x01);
		sensor_write_reg(client,0x2b, 0x20);
		sensor_write_reg(client,0x2c, 0x21);
		sensor_write_reg(client,0x2d, 0x55);
		sensor_write_reg(client,0x2e, 0x21);
		sensor_write_reg(client,0x2f, 0x55);
		sensor_write_reg(client,0x30, 0x4b);
		dprintk("--------------------size_switch 352x288\n");
	}  
	else if(width == 176 && height == 144)
	{
		sensor_write_reg(client,0x03, 0x00);
		sensor_write_reg(client,0x10, 0x00);
		sensor_write_reg(client,0x03, 0x18);
		sensor_write_reg(client,0x12, 0x20);
		sensor_write_reg(client,0x10, 0x07);
		sensor_write_reg(client,0x11, 0x00);
		sensor_write_reg(client,0x20, 0x00);
		sensor_write_reg(client,0x21, 0xc0);
		sensor_write_reg(client,0x22, 0x00);
		sensor_write_reg(client,0x23, 0x90);
		sensor_write_reg(client,0x24, 0x00);
		sensor_write_reg(client,0x25, 0x08);
		sensor_write_reg(client,0x26, 0x00);
		sensor_write_reg(client,0x27, 0x00);
		sensor_write_reg(client,0x28, 0x00);
		sensor_write_reg(client,0x29, 0xb8);
		sensor_write_reg(client,0x2a, 0x00);
		sensor_write_reg(client,0x2b, 0x90);
		sensor_write_reg(client,0x2c, 0x42);
		sensor_write_reg(client,0x2d, 0xaa);
		sensor_write_reg(client,0x2e, 0x42);
		sensor_write_reg(client,0x2f, 0xaa);
		sensor_write_reg(client,0x30, 0x2c);
		dprintk("--------------------size_switch 176x144\n");
	}  
	else
		return;
//	mdelay(500);
}

void hi253_set_night_reg(struct i2c_client *client,int enable)
{
	if (!enable)
	{
		dprintk("--------------------!hi253_set_nightmode\n");   
	}
	else
	{
		dprintk("--------------------hi253_set_nightmode\n");	
	}
}   /* hi253_NightMode */

void hi253_set_ab_50hz(struct i2c_client *client)
{
	sensor_write_reg(client,0x03,0x20);
	sensor_write_reg(client,0x10,0x9c);
	dprintk("--------------------hi253_set_ab_50hz\n");	
}

void hi253_set_ab_60hz(struct i2c_client *client)
{
	sensor_write_reg(client,0x03,0x20);
	sensor_write_reg(client,0x10,0x8c);
	dprintk("--------------------hi253_set_ab_60hz\n");	
}

void hi253_set_effect_normal(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x10);
	sensor_write_reg(client,0x11, 0x03);
	sensor_write_reg(client,0x12, 0x30);
	sensor_write_reg(client,0x13, 0x02);
	sensor_write_reg(client,0x44, 0x80);
	sensor_write_reg(client,0x45, 0x80);
	dprintk("--------------------hi253_set_effect_normal\n");	
}

void hi253_set_effect_grayscale(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x10);
	sensor_write_reg(client,0x11, 0x03);
	sensor_write_reg(client,0x12, 0x03);
	sensor_write_reg(client,0x13, 0x02);
	sensor_write_reg(client,0x40, 0x00);
	sensor_write_reg(client,0x44, 0x80);
	sensor_write_reg(client,0x45, 0x80);
	dprintk("--------------------hi253_set_effect_grayscale\n");	
}

void hi253_set_effect_sepia(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x10);
	sensor_write_reg(client,0x11, 0x03);
	sensor_write_reg(client,0x12, 0x33);
	sensor_write_reg(client,0x13, 0x00);
	sensor_write_reg(client,0x44, 0x70);
	sensor_write_reg(client,0x45, 0x98);	
	dprintk("--------------------hi253_set_effect_sepia\n");	
}

void hi253_set_effect_colorinv(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x10);
	sensor_write_reg(client,0x11, 0x03);
	sensor_write_reg(client,0x12, 0x08);
	sensor_write_reg(client,0x13, 0x02);
	sensor_write_reg(client,0x14, 0x00);
	dprintk("--------------------hi253_set_effect_colorinv\n");	
}

void hi253_set_effect_sepiagreen(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x10);
	sensor_write_reg(client,0x11, 0x03);
	sensor_write_reg(client,0x12, 0x03);
	sensor_write_reg(client,0x40, 0x00);
	sensor_write_reg(client,0x13, 0x02);
	sensor_write_reg(client,0x44, 0x30);
	sensor_write_reg(client,0x45, 0x50);
	dprintk("--------------------hi253_set_effect_sepiagreen\n");

}

void hi253_set_effect_sepiablue(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x10);
	sensor_write_reg(client,0x11, 0x03);
	sensor_write_reg(client,0x12, 0x03);
	sensor_write_reg(client,0x40, 0x00);
	sensor_write_reg(client,0x13, 0x02);
	sensor_write_reg(client,0x44, 0xb0);
	sensor_write_reg(client,0x45, 0x40);
	dprintk("--------------------hi253_set_effect_sepiablue\n");
}

void hi253_set_wb_auto(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x22);			
	sensor_write_reg(client,0x11, 0x2e);				
	//sensor_write_reg(client,0x80, 0x38);
	//sensor_write_reg(client,0x82, 0x38);				
	sensor_write_reg(client,0x83, 0x6e);
	sensor_write_reg(client,0x84, 0x14);
	sensor_write_reg(client,0x85, 0x69);
	sensor_write_reg(client,0x86, 0x14);				
	dprintk("--------------------hi253_set_wb_auto\n");
}

void hi253_set_wb_cloud(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x22);
	sensor_write_reg(client,0x11, 0x28);
	sensor_write_reg(client,0x80, 0x71);
	sensor_write_reg(client,0x82, 0x2b);
	sensor_write_reg(client,0x83, 0x72);
	sensor_write_reg(client,0x84, 0x70);
	sensor_write_reg(client,0x85, 0x2b);
	sensor_write_reg(client,0x86, 0x28);
	dprintk("--------------------hi253_set_wb_cloud\n");
}

void hi253_set_wb_daylight(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x22);
	sensor_write_reg(client,0x11, 0x28);		  
	sensor_write_reg(client,0x80, 0x59);
	sensor_write_reg(client,0x82, 0x29);
	sensor_write_reg(client,0x83, 0x60);
	sensor_write_reg(client,0x84, 0x50);
	sensor_write_reg(client,0x85, 0x2f);
	sensor_write_reg(client,0x86, 0x23);
	dprintk("--------------------hi253_set_wb_daylight\n");
}

void hi253_set_wb_incandescence(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x22);
	sensor_write_reg(client,0x11, 0x28);		  
	sensor_write_reg(client,0x80, 0x29);
	sensor_write_reg(client,0x82, 0x54);
	sensor_write_reg(client,0x83, 0x2e);
	sensor_write_reg(client,0x84, 0x23);
	sensor_write_reg(client,0x85, 0x58);
	sensor_write_reg(client,0x86, 0x4f);
	dprintk("--------------------hi253_set_wb_incandescence\n");	               
}

void hi253_set_wb_fluorescent(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x22);
	sensor_write_reg(client,0x11, 0x28);
	sensor_write_reg(client,0x80, 0x41);
	sensor_write_reg(client,0x82, 0x42);
	sensor_write_reg(client,0x83, 0x44);
	sensor_write_reg(client,0x84, 0x34);
	sensor_write_reg(client,0x85, 0x46);
	sensor_write_reg(client,0x86, 0x3a);	
	dprintk("--------------------hi253_set_wb_fluorescent\n");	                      
}

void hi253_set_wb_tungsten(struct i2c_client *client)
{
	sensor_write_reg(client,0x03, 0x22);
	sensor_write_reg(client,0x80, 0x24);
	sensor_write_reg(client,0x82, 0x58);
	sensor_write_reg(client,0x83, 0x27);
	sensor_write_reg(client,0x84, 0x22);
	sensor_write_reg(client,0x85, 0x58);
	sensor_write_reg(client,0x86, 0x52);                                       
	dprintk("--------------------hi253_set_wb_tungsten\n");	
}

void hi253_init_setting(struct i2c_client *client)
{
	dprintk("--------------------hi253_init_setting  1\n");	
	/////// Start Sleep ///////
	sensor_write_reg(client,0x01, 0xf9); //sleep on
	sensor_write_reg(client,0x08, 0x0f); //Hi-Z on
	sensor_write_reg(client,0x01, 0xf8); //sleep off

	sensor_write_reg(client,0x03, 0x00); // Dummy 750us START
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00); // Dummy 750us END

	sensor_write_reg(client,0x0e, 0x03); //PLL On
	sensor_write_reg(client,0x0e, 0x73); //PLLx2

	sensor_write_reg(client,0x03, 0x00); // Dummy 750us START
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00); // Dummy 750us END

	sensor_write_reg(client,0x0e, 0x00); //PLL off
	sensor_write_reg(client,0x01, 0xf1); //sleep on
	sensor_write_reg(client,0x08, 0x00); //Hi-Z off

	sensor_write_reg(client,0x01, 0xf3);
	sensor_write_reg(client,0x01, 0xf1);

	// PAGE 20
	sensor_write_reg(client,0x03, 0x20); //page 20
	sensor_write_reg(client,0x10, 0x1c); //ae off

	// PAGE 22
	sensor_write_reg(client,0x03, 0x22); //page 22
	sensor_write_reg(client,0x10, 0x69); //awb off

	//Initial Start
	/////// PAGE 0 START ///////
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x10, 0x11); // Sub1/2_Preview2 Mode_H binning
	sensor_write_reg(client,0x11, 0x90);
	sensor_write_reg(client,0x12, 0x00);

	sensor_write_reg(client,0x0b, 0xaa); // ESD Check Register
	sensor_write_reg(client,0x0c, 0xaa); // ESD Check Register
	sensor_write_reg(client,0x0d, 0xaa); // ESD Check Register

	sensor_write_reg(client,0x20, 0x00); // Windowing start point Y
	sensor_write_reg(client,0x21, 0x04);
	sensor_write_reg(client,0x22, 0x00); // Windowing start point X
	sensor_write_reg(client,0x23, 0x03);//07

	sensor_write_reg(client,0x24, 0x04);
	sensor_write_reg(client,0x25, 0xb0);
	sensor_write_reg(client,0x26, 0x06);
	sensor_write_reg(client,0x27, 0x40); // WINROW END

	sensor_write_reg(client,0x40, 0x01); //Hblank 408
	sensor_write_reg(client,0x41, 0x68); //98
	sensor_write_reg(client,0x42, 0x00); //Vblank 20
	sensor_write_reg(client,0x43, 0x14);

	sensor_write_reg(client,0x45, 0x04);
	sensor_write_reg(client,0x46, 0x18);
	sensor_write_reg(client,0x47, 0xd8);

	//BLC
	sensor_write_reg(client,0x80, 0x2e);
	sensor_write_reg(client,0x81, 0x7e);
	sensor_write_reg(client,0x82, 0x90);
	sensor_write_reg(client,0x83, 0x00);
	sensor_write_reg(client,0x84, 0x0c);
	sensor_write_reg(client,0x85, 0x00);
	sensor_write_reg(client,0x90, 0x0a); //BLC_TIME_TH_ON
	sensor_write_reg(client,0x91, 0x0a); //BLC_TIME_TH_OFF 
	sensor_write_reg(client,0x92, 0xd8); //BLC_AG_TH_ON
	sensor_write_reg(client,0x93, 0xd0); //BLC_AG_TH_OFF
	sensor_write_reg(client,0x94, 0x75);
	sensor_write_reg(client,0x95, 0x70);
	sensor_write_reg(client,0x96, 0xdc);
	sensor_write_reg(client,0x97, 0xfe);
	sensor_write_reg(client,0x98, 0x38);

	//OutDoor  BLC
	sensor_write_reg(client,0x99, 0x43);
	sensor_write_reg(client,0x9a, 0x43);
	sensor_write_reg(client,0x9b, 0x43);
	sensor_write_reg(client,0x9c, 0x43);

	//Dark BLC
	sensor_write_reg(client,0xa0, 0x00);
	sensor_write_reg(client,0xa2, 0x00);
	sensor_write_reg(client,0xa4, 0x00);
	sensor_write_reg(client,0xa6, 0x00);

	//Normal BLC
	sensor_write_reg(client,0xa8, 0x43);
	sensor_write_reg(client,0xaa, 0x43);
	sensor_write_reg(client,0xac, 0x43);
	sensor_write_reg(client,0xae, 0x43);

	/////// PAGE 2 START ///////
	sensor_write_reg(client,0x03, 0x02);
	sensor_write_reg(client,0x12, 0x03);
	sensor_write_reg(client,0x13, 0x03);
	sensor_write_reg(client,0x16, 0x00);
	sensor_write_reg(client,0x17, 0x8C);
	sensor_write_reg(client,0x18, 0x4c); //Double_AG off
	sensor_write_reg(client,0x19, 0x00);
	sensor_write_reg(client,0x1a, 0x39); //ADC400->560
	sensor_write_reg(client,0x1c, 0x09);
	sensor_write_reg(client,0x1d, 0x40);
	sensor_write_reg(client,0x1e, 0x30);
	sensor_write_reg(client,0x1f, 0x10);

	sensor_write_reg(client,0x20, 0x77);
	sensor_write_reg(client,0x21, 0xde);
	sensor_write_reg(client,0x22, 0xa7);
	sensor_write_reg(client,0x23, 0x30); //CLAMP
	sensor_write_reg(client,0x27, 0x3c);
	sensor_write_reg(client,0x2b, 0x80);
	sensor_write_reg(client,0x2e, 0x11);
	sensor_write_reg(client,0x2f, 0xa1);
	sensor_write_reg(client,0x30, 0x05); //For Hi-253 never no change 0x05

	sensor_write_reg(client,0x50, 0x20);
	sensor_write_reg(client,0x52, 0x01);
	sensor_write_reg(client,0x55, 0x1c);
	sensor_write_reg(client,0x56, 0x11);
	sensor_write_reg(client,0x5d, 0xa2);
	sensor_write_reg(client,0x5e, 0x5a);

	sensor_write_reg(client,0x60, 0x87);
	sensor_write_reg(client,0x61, 0x99);
	sensor_write_reg(client,0x62, 0x88);
	sensor_write_reg(client,0x63, 0x97);
	sensor_write_reg(client,0x64, 0x88);
	sensor_write_reg(client,0x65, 0x97);

	sensor_write_reg(client,0x67, 0x0c);
	sensor_write_reg(client,0x68, 0x0c);
	sensor_write_reg(client,0x69, 0x0c);

	sensor_write_reg(client,0x72, 0x89);
	sensor_write_reg(client,0x73, 0x96);
	sensor_write_reg(client,0x74, 0x89);
	sensor_write_reg(client,0x75, 0x96);
	sensor_write_reg(client,0x76, 0x89);
	sensor_write_reg(client,0x77, 0x96);

	sensor_write_reg(client,0x7c, 0x85);
	sensor_write_reg(client,0x7d, 0xaf);
	sensor_write_reg(client,0x80, 0x01);
	sensor_write_reg(client,0x81, 0x7f);
	sensor_write_reg(client,0x82, 0x13);

	sensor_write_reg(client,0x83, 0x24);
	sensor_write_reg(client,0x84, 0x7d);
	sensor_write_reg(client,0x85, 0x81);
	sensor_write_reg(client,0x86, 0x7d);
	sensor_write_reg(client,0x87, 0x81);

	sensor_write_reg(client,0x92, 0x48);
	sensor_write_reg(client,0x93, 0x54);
	sensor_write_reg(client,0x94, 0x7d);
	sensor_write_reg(client,0x95, 0x81);
	sensor_write_reg(client,0x96, 0x7d);
	sensor_write_reg(client,0x97, 0x81);

	sensor_write_reg(client,0xa0, 0x02);
	sensor_write_reg(client,0xa1, 0x7b);
	sensor_write_reg(client,0xa2, 0x02);
	sensor_write_reg(client,0xa3, 0x7b);
	sensor_write_reg(client,0xa4, 0x7b);
	sensor_write_reg(client,0xa5, 0x02);
	sensor_write_reg(client,0xa6, 0x7b);
	sensor_write_reg(client,0xa7, 0x02);

	sensor_write_reg(client,0xa8, 0x85);
	sensor_write_reg(client,0xa9, 0x8c);
	sensor_write_reg(client,0xaa, 0x85);
	sensor_write_reg(client,0xab, 0x8c);
	sensor_write_reg(client,0xac, 0x10);
	sensor_write_reg(client,0xad, 0x16);
	sensor_write_reg(client,0xae, 0x10);
	sensor_write_reg(client,0xaf, 0x16);

	sensor_write_reg(client,0xb0, 0x99);
	sensor_write_reg(client,0xb1, 0xa3);
	sensor_write_reg(client,0xb2, 0xa4);
	sensor_write_reg(client,0xb3, 0xae);
	sensor_write_reg(client,0xb4, 0x9b);
	sensor_write_reg(client,0xb5, 0xa2);
	sensor_write_reg(client,0xb6, 0xa6);
	sensor_write_reg(client,0xb7, 0xac);
	sensor_write_reg(client,0xb8, 0x9b);
	sensor_write_reg(client,0xb9, 0x9f);
	sensor_write_reg(client,0xba, 0xa6);
	sensor_write_reg(client,0xbb, 0xaa);
	sensor_write_reg(client,0xbc, 0x9b);
	sensor_write_reg(client,0xbd, 0x9f);
	sensor_write_reg(client,0xbe, 0xa6);
	sensor_write_reg(client,0xbf, 0xaa);

	sensor_write_reg(client,0xc4, 0x2c);
	sensor_write_reg(client,0xc5, 0x43);
	sensor_write_reg(client,0xc6, 0x63);
	sensor_write_reg(client,0xc7, 0x79);

	sensor_write_reg(client,0xc8, 0x2d);
	sensor_write_reg(client,0xc9, 0x42);
	sensor_write_reg(client,0xca, 0x2d);
	sensor_write_reg(client,0xcb, 0x42);
	sensor_write_reg(client,0xcc, 0x64);
	sensor_write_reg(client,0xcd, 0x78);
	sensor_write_reg(client,0xce, 0x64);
	sensor_write_reg(client,0xcf, 0x78);

	sensor_write_reg(client,0xd0, 0x0a);
	sensor_write_reg(client,0xd1, 0x09);
	sensor_write_reg(client,0xd4, 0x0a); //DCDC_TIME_TH_ON
	sensor_write_reg(client,0xd5, 0x0a); //DCDC_TIME_TH_OFF 
	sensor_write_reg(client,0xd6, 0xd8); //DCDC_AG_TH_ON
	sensor_write_reg(client,0xd7, 0xd0); //DCDC_AG_TH_OFF
	sensor_write_reg(client,0xe0, 0xc4);
	sensor_write_reg(client,0xe1, 0xc4);
	sensor_write_reg(client,0xe2, 0xc4);
	sensor_write_reg(client,0xe3, 0xc4);
	sensor_write_reg(client,0xe4, 0x00);
	sensor_write_reg(client,0xe8, 0x80);
	sensor_write_reg(client,0xe9, 0x40);
	sensor_write_reg(client,0xea, 0x7f);

	/////// PAGE 3 ///////
	sensor_write_reg(client,0x03, 0x03);
	sensor_write_reg(client,0x10, 0x10);

	/////// PAGE 10 START ///////
	sensor_write_reg(client,0x03, 0x10);
	sensor_write_reg(client,0x10, 0x03); // CrYCbY // For Demoset 0x03
	sensor_write_reg(client,0x12, 0x30);
	sensor_write_reg(client,0x20, 0x00);

	sensor_write_reg(client,0x30, 0x00);
	sensor_write_reg(client,0x31, 0x00);
	sensor_write_reg(client,0x32, 0x00);
	sensor_write_reg(client,0x33, 0x00);

	sensor_write_reg(client,0x34, 0x30);
	sensor_write_reg(client,0x35, 0x00);
	sensor_write_reg(client,0x36, 0x00);
	sensor_write_reg(client,0x38, 0x00);
	sensor_write_reg(client,0x3e, 0x58);
	sensor_write_reg(client,0x3f, 0x00);

	sensor_write_reg(client,0x40, 0x80); // YOFS
	sensor_write_reg(client,0x41, 0x00); // DYOFS

	sensor_write_reg(client,0x60, 0x67);
	sensor_write_reg(client,0x61, 0x7c); //7e //8e //88 //80
	sensor_write_reg(client,0x62, 0x7c); //7e //8e //88 //80
	sensor_write_reg(client,0x63, 0x50); //Double_AG 50->30
	sensor_write_reg(client,0x64, 0x41);

	sensor_write_reg(client,0x66, 0x42);
	sensor_write_reg(client,0x67, 0x20);

	sensor_write_reg(client,0x6a, 0x80); //8a
	sensor_write_reg(client,0x6b, 0x84); //74
	sensor_write_reg(client,0x6c, 0x80); //7e //7a
	sensor_write_reg(client,0x6d, 0x80); //8e

	//Don't touch//////////////////////////
	//sensor_write_reg(client,0x72, 0x84);
	//sensor_write_reg(client,0x76, 0x19);
	//sensor_write_reg(client,0x73, 0x70);
	//sensor_write_reg(client,0x74, 0x68);
	//sensor_write_reg(client,0x75, 0x60); // white protection ON
	//sensor_write_reg(client,0x77, 0x0e); //08 //0a
	//sensor_write_reg(client,0x78, 0x2a); //20
	//sensor_write_reg(client,0x79, 0x08);
	////////////////////////////////////////

	/////// PAGE 11 START ///////
	sensor_write_reg(client,0x03, 0x11);
	sensor_write_reg(client,0x10, 0x7f);
	sensor_write_reg(client,0x11, 0x40);
	sensor_write_reg(client,0x12, 0x0a); // Blue Max-Filter Delete
	sensor_write_reg(client,0x13, 0xbb);

	sensor_write_reg(client,0x26, 0x31); // Double_AG 31->20
	sensor_write_reg(client,0x27, 0x34); // Double_AG 34->22
	sensor_write_reg(client,0x28, 0x0f);
	sensor_write_reg(client,0x29, 0x10);
	sensor_write_reg(client,0x2b, 0x30);
	sensor_write_reg(client,0x2c, 0x32);

	//Out2 D-LPF th
	sensor_write_reg(client,0x30, 0x70);
	sensor_write_reg(client,0x31, 0x10);
	sensor_write_reg(client,0x32, 0x58);
	sensor_write_reg(client,0x33, 0x09);
	sensor_write_reg(client,0x34, 0x06);
	sensor_write_reg(client,0x35, 0x03);

	//Out1 D-LPF th
	sensor_write_reg(client,0x36, 0x70);
	sensor_write_reg(client,0x37, 0x18);
	sensor_write_reg(client,0x38, 0x58);
	sensor_write_reg(client,0x39, 0x09);
	sensor_write_reg(client,0x3a, 0x06);
	sensor_write_reg(client,0x3b, 0x03);

	//Indoor D-LPF th
	sensor_write_reg(client,0x3c, 0x80);
	sensor_write_reg(client,0x3d, 0x18);
	sensor_write_reg(client,0x3e, 0xa0); //80
	sensor_write_reg(client,0x3f, 0x0c);
	sensor_write_reg(client,0x40, 0x09);
	sensor_write_reg(client,0x41, 0x06);

	sensor_write_reg(client,0x42, 0x80);
	sensor_write_reg(client,0x43, 0x18);
	sensor_write_reg(client,0x44, 0xa0); //80
	sensor_write_reg(client,0x45, 0x12);
	sensor_write_reg(client,0x46, 0x10);
	sensor_write_reg(client,0x47, 0x10);

	sensor_write_reg(client,0x48, 0x90);
	sensor_write_reg(client,0x49, 0x40);
	sensor_write_reg(client,0x4a, 0x80);
	sensor_write_reg(client,0x4b, 0x13);
	sensor_write_reg(client,0x4c, 0x10);
	sensor_write_reg(client,0x4d, 0x11);

	sensor_write_reg(client,0x4e, 0x80);
	sensor_write_reg(client,0x4f, 0x30);
	sensor_write_reg(client,0x50, 0x80);
	sensor_write_reg(client,0x51, 0x13);
	sensor_write_reg(client,0x52, 0x10);
	sensor_write_reg(client,0x53, 0x13);

	sensor_write_reg(client,0x54, 0x11);
	sensor_write_reg(client,0x55, 0x17);
	sensor_write_reg(client,0x56, 0x20);
	sensor_write_reg(client,0x57, 0x01);
	sensor_write_reg(client,0x58, 0x00);
	sensor_write_reg(client,0x59, 0x00);

	sensor_write_reg(client,0x5a, 0x1f); //18
	sensor_write_reg(client,0x5b, 0x00);
	sensor_write_reg(client,0x5c, 0x00);

	sensor_write_reg(client,0x60, 0x3f);
	sensor_write_reg(client,0x62, 0x60);
	sensor_write_reg(client,0x70, 0x06);

	/////// PAGE 12 START ///////
	sensor_write_reg(client,0x03, 0x12);
	sensor_write_reg(client,0x20, 0x0f);
	sensor_write_reg(client,0x21, 0x0f);

	sensor_write_reg(client,0x25, 0x00); //0x30

	sensor_write_reg(client,0x28, 0x00);
	sensor_write_reg(client,0x29, 0x00);
	sensor_write_reg(client,0x2a, 0x00);

	sensor_write_reg(client,0x30, 0x50);
	sensor_write_reg(client,0x31, 0x18);
	sensor_write_reg(client,0x32, 0x32);
	sensor_write_reg(client,0x33, 0x40);
	sensor_write_reg(client,0x34, 0x50);
	sensor_write_reg(client,0x35, 0x70);
	sensor_write_reg(client,0x36, 0xa0);

	//Out2 th
	sensor_write_reg(client,0x40, 0xa0);
	sensor_write_reg(client,0x41, 0x40);
	sensor_write_reg(client,0x42, 0xa0);
	sensor_write_reg(client,0x43, 0x90);
	sensor_write_reg(client,0x44, 0x90);
	sensor_write_reg(client,0x45, 0x80);

	//Out1 th
	sensor_write_reg(client,0x46, 0xb0);
	sensor_write_reg(client,0x47, 0x55);
	sensor_write_reg(client,0x48, 0xa0);
	sensor_write_reg(client,0x49, 0x90);
	sensor_write_reg(client,0x4a, 0x90);
	sensor_write_reg(client,0x4b, 0x80);

	//Indoor th
	sensor_write_reg(client,0x4c, 0xb0);
	sensor_write_reg(client,0x4d, 0x40);
	sensor_write_reg(client,0x4e, 0x90);
	sensor_write_reg(client,0x4f, 0x90);
	sensor_write_reg(client,0x50, 0xa0);
	sensor_write_reg(client,0x51, 0x80);

	//Dark1 th
	sensor_write_reg(client,0x52, 0xb0);
	sensor_write_reg(client,0x53, 0x60);
	sensor_write_reg(client,0x54, 0xc0);
	sensor_write_reg(client,0x55, 0xc0);
	sensor_write_reg(client,0x56, 0xc0);
	sensor_write_reg(client,0x57, 0x80);

	//Dark2 th
	sensor_write_reg(client,0x58, 0x90);
	sensor_write_reg(client,0x59, 0x40);
	sensor_write_reg(client,0x5a, 0xd0);
	sensor_write_reg(client,0x5b, 0xd0);
	sensor_write_reg(client,0x5c, 0xe0);
	sensor_write_reg(client,0x5d, 0x80);

	//Dark3 th
	sensor_write_reg(client,0x5e, 0x88);
	sensor_write_reg(client,0x5f, 0x40);
	sensor_write_reg(client,0x60, 0xe0);
	sensor_write_reg(client,0x61, 0xe0);
	sensor_write_reg(client,0x62, 0xe0);
	sensor_write_reg(client,0x63, 0x80);

	sensor_write_reg(client,0x70, 0x15);
	sensor_write_reg(client,0x71, 0x01); //Don't Touch register

	sensor_write_reg(client,0x72, 0x18);
	sensor_write_reg(client,0x73, 0x01); //Don't Touch register

	sensor_write_reg(client,0x74, 0x25);
	sensor_write_reg(client,0x75, 0x15);

	sensor_write_reg(client,0x80, 0x20);
	sensor_write_reg(client,0x81, 0x40);
	sensor_write_reg(client,0x82, 0x65);
	sensor_write_reg(client,0x85, 0x1a);
	sensor_write_reg(client,0x88, 0x00);
	sensor_write_reg(client,0x89, 0x00);
	sensor_write_reg(client,0x90, 0x5d); //For Preview

	//Dont Touch register
	sensor_write_reg(client,0xD0, 0x0c);
	sensor_write_reg(client,0xD1, 0x80);
	sensor_write_reg(client,0xD2, 0x67);
	sensor_write_reg(client,0xD3, 0x00);
	sensor_write_reg(client,0xD4, 0x00);
	sensor_write_reg(client,0xD5, 0x02);
	sensor_write_reg(client,0xD6, 0xff);
	sensor_write_reg(client,0xD7, 0x18);
	//End
	sensor_write_reg(client,0x3b, 0x06);
	sensor_write_reg(client,0x3c, 0x06);

	sensor_write_reg(client,0xc5, 0x00);//55->48
	sensor_write_reg(client,0xc6, 0x00);//48->40

	/////// PAGE 13 START ///////
	sensor_write_reg(client,0x03, 0x13);
	//Edge
	sensor_write_reg(client,0x10, 0xcb);
	sensor_write_reg(client,0x11, 0x7b);
	sensor_write_reg(client,0x12, 0x07);
	sensor_write_reg(client,0x14, 0x00);

	sensor_write_reg(client,0x20, 0x15);
	sensor_write_reg(client,0x21, 0x13);
	sensor_write_reg(client,0x22, 0x33);
	sensor_write_reg(client,0x23, 0x05);
	sensor_write_reg(client,0x24, 0x09);

	sensor_write_reg(client,0x25, 0x0a);

	sensor_write_reg(client,0x26, 0x18);
	sensor_write_reg(client,0x27, 0x30);
	sensor_write_reg(client,0x29, 0x12);
	sensor_write_reg(client,0x2a, 0x50);

	//Low clip th
	sensor_write_reg(client,0x2b, 0x02);
	sensor_write_reg(client,0x2c, 0x02);
	sensor_write_reg(client,0x25, 0x06);
	sensor_write_reg(client,0x2d, 0x0c);
	sensor_write_reg(client,0x2e, 0x12);
	sensor_write_reg(client,0x2f, 0x12);

	//Out2 Edge
	sensor_write_reg(client,0x50, 0x10);
	sensor_write_reg(client,0x51, 0x14);
	sensor_write_reg(client,0x52, 0x12);
	sensor_write_reg(client,0x53, 0x0c);
	sensor_write_reg(client,0x54, 0x0f);
	sensor_write_reg(client,0x55, 0x0c);

	//Out1 Edge
	sensor_write_reg(client,0x56, 0x10);
	sensor_write_reg(client,0x57, 0x13);
	sensor_write_reg(client,0x58, 0x12);
	sensor_write_reg(client,0x59, 0x0c);
	sensor_write_reg(client,0x5a, 0x0f);
	sensor_write_reg(client,0x5b, 0x0c);

	//Indoor Edge
	sensor_write_reg(client,0x5c, 0x0a);
	sensor_write_reg(client,0x5d, 0x0b);
	sensor_write_reg(client,0x5e, 0x0a);
	sensor_write_reg(client,0x5f, 0x08);
	sensor_write_reg(client,0x60, 0x09);
	sensor_write_reg(client,0x61, 0x08);

	//Dark1 Edge
	sensor_write_reg(client,0x62, 0x08);
	sensor_write_reg(client,0x63, 0x08);
	sensor_write_reg(client,0x64, 0x08);
	sensor_write_reg(client,0x65, 0x06);
	sensor_write_reg(client,0x66, 0x06);
	sensor_write_reg(client,0x67, 0x06);

	//Dark2 Edge
	sensor_write_reg(client,0x68, 0x07);
	sensor_write_reg(client,0x69, 0x07);
	sensor_write_reg(client,0x6a, 0x07);
	sensor_write_reg(client,0x6b, 0x05);
	sensor_write_reg(client,0x6c, 0x05);
	sensor_write_reg(client,0x6d, 0x05);

	//Dark3 Edge
	sensor_write_reg(client,0x6e, 0x07);
	sensor_write_reg(client,0x6f, 0x07);
	sensor_write_reg(client,0x70, 0x07);
	sensor_write_reg(client,0x71, 0x05);
	sensor_write_reg(client,0x72, 0x05);
	sensor_write_reg(client,0x73, 0x05);

	//2DY
	sensor_write_reg(client,0x80, 0xfd);
	sensor_write_reg(client,0x81, 0x1f);
	sensor_write_reg(client,0x82, 0x05);
	sensor_write_reg(client,0x83, 0x31);

	sensor_write_reg(client,0x90, 0x05);
	sensor_write_reg(client,0x91, 0x05);
	sensor_write_reg(client,0x92, 0x33);
	sensor_write_reg(client,0x93, 0x30);
	sensor_write_reg(client,0x94, 0x03);
	sensor_write_reg(client,0x95, 0x14);
	sensor_write_reg(client,0x97, 0x20);
	sensor_write_reg(client,0x99, 0x20);

	sensor_write_reg(client,0xa0, 0x01);
	sensor_write_reg(client,0xa1, 0x02);
	sensor_write_reg(client,0xa2, 0x01);
	sensor_write_reg(client,0xa3, 0x02);
	sensor_write_reg(client,0xa4, 0x05);
	sensor_write_reg(client,0xa5, 0x05);
	sensor_write_reg(client,0xa6, 0x07);
	sensor_write_reg(client,0xa7, 0x08);
	sensor_write_reg(client,0xa8, 0x07);
	sensor_write_reg(client,0xa9, 0x08);
	sensor_write_reg(client,0xaa, 0x07);
	sensor_write_reg(client,0xab, 0x08);

	//Out2 
	sensor_write_reg(client,0xb0, 0x22);
	sensor_write_reg(client,0xb1, 0x2a);
	sensor_write_reg(client,0xb2, 0x28);
	sensor_write_reg(client,0xb3, 0x22);
	sensor_write_reg(client,0xb4, 0x2a);
	sensor_write_reg(client,0xb5, 0x28);

	//Out1 
	sensor_write_reg(client,0xb6, 0x22);
	sensor_write_reg(client,0xb7, 0x2a);
	sensor_write_reg(client,0xb8, 0x28);
	sensor_write_reg(client,0xb9, 0x22);
	sensor_write_reg(client,0xba, 0x2a);
	sensor_write_reg(client,0xbb, 0x28);

	//Indoor 
	sensor_write_reg(client,0xbc, 0x25);
	sensor_write_reg(client,0xbd, 0x2a);
	sensor_write_reg(client,0xbe, 0x27);
	sensor_write_reg(client,0xbf, 0x25);
	sensor_write_reg(client,0xc0, 0x2a);
	sensor_write_reg(client,0xc1, 0x27);

	//Dark1
	sensor_write_reg(client,0xc2, 0x1e);
	sensor_write_reg(client,0xc3, 0x24);
	sensor_write_reg(client,0xc4, 0x20);
	sensor_write_reg(client,0xc5, 0x1e);
	sensor_write_reg(client,0xc6, 0x24);
	sensor_write_reg(client,0xc7, 0x20);

	//Dark2
	sensor_write_reg(client,0xc8, 0x18);
	sensor_write_reg(client,0xc9, 0x20);
	sensor_write_reg(client,0xca, 0x1e);
	sensor_write_reg(client,0xcb, 0x18);
	sensor_write_reg(client,0xcc, 0x20);
	sensor_write_reg(client,0xcd, 0x1e);

	//Dark3 
	sensor_write_reg(client,0xce, 0x18);
	sensor_write_reg(client,0xcf, 0x20);
	sensor_write_reg(client,0xd0, 0x1e);
	sensor_write_reg(client,0xd1, 0x18);
	sensor_write_reg(client,0xd2, 0x20);
	sensor_write_reg(client,0xd3, 0x1e);

	/////// PAGE 14 START ///////
	sensor_write_reg(client,0x03, 0x14);
	sensor_write_reg(client,0x10, 0x11);

	sensor_write_reg(client,0x14, 0x80); // GX
	sensor_write_reg(client,0x15, 0x80); // GY
	sensor_write_reg(client,0x16, 0x80); // RX
	sensor_write_reg(client,0x17, 0x80); // RY
	sensor_write_reg(client,0x18, 0x80); // BX
	sensor_write_reg(client,0x19, 0x80); // BY

	sensor_write_reg(client,0x20, 0x60); //X 60 //a0
	sensor_write_reg(client,0x21, 0x80); //Y

	sensor_write_reg(client,0x22, 0x80);
	sensor_write_reg(client,0x23, 0x80);
	sensor_write_reg(client,0x24, 0x80);

	sensor_write_reg(client,0x30, 0xc8);
	sensor_write_reg(client,0x31, 0x2b);
	sensor_write_reg(client,0x32, 0x00);
	sensor_write_reg(client,0x33, 0x00);
	sensor_write_reg(client,0x34, 0x90);

	sensor_write_reg(client,0x40, 0x48); //31
	sensor_write_reg(client,0x50, 0x34); //23 //32
	sensor_write_reg(client,0x60, 0x29); //1a //27
	sensor_write_reg(client,0x70, 0x34); //23 //32

	/////// PAGE 15 START ///////
	sensor_write_reg(client,0x03, 0x15);
	sensor_write_reg(client,0x10, 0x0f);

	//Rstep H 16
	//Rstep L 14
	sensor_write_reg(client,0x14, 0x42); //CMCOFSGH_Day //4c
	sensor_write_reg(client,0x15, 0x32); //CMCOFSGM_CWF //3c
	sensor_write_reg(client,0x16, 0x24); //CMCOFSGL_A //2e
	sensor_write_reg(client,0x17, 0x2f); //CMC SIGN

	//CMC_Default_CWF
	sensor_write_reg(client,0x30, 0x8f);
	sensor_write_reg(client,0x31, 0x59);
	sensor_write_reg(client,0x32, 0x0a);
	sensor_write_reg(client,0x33, 0x15);
	sensor_write_reg(client,0x34, 0x5b);
	sensor_write_reg(client,0x35, 0x06);
	sensor_write_reg(client,0x36, 0x07);
	sensor_write_reg(client,0x37, 0x40);
	sensor_write_reg(client,0x38, 0x87); //86

	//CMC OFS L_A
	sensor_write_reg(client,0x40, 0x92);
	sensor_write_reg(client,0x41, 0x1b);
	sensor_write_reg(client,0x42, 0x89);
	sensor_write_reg(client,0x43, 0x81);
	sensor_write_reg(client,0x44, 0x00);
	sensor_write_reg(client,0x45, 0x01);
	sensor_write_reg(client,0x46, 0x89);
	sensor_write_reg(client,0x47, 0x9e);
	sensor_write_reg(client,0x48, 0x28);

	//sensor_write_reg(client,0x40, 0x93);
	//sensor_write_reg(client,0x41, 0x1c);
	//sensor_write_reg(client,0x42, 0x89);
	//sensor_write_reg(client,0x43, 0x82);
	//sensor_write_reg(client,0x44, 0x01);
	//sensor_write_reg(client,0x45, 0x01);
	//sensor_write_reg(client,0x46, 0x8a);
	//sensor_write_reg(client,0x47, 0x9d);
	//sensor_write_reg(client,0x48, 0x28);

	//CMC POFS H_DAY
	sensor_write_reg(client,0x50, 0x02);
	sensor_write_reg(client,0x51, 0x82);
	sensor_write_reg(client,0x52, 0x00);
	sensor_write_reg(client,0x53, 0x07);
	sensor_write_reg(client,0x54, 0x11);
	sensor_write_reg(client,0x55, 0x98);
	sensor_write_reg(client,0x56, 0x00);
	sensor_write_reg(client,0x57, 0x0b);
	sensor_write_reg(client,0x58, 0x8b);

	sensor_write_reg(client,0x80, 0x03);
	sensor_write_reg(client,0x85, 0x40);
	sensor_write_reg(client,0x87, 0x02);
	sensor_write_reg(client,0x88, 0x00);
	sensor_write_reg(client,0x89, 0x00);
	sensor_write_reg(client,0x8a, 0x00);

	/////// PAGE 16 START ///////
	sensor_write_reg(client,0x03, 0x16);
	sensor_write_reg(client,0x10, 0x31);
	sensor_write_reg(client,0x18, 0x5e);// Double_AG 5e->37
	sensor_write_reg(client,0x19, 0x5d);// Double_AG 5e->36
	sensor_write_reg(client,0x1a, 0x0e);
	sensor_write_reg(client,0x1b, 0x01);
	sensor_write_reg(client,0x1c, 0xdc);
	sensor_write_reg(client,0x1d, 0xfe);

	//GMA Default
	sensor_write_reg(client,0x30, 0x00);
	sensor_write_reg(client,0x31, 0x0a);
	sensor_write_reg(client,0x32, 0x1f);
	sensor_write_reg(client,0x33, 0x33);
	sensor_write_reg(client,0x34, 0x53);
	sensor_write_reg(client,0x35, 0x6c);
	sensor_write_reg(client,0x36, 0x81);
	sensor_write_reg(client,0x37, 0x94);
	sensor_write_reg(client,0x38, 0xa4);
	sensor_write_reg(client,0x39, 0xb3);
	sensor_write_reg(client,0x3a, 0xc0);
	sensor_write_reg(client,0x3b, 0xcb);
	sensor_write_reg(client,0x3c, 0xd5);
	sensor_write_reg(client,0x3d, 0xde);
	sensor_write_reg(client,0x3e, 0xe6);
	sensor_write_reg(client,0x3f, 0xee);
	sensor_write_reg(client,0x40, 0xf5);
	sensor_write_reg(client,0x41, 0xfc);
	sensor_write_reg(client,0x42, 0xff);

	sensor_write_reg(client,0x50, 0x00);
	sensor_write_reg(client,0x51, 0x09);
	sensor_write_reg(client,0x52, 0x1f);
	sensor_write_reg(client,0x53, 0x37);
	sensor_write_reg(client,0x54, 0x5b);
	sensor_write_reg(client,0x55, 0x76);
	sensor_write_reg(client,0x56, 0x8d);
	sensor_write_reg(client,0x57, 0xa1);
	sensor_write_reg(client,0x58, 0xb2);
	sensor_write_reg(client,0x59, 0xbe);
	sensor_write_reg(client,0x5a, 0xc9);
	sensor_write_reg(client,0x5b, 0xd2);
	sensor_write_reg(client,0x5c, 0xdb);
	sensor_write_reg(client,0x5d, 0xe3);
	sensor_write_reg(client,0x5e, 0xeb);
	sensor_write_reg(client,0x5f, 0xf0);
	sensor_write_reg(client,0x60, 0xf5);
	sensor_write_reg(client,0x61, 0xf7);
	sensor_write_reg(client,0x62, 0xf8);

	sensor_write_reg(client,0x70, 0x00);
	sensor_write_reg(client,0x71, 0x08);
	sensor_write_reg(client,0x72, 0x17);
	sensor_write_reg(client,0x73, 0x2f);
	sensor_write_reg(client,0x74, 0x53);
	sensor_write_reg(client,0x75, 0x6c);
	sensor_write_reg(client,0x76, 0x81);
	sensor_write_reg(client,0x77, 0x94);
	sensor_write_reg(client,0x78, 0xa4);
	sensor_write_reg(client,0x79, 0xb3);
	sensor_write_reg(client,0x7a, 0xc0);
	sensor_write_reg(client,0x7b, 0xcb);
	sensor_write_reg(client,0x7c, 0xd5);
	sensor_write_reg(client,0x7d, 0xde);
	sensor_write_reg(client,0x7e, 0xe6);
	sensor_write_reg(client,0x7f, 0xee);
	sensor_write_reg(client,0x80, 0xf4);
	sensor_write_reg(client,0x81, 0xfa);
	sensor_write_reg(client,0x82, 0xff);

	/////// PAGE 17 START ///////
	sensor_write_reg(client,0x03, 0x17);
	sensor_write_reg(client,0x10, 0xf7);

	/////// PAGE 20 START ///////
	sensor_write_reg(client,0x03, 0x20);
	sensor_write_reg(client,0x11, 0x1c);
	sensor_write_reg(client,0x18, 0x30);
	sensor_write_reg(client,0x1a, 0x08);
	sensor_write_reg(client,0x20, 0x01); //05_lowtemp Y Mean off
	sensor_write_reg(client,0x21, 0x30);
	sensor_write_reg(client,0x22, 0x10);
	sensor_write_reg(client,0x23, 0x00);
	sensor_write_reg(client,0x24, 0x00); //Uniform Scene Off

	sensor_write_reg(client,0x28, 0xe7);
	sensor_write_reg(client,0x29, 0x0d); //20100305 ad->0d
	sensor_write_reg(client,0x2a, 0xff);
	sensor_write_reg(client,0x2b, 0x04); //f4->Adaptive off

	sensor_write_reg(client,0x2c, 0xc2);
	sensor_write_reg(client,0x2d, 0xcf);  //fe->AE Speed option
	sensor_write_reg(client,0x2e, 0x33);
	sensor_write_reg(client,0x30, 0x78); //f8
	sensor_write_reg(client,0x32, 0x03);
	sensor_write_reg(client,0x33, 0x2e);
	sensor_write_reg(client,0x34, 0x30);
	sensor_write_reg(client,0x35, 0xd4);
	sensor_write_reg(client,0x36, 0xfe);
	sensor_write_reg(client,0x37, 0x32);
	sensor_write_reg(client,0x38, 0x04);

	sensor_write_reg(client,0x39, 0x22); //AE_escapeC10
	sensor_write_reg(client,0x3a, 0xde); //AE_escapeC11

	sensor_write_reg(client,0x3b, 0x22); //AE_escapeC1
	sensor_write_reg(client,0x3c, 0xde); //AE_escapeC2

	sensor_write_reg(client,0x50, 0x45);
	sensor_write_reg(client,0x51, 0x88);

	sensor_write_reg(client,0x56, 0x03);
	sensor_write_reg(client,0x57, 0xf7);
	sensor_write_reg(client,0x58, 0x14);
	sensor_write_reg(client,0x59, 0x88);
	sensor_write_reg(client,0x5a, 0x04);

	//New Weight For Samsung
	//sensor_write_reg(client,0x60, 0xaa);
	//sensor_write_reg(client,0x61, 0xaa);
	//sensor_write_reg(client,0x62, 0xaa);
	//sensor_write_reg(client,0x63, 0xaa);
	//sensor_write_reg(client,0x64, 0xaa);
	//sensor_write_reg(client,0x65, 0xaa);
	//sensor_write_reg(client,0x66, 0xab);
	//sensor_write_reg(client,0x67, 0xEa);
	//sensor_write_reg(client,0x68, 0xab);
	//sensor_write_reg(client,0x69, 0xEa);
	//sensor_write_reg(client,0x6a, 0xaa);
	//sensor_write_reg(client,0x6b, 0xaa);
	//sensor_write_reg(client,0x6c, 0xaa);
	//sensor_write_reg(client,0x6d, 0xaa);
	//sensor_write_reg(client,0x6e, 0xaa);
	//sensor_write_reg(client,0x6f, 0xaa);

	sensor_write_reg(client,0x60, 0x55); // AEWGT1
	sensor_write_reg(client,0x61, 0x55); // AEWGT2
	sensor_write_reg(client,0x62, 0x6a); // AEWGT3
	sensor_write_reg(client,0x63, 0xa9); // AEWGT4
	sensor_write_reg(client,0x64, 0x6a); // AEWGT5
	sensor_write_reg(client,0x65, 0xa9); // AEWGT6
	sensor_write_reg(client,0x66, 0x6a); // AEWGT7
	sensor_write_reg(client,0x67, 0xa9); // AEWGT8
	sensor_write_reg(client,0x68, 0x6b); // AEWGT9
	sensor_write_reg(client,0x69, 0xe9); // AEWGT10
	sensor_write_reg(client,0x6a, 0x6a); // AEWGT11
	sensor_write_reg(client,0x6b, 0xa9); // AEWGT12
	sensor_write_reg(client,0x6c, 0x6a); // AEWGT13
	sensor_write_reg(client,0x6d, 0xa9); // AEWGT14
	sensor_write_reg(client,0x6e, 0x55); // AEWGT15
	sensor_write_reg(client,0x6f, 0x55); // AEWGT16

	sensor_write_reg(client,0x70, 0x76); //6e
	sensor_write_reg(client,0x71, 0x00); //82(+8)->+0

	// haunting control
	sensor_write_reg(client,0x76, 0x43);
	sensor_write_reg(client,0x77, 0xe2); //04 //f2
	sensor_write_reg(client,0x78, 0x23); //Yth1
	sensor_write_reg(client,0x79, 0x42); //Yth2 //46
	sensor_write_reg(client,0x7a, 0x23); //23
	sensor_write_reg(client,0x7b, 0x22); //22
	sensor_write_reg(client,0x7d, 0x23);

	sensor_write_reg(client,0x83, 0x01); //EXP Normal 33.33 fps 
	sensor_write_reg(client,0x84, 0x5f); 
	sensor_write_reg(client,0x85, 0x00); 

	sensor_write_reg(client,0x86, 0x02); //EXPMin 5859.38 fps
	sensor_write_reg(client,0x87, 0x00); 

	//sensor_write_reg(client,0x88, 0x04); //EXP Max 10.00 fps 
	//sensor_write_reg(client,0x89, 0x92); 
	//sensor_write_reg(client,0x8a, 0x00); 

	sensor_write_reg(client,0x88, 0x02); //EXP Max 15.00 fps 
	sensor_write_reg(client,0x89, 0xbe); 
	sensor_write_reg(client,0x8a, 0x00); 

	sensor_write_reg(client,0x8B, 0x75); //EXP100 
	sensor_write_reg(client,0x8C, 0x00); 
	sensor_write_reg(client,0x8D, 0x61); //EXP120 
	sensor_write_reg(client,0x8E, 0x00); 

	sensor_write_reg(client,0x9c, 0x18); //EXP Limit 488.28 fps 
	sensor_write_reg(client,0x9d, 0x00); 
	sensor_write_reg(client,0x9e, 0x02); //EXP Unit 
	sensor_write_reg(client,0x9f, 0x00); 

	//AE_Middle Time option
	//sensor_write_reg(client,0xa0, 0x03);
	//sensor_write_reg(client,0xa1, 0xa9);
	//sensor_write_reg(client,0xa2, 0x80);

	sensor_write_reg(client,0xb0, 0x18);
	sensor_write_reg(client,0xb1, 0x14); //ADC 400->560
	sensor_write_reg(client,0xb2, 0xe0); //d0
	sensor_write_reg(client,0xb3, 0x18);
	sensor_write_reg(client,0xb4, 0x1a);
	sensor_write_reg(client,0xb5, 0x44);
	sensor_write_reg(client,0xb6, 0x2f);
	sensor_write_reg(client,0xb7, 0x28);
	sensor_write_reg(client,0xb8, 0x25);
	sensor_write_reg(client,0xb9, 0x22);
	sensor_write_reg(client,0xba, 0x21);
	sensor_write_reg(client,0xbb, 0x20);
	sensor_write_reg(client,0xbc, 0x1f);
	sensor_write_reg(client,0xbd, 0x1f);

	//AE_Adaptive Time option
	//sensor_write_reg(client,0xc0, 0x10);
	//sensor_write_reg(client,0xc1, 0x2b);
	//sensor_write_reg(client,0xc2, 0x2b);
	//sensor_write_reg(client,0xc3, 0x2b);
	//sensor_write_reg(client,0xc4, 0x08);

	sensor_write_reg(client,0xc8, 0x80);
	sensor_write_reg(client,0xc9, 0x40);

	/////// PAGE 22 START ///////
	sensor_write_reg(client,0x03, 0x22);
	sensor_write_reg(client,0x10, 0xfd);
	sensor_write_reg(client,0x11, 0x2e);
	sensor_write_reg(client,0x19, 0x01); // Low On //
	sensor_write_reg(client,0x20, 0x30);
	sensor_write_reg(client,0x21, 0x80);
	sensor_write_reg(client,0x24, 0x01);
	//sensor_write_reg(client,0x25, 0x00); //7f New Lock Cond & New light stable

	sensor_write_reg(client,0x30, 0x80);
	sensor_write_reg(client,0x31, 0x80);
	sensor_write_reg(client,0x38, 0x11);
	sensor_write_reg(client,0x39, 0x34);

	sensor_write_reg(client,0x40, 0xf4);
	sensor_write_reg(client,0x41, 0x55); //44
	sensor_write_reg(client,0x42, 0x33); //43

	sensor_write_reg(client,0x43, 0xf6);
	sensor_write_reg(client,0x44, 0x55); //44
	sensor_write_reg(client,0x45, 0x44); //33

	sensor_write_reg(client,0x46, 0x00);
	sensor_write_reg(client,0x50, 0xb2);
	sensor_write_reg(client,0x51, 0x81);
	sensor_write_reg(client,0x52, 0x98);

	sensor_write_reg(client,0x80, 0x40); //3e
	sensor_write_reg(client,0x81, 0x20);
	sensor_write_reg(client,0x82, 0x3e);

	sensor_write_reg(client,0x83, 0x5e); //5e
	sensor_write_reg(client,0x84, 0x1e); //24
	sensor_write_reg(client,0x85, 0x5e); //54 //56 //5a
	sensor_write_reg(client,0x86, 0x22); //24 //22

	sensor_write_reg(client,0x87, 0x49);
	sensor_write_reg(client,0x88, 0x39);
	sensor_write_reg(client,0x89, 0x37); //38
	sensor_write_reg(client,0x8a, 0x28); //2a

	sensor_write_reg(client,0x8b, 0x41); //47
	sensor_write_reg(client,0x8c, 0x39); 
	sensor_write_reg(client,0x8d, 0x34); 
	sensor_write_reg(client,0x8e, 0x28); //2c

	sensor_write_reg(client,0x8f, 0x53); //4e
	sensor_write_reg(client,0x90, 0x52); //4d
	sensor_write_reg(client,0x91, 0x51); //4c
	sensor_write_reg(client,0x92, 0x4e); //4a
	sensor_write_reg(client,0x93, 0x4a); //46
	sensor_write_reg(client,0x94, 0x45);
	sensor_write_reg(client,0x95, 0x3d);
	sensor_write_reg(client,0x96, 0x31);
	sensor_write_reg(client,0x97, 0x28);
	sensor_write_reg(client,0x98, 0x24);
	sensor_write_reg(client,0x99, 0x20);
	sensor_write_reg(client,0x9a, 0x20);

	sensor_write_reg(client,0x9b, 0x77);
	sensor_write_reg(client,0x9c, 0x77);
	sensor_write_reg(client,0x9d, 0x48);
	sensor_write_reg(client,0x9e, 0x38);
	sensor_write_reg(client,0x9f, 0x30);

	sensor_write_reg(client,0xa0, 0x60);
	sensor_write_reg(client,0xa1, 0x34);
	sensor_write_reg(client,0xa2, 0x6f);
	sensor_write_reg(client,0xa3, 0xff);

	sensor_write_reg(client,0xa4, 0x14); //1500fps
	sensor_write_reg(client,0xa5, 0x2c); // 700fps
	sensor_write_reg(client,0xa6, 0xcf);

	sensor_write_reg(client,0xad, 0x40);
	sensor_write_reg(client,0xae, 0x4a);

	sensor_write_reg(client,0xaf, 0x28);  // low temp Rgain
	sensor_write_reg(client,0xb0, 0x26);  // low temp Rgain

	sensor_write_reg(client,0xb1, 0x00); //0x20 -> 0x00 0405 modify
	sensor_write_reg(client,0xb4, 0xea);
	sensor_write_reg(client,0xb8, 0xa0); //a2: b-2, R+2  //b4 B-3, R+4 lowtemp
	sensor_write_reg(client,0xb9, 0x00);

	/////// PAGE 20 ///////
	sensor_write_reg(client,0x03, 0x20);
	sensor_write_reg(client,0x10, 0x8c);

	// PAGE 20
	sensor_write_reg(client,0x03, 0x20); //page 20
	sensor_write_reg(client,0x10, 0x9c); //ae off

	// PAGE 22
	sensor_write_reg(client,0x03, 0x22); //page 22
	sensor_write_reg(client,0x10, 0xe9); //awb off

	// PAGE 0
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x0e, 0x03); //PLL On
	sensor_write_reg(client,0x0e, 0x73); //PLLx2

	sensor_write_reg(client,0x03, 0x00); // Dummy 750us
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);
	sensor_write_reg(client,0x03, 0x00);

	sensor_write_reg(client,0x03, 0x00); // Page 0
	sensor_write_reg(client,0x01, 0x50); // Sleep Off
}   /* hi253_Write_Sensor_Initial_Setting */

