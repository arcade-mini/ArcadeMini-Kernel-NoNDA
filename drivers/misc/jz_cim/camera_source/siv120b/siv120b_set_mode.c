#include <asm/jzsoc.h>
#include "../../jz_sensor.h"
#include <linux/i2c.h>

#define siv120b_DEBUG
#ifdef siv120b_DEBUG
#define dprintk(x...)   do{printk("cm3511---\t");printk(x);printk("\n");}while(0)
#else
#define dprintk(x...)
#endif

/*----------------------------------set white balance------------------------------------------------*/

void siv120b_set_wb_auto_mode(struct i2c_client *client)
{
	sensor_write_reg(client,0x00,0x02);
	sensor_write_reg(client,0x10,0xD3);   // select Auto WB
	sensor_write_reg(client,0x60,0xAA);
	sensor_write_reg(client,0x61,0xBE);
}

void siv120b_set_wb_sunny_mode(struct i2c_client *client)
{
	sensor_write_reg(client,0x00,0x02);
	sensor_write_reg(client,0x10,0x00);   // select Daylight
	sensor_write_reg(client,0x60,0xA1);
	sensor_write_reg(client,0x61,0x8B);
}

void siv120b_set_wb_cloudy_mode(struct i2c_client *client)
{ 
	sensor_write_reg(client,0x00,0x02);
	sensor_write_reg(client,0x10,0x00);   // select Cloud
	sensor_write_reg(client,0x60,0xCA);
	sensor_write_reg(client,0x61,0xCF);
}

void siv120b_set_wb_office_mode(struct i2c_client *client)
{ 
	sensor_write_reg(client,0x00,0x02);
	sensor_write_reg(client,0x10,0x00);   // select Incandescence
	sensor_write_reg(client,0x60,0x75);
	sensor_write_reg(client,0x61,0xD3);	
}

void siv120b_set_wb_fluorescent_mode(struct i2c_client *client)
{
	sensor_write_reg(client,0x00,0x02);
	sensor_write_reg(client,0x10,0x00);   // select Fluorescent
	sensor_write_reg(client,0x60,0x9D);
	sensor_write_reg(client,0x61,0xCD);
}

/*---------------------------------------set banding------------------------------------------------*/
void siv120b_ab_auto(struct i2c_client *client)
{
	sensor_write_reg(client,0x00,0x01);
	sensor_write_reg(client,0x10,0x80);
}

/*---------------------------------------set effect------------------------------------------------*/

void siv120b_set_effect_normal(struct i2c_client *client)
{
	sensor_write_reg(client,0x00,0x03);
	sensor_write_reg(client,0xB6,0x00);
}

void siv120b_set_effect_sepia(struct i2c_client *client)
{
	sensor_write_reg(client,0x00,0x03);
	sensor_write_reg(client,0xB6,0x80);
	sensor_write_reg(client,0xB7,0x60);
	sensor_write_reg(client,0xB8, 0xA0);
}

void siv120b_set_effect_greenish(struct i2c_client *client)
{
	sensor_write_reg(client,0x00,0x03);
	sensor_write_reg(client,0xB6,0x80);
	sensor_write_reg(client,0xB7,0x50);
	sensor_write_reg(client,0xB8,0x50);
}

void siv120b_set_effect_aqua(struct i2c_client *client)
{
	sensor_write_reg(client,0x00,0x03);	//Aqua mode
	sensor_write_reg(client,0xB6,0x80);
	sensor_write_reg(client,0xB7,0xC0);
	sensor_write_reg(client,0xB8,0x60);
}

void siv120b_set_effect_blackwhite(struct i2c_client *client)
{
	sensor_write_reg(client,0x00,0x03);
	sensor_write_reg(client,0xB6,0x40);	//Mono mode
}

void siv120b_set_effect_negative(struct i2c_client *client)
{
	sensor_write_reg(client,0x00,0x03);
	sensor_write_reg(client,0xB6,0x10);	//Y,Cb,Cr Inverse mode
}

void siv120b_set_effect_blackboard(struct i2c_client *client)
{
	sensor_write_reg(client,0x00,0x03);
	sensor_write_reg(client,0xB6,0x20);	//Inverse Mono mode
}

