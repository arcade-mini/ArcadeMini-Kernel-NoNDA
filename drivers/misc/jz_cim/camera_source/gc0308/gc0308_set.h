#ifndef gc0308_SET_H
#define gc0308_SET_H

#include<linux/i2c.h>

void gc0308_init_setting(struct i2c_client *client);
void gc0308_preview_set(struct i2c_client *client);
void gc0308_capture_set(struct i2c_client *client);
int gc0308_windows_switch(struct i2c_client *client,int width,int height);
void gc0308_set_nightmode(struct i2c_client *client,int enable);

void gc0308_set_ab_50hz(struct i2c_client *client);
void gc0308_set_ab_60hz(struct i2c_client *client);

void gc0308_set_wb_auto(struct i2c_client *client);
void gc0308_set_wb_cloud(struct i2c_client *client);
void gc0308_set_wb_daylight(struct i2c_client *client);
void gc0308_set_wb_incandescence(struct i2c_client *client);
void gc0308_set_wb_fluorescent(struct i2c_client *client);
void gc0308_set_wb_tungsten(struct i2c_client *client);

void gc0308_set_effect_normal(struct i2c_client *client);
void gc0308_set_effect_grayscale(struct i2c_client *client);
void gc0308_set_effect_sepia(struct i2c_client *client);
void gc0308_set_effect_colorinv(struct i2c_client *client);
void gc0308_set_effect_sepiagreen(struct i2c_client *client);
void gc0308_set_effect_sepiablue(struct i2c_client *client);
void gc0308_set_effect_grayinv(struct i2c_client *client);
void gc0308_set_effect_embossment(struct i2c_client *client);
void gc0308_set_effect_sketch(struct i2c_client *client);

#endif

