/*
 * Ultrasonic_Module.c
 *
 *  Created on: Apr 15, 2024
 *      Author: Q
 */
#include "Ultrasonic_Module.h"
#include <stdlib.h>
#include <stdio.h>


int US_distance = 0;

/*define states */
enum
{
	US_BUSY
}US_State_et;

/* define a State as pointer to function return void and take nothing */
void (*US_State)(void);

void US_Init(void)
{
	/*init ultrasonic driver*/
	printf(".....Ultrasonic is initialized \n");
}
STATE_Define(US_Busy)
{
	 /*State name*/
	US_State_et = US_BUSY;
	/* state action */
	US_distance = US_Get_diatance_Random(45,55,1);
	printf("US_Busy State : CA_distance = %d  \n",US_distance);
	/* send distance signal */
	US_Set_Distance(US_distance);
	US_State = STATE_Symbol(US_Busy);
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
