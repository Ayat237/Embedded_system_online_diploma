/*
 * Alarm_Monitor.h
 * Created on: Apr 19, 2024
 * Author: Ayat Mohamed
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include "state.h"
/* define all states function */
STATE_Define(AM_Alarm_ON);
STATE_Define(AM_Alarm_OFF);
STATE_Define(AM_Waiting);

void AM_Init(void);

/* declare a State as pointer to function return void and take nothing */
extern void (*AM_State)(void);



#endif /* ALARM_MONITOR_H_ */
