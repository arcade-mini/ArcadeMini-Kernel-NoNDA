#include "../../jz_cim_core.h"
#include "../../jz_sensor.h"
#include <linux/i2c.h>
#include <asm/jzsoc.h>

//#define bf3703_DEBUG
#undef bf3703_DEBUG
#ifdef bf3703_DEBUG
#define dprintk(x...)   do{printk("bf3703-\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

//for test
void retry_write_reg(struct i2c_client *client ,int addr, int value)
{
    int num = 0;
    sensor_write_reg(client,addr,value);
    while(sensor_read_reg(client,addr) != value)
    {
        num++;
        //printk("this is %d to retry_write_reg, addr is %d \n",num,addr);
        sensor_write_reg(client,addr,value);
        if(num > 10)
            break;
    }
}
//end


void preview_set(struct i2c_client *client)                   
{
	
}    //===preview setting end===

void set_size_640x480(struct i2c_client *client,int mode)
{
		sensor_write_reg(client,0x6b,0x02);//huangsen test it for JH

		retry_write_reg(client,0x17,0x00);
		retry_write_reg(client,0x18,0xa0);
		retry_write_reg(client,0x19,0x00);
		retry_write_reg(client,0x1a,0x78);
		retry_write_reg(client,0x03,0x00);
		retry_write_reg(client,0x12,0x00);
		retry_write_reg(client,0x8e,0x05); 
		retry_write_reg(client,0x8f,0xfb);

//		sensor_write_reg(client,0x6b,0x02);//huangsen test it for JH
       // skip rame
	//	retry_write_reg(client,0x0b,0x00);

	dprintk("VGA 640x480");
}  

void set_size_352x288(struct i2c_client *client,int mode)
{
#if 0
		retry_write_reg(client,0x17,0x36);
	        retry_write_reg(client,0x18,0x8e);
		retry_write_reg(client,0x19,0x1b);
		retry_write_reg(client,0x1a,0x63);
		retry_write_reg(client,0x03,0xf0);
		retry_write_reg(client,0x12,0x00);

		retry_write_reg(client,0x8e,0x03); 
		retry_write_reg(client,0x8f,0xfc);


       //  skip frame
	//	retry_write_reg(client,0x0b,0x00);
#else   // huangsen test it for JH
		retry_write_reg(client,0x17,0x00);
		retry_write_reg(client,0x18,0x58);
		retry_write_reg(client,0x19,0x00);
		retry_write_reg(client,0x1a,0x48);
//		retry_write_reg(client,0x03,0xf0);

//		retry_write_reg(client,0x12,0x00); //YUV422I

//		retry_write_reg(client,0x8e,0x03);
//		retry_write_reg(client,0x8f,0xfc);
#endif
		retry_write_reg(client,0x0a,0x21);
		retry_write_reg(client,0x10,0x21);
		retry_write_reg(client,0x3d,0x59); 
		retry_write_reg(client,0x6b,0x03);

	dprintk("CIF 352x288");
}  

void set_size_320x240(struct i2c_client *client,int mode)
{
	retry_write_reg(client,0x17,0x00);
	retry_write_reg(client,0x18,0xa0);
	retry_write_reg(client,0x19,0x00);
	retry_write_reg(client,0x1a,0x78);
	retry_write_reg(client,0x03,0x00);
	sensor_write_reg(client,0x12,0x10);	

	dprintk("QVGA 320x320");
}  

void set_size_176x144(struct i2c_client *client,int mode)
{

	sensor_write_reg(client,0x17,0x36);
	sensor_write_reg(client,0x18,0x8e);
	sensor_write_reg(client,0x19,0x1b);
	sensor_write_reg(client,0x1a,0x63);
	sensor_write_reg(client,0x03,0xf0);
	sensor_write_reg(client,0x12,0x10);

	dprintk("QCIF 176x144");
} 

void size_switch(struct i2c_client *client,int width,int height,int setmode)
{
	dprintk("%dx%d - mode(%d)",width,height,setmode);

	//return;
	if(width == 640 && height == 480)
	{
		set_size_640x480(client,setmode);
	} 
	else if(width == 352 && height == 288)
	{
		set_size_352x288(client,setmode);
	} 
	else if(width == 320 && height == 240)
	{
		set_size_320x240(client,setmode);
	}  
	else if(width == 176 && height == 144)
	{
		set_size_176x144(client,setmode);
	}  
	else
		return;
	//	mdelay(500);
}

void bf3703_reset(void);
void bf3703_init_setting(struct i2c_client *client)
{
	//SOFE RESET
	//retry_write_reg16(client,0x12,0x80);
	bf3703_reset();
	mdelay(10);	
	retry_write_reg(client,0x11,0x80);

	//retry_write_reg(client,0x11,0x80);//modify by huawu
	retry_write_reg(client,0x20,0x40);
	retry_write_reg(client,0x09,0xc0);
	//retry_write_reg(client,0x12,0x00); 
	retry_write_reg(client,0x13,0x00);
	retry_write_reg(client,0x01,0x13);
	retry_write_reg(client,0x01,0x13);//retry 01 huawu modify
	retry_write_reg(client,0x02,0x25);
	retry_write_reg(client,0x8c,0x02); 
	retry_write_reg(client,0x8d,0xfd);
	retry_write_reg(client,0x87,0x1a);
	retry_write_reg(client,0x13,0x07); 
	//POLARITY of Signal 
	retry_write_reg(client,0x15,0x00);
	retry_write_reg(client,0x3a,0x03);
	//black level ,对上电偏绿有改善,如果需要请使用
	/*                                             
	retry_write_reg(client,0x05,0x1f); 
	retry_write_reg(client,0x06,0x60); 
	retry_write_reg(client,0x14,0x1f); 
	retry_write_reg(client,0x06,0xe0); 
	*/
	/*
	retry_write_reg(client,0x17,0x00);
	retry_write_reg(client,0x18,0xa0);
	retry_write_reg(client,0x19,0x00);
	retry_write_reg(client,0x1a,0x78);
	retry_write_reg(client,0x03,0x00);
	*/
	//lens shading 
	retry_write_reg(client,0x35,0x68);
	retry_write_reg(client,0x65,0x68);
	retry_write_reg(client,0x66,0x62); 
	retry_write_reg(client,0x36,0x05); 
	retry_write_reg(client,0x37,0xf6); 
	retry_write_reg(client,0x38,0x46); 
	retry_write_reg(client,0x9b,0xf6); 
	retry_write_reg(client,0x9c,0x46); 
	retry_write_reg(client,0xbc,0x01); 
	retry_write_reg(client,0xbd,0xf6); 
	retry_write_reg(client,0xbe,0x46); 
	//AE 
	retry_write_reg(client,0x82,0x12); 
	retry_write_reg(client,0x83,0x23); 
	retry_write_reg(client,0x9a,0x23); 
	retry_write_reg(client,0x84,0x1a); 
	retry_write_reg(client,0x85,0x20); 
	retry_write_reg(client,0x89,0x04); 
	retry_write_reg(client,0x8a,0x08); 
	retry_write_reg(client,0x86,0x25); 
	retry_write_reg(client,0x96,0xa6); 
	retry_write_reg(client,0x97,0x0c); 
	retry_write_reg(client,0x98,0x18); 
	//AE target
	retry_write_reg(client,0x24,0x72); 
	retry_write_reg(client,0x25,0x82); 
	retry_write_reg(client,0x94,0x0a); 
	retry_write_reg(client,0x80,0x55); 
	//denoise 
	retry_write_reg(client,0x70,0x2f); 
	retry_write_reg(client,0x72,0x4f); 
	retry_write_reg(client,0x73,0x2f); 
	retry_write_reg(client,0x74,0x27); 
	retry_write_reg(client,0x7a,0x0e); 
	retry_write_reg(client,0x7b,0x25); 
	//black level  
	retry_write_reg(client,0X1F,0x20); 
	retry_write_reg(client,0X22,0x20); 
	retry_write_reg(client,0X26,0x20); 
	//模拟部分参数 
	retry_write_reg(client,0X16,0x01); 
	retry_write_reg(client,0xbb,0x20); 
	retry_write_reg(client,0xeb,0x30); 
	retry_write_reg(client,0xf5,0x21); 
	retry_write_reg(client,0xe1,0x3c); 
	retry_write_reg(client,0xbb,0x20); 
	retry_write_reg(client,0X2f,0Xf6); 
	retry_write_reg(client,0x06,0xe0); 
	 //anti black sun spot  
	retry_write_reg(client,0x61,0xd3); 
	retry_write_reg(client,0x79,0x48); 
     //Gamma  
	retry_write_reg(client,0x3b,0x60); 
	retry_write_reg(client,0x3c,0x20); 
	retry_write_reg(client,0x56,0x40); 
	retry_write_reg(client,0x39,0x80); 
	//gamma1 
#if 0
	retry_write_reg(client,0x3f,0xa8); 
	retry_write_reg(client,0X40,0X48); 
	retry_write_reg(client,0X41,0X54); 
	retry_write_reg(client,0X42,0X4E); 
	retry_write_reg(client,0X43,0X44); 
	retry_write_reg(client,0X44,0X3e); 
	retry_write_reg(client,0X45,0X39); 
	retry_write_reg(client,0X46,0X35); 
	retry_write_reg(client,0X47,0X31); 
	retry_write_reg(client,0X48,0X2e); 
	retry_write_reg(client,0X49,0X2b); 
	retry_write_reg(client,0X4b,0X29); 
	retry_write_reg(client,0X4c,0X27); 
	retry_write_reg(client,0X4e,0X23); 
	retry_write_reg(client,0X4f,0X20); 
	retry_write_reg(client,0X50,0X20); 
#endif
	/*				
	//gamma2  高亮度 
	retry_write_reg(client,0x3f,0xc8); 
	retry_write_reg(client,0X40,0X9b); 
	retry_write_reg(client,0X41,0X88); 
	retry_write_reg(client,0X42,0X6e); 
	retry_write_reg(client,0X43,0X59); 
	retry_write_reg(client,0X44,0X4d); 
	retry_write_reg(client,0X45,0X45); 
	retry_write_reg(client,0X46,0X3e); 
	retry_write_reg(client,0X47,0X39); 
	retry_write_reg(client,0X48,0X35); 
	retry_write_reg(client,0X49,0X31); 
	retry_write_reg(client,0X4b,0X2e); 
	retry_write_reg(client,0X4c,0X2b); 
	retry_write_reg(client,0X4e,0X26); 
	retry_write_reg(client,0X4f,0X23); 
	retry_write_reg(client,0X50,0X1F); 

*/
	/*
	//gamma3 清晰亮丽
	retry_write_reg(client,0X3f,0Xa0); 
	retry_write_reg(client,0X40,0X60); 
	retry_write_reg(client,0X41,0X60); 
	retry_write_reg(client,0X42,0X66); 
	retry_write_reg(client,0X43,0X57); 
	retry_write_reg(client,0X44,0X4c); 
	retry_write_reg(client,0X45,0X43); 
	retry_write_reg(client,0X46,0X3c); 
	retry_write_reg(client,0X47,0X37); 
	retry_write_reg(client,0X48,0X32); 
	retry_write_reg(client,0X49,0X2f); 
	retry_write_reg(client,0X4b,0X2c); 
	retry_write_reg(client,0X4c,0X29); 
	retry_write_reg(client,0X4e,0X25); 
	retry_write_reg(client,0X4f,0X22); 
	retry_write_reg(client,0X50,0X20); 
	*/
	//gamma 4 	low noise	 
	retry_write_reg(client,0X3f,0Xc0); 
	retry_write_reg(client,0X40,0X48); 
	retry_write_reg(client,0X41,0X54); 
	retry_write_reg(client,0X42,0X4E); 
	retry_write_reg(client,0X43,0X44); 
	retry_write_reg(client,0X44,0X3E); 
	retry_write_reg(client,0X45,0X39); 
	retry_write_reg(client,0X46,0X34); 
	retry_write_reg(client,0X47,0X30); 
	retry_write_reg(client,0X48,0X2D); 
	retry_write_reg(client,0X49,0X2A); 
	retry_write_reg(client,0X4b,0X28); 
	retry_write_reg(client,0X4c,0X26); 
	retry_write_reg(client,0X4e,0X22); 
	retry_write_reg(client,0X4f,0X20); 
	retry_write_reg(client,0X50,0X1E); 

	
	//color matrix	
	//艳丽
	retry_write_reg(client,0x51,0x0d); 
	retry_write_reg(client,0x52,0x21); 
	retry_write_reg(client,0x53,0x14); 
	retry_write_reg(client,0x54,0x15); 
	retry_write_reg(client,0x57,0x8d); 
	retry_write_reg(client,0x58,0x78); 
	retry_write_reg(client,0x59,0x5f); 
	retry_write_reg(client,0x5a,0x84); 
	retry_write_reg(client,0x5b,0x25); 
	retry_write_reg(client,0x5c,0x0e); 
	retry_write_reg(client,0x5d,0x95); 

	 /* 
	 //适中
	retry_write_reg(client,0x51,0x06); 
	retry_write_reg(client,0x52,0x16); 
	retry_write_reg(client,0x53,0x10); 
	retry_write_reg(client,0x54,0x11); 
	retry_write_reg(client,0x57,0x62); 
	retry_write_reg(client,0x58,0x51); 
	retry_write_reg(client,0x59,0x49); 
	retry_write_reg(client,0x5a,0x65); 
	retry_write_reg(client,0x5b,0x1c); 
	retry_write_reg(client,0x5c,0x0e); 
	retry_write_reg(client,0x5d,0x95); 
	*/  
	  /*
	  //淡
	retry_write_reg(client,0x51,0x03); 
	retry_write_reg(client,0x52,0x0d); 
	retry_write_reg(client,0x53,0x0b); 
	retry_write_reg(client,0x54,0x14); 
	retry_write_reg(client,0x57,0x59); 
	retry_write_reg(client,0x58,0x45); 
	retry_write_reg(client,0x59,0x41); 
	retry_write_reg(client,0x5a,0x5f); 
	retry_write_reg(client,0x5b,0x1e); 
	retry_write_reg(client,0x5c,0x0e); 
	retry_write_reg(client,0x5d,0x95); 
	*/
	
	retry_write_reg(client,0x60,0x20); 
	//AWB	  
	retry_write_reg(client,0x6a,0x81); //01
	retry_write_reg(client,0x23,0x66); //Green gain
	retry_write_reg(client,0xa0,0x03); //07

	retry_write_reg(client,0xa1,0X41); 
	retry_write_reg(client,0xa2,0X0e); 
	retry_write_reg(client,0xa3,0X26); 
	retry_write_reg(client,0xa4,0X0d); 
	retry_write_reg(client,0xa5,0x28); 
	retry_write_reg(client,0xa6,0x04); 
	retry_write_reg(client,0xa7,0x80); 
	retry_write_reg(client,0xa8,0x80); 
	retry_write_reg(client,0xa9,0x28); 
	retry_write_reg(client,0xaa,0x28); 
	retry_write_reg(client,0xab,0x28); 
	retry_write_reg(client,0xac,0x3c); 
	retry_write_reg(client,0xad,0xf0); 
	retry_write_reg(client,0xc8,0x18); 
	retry_write_reg(client,0xc9,0x20); 
	retry_write_reg(client,0xca,0x17); 
	retry_write_reg(client,0xcb,0x1f); 
	retry_write_reg(client,0xaf,0x00); 
	retry_write_reg(client,0xc5,0x18); 
	retry_write_reg(client,0xc6,0x00); 
	retry_write_reg(client,0xc7,0x20); 
	retry_write_reg(client,0xae,0x81); //83
	retry_write_reg(client,0xcc,0x30);
	retry_write_reg(client,0xcd,0x70); 
	retry_write_reg(client,0xee,0x4c); 

	retry_write_reg(client,0xae,0x81); //83 retry ae
	// color saturation

	retry_write_reg(client,0xb0,0xd0); 
	retry_write_reg(client,0xb1,0xc0); 
	retry_write_reg(client,0xb2,0xb0); 
	retry_write_reg(client,0xb3,0x88); 

	//retry_write_reg(client,0x8e,0x05); //0x07,8帧//0x03,10
	//retry_write_reg(client,0x8f,0xfb); //0x79//0xfc,10
	retry_write_reg(client,0x9d,0x99); 

	//switch  
//	retry_write_reg(client,0x1e,0x00); //00,10,20,30
	retry_write_reg(client,0x1e,0x20); //00,10,20,30  //modify by huawu
	
}

uint32_t stop_ae(struct i2c_client *client)
{
	
	return 0;
}

void capture_set(struct i2c_client *client)
{
	
}

