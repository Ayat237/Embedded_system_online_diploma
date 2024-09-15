/*
 * Main_Algorithm.c
 * Created on: Apr 19, 2024
 * Author: Ayat Mohamed
 */

#include "driver.h"
#include "Main_Algorithm.h"
#include <stdio.h>
#include <stdlib.h>

/* define all variables */
int PressureValue = 0;
int Threshold = 20;

/*define states */
enum
{
	MA_PRESSURE_DETECTION,
}MA_State_et;

/* define a State as pointer to function return void and take nothing */
void (*MA_State)(void);



/*Functions Implementation */

STATE_Define(MA_Pressure_Detected)
{
	/*define state name*/
	MA_State_et = MA_PRESSURE_DETECTION;

}

void Set_Pressure_Sensor(int P_Value)
{
	PressureValue = P_Value ;
	/*check high pressure */
	if(PressureValue <= Threshold)
	{
		printf(".... Low Pressure Detected ....\n");
		MA_State = STATE_Symbol(MA_Pressure_Detected);
	}
	else if (PressureValue > Threshold)
	{
		High_Pressure_Dtected();
		printf(".... High Pressure Detected ....\n");
		MA_State = STATE_Symbol(MA_Pressure_Detected);
	}

}
