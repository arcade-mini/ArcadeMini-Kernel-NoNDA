#include "../../jz_cim_core.h"
#include "../../jz_sensor.h"
#include <linux/i2c.h>
#include <asm/jzsoc.h>

#define siv120b_DEBUG
#ifdef siv120b_DEBUG
#define dprintk(x...)   do{printk("siv120b-\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

void set_size_640x480(struct i2c_client *client,int mode)
{
	sensor_write_reg(client,0x00,0x00);
	sensor_write_reg(client,0x05,0x06);
}  

void set_size_320x240(struct i2c_client *client,int mode)
{
	sensor_write_reg(client,0x00,0x00);
	sensor_write_reg(client,0x05,0x05);
}  

void size_switch(struct i2c_client *client,int width,int height,int setmode)
{
	dprintk("%dx%d - mode(%d)",width,height,setmode);

	if(width == 640&& height == 480)
	{
		set_size_640x480(client, setmode);
		return;
	}
	else if(width == 320 && height == 240)
	{
		set_size_320x240(client, setmode);
		return;
	}
	else
		return;
}

void siv120b_reset(void);
void siv120b_init_setting(struct i2c_client *client)
{
	siv120b_reset();
	//[init]
	sensor_write_reg(client,0x00,0x00); //
	sensor_write_reg(client,0x04,0x01); //	#mirror image
	sensor_write_reg(client,0x13,0x17); //	#anti_black sun
	sensor_write_reg(client,0x16,0xcf); //	#0xb6

	//60Hz flicker
	sensor_write_reg(client,0x20,0x00); //	#P_BNKT  
	sensor_write_reg(client,0x21,0x01); //	#P_HBNKT 
	sensor_write_reg(client,0x22,0x01); //	#P_ROWFIL
	sensor_write_reg(client,0x23,0x01); //	#P_VBNKT 

	//50Hz flicker
	//sensor_write_reg(client,0x20,0x00); //	#P_BNKT  
	//sensor_write_reg(client,0x21,0x01); //	#P_HBNKT 
	//sensor_write_reg(client,0x22,0x01); //	#P_ROWFIL
	//sensor_write_reg(client,0x23,0x65); //	#P_VBNKT 
	
	sensor_write_reg(client,0x40,0x00); //	#0x8b
	sensor_write_reg(client,0x41,0x00); //  	#0x96
	sensor_write_reg(client,0x42,0x00); //  	#0xda
	sensor_write_reg(client,0x43,0x00); //	#0x83

	//AE Register setting
	sensor_write_reg(client,0x00,0x01); //              
	sensor_write_reg(client,0x11,0x0c); //0x0c_0113   # 10fps at lowlux            
	sensor_write_reg(client,0x12,0x68); //0x78_0113	# D65 target 0x74
	sensor_write_reg(client,0x13,0x68); //0x78_0113	# CWF target 0x74
	sensor_write_reg(client,0x14,0x68); //0x78_0113	# A target   0x74
	sensor_write_reg(client,0x1e,0x00);	//	# ini gain
	
	//60Hz flicker
	sensor_write_reg(client,0x34,0x7d);
	//50Hz flicker
	//sensor_write_reg(client,0x34,0x96);
	                    
	sensor_write_reg(client,0x40,0x38); // 0x48_0113	# Max x6            

	sensor_write_reg(client,0x41,0x28); //	#AG_TOP1	0x28
	sensor_write_reg(client,0x42,0x28); //	#AG_TOP0	0x28
	sensor_write_reg(client,0x43,0x08); //	#AG_MIN1	0x08
	sensor_write_reg(client,0x44,0x08); //	#AG_MIN0	0x08
	sensor_write_reg(client,0x45,0x09); //	#G50_dec	0x09
	sensor_write_reg(client,0x46,0x17); //	#G33_dec	0x17
	sensor_write_reg(client,0x47,0x1d); //	#G25_dec	0x1d
	sensor_write_reg(client,0x48,0x21); //	#G20_dec	0x21
	sensor_write_reg(client,0x49,0x23); //	#G12_dec	0x23
	sensor_write_reg(client,0x4a,0x24); //	#G09_dec	0x24
	sensor_write_reg(client,0x4b,0x26); //	#G06_dec	0x26
	sensor_write_reg(client,0x4c,0x27); //	#G03_dec	0x27
	sensor_write_reg(client,0x4d,0x27); //	#G100_inc	0x27
	sensor_write_reg(client,0x4e,0x1a);
	sensor_write_reg(client,0x4f,0x14);
	sensor_write_reg(client,0x50,0x11);
	sensor_write_reg(client,0x51,0x0f);
	sensor_write_reg(client,0x52,0x0d);
	sensor_write_reg(client,0x53,0x0c);
	sensor_write_reg(client,0x54,0x0a);
	sensor_write_reg(client,0x55,0x09);

	//AWB Register Setting
	sensor_write_reg(client,0x00,0x02); //
	sensor_write_reg(client,0x10,0xd0); //
	sensor_write_reg(client,0x11,0xc0); //
	sensor_write_reg(client,0x12,0x80); //
	sensor_write_reg(client,0x13,0x7f); //
	sensor_write_reg(client,0x14,0x7f); //
	sensor_write_reg(client,0x15,0xfe); //		# R gain Top
	sensor_write_reg(client,0x16,0x7f); //	# R gain bottom 0x80
	sensor_write_reg(client,0x17,0xcb); //	# B gain Top
	sensor_write_reg(client,0x18,0x70); //	# B gain bottom
	sensor_write_reg(client,0x19,0x94); //	# Cr top value
	sensor_write_reg(client,0x1a,0x6c); //	# Cr bottom value
	sensor_write_reg(client,0x1b,0x94); //	# Cb top value
	sensor_write_reg(client,0x1c,0x6c); //		# Cb bottom value
	sensor_write_reg(client,0x1d,0x94); //
	sensor_write_reg(client,0x1e,0x6c); //
	sensor_write_reg(client,0x20,0xe8); //	# AWB luminous top value
	sensor_write_reg(client,0x21,0x30); //	# AWB luminous bottom value
	sensor_write_reg(client,0x22,0xa4); //
	sensor_write_reg(client,0x23,0x20); //
	sensor_write_reg(client,0x25,0x20); //
	sensor_write_reg(client,0x26,0x0f); //
	sensor_write_reg(client,0x27,0x10); //	# ST for outdoor enable
	sensor_write_reg(client,0x28,0x80); //	# ST for outdoor disable
	sensor_write_reg(client,0x29,0xa9); //	# AWB R gain at outdoor
	sensor_write_reg(client,0x2a,0x8c); //	# AWB B gain at outdoor	sensor_write_reg(client,0x4e,0x10); //	#G50_inc	0x1a

	sensor_write_reg(client,0x30,0x00);
	sensor_write_reg(client,0x31,0x10);
	sensor_write_reg(client,0x32,0x00);
	sensor_write_reg(client,0x33,0x10);
	sensor_write_reg(client,0x34,0x02);
	sensor_write_reg(client,0x35,0x76);
	sensor_write_reg(client,0x36,0x01);
	sensor_write_reg(client,0x37,0xd6);
	sensor_write_reg(client,0x40,0x01);
	sensor_write_reg(client,0x41,0x04);
	sensor_write_reg(client,0x42,0x08);
	sensor_write_reg(client,0x43,0x10);
	sensor_write_reg(client,0x44,0x12);
	sensor_write_reg(client,0x45,0x35);
	sensor_write_reg(client,0x46,0x64);
	sensor_write_reg(client,0x50,0x33);
	sensor_write_reg(client,0x51,0x20);
	sensor_write_reg(client,0x52,0xe5);
	sensor_write_reg(client,0x53,0xfb);
	sensor_write_reg(client,0x54,0x13);
	sensor_write_reg(client,0x55,0x26);
	sensor_write_reg(client,0x56,0x07);
	sensor_write_reg(client,0x57,0xf5);
	sensor_write_reg(client,0x58,0xea);
	sensor_write_reg(client,0x59,0x21);

	sensor_write_reg(client,0x63,0x9c); //R D30 to D20
	sensor_write_reg(client,0x64,0xa0); //B D30 to D20
	sensor_write_reg(client,0x65,0x9c); //R D20 to D30
	sensor_write_reg(client,0x66,0xa0); //B D20 to D30
	sensor_write_reg(client,0x67,0xbb); //R D65 to D30
	sensor_write_reg(client,0x68,0x9f); //B D65 to D30
	sensor_write_reg(client,0x69,0xbb); //R D30 to D65
	sensor_write_reg(client,0x6a,0x9f); //B D30 to D65

	//IDP Register Setting 
	sensor_write_reg(client,0x00,0x03);             
	sensor_write_reg(client,0x10,0xff);             
	sensor_write_reg(client,0x11,0x0d);
	sensor_write_reg(client,0x12,0x3d);

	//640x480 windowing
	sensor_write_reg(client,0xc0,0x24);	//windowing
	sensor_write_reg(client,0xc1,0x00);	//windowing
	sensor_write_reg(client,0xc2,0x80);	//windowing
	sensor_write_reg(client,0xc3,0x00);	//windowing
	sensor_write_reg(client,0xc4,0xe0);	//windowing
	
	sensor_write_reg(client,0x8c,0x10); //            

	//DPCNR     
	#if 1
	sensor_write_reg(client,0x17,0x98); //DPCNRCTRL
	sensor_write_reg(client,0x18,0x00); //DPTHR
	sensor_write_reg(client,0x19,0x46); //[7:6] G DP Number Thr @ Dark | [5:0] DPTHRMIN
	sensor_write_reg(client,0x1a,0x46); //[7:6] G DP Number Thr @ Normal | [5:0] DPTHRMAX
	sensor_write_reg(client,0x1b,0x12); //DPTHRSLP( [7:4] @ Normal | [3:0] @ Dark )
	sensor_write_reg(client,0x1c,0x00); //NRTHR
	sensor_write_reg(client,0x1d,0x4f); //[7:6] C DP Number Thr @ Dark | [5:0] NRTHRMIN 0x48
	sensor_write_reg(client,0x1e,0x4f); //[7:6] C DP Number Thr @ Normal | [5:0] NRTHRMAX
	sensor_write_reg(client,0x1f,0x3f); //NRTHRSLP( [7:4] @ Normal | [3:0] @ Dark ) 0x20
	sensor_write_reg(client,0x20,0x04); //IllumiInfo STRTNOR
	sensor_write_reg(client,0x21,0x0f); //IllumiInfo STRTDRK
	#else
	sensor_write_reg(client,0x17,0xB8); //DPCNRCTRL
	sensor_write_reg(client,0x18,0x18); //DPTHR
	sensor_write_reg(client,0x19,0x48); //[7:6] G DP Number Thr @ Dark | [5:0] DPTHRMIN
	sensor_write_reg(client,0x1a,0x48); //[7:6] G DP Number Thr @ Normal | [5:0] DPTHRMAX
	sensor_write_reg(client,0x1b,0x3f); //DPTHRSLP( [7:4] @ Normal | [3:0] @ Dark )
	sensor_write_reg(client,0x1c,0x10); //NRTHR
	sensor_write_reg(client,0x1d,0x58); //[7:6] C DP Number Thr @ Dark | [5:0] NRTHRMIN 0x48
	sensor_write_reg(client,0x1e,0x58); //[7:6] C DP Number Thr @ Normal | [5:0] NRTHRMAX
	sensor_write_reg(client,0x1f,0x4f); //NRTHRSLP( [7:4] @ Normal | [3:0] @ Dark ) 0x20
	sensor_write_reg(client,0x20,0x06); //IllumiInfo STRTNOR
	sensor_write_reg(client,0x21,0x0f); //IllumiInfo STRTDRK

	
	#endif
#if 1
	//Gamma     //  “Õ‚             
	sensor_write_reg(client,0x30,0x00); // #0x0 
	sensor_write_reg(client,0x31,0x04); // #0x6 
	sensor_write_reg(client,0x32,0x0b); // #0x10
	sensor_write_reg(client,0x33,0x24); // #0x27
	sensor_write_reg(client,0x34,0x49); // #0x48
	sensor_write_reg(client,0x35,0x66); // #0x62
	sensor_write_reg(client,0x36,0x7c); // #0x77
	sensor_write_reg(client,0x37,0x8d); // #0x88
	sensor_write_reg(client,0x38,0x9b); // #0x97
	sensor_write_reg(client,0x39,0xaa); // #0xA5
	sensor_write_reg(client,0x3a,0xb6); // #0xB2
	sensor_write_reg(client,0x3b,0xca); // #0xC9
	sensor_write_reg(client,0x3c,0xdc); // #0xDB
	sensor_write_reg(client,0x3d,0xef); // #0xED
	sensor_write_reg(client,0x3e,0xf8); // #0xF7
	sensor_write_reg(client,0x3f,0xff); // #0xFF
	#else
		//Gamma     “ƒ⁄ (noice  less)
		
	sensor_write_reg(client,0x30,0x00); // #0x0 
	sensor_write_reg(client,0x31,0x03); // #0x6 
	sensor_write_reg(client,0x32,0x07); // #0x10
	sensor_write_reg(client,0x33,0x0f); // #0x27
	sensor_write_reg(client,0x34,0x22); // #0x48
	sensor_write_reg(client,0x35,0x30); // #0x62
	sensor_write_reg(client,0x36,0x40); // #0x77
	sensor_write_reg(client,0x37,0x55); // #0x88
	sensor_write_reg(client,0x38,0x63); // #0x97
	sensor_write_reg(client,0x39,0x72); // #0xA5
	sensor_write_reg(client,0x3a,0x7e); // #0xB2
	sensor_write_reg(client,0x3b,0xa0); // #0xC9
	sensor_write_reg(client,0x3c,0xc0); // #0xDB
	sensor_write_reg(client,0x3d,0xdf); // #0xED
	sensor_write_reg(client,0x3e,0xef); // #0xF7
	sensor_write_reg(client,0x3f,0xfe); // #0xFF
	#endif
		
	//Shading Register Setting                                    
	sensor_write_reg(client,0x40,0x0a);
	sensor_write_reg(client,0x41,0xba);
	sensor_write_reg(client,0x42,0x32);
	sensor_write_reg(client,0x43,0x32);
	sensor_write_reg(client,0x44,0x21);
	sensor_write_reg(client,0x45,0x00);                                             
	sensor_write_reg(client,0x46,0x01); //left R gain[7:4], right R gain[3:0]             
	sensor_write_reg(client,0x47,0x21); //top R gain[7:4], bottom R gain[3:0]             
	sensor_write_reg(client,0x48,0x01); //left Gr gain[7:4], right Gr gain[3:0]           
	sensor_write_reg(client,0x49,0x00); //top Gr gain[7:4], bottom Gr gain[3:0]           
	sensor_write_reg(client,0x4a,0x01); //left Gb gain[7:4], right Gb gain[3:0]           
	sensor_write_reg(client,0x4b,0x00); //top Gb gain[7:4], bottom Gb gain[3:0]           
	sensor_write_reg(client,0x4c,0x01); //left B gain[7:4], right B gain[3:0]             
	sensor_write_reg(client,0x4d,0x20); //top B gain[7:4], bottom B gain[3:0]             
	sensor_write_reg(client,0x4e,0x04); //X-axis center high[3:2], Y-axis center high[1:0]
	sensor_write_reg(client,0x4f,0x40); //X-axis center low[7:0]                          
	sensor_write_reg(client,0x50,0xc8); //Y-axis center low[7:0]                          
	sensor_write_reg(client,0x51,0x88); //Shading Center Gain                             
	sensor_write_reg(client,0x52,0x00); //Shading R Offset                                
	sensor_write_reg(client,0x53,0x00); //Shading Gr Offset                               
	sensor_write_reg(client,0x54,0x00); //Shading Gb Offset                               
	sensor_write_reg(client,0x55,0x00); //Shading B Offset                                
	                        
	 //Color matrix (D65) - Daylight
	sensor_write_reg(client,0x71,0x42); //0x41                     
	sensor_write_reg(client,0x72,0xbf); //0xb8                    
	sensor_write_reg(client,0x73,0x00); //0x07                    
	sensor_write_reg(client,0x74,0x0f); //0x14                     
	sensor_write_reg(client,0x75,0x31); //0x1e                     
	sensor_write_reg(client,0x76,0x00); //0x0e                     
	sensor_write_reg(client,0x77,0x00); //0xf6                    
	sensor_write_reg(client,0x78,0xbc); //0xcc                     
	sensor_write_reg(client,0x79,0x44); //0x3e                     

	 //Color matrix (D30) - CWF
	sensor_write_reg(client,0x7a,0x3a); //0x41          
	sensor_write_reg(client,0x7b,0xcd); //0xc8          
	sensor_write_reg(client,0x7c,0xf9); //0xf7        
	sensor_write_reg(client,0x7d,0x12); //0x15          
	sensor_write_reg(client,0x7e,0x2b); //0x32          
	sensor_write_reg(client,0x7f,0x04); //0xf9          
	sensor_write_reg(client,0x80,0xf4); //0xf0        
	sensor_write_reg(client,0x81,0xc4); //0xbd          
	sensor_write_reg(client,0x82,0x49); //0x53          

	 //Color matrix (D20) - A
	sensor_write_reg(client,0x83,0x3a); //0x42           
	sensor_write_reg(client,0x84,0xcd); //0xbf            
	sensor_write_reg(client,0x85,0xf9); //0x00         
	sensor_write_reg(client,0x86,0x12); //0x0f           
	sensor_write_reg(client,0x87,0x2b); //0x31            
	sensor_write_reg(client,0x88,0x04); //0x00            
	sensor_write_reg(client,0x89,0xf4); //0x00        
	sensor_write_reg(client,0x8a,0xc3); //0xbc            
	sensor_write_reg(client,0x8b,0x49); //0x44            

	//sensor_write_reg(client,0x56,0x10); //	# lowlux shading enable
	//sensor_write_reg(client,0x57,0x92); //	# lowlux shading
	//sensor_write_reg(client,0x58,0x00); //	# lowlux shading on

	//Edge gain
	sensor_write_reg(client,0x90,0x12); //	# upper gain
	sensor_write_reg(client,0x91,0x12); //	# down gain
	sensor_write_reg(client,0x92,0x00); //	# upper coring value
	sensor_write_reg(client,0x96,0x00); //	# down coring value

	sensor_write_reg(client,0x9f,0x18); //	# Yeugain
	sensor_write_reg(client,0xa0,0x18); //	# Yedgain9
	sensor_write_reg(client,0xa1,0x02);
	sensor_write_reg(client,0xa2,0x02);
	
	sensor_write_reg(client,0xa9,0x10); //	# Cr saturation
	sensor_write_reg(client,0xaa,0x10); //	# Cb saturation
	sensor_write_reg(client,0xab,0x82);  //0x82_0113
	sensor_write_reg(client,0xae,0x40);
	sensor_write_reg(client,0xaf,0x86);
	sensor_write_reg(client,0xb9,0x10); //	# 0x13 lowlux color
	sensor_write_reg(client,0xba,0x20); // 0x20_0113	# 0x10 lowlux color

	sensor_write_reg(client,0xdd,0x0f); //	# ENHCTRL5
	sensor_write_reg(client,0xde,0xfa); //	# NOIZCTRL
	
	sensor_write_reg(client,0xdf,0x10);
	sensor_write_reg(client,0xe0,0x60);
	sensor_write_reg(client,0xe1,0x90);
	sensor_write_reg(client,0xe2,0x08);
	sensor_write_reg(client,0xe3,0x08);

	sensor_write_reg(client,0xe5,0x15); //
	sensor_write_reg(client,0xe6,0x28); //
	sensor_write_reg(client,0xe7,0x04); //

	//AE On    
	sensor_write_reg(client,0x00,0x01); //
	sensor_write_reg(client,0x10,0x80); //

	//Sensor On    
	sensor_write_reg(client,0x00,0x00); //
	sensor_write_reg(client,0x03,0xf5); //
}

