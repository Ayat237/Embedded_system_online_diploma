/*
 * main.c
 * Created on: Apr 19, 2024
 * Author: Ayat Mohamed
 */
#include <stdint.h>
#include <stdio.h>
#include "driver.h"
#include "Pressure_Sensor_Module.h"
#include "Main_Algorithm.h"
#include "Alarm_Monitor.h"
#include "Alarm_Actuator.h"

/* Discription : intialize all modules and states */
void setup(void);

int main (){

	setup();
	while (1)
	{
		
		PS_State();
		MA_State();
		AM_State();
		AA_State();
	}
}

void setup(void)
{
	/* initialize all modules*/
	PS_Init();
	AM_Init();
	AA_Init();

	/*set states pointers for each block*/
	PS_State = STATE_Symbol(PS_Read_Value);
	MA_State = STATE_Symbol(MA_Pressure_Detected);
	AM_State = STATE_Symbol(AM_Alarm_OFF);
	AA_State = STATE_Symbol(AM_Waiting);

}
