/*
 * Alarm_Actuator.c
 * Created on: Apr 19, 2024
 * Author: Ayat Mohamed
 */

#include "driver.h"
#include "Alarm_Actuator.h"
#include <stdio.h>
#include <stdlib.h>

/*define states */
enum
{
	AA_WAITING,
	AA_ALARM_ON,
	AA_ALARM_OFF,
}AA_State_et;

/* define a State as pointer to function return void and take nothing */
void (*AA_State)(void);


void AA_Init(void)
{
	/*initialize alarm actuator driver */
	//GPIO_INITIALIZATION();
}

STATE_Define(AA_Waiting)
{
	/*define state name */
	AA_State_et = AA_WAITING;

	/*go to waiting state */
	AA_State = STATE_Symbol(AA_Waiting);
}

STATE_Define(AA_Alarm_ON)
{
	/*define state name */
	AA_State_et = AA_ALARM_ON;

	/*go to waiting state */
	AA_State = STATE_Symbol(AA_Waiting);
}
STATE_Define(AA_Alarm_OFF)
{
	/*define state name */
	AA_State_et = AA_ALARM_OFF;

	/*go to waiting state */
	AA_State = STATE_Symbol(AA_Waiting);
}


void Start_Alarm(void)
{
	/*set alarm actuator -> led on */
	//Set_Alarm_actuator(1);

	printf(".... Alarm ON ....\n");
	/* go to alarm on */
	AA_State = STATE_Symbol(AA_Alarm_ON);

}
void Stop_Alarm(void)
{
	/*clear alarm actuator -> led off */
	//Set_Alarm_actuator(0);

	printf(".... Alarm oFF ....\n");
	/* go to alarm off */
	AA_State = STATE_Symbol(AA_Alarm_OFF);

}
