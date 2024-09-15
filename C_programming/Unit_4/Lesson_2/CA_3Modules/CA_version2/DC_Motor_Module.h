/*
 * DC_Motor_Module.h
 *
 *  Created on: Apr 15, 2024
 *      Author: Q
 */

#ifndef DC_MOTOR_MODULE_H_
#define DC_MOTOR_MODULE_H_
#include "State.h"

/* declare state function DC */
STATE_Define(DC_Idle); /*void DC_Idle */
STATE_Define(DC_Busy); /*void DC_Busy */

/*  Description : initialize DC_Motor */
void DC_Init(void);

/* declare a State as pointer to function return void and take nothing */
extern void (*DC_State)(void);


#endif /* DC_MOTOR_MODULE_H_ */
