#ifndef gc0328_SET_H
#define gc0328_SET_H

#include<linux/i2c.h>

void gc0328_init_setting(struct i2c_client *client);
void gc0328_preview_set(struct i2c_client *client);
void gc0328_capture_set(struct i2c_client *client);
int gc0328_windows_switch(struct i2c_client *client,int width,int height);
void gc0328_set_nightmode(struct i2c_client *client,int enable);

void gc0328_set_ab_50hz(struct i2c_client *client);
void gc0328_set_ab_60hz(struct i2c_client *client);

void gc0328_set_wb_auto(struct i2c_client *client);
void gc0328_set_wb_cloud(struct i2c_client *client);
void gc0328_set_wb_daylight(struct i2c_client *client);
void gc0328_set_wb_incandescence(struct i2c_client *client);
void gc0328_set_wb_fluorescent(struct i2c_client *client);
void gc0328_set_wb_tungsten(struct i2c_client *client);

void gc0328_set_effect_normal(struct i2c_client *client);
void gc0328_set_effect_grayscale(struct i2c_client *client);
void gc0328_set_effect_sepia(struct i2c_client *client);
void gc0328_set_effect_colorinv(struct i2c_client *client);
void gc0328_set_effect_sepiagreen(struct i2c_client *client);
void gc0328_set_effect_sepiablue(struct i2c_client *client);
void gc0328_set_effect_grayinv(struct i2c_client *client);
void gc0328_set_effect_embossment(struct i2c_client *client);
void gc0328_set_effect_sketch(struct i2c_client *client);

#endif

