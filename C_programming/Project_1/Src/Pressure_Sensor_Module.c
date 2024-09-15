/*
 * Pressure_Sensor_Module.c
 * Created on: Apr 19, 2024
 * Author: Ayat Mohamed
 */
#include "driver.h"
#include "Pressure_Sensor_Module.h"
#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------------------------------------------*/
/*----------------------------------------Definitions-----------------------------------------*/
/*--------------------------------------------------------------------------------------------*/
/* define all variables */
int PS_Pressure_Value = 0;
int Pressure_Pull_Timer = 10000 ;

/*define states */
enum
{
	PS_READING,
	PS_WAITING
}PS_State_et;

/* define a State as pointer to function return void and take nothing */
void (*PS_State)(void);

/*--------------------------------------------------------------------------------------------*/
/*---------------------------------Functions Implementation-----------------------------------*/
/*--------------------------------------------------------------------------------------------*/

void PS_Init(void)
{
	/* define all initialization of Pressure sensor*/
	GPIO_INITIALIZATION();
}

/*--------------------------------------------------------------------------------------------*/
/*---------------------------------States Implementation--------------------------------------*/
/*--------------------------------------------------------------------------------------------*/

STATE_Define(PS_Read_Value)
{
	/*define state name */
	PS_State_et = PS_READING;

	/* Action */
	PS_Pressure_Value = getPressureVal();

	Set_Pressure_Sensor(PS_Pressure_Value);

	/*go to waiting state*/
	PS_State = STATE_Symbol(PS_Waiting);
}

STATE_Define(PS_Waiting)
{
	/*define state name */
	PS_State_et = PS_WAITING;

	/* set pull timer and wait until timer expire */
	Delay(Pressure_Pull_Timer);

	/*go to reading state*/
	PS_State = STATE_Symbol(PS_Read_Value);
	/*Reset pull timer*/
}


