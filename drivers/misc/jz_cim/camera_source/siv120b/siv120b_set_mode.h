#ifndef SIV120B_SET_MODE_H
#define SIV120B_SET_MODE_H

#include<linux/i2c.h>

void siv120b_night_select(struct i2c_client *client,int enable);

void siv120b_set_wb_auto_mode(struct i2c_client *client);
void siv120b_set_wb_sunny_mode(struct i2c_client *client);
void siv120b_set_wb_cloudy_mode(struct i2c_client *client);
void siv120b_set_wb_office_mode(struct i2c_client *client);
void siv120b_set_wb_home_mode(struct i2c_client *client);
void siv120b_set_wb_fluorescent_mode(struct i2c_client *client);
void siv120b_set_effect_blackboard(struct i2c_client *client);

void siv120b_ab_auto(struct i2c_client *client);
void siv120b_ab_50hz(struct i2c_client *client);
void siv120b_ab_60hz(struct i2c_client *client);
void siv120b_ab_off(struct i2c_client *client);


void siv120b_set_effect_normal(struct i2c_client *client);
void siv120b_set_effect_sepia(struct i2c_client *client);
void siv120b_set_effect_bluish(struct i2c_client *client);
void siv120b_set_effect_greenish(struct i2c_client *client);
void siv120b_set_effect_reddish(struct i2c_client *client);
void siv120b_set_effect_yellowish(struct i2c_client *client);
void siv120b_set_effect_blackwhite(struct i2c_client *client);
void siv120b_set_effect_negative(struct i2c_client *client);

#endif

