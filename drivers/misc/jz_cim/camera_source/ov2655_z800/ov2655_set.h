#ifndef ov2655_SET_H
#define ov2655_SET_H

#include<linux/i2c.h>

void ov2655_init_setting(struct i2c_client *client);
void ov2655_preview_set(struct i2c_client *client);
void ov2655_capture_set(struct i2c_client *client);
void ov2655_size_switch(struct i2c_client *client,int width,int height,int setmode);

void ov2655_read_shutter(struct i2c_client *client);

#endif

