/*
 * sensor_driver.h
 *
 * Created: 20/09/2019 17:52:42
 *  Author: brunn
 */ 


#ifndef SENSOR_DRIVER_H_
#define SENSOR_DRIVER_H_

int sensor_init(void (* callback_sensor)(float));

#endif /* SENSOR_DRIVER_H_ */