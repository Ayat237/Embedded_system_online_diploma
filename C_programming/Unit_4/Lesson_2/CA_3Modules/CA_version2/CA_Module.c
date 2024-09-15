/*
 * CA_version1.c
 * Created on: Apr 14, 2024
 * Author: Ayat Mohamed
 */
#include "CA_Module.h"

#include <stdlib.h>
#include <stdio.h>

/* CA Module Variables */
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

/* define a State as pointer to function return void and take nothing */
void (*CA_State)(void);

enum state
{
	CA_WAITING,
	CA_DRIVING
}CA_State_et;

void US_Set_Distance(int distance)
{
	CA_distance = distance;
	if(CA_distance <= CA_threshold)
		{

			CA_State = STATE_Symbol(CA_Waiting);

		}
		else
		{
			CA_State = STATE_Symbol(CA_Driving);
		}
	printf(".......US_distance = %d........\n",CA_distance);
}

STATE_Define(CA_Waiting)
{
	 /*State name*/
	CA_State_et = CA_WAITING;
	/* Action */
	CA_speed = 0;
	/* DC_Motor(CA_speed);*/
	DC_Set_Speed(CA_speed);
	printf("CA_Wating State : CA_distance = %d , CA_speed = %d \n",CA_distance,CA_speed);
}
STATE_Define(CA_Driving)
{
	 /*State name*/
	CA_State_et = CA_DRIVING;
	/* Action */
	CA_speed = 30;

	/* DC_Motor(CA_speed);*/
	DC_Set_Speed(CA_speed);
	printf("CA_Driving State : CA_distance = %d , CA_speed = %d\n",CA_distance,CA_speed);

}
