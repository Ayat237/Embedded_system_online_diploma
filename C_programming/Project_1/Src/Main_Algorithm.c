/*
 * Main_Algorithm.c
 * Created on: Apr 19, 2024
 * Author: Ayat Mohamed
 */

#include "driver.h"
#include "Main_Algorithm.h"
#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------------------------------------------*/
/*----------------------------------------Definitions-----------------------------------------*/
/*--------------------------------------------------------------------------------------------*/

/* define all variables */
int MA_Pressure_Value = 0;
int Threshold = 20;

/*define states */
enum
{
	MA_PRESSURE_DETECTION
}MA_State_et;

/* define a State as pointer to function return void and take nothing */
void (*MA_State)(void);

/*--------------------------------------------------------------------------------------------*/
/*---------------------------------States Implementation--------------------------------------*/
/*--------------------------------------------------------------------------------------------*/

STATE_Define(MA_Pressure_Detected)
{
	/*define state name*/
	MA_State_et = MA_PRESSURE_DETECTION;
}

/*--------------------------------------------------------------------------------------------*/
/*------------------------------Connections Implementations-----------------------------------*/
/*--------------------------------------------------------------------------------------------*/

Set_Pressure_Sensor(int P_Value)
{
	MA_Pressure_Value = P_Value ;

    /*check high pressure */
	if(MA_Pressure_Value <= Threshold)
	{
		MA_State = STATE_Symbol(MA_Pressure_Detected);
	}
	else
	{
		High_Pressure_Dtected();
		MA_State = STATE_Symbol(MA_Pressure_Detected);
	}
}

