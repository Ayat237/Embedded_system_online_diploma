/*
 * Alarm_Monitor.c
 * Created on: Apr 19, 2024
 * Author: Ayat Mohamed
 */
#include "driver.h"
#include "Alarm_Monitor.h"
#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------------------------------------------*/
/*----------------------------------------Definitions-----------------------------------------*/
/*--------------------------------------------------------------------------------------------*/

/* define all variables */
int Alarm_Period = 60000; /* 60 sec */

/*define states */
enum
{
	AM_ALARM_ON,
	AM_ALARM_OFF,
	AM_WAITING
}AM_State_et;

/* define a State as pointer to function return void and take nothing */
void (*AM_State)(void);

/*--------------------------------------------------------------------------------------------*/
/*---------------------------------Functions Implementation-----------------------------------*/
/*--------------------------------------------------------------------------------------------*/

void AM_Init(void)
{
	/* initialize alarm monitor driver */
	GPIO_INITIALIZATION();
}

/*--------------------------------------------------------------------------------------------*/
/*---------------------------------States Implementation--------------------------------------*/
/*--------------------------------------------------------------------------------------------*/

STATE_Define(AM_Alarm_OFF)
{
	/*define state name */
	AM_State_et = AM_ALARM_OFF;

	/* Action */
	Stop_Alarm();

	/*go to AM_Alarm_OFF state*/
	AM_State = STATE_Symbol(AM_Alarm_OFF);
}

STATE_Define(AM_Alarm_ON)
{
	/*define state name */
	AM_State_et = AM_ALARM_ON;

	/* Action */
	Start_Alarm();

	/*go to waiting state */
	AM_State = STATE_Symbol(AM_Waiting);

}

STATE_Define(AM_Waiting)
{
	/*define state name */
	AM_State_et = AM_WAITING;
    
	/* set Alarm_Period and wait until timer expire */
	Delay(Alarm_Period);

	/* Action */
	Stop_Alarm();

	/*go to AM_Alarm_OFF state*/
	AM_State = STATE_Symbol(AM_Alarm_OFF);
	/*Reset pull timer*/
}

/*--------------------------------------------------------------------------------------------*/
/*------------------------------Connections Implementations-----------------------------------*/
/*--------------------------------------------------------------------------------------------*/

void High_Pressure_Dtected(void)
{
	/*when high pressure detected the alarm will start */
	AM_State = STATE_Symbol(AM_Alarm_ON);
}
