/*
 * linux/drivers/misc/camera_source/ov7675/camera.h -- Ingenic CIM driver
 *
 * Copyright (C) 2005-2010, Ingenic Semiconductor Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#ifndef OV7675_SET_H
#define OV7675_SET_H


#include "../../jz_cim_core.h"
#include "../../jz_sensor.h"


struct ov7675_sensor
{
	struct i2c_client      		 *client;
	struct camera_sensor_desc	 desc;
};

#endif
