/*
 * Alarm_Actuator.h
 * Created on: Apr 19, 2024
 * Author: Ayat Mohamed
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_
#include "state.h"

/* define all states function */
STATE_Define(AA_Alarm_ON);
STATE_Define(AA_Alarm_OFF);
STATE_Define(AA_Waiting);

void AA_Init(void);

/* declare a State as pointer to function return void and take nothing */
extern void (*AA_State)(void);




#endif /* ALARM_ACTUATOR_H_ */
