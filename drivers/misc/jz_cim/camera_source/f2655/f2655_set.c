#include "../../jz_cim_core.h"
#include "../../jz_sensor.h"
#include <linux/i2c.h>
#include <asm/jzsoc.h>
 
//#include"../../../../../board-z800.h"

#define f2655_DEBUG
#ifdef f2655_DEBUG
#define dprintk(x...)   do{printk("f2655-\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif


#define Default_SVGA_Line_Width (970)   // 970
#define Default_UXGA_Line_Width (1940)  //1940
uint8_t Default_Reg0x3028 = 7; 
uint8_t Default_Reg0x3029 = 147; 
uint8_t Default_Reg0x302a = 4; 
uint8_t Default_Reg0x302b = 212;

#define Default_UXGA_maximum_shutter (1200)  // 1200 
//#define Preview_dummy_pixel  0
#define Capture_dummy_pixel  (0)
#define Capture_PCLK_Frequency (36)//Unit is MHz
#define Preview_PCLK_Frequency (12)//Unit is MHz

uint8_t Preview_Reg0x3000, 
	Reg0x3013,
	Reg0x3014,
	Reg0x3000,
	Reg0x3002,
	Reg0x3003,
	Reg0x302d,
	Reg0x302e;

uint16_t Preview_dummy_pixel,
	 Extra_lines,
	 Capture_Banding_Filter,
	 Capture_Gain16,
	 Preview_Gain16, 
	 Capture_dummy_line = 63;
 
uint32_t Preview_Exposure, 
	 Shutter, 
	 Capture_Max_Gain16, 
	 Preview_Line_Width, 
	 Capture_Line_Width, 
	 Capture_Exposure, 
	 Gain_Exposure,
	 Capture_Maximum_Shutter;


void f2655_preview_set(struct i2c_client *client)                   
{
//IO & Clock & Analog Setup
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
sensor_write_reg16(client,0x3015,0x02);
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
sensor_write_reg16(client,0x3011,0x02);
sensor_write_reg16(client,0x302d,0x00);
sensor_write_reg16(client,0x302e,0x00);

//D5060
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
sensor_write_reg16(client,0x3014,0xc5);
sensor_write_reg16(client,0x3071,0x00);
sensor_write_reg16(client,0x3070,0x7c);
sensor_write_reg16(client,0x3073,0x00);
sensor_write_reg16(client,0x3072,0x4d);
sensor_write_reg16(client,0x301c,0x04);
sensor_write_reg16(client,0x301d,0x06);
sensor_write_reg16(client,0x304d,0x42);
sensor_write_reg16(client,0x304a,0x40);
sensor_write_reg16(client,0x304f,0x40);
sensor_write_reg16(client,0x3095,0x07);
sensor_write_reg16(client,0x3096,0x16);
sensor_write_reg16(client,0x3097,0x1d);

//Window Setup
	sensor_write_reg16(client,0x300e,0x34); 
	sensor_write_reg16(client,0x3020,0x01); 
	sensor_write_reg16(client,0x3021,0x18);
	sensor_write_reg16(client,0x3022,0x00);
	sensor_write_reg16(client,0x3023,0x06);
	sensor_write_reg16(client,0x3024,0x06);
	sensor_write_reg16(client,0x3025,0x58);
	sensor_write_reg16(client,0x3026,0x02);
	sensor_write_reg16(client,0x3027,0x61); //5e
	//800x600
	sensor_write_reg16(client,0x3088,0x03);  
	sensor_write_reg16(client,0x3089,0x20);   //high
	sensor_write_reg16(client,0x308a,0x02); 
	sensor_write_reg16(client,0x308b,0x58);   //width
	sensor_write_reg16(client,0x3316,0x64);
	sensor_write_reg16(client,0x3317,0x25);
	sensor_write_reg16(client,0x3318,0x80);
	sensor_write_reg16(client,0x3319,0x08);
	sensor_write_reg16(client,0x331a,0x64);
	sensor_write_reg16(client,0x331b,0x4b);
	sensor_write_reg16(client,0x331c,0x00);
	sensor_write_reg16(client,0x331d,0x38);
	sensor_write_reg16(client,0x3100,0x00);

//AGC gain ceiling
sensor_write_reg16(client,0x3014,0x85);//0x84,//0x8C:auto frame
sensor_write_reg16(client,0x3015,0x02);//0x02
sensor_write_reg16(client,0x301c,0x04);
sensor_write_reg16(client,0x3070,0x7c);

mdelay(10);

//;Other,0xfunctions
	sensor_write_reg16(client,0x3300,0xfc);
	sensor_write_reg16(client,0x3302,0x11);
	sensor_write_reg16(client,0x3400,0x03);    //fish mark that use YUV422
	sensor_write_reg16(client,0x3606,0x20);
	sensor_write_reg16(client,0x3601,0x30);
	//	sensor_write_reg16(client,0x30f3,0x83);
	sensor_write_reg16(client,0x300e,0x34);
	sensor_write_reg16(client,0x3011,0x02);
	sensor_write_reg16(client,0x30f3,0x83);
	sensor_write_reg16(client,0x304e,0x88);
	//fish add from spec 1.54
	//    sensor_write_reg16(client,0x3090,0x03);
	//    sensor_write_reg16(client,0x30aa,0x32);
	//    sensor_write_reg16(client,0x30a3,0x80);
	//	sensor_write_reg16(client,0x30a1,0x41);
	//    sensor_write_reg16(client,0x363b,0x01);
	//    sensor_write_reg16(client,0x363c,0xf2);
	sensor_write_reg16(client,0x3086,0x0f);
	sensor_write_reg16(client,0x3086,0x00);
	sensor_write_reg16(client,0x3600,0x84);

	dprintk("---------------------------------------preview_set UXGA>SVGA");
	// transfer from UXGA to SVGA
	
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

	//Gamma
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

	sensor_write_reg16(client,0x302a,0x02);
	sensor_write_reg16(client,0x302b,0x6a);
	sensor_write_reg16(client,0x302d,0x00);
	sensor_write_reg16(client,0x302e,0x00);

	mdelay(100);
}    //===preview setting end===


void f2655_capture_reg_set(struct i2c_client *client)
{
	dprintk("-----------------------------------------------capture_reg_set");
	// ?? -> 1600x1200
	/*
	sensor_write_reg16(client,0x300e,0x34);
	sensor_write_reg16(client,0x3011,0x02);
	sensor_write_reg16(client,0x3012,0x00);
	sensor_write_reg16(client,0x302A,0x04);
	sensor_write_reg16(client,0x302B,0xd4);
	sensor_write_reg16(client,0x306f,0x54);
	sensor_write_reg16(client,0x3020,0x01);
	sensor_write_reg16(client,0x3021,0x0d);
	sensor_write_reg16(client,0x3022,0x00);
	sensor_write_reg16(client,0x3023,0x06);
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
	sensor_write_reg16(client,0x331c,0x00);
	sensor_write_reg16(client,0x331d,0x4c);
	sensor_write_reg16(client,0x3302,0x01);
*/
	sensor_write_reg16(client,0x30d9,0x95);
	sensor_write_reg16(client,0x3016,0xd2);
	sensor_write_reg16(client,0x3012,0x00);
	sensor_write_reg16(client,0x302A,0x04);
	sensor_write_reg16(client,0x302B,0xd4);
	sensor_write_reg16(client,0x306f,0x54);
	sensor_write_reg16(client,0x3020,0x01);
	sensor_write_reg16(client,0x3021,0x0c);
	sensor_write_reg16(client,0x3022,0x00);
	sensor_write_reg16(client,0x3023,0x0a);
	sensor_write_reg16(client,0x3024,0x06);
	sensor_write_reg16(client,0x3025,0x58);
	sensor_write_reg16(client,0x3026,0x04);
	sensor_write_reg16(client,0x3027,0xbc);
	sensor_write_reg16(client,0x3302,0x00);
	sensor_write_reg16(client,0x3088,0x06);
	sensor_write_reg16(client,0x3089,0x40);
	sensor_write_reg16(client,0x308a,0x04);
	sensor_write_reg16(client,0x308b,0xb0);
	sensor_write_reg16(client,0x3100,0x00);
	sensor_write_reg16(client,0x3316,0x64);
	sensor_write_reg16(client,0x3317,0x4b);
	sensor_write_reg16(client,0x3318,0x00);
	sensor_write_reg16(client,0x3319,0x6c);
	sensor_write_reg16(client,0x331a,0x64);
	sensor_write_reg16(client,0x331b,0x4b);
	sensor_write_reg16(client,0x331c,0x00);
	sensor_write_reg16(client,0x331d,0x6c);
	sensor_write_reg16(client,0x3362,0x80);
	sensor_write_reg16(client,0x300f,0xa6);
	sensor_write_reg16(client,0x300e,0x34);
	sensor_write_reg16(client,0x3011,0x01);
/*
	sensor_write_reg16(client,0x3340,0x08);
	sensor_write_reg16(client,0x3341,0x17);
	sensor_write_reg16(client,0x3342,0x29);
	sensor_write_reg16(client,0x3343,0x3b);
	sensor_write_reg16(client,0x3344,0x4b);
	sensor_write_reg16(client,0x3345,0x57);
	sensor_write_reg16(client,0x3346,0x65);
	sensor_write_reg16(client,0x3347,0x71);
	sensor_write_reg16(client,0x3348,0x7e);
	sensor_write_reg16(client,0x3349,0x95); 
	sensor_write_reg16(client,0x334a,0xa9); 
	sensor_write_reg16(client,0x334b,0xb9);
	sensor_write_reg16(client,0x334c,0xd3);
	sensor_write_reg16(client,0x334d,0xe4);
	sensor_write_reg16(client,0x334e,0xf0);
	sensor_write_reg16(client,0x334f,0x15);
*/
	sensor_write_reg16(client,0x3340,0x06);
	sensor_write_reg16(client,0x3341,0x11);
	sensor_write_reg16(client,0x3342,0x24);
	sensor_write_reg16(client,0x3343,0x37);
	sensor_write_reg16(client,0x3344,0x48);
	sensor_write_reg16(client,0x3345,0x57);
	sensor_write_reg16(client,0x3346,0x65);
	sensor_write_reg16(client,0x3347,0x71);
	sensor_write_reg16(client,0x3348,0x7e);
	sensor_write_reg16(client,0x3349,0x95); 
	sensor_write_reg16(client,0x334a,0xa9); 
	sensor_write_reg16(client,0x334b,0xb9);
	sensor_write_reg16(client,0x334c,0xd3);
	sensor_write_reg16(client,0x334d,0xe4);
	sensor_write_reg16(client,0x334e,0xf0);
	sensor_write_reg16(client,0x334f,0x15);

	mdelay(100);
}

void f2655_capture_set(struct i2c_client *client)
	{
//f2655_capture_reg_set(client);
//return 0;

		uint16_t PV_Line_Width;
		uint16_t Capture_Line_Width;
		uint32_t Capture_Maximum_Shutter;
		uint32_t Capture_Exposure;
		uint32_t Capture_Gain16;
		uint32_t P_Gain16;
		uint32_t temp_reg;
		uint32_t Capture_Banding_Filter;
		uint32_t Gain_Exposure=0;
		uint32_t Capture_Extra_Lines;
		uint32_t PV_Extra_Lines;
		uint16_t temp_gain;
		uint32_t Capture_Shutter;
		uint32_t shutter;
		uint8_t  Reg3013_1;
		uint8_t  Reg3014_1;

		uint16_t sensor_gain;
	
		dprintk("------------------------------------------------capture_set");  
	
		Reg0x3014 = sensor_read_reg16(client,0x3014);
		Reg0x3014 = temp_reg & 0xf7; //Disable night mode
		sensor_write_reg16(client,0x3014,Reg0x3014);  
		
		// turn off AEC/AGC
		Reg0x3013 = sensor_read_reg16(client,0x3013)&(0xfa);
		sensor_write_reg16(client,0x3013,Reg0x3013);

		Reg3014_1 = sensor_read_reg16(client,0x3014);
		Reg3013_1 = sensor_read_reg16(client,0x3013);	
		//	dprintk("------------------------------Reg0x3013=%x\n",Reg0x3013);
		//	dprintk("------------------------------Reg0x3014=%x\n",Reg0x3014);

	//	mdelay(50);
	
		Reg0x3002 = sensor_read_reg16(client,0x3002); 
		Reg0x3003 = sensor_read_reg16(client,0x3003);  
		Reg0x302d = sensor_read_reg16(client,0x302d); 
		Reg0x302e = sensor_read_reg16(client,0x302e);
	
		Preview_Exposure = (Reg0x3002<<8) + Reg0x3003 +(Reg0x302d<<8) + Reg0x302e ;
		PV_Extra_Lines = (Reg0x302d<<8) + Reg0x302e;
		//		dprintk("-------------------------------- 1\n");
		//		dprintk("------------------------------------Reg0x3002=%x\n",Reg0x3002); 
		//		dprintk("------------------------------------Reg0x3003=%x\n",Reg0x3003); 
		//		dprintk("------------------------------------Reg0x302d=%x\n",Reg0x302d); 
		//		dprintk("------------------------------------Reg0x302e=%x\n",Reg0x302e); 
		//		dprintk("------------------------------------Preview_Exposure=%x\n",Preview_Exposure);   
		//		dprintk("------------------------------------Preview_Exposure=%d\n",Preview_Exposure);  

		f2655_capture_reg_set(client);
	
		mdelay(30);
	
	        //Read Back Gain for preview
		Reg0x3000 = sensor_read_reg16(client,0x3000);
		P_Gain16=sensor_read_reg16(client,0x3000);	
		Preview_Gain16=(16+(Reg0x3000&0x0F));
		
		//	dprintk("---------------------------------------P_Gain16(Reg0x3000)=%x\n",Reg0x3000); 
		//	dprintk("---------------------------------------P_Gain16(P_Gain16)=%x\n",P_Gain16); 		
		//	dprintk("---------------------------------------Preview_Gain16=%d\n",Preview_Gain16); 
	 
	   if(P_Gain16&0x10)
		  Preview_Gain16<<=1;
		  
	   if(P_Gain16&0x20)
		  Preview_Gain16<<=1;
		  
	   if(P_Gain16&0x40)
		  Preview_Gain16<<=1;
		  
	   if(P_Gain16&0x80)
		  Preview_Gain16<<=1;
	   //		dprintk("-------------------------------- 2\n");
	   //		dprintk("--------------------------------Preview_Gain16 = %d\n",Preview_Gain16);
		
		//Maximum gain limitation for capture, Capture_max_gain16 = capture_maximum_gain * 16
		Capture_Max_Gain16 = 128;					
		Preview_Line_Width = 970;		  //Default_SVGA_Line_Width ;
		Capture_Line_Width = 1940;		  //Default_UXGA_Line_Width ;
		Capture_Maximum_Shutter = 1236;   //Default_UXGA_maximum_shutter;
		
		Gain_Exposure = Preview_Gain16*Preview_Exposure*Capture_PCLK_Frequency*Preview_Line_Width/Preview_PCLK_Frequency/Capture_Line_Width;
		//			dprintk("-------------------------------- 3\n");
	 
		Capture_Banding_Filter = Capture_PCLK_Frequency*10000/(2*Capture_Line_Width)+(50/100);	   // 240000/2/1200  = 100

		//		dprintk("------------------------Gain_Exposure=%d\n",Gain_Exposure);   
		//		dprintk("------------------------Capture_Banding_Filter=%d\n",Gain_Exposure);   
	
		if (Gain_Exposure < Capture_Banding_Filter * 16)								 //  < 1600
		{                           													//1200
			// Exposure < 1/100
			if(Gain_Exposure < 16)
			{
				Gain_Exposure = Gain_Exposure*4;
				Capture_Exposure = 1;
				Capture_Gain16 = (Gain_Exposure*2+1)/Capture_Exposure/2/4;
				//		dprintk("-------------------------------- 4\n");
			}
			else
			{	
				Capture_Exposure = Gain_Exposure /16;
				Capture_Gain16 = (Gain_Exposure*2 + 1)/Capture_Exposure/2;
				//		dprintk("-------------------------------- 5\n");
			}	
		}
		else 
		{
			if (Gain_Exposure > Capture_Maximum_Shutter * 16)						  //16720
			{
				Capture_Exposure = Capture_Maximum_Shutter/Capture_Banding_Filter;
				Capture_Exposure = Capture_Exposure*Capture_Banding_Filter;
				Capture_Gain16 = (Gain_Exposure*2 + 1)/Capture_Maximum_Shutter/2;
				//		dprintk("-------------------------------- 6\n");
				//	dprintk("--------------------------------Capture_Gain16=%d\n",Capture_Gain16);
				if (Capture_Gain16 > Capture_Max_Gain16) 
				{
					Capture_Gain16 = Gain_Exposure*11/10/Capture_Max_Gain16;
					Capture_Exposure = Capture_Exposure/Capture_Banding_Filter;
					Capture_Exposure = Capture_Exposure*Capture_Banding_Filter;
					Capture_Gain16 = (Gain_Exposure *4)/ (Capture_Exposure+3)/4;
					//	dprintk("-------------------------------- 7\n");
					//	dprintk("----------------------------Capture_Gain16=%d\n",Capture_Gain16);
				}
			}
			else		  //  (1600 , 16720)
			{	
				Capture_Exposure = Gain_Exposure/16/Capture_Banding_Filter; 
				Capture_Exposure = Capture_Exposure * Capture_Banding_Filter; 
				Capture_Gain16 = (Gain_Exposure*2 +1) / Capture_Exposure/2;
				//		dprintk("-------------------------------- 8\n");
				//	dprintk("--------------------------------------------Capture_Gain16=%d\n",Capture_Gain16); 
			}
		}
		Capture_Gain16 = Capture_Gain16;
		Capture_Extra_Lines = (Capture_Exposure > Capture_Maximum_Shutter)?
				(Capture_Exposure - Capture_Maximum_Shutter/Capture_Banding_Filter*Capture_Banding_Filter):0;	  
		Capture_Shutter = Capture_Exposure - Capture_Extra_Lines;
	
		shutter = Capture_Shutter + Capture_Extra_Lines;
		if (shutter < 1) 
		{
			shutter = 1;
		}
		if (shutter <= Capture_Maximum_Shutter) 
		{
		Capture_Extra_Lines = 0;
		}
		else 
		{
		Capture_Extra_Lines = shutter - Capture_Maximum_Shutter;
		}
		if (shutter > Capture_Maximum_Shutter) 
		{
			shutter = Capture_Maximum_Shutter;
		}

		//	dprintk("--------------------------------------------Shutter=%x\n",Shutter); 	
		//	dprintk("--------------------------------------------Capture_Extra_Lines=%x\n",Capture_Extra_Lines); 

		Reg0x3003 = Shutter & 0x00ff;
		Reg0x3002 = (shutter & 0xff00) >> 8;
		sensor_write_reg16(client,0x3003, Reg0x3003);
		sensor_write_reg16(client,0x3002, Reg0x3002);
		
		Reg0x302e = Capture_Extra_Lines & 0x00ff;
		Reg0x302d = (Capture_Extra_Lines & 0xff00) >> 8;
		sensor_write_reg16(client,0x302e, Reg0x302e);
		sensor_write_reg16(client,0x302d, Reg0x302d);
		temp_gain = 0;
	
		if (Capture_Gain16 > 31)
		{
			temp_gain |= 0x10;
			Capture_Gain16 = Capture_Gain16 >> 1;
		}
		if (Capture_Gain16 > 31)
		{
			temp_gain |= 0x20;
			Capture_Gain16 = Capture_Gain16 >> 1;
		}
		if (Capture_Gain16 > 31)
		{
			temp_gain |= 0x40;
			Capture_Gain16 = Capture_Gain16 >> 1;
		}
		if (Capture_Gain16 > 31)
		{
		temp_gain |= 0x80;
		Capture_Gain16 = Capture_Gain16 >> 1;
		}
		if (Capture_Gain16 > 16)
		{
			temp_gain |= ((Capture_Gain16 -16) & 0x0f);
		}	
		//	dprintk("--------------------------------------------temp_gain=%x\n",temp_gain);	

		sensor_write_reg16(client,0x3000, temp_gain+8);
	//	mdelay(100);
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
		dprintk("-------------------------------- CAMERA_MODE_CAPTURE  1280x1024");
	}
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
		dprintk("-------------------------------- CAMERA_MODE_CAPTURE  1024x768");
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
		dprintk("-------------------------------- CAMERA_MODE_PREVIEW  800x600");
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
		dprintk("-------------------------------- CAMERA_MODE_CAPTURE  800x600");
	}
	dprintk("-------------------------------- UXGA>SVGA 800x600");
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
	dprintk("--------------------------------------------CAMERA_MODE_PREVIEW 640x480");
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
	dprintk("--------------------------------------------CAMERA_MODE_CAPTURE 640x480");
	}
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

void _init_91_1(struct i2c_client *client)
{
  //	__set_backlight_level(255);
	dprintk("1111--------------------------------------------init_911");

//Soft Reset
sensor_write_reg16(client,0x3012,0x80);

mdelay(100);

//IO & Clock & Analog Setup
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
sensor_write_reg16(client,0x3015,0x02);
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
sensor_write_reg16(client,0x3011,0x02);


//AEC/AGC
sensor_write_reg16(client,0x3013,0xf7);
sensor_write_reg16(client,0x301c,0x04);
sensor_write_reg16(client,0x301d,0x17);
sensor_write_reg16(client,0x3070,0x7c);
sensor_write_reg16(client,0x3072,0x4d);
//D5060
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
sensor_write_reg16(client,0x3014,0xc4);
sensor_write_reg16(client,0x3071,0x00);
sensor_write_reg16(client,0x3070,0x7c);
sensor_write_reg16(client,0x3073,0x00);
sensor_write_reg16(client,0x3072,0x4d);
sensor_write_reg16(client,0x301c,0x04);
sensor_write_reg16(client,0x301d,0x06);
sensor_write_reg16(client,0x304d,0x42);
sensor_write_reg16(client,0x304a,0x40);
sensor_write_reg16(client,0x304f,0x40);
sensor_write_reg16(client,0x3095,0x07);
sensor_write_reg16(client,0x3096,0x16);
sensor_write_reg16(client,0x3097,0x1d);

//Window Setup

	sensor_write_reg16(client,0x300e,0x34); 
	sensor_write_reg16(client,0x3020,0x01); 
	sensor_write_reg16(client,0x3021,0x18);
	sensor_write_reg16(client,0x3022,0x00);
	sensor_write_reg16(client,0x3023,0x06);
	sensor_write_reg16(client,0x3024,0x06);
	sensor_write_reg16(client,0x3025,0x58);
	sensor_write_reg16(client,0x3026,0x02);
	sensor_write_reg16(client,0x3027,0x61); //5e
	//800x600
	sensor_write_reg16(client,0x3088,0x03);  
	sensor_write_reg16(client,0x3089,0x20);   //high
	sensor_write_reg16(client,0x308a,0x02); 
	sensor_write_reg16(client,0x308b,0x58);   //width
	sensor_write_reg16(client,0x3316,0x64);
	sensor_write_reg16(client,0x3317,0x25);
	sensor_write_reg16(client,0x3318,0x80);
	sensor_write_reg16(client,0x3319,0x08);
	sensor_write_reg16(client,0x331a,0x64);
	sensor_write_reg16(client,0x331b,0x4b);
	sensor_write_reg16(client,0x331c,0x00);
	sensor_write_reg16(client,0x331d,0x38);
	sensor_write_reg16(client,0x3100,0x00);




//AWB
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
sensor_write_reg16(client,0x332d,0xce);
sensor_write_reg16(client,0x332e,0x2e);
sensor_write_reg16(client,0x332f,0x36);
sensor_write_reg16(client,0x3330,0x4d);
sensor_write_reg16(client,0x3331,0x44);
sensor_write_reg16(client,0x3332,0xf0);
sensor_write_reg16(client,0x3333,0x0a);
sensor_write_reg16(client,0x3334,0xf0);
sensor_write_reg16(client,0x3335,0xf0);
sensor_write_reg16(client,0x3336,0xf0);
sensor_write_reg16(client,0x3337,0x40);
sensor_write_reg16(client,0x3338,0x40);
sensor_write_reg16(client,0x3339,0x40);
sensor_write_reg16(client,0x333a,0x00);
sensor_write_reg16(client,0x333b,0x00);

//Gamma
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



//UVadjust
//sensor_write_reg16(client,0x3301,0xff,
//sensor_write_reg16(client,0x338b,0x11,
//sensor_write_reg16(client,0x338c,0x10,
//sensor_write_reg16(client,0x338d,0x40,
//Sharpness/De-noise
sensor_write_reg16(client,0x3370,0xd0);
sensor_write_reg16(client,0x3371,0x00);
sensor_write_reg16(client,0x3372,0x00);
sensor_write_reg16(client,0x3373,0x30);
sensor_write_reg16(client,0x3374,0x10);
sensor_write_reg16(client,0x3375,0x10);
sensor_write_reg16(client,0x3376,0x05);
sensor_write_reg16(client,0x3377,0x00);
sensor_write_reg16(client,0x3378,0x04);
sensor_write_reg16(client,0x3379,0x80);
//BLC
sensor_write_reg16(client,0x3069,0x84);
sensor_write_reg16(client,0x307c,0x10);
sensor_write_reg16(client,0x3087,0x02);

//black sun 
//Avdd 2.55~3.0V
//sensor_write_reg16(client,0x3090,0x03,
//sensor_write_reg16(client,0x30aa,0x32,
//sensor_write_reg16(client,0x30a3,0x80,
//sensor_write_reg16(client,0x30a1,0x41,

//;Other,0xfunctions


sensor_write_reg16(client,0x3300,0xfc);
	sensor_write_reg16(client,0x3302,0x11);
	sensor_write_reg16(client,0x3400,0x03);    //fish mark that use YUV422
	sensor_write_reg16(client,0x3606,0x20);
	sensor_write_reg16(client,0x3601,0x30);
	//	sensor_write_reg16(client,0x30f3,0x83);
	sensor_write_reg16(client,0x300e,0x34);
	sensor_write_reg16(client,0x3011,0x02);
	sensor_write_reg16(client,0x30f3,0x83);
	sensor_write_reg16(client,0x304e,0x88);
	//fish add from spec 1.54
	//    sensor_write_reg16(client,0x3090,0x03);
	//    sensor_write_reg16(client,0x30aa,0x32);
	//    sensor_write_reg16(client,0x30a3,0x80);
	//	sensor_write_reg16(client,0x30a1,0x41);
	//    sensor_write_reg16(client,0x363b,0x01);
	//    sensor_write_reg16(client,0x363c,0xf2);
	sensor_write_reg16(client,0x3086,0x0f);
	sensor_write_reg16(client,0x3086,0x00);
	sensor_write_reg16(client,0x3600,0x84);



//GAMMA
sensor_write_reg16(client,0x334f,0x19);
sensor_write_reg16(client,0x3340,0x0f);
sensor_write_reg16(client,0x3341,0x24);
sensor_write_reg16(client,0x3342,0x3a);
sensor_write_reg16(client,0x3343,0x4f);
sensor_write_reg16(client,0x3344,0x63);
sensor_write_reg16(client,0x3345,0x6e);
sensor_write_reg16(client,0x3346,0x7b);
sensor_write_reg16(client,0x3347,0x84);
sensor_write_reg16(client,0x3348,0x90);
sensor_write_reg16(client,0x3349,0x9f);
sensor_write_reg16(client,0x334a,0xae);
sensor_write_reg16(client,0x334b,0xbb);
sensor_write_reg16(client,0x334c,0xcf);
sensor_write_reg16(client,0x334d,0xdf);
sensor_write_reg16(client,0x334e,0xed);
//SG AWB
sensor_write_reg16(client,0x3320,0xf8);  
sensor_write_reg16(client,0x3321,0x11); 
sensor_write_reg16(client,0x3322,0x92);
sensor_write_reg16(client,0x3323,0x01);
sensor_write_reg16(client,0x3324,0x97);
sensor_write_reg16(client,0x3325,0x02);
sensor_write_reg16(client,0x3326,0xff);
sensor_write_reg16(client,0x3327,0x0a);
sensor_write_reg16(client,0x3328,0x0a);
sensor_write_reg16(client,0x3329,0x15);
sensor_write_reg16(client,0x332a,0x58);
sensor_write_reg16(client,0x332b,0x50);
sensor_write_reg16(client,0x332c,0xbe);  
sensor_write_reg16(client,0x332d,0xce); 
sensor_write_reg16(client,0x332e,0x35); 
sensor_write_reg16(client,0x332f,0x33); 
sensor_write_reg16(client,0x3330,0x4d); 
sensor_write_reg16(client,0x3331,0x3c); 
sensor_write_reg16(client,0x3332,0xf0); 
sensor_write_reg16(client,0x3333,0x0a);  
sensor_write_reg16(client,0x3334,0xf0); 
sensor_write_reg16(client,0x3335,0xf0); 
sensor_write_reg16(client,0x3336,0xf0); 
sensor_write_reg16(client,0x3337,0x40);
sensor_write_reg16(client,0x3338,0x40); 
sensor_write_reg16(client,0x3339,0x40);
sensor_write_reg16(client,0x333a,0x00);
sensor_write_reg16(client,0x333b,0x00);

//LENS 
sensor_write_reg16(client,0x3350,0x32);//2e
sensor_write_reg16(client,0x3351,0x27);//25
sensor_write_reg16(client,0x3352,0x78);
sensor_write_reg16(client,0x3353,0x52);	 			
sensor_write_reg16(client,0x3354,0x93);
sensor_write_reg16(client,0x3355,0x77);
sensor_write_reg16(client,0x3356,0x32);//33
sensor_write_reg16(client,0x3357,0x2a);//25
sensor_write_reg16(client,0x3358,0x78);
sensor_write_reg16(client,0x3359,0x46);
sensor_write_reg16(client,0x335A,0x93);
sensor_write_reg16(client,0x335B,0x77);
sensor_write_reg16(client,0x335C,0x31);//33
sensor_write_reg16(client,0x335D,0x2a);//25
sensor_write_reg16(client,0x335E,0x78);
sensor_write_reg16(client,0x335F,0x38);
sensor_write_reg16(client,0x3360,0xa0);
sensor_write_reg16(client,0x3361,0x77);

sensor_write_reg16(client,0x3363,0xff);// 70
sensor_write_reg16(client,0x3364,0xff);// 7f
sensor_write_reg16(client,0x3365,0x00);
sensor_write_reg16(client,0x3366,0x00);

sensor_write_reg16(client,0x3300,0xFC);
//AE
sensor_write_reg16(client,0x3018,0x80);//0x90
sensor_write_reg16(client,0x3019,0x70);//0x80
sensor_write_reg16(client,0x301a,0xa5);//0xb5
//Color Matrix
//sensor_write_reg16(client,0x3380,0x27,
//sensor_write_reg16(client,0x3381,0x58,
//sensor_write_reg16(client,0x3382,0x0a,
//sensor_write_reg16(client,0x3383,0x28,
//sensor_write_reg16(client,0x3384,0xa6,
//sensor_write_reg16(client,0x3385,0xce,
//sensor_write_reg16(client,0x3386,0xb9,
//sensor_write_reg16(client,0x3387,0xb6,
//sensor_write_reg16(client,0x3388,0x03,
//sensor_write_reg16(client,0x3389,0x98,
//sensor_write_reg16(client,0x338a,0x01,

/*
sensor_write_reg16(client,0x3380,0x20);  
sensor_write_reg16(client,0x3381,0x5b);  
sensor_write_reg16(client,0x3382,0x05); 
sensor_write_reg16(client,0x3383,0x22);
sensor_write_reg16(client,0x3384,0x9d);
sensor_write_reg16(client,0x3385,0xc0);   
sensor_write_reg16(client,0x3386,0xb6); 
sensor_write_reg16(client,0x3387,0xb5); 
sensor_write_reg16(client,0x3388,0x02); 
sensor_write_reg16(client,0x3389,0x98);
sensor_write_reg16(client,0x338a,0x00);
*/

sensor_write_reg16(client,0x3380,0x20);  
sensor_write_reg16(client,0x3381,0x5b);  
sensor_write_reg16(client,0x3382,0x05 ); 
sensor_write_reg16(client,0x3383,0x22);
sensor_write_reg16(client,0x3384,0x9d);
sensor_write_reg16(client,0x3385,0xc0);   
sensor_write_reg16(client,0x3386,0xb6); 
sensor_write_reg16(client,0x3387,0xb5); 
sensor_write_reg16(client,0x3388,0x02 ); 
sensor_write_reg16(client,0x3389,0x98);
sensor_write_reg16(client,0x338a,0x00 );


//AGC gain ceiling
sensor_write_reg16(client,0x3014,0x83);//0x84,//0x8C:auto frame
sensor_write_reg16(client,0x3015,0x02);//0x02
sensor_write_reg16(client,0x301c,0x04);
sensor_write_reg16(client,0x3070,0x7c);



//Brightness +3
sensor_write_reg16(client,0x3391,0x06);
sensor_write_reg16(client,0x339a,0x30);

sensor_write_reg16(client,0x3320,0x99);//0x02
sensor_write_reg16(client,0x3332,0xf0);
sensor_write_reg16(client,0x3333,0x0a);

	dprintk("2222--------------------------------------------init_911");

}

void f2655_size_switch(struct i2c_client *client,int width,int height,int setmode)
{
	dprintk("-----------------------------------%dx%d - mode(%d)",width,height,setmode);

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


void f2655_init_setting(struct i2c_client *client)
{

	_init_91_1(client);


}   /* f2655_Write_Sensor_Initial_Setting */

