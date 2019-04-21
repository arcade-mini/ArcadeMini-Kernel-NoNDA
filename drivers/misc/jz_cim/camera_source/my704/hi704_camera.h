/*
 * linux/drivers/misc/camera_source/hi704/camera.h -- Ingenic CIM driver
 *
 * Copyright (C) 2005-2010, Ingenic Semiconductor Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#ifndef HI704_SET_H
#define HI704_SET_H


#include "../../jz_cim_core.h"
#include "../../jz_sensor.h"


struct hi704_sensor
{
	struct i2c_client      		 *client;
	struct camera_sensor_desc	 desc;
};

#endif
