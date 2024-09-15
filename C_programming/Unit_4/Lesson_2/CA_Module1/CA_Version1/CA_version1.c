/*
 * CA_version1.c
 * Created on: Apr 14, 2024
 * Author: Ayat Mohamed
 */
#include "CA_version1.h"
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

STATE_Define(CA_Waiting)
{
	 /*State name*/
	CA_State_et = CA_WAITING;

	/* Action */
	CA_speed = 0;
	/* DC_Motor(CA_speed);*/


	/* Event check */
	/*US_Get_diatance(CA_distance)*/
	CA_distance = US_Get_diatance_Random(45,55,1);
	if(CA_distance <= CA_threshold)
	{

		CA_State = STATE_Symbol(CA_Waiting);
		printf("CA_Wating State : CA_distance = %d , CA_speed = %d \n",CA_distance,CA_speed);
	}
	else
	{
		CA_State = STATE_Symbol(CA_Driving);
	}
}
STATE_Define(CA_Driving)
{
	 /*State name*/
	CA_State_et = CA_DRIVING;

	/* Action */
	CA_speed = 30;
	/* DC_Motor(CA_speed);*/


	/* Event check */
	/*US_Get_diatance(CA_distance)*/
	CA_distance = US_Get_diatance_Random(45,55,1);
	if(CA_distance <= CA_threshold)
	{

		CA_State = STATE_Symbol(CA_Waiting);
	}
	else
	{
		CA_State = STATE_Symbol(CA_Driving);
		printf("CA_Driving State : CA_distance = %d , CA_speed = %d\n",CA_distance,CA_speed);
	}

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
