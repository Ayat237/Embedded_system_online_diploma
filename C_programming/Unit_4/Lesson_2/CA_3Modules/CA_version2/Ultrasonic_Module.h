/*
 * Ultrasonic_Module.h
 *
 *  Created on: Apr 15, 2024
 *      Author: Q
 */

#ifndef ULTRASONIC_MODULE_H_
#define ULTRASONIC_MODULE_H_
#include "State.h"

/* declare state function US */
STATE_Define(US_Busy); /*void US_Busy */

/*  Description : initialize US */
void US_Init(void);

/* declare a State as pointer to function return void and take nothing */
extern void (*US_State)(void);

/*
 * description : Generate random numbers between Min_Number and Max_Number
 * inputs: Min_Number , Max_Number , Counter
 * output : All random numbers are generated*/
int US_Get_diatance_Random(int min_num , int max_num ,int count);
#endif /* ULTRASONIC_MODULE_H_ */
