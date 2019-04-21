
#ifndef n200pc20_SET_H
#define n200pc20_SET_H

int n200pc20_set_r(struct i2c_client *client,int width,int height);

void n200pc20_set_preview_mode(struct i2c_client *client);
void n200pc20_set_capture_mode(struct i2c_client *client);

void n200pc20_init_setting(struct i2c_client *client);
void n200pc20_set_nightmode(struct i2c_client *client,int enable);

void n200pc20_set_ab_50hz(struct i2c_client *client);
void n200pc20_set_ab_60hz(struct i2c_client *client);

void n200pc20_set_wb_auto(struct i2c_client *client);
void n200pc20_set_wb_cloud(struct i2c_client *client);
void n200pc20_set_wb_daylight(struct i2c_client *client);
void n200pc20_set_wb_incandescence(struct i2c_client *client);
void n200pc20_set_wb_fluorescent(struct i2c_client *client);
void n200pc20_set_wb_tungsten(struct i2c_client *client);

void n200pc20_set_effect_normal(struct i2c_client *client);
void n200pc20_set_effect_grayscale(struct i2c_client *client);
void n200pc20_set_effect_sepia(struct i2c_client *client);
void n200pc20_set_effect_colorinv(struct i2c_client *client);
void n200pc20_set_effect_sepiagreen(struct i2c_client *client);
void n200pc20_set_effect_sepiablue(struct i2c_client *client);
void n200pc20_set_effect_grayinv(struct i2c_client *client);
void n200pc20_set_effect_embossment(struct i2c_client *client);
void n200pc20_set_effect_sketch(struct i2c_client *client);

#endif
