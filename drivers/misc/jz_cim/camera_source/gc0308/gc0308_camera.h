/*
 * linux/drivers/misc/camera_source/gc0308/camera.h -- Ingenic CIM driver
 *
 * Copyright (C) 2005-2010, Ingenic Semiconductor Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#ifndef gc0308_CAMERA_H
#define gc0308_CAMERA_H


#include "../../jz_cim_core.h"
#include "../../jz_sensor.h"

/*
struct private_info
{
	int cur_rwidth;
	int cur_rheight;
	int cur_mode;

	int cur_focus_mode;
};
*/

struct gc0308_sensor
{
	struct i2c_client      		 *client;
//	struct private_info		 pinfo;
	struct camera_sensor_desc	 desc;
};

#endif
