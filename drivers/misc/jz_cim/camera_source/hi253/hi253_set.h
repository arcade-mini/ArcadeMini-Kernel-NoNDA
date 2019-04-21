#ifndef hi253_CAMERA_H
#define hi253_CAMERA_H

void hi253_size_switch(struct i2c_client *client,int width,int height,int setmode);

void hi253_preview_set_reg(struct i2c_client *client);
void hi253_capture_set_reg(struct i2c_client *client);
void hi253_capture_set(struct i2c_client *client);
void hi253_preview_set(struct i2c_client *client);

void hi253_init_setting(struct i2c_client *client);
void hi253_set_night_reg(struct i2c_client *client,int enable);

void hi253_set_ab_50hz(struct i2c_client *client);
void hi253_set_ab_60hz(struct i2c_client *client);

void hi253_set_wb_auto(struct i2c_client *client);
void hi253_set_wb_cloud(struct i2c_client *client);
void hi253_set_wb_daylight(struct i2c_client *client);
void hi253_set_wb_incandescence(struct i2c_client *client);
void hi253_set_wb_fluorescent(struct i2c_client *client);
void hi253_set_wb_tungsten(struct i2c_client *client);

void hi253_set_effect_normal(struct i2c_client *client);
void hi253_set_effect_grayscale(struct i2c_client *client);
void hi253_set_effect_sepia(struct i2c_client *client);
void hi253_set_effect_colorinv(struct i2c_client *client);
void hi253_set_effect_sepiagreen(struct i2c_client *client);
void hi253_set_effect_sepiablue(struct i2c_client *client);
void hi253_set_effect_grayinv(struct i2c_client *client);
void hi253_set_effect_embossment(struct i2c_client *client);
void hi253_set_effect_sketch(struct i2c_client *client);

#endif
