/*
 * Pressure_Sensor_Module.h
 * Created on: Apr 19, 2024
 * Author: Ayat Mohamed
 */

#ifndef PRESSURE_SENSOR_MODULE_H_
#define PRESSURE_SENSOR_MODULE_H_
#include "state.h"

/* define all states function */
STATE_Define(PS_Read_Value);
STATE_Define(PS_Waiting);

void PS_Init(void);

/* declare a State as pointer to function return void and take nothing */
extern void (*PS_State)(void);

#endif /* PRESSURE_SENSOR_MODULE_H_ */
