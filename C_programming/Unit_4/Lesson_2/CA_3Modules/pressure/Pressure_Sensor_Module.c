/*
 * Pressure_Sensor_Module.c
 * Created on: Apr 19, 2024
 * Author: Ayat Mohamed
 */
#include "driver.h"
#include "Pressure_Sensor_Module.h"
#include <stdio.h>
#include <stdlib.h>

/* define all variables */
int Pressure_Value = 0;
int Pressure_Pull_Timer = 10000;

/*define states */
enum
{
	PS_READING,
	PS_WAITING
}PS_State_et;

/* define a State as pointer to function return void and take nothing */
void (*PS_State)(void);

void PS_Init(void)
{
	/* define all initialization of Pressure sensor*/
	//GPIO_INITIALIZATION();
}


STATE_Define(PS_Read_Value)
{
	/*define state name */
	PS_State_et = PS_READING;

	/* Action */
	Pressure_Value = US_Get_diatance_Random(15,25,1);
	printf("PS_Read_Value : Pressure = %d ----> PS_Waiting\n",Pressure_Value);
	Set_Pressure_Sensor(Pressure_Value);
	/*go to waiting state*/
	PS_State = STATE_Symbol(PS_Waiting);

}
STATE_Define(PS_Waiting)
{
	/*define state name */
	PS_State_et = PS_WAITING;

	/* set pull timer and wait until timer expire */
	Delay(Pressure_Pull_Timer);
	printf("...PS Sensor Waiting....\n");
	/*go to reading state*/
	PS_State = STATE_Symbol(PS_Read_Value);
	/*Reset pull timer*/
}

int US_Get_diatance_Random(int min_num , int max_num ,int count)
{
	/* Generate random number between low_num and range */
	int i ;
	int rand_num;
	for (i = 0 ; i < count ; i ++)
	{
		rand_num = (rand() % (max_num - min_num +1)) + min_num;
		return rand_num;
	}

}
