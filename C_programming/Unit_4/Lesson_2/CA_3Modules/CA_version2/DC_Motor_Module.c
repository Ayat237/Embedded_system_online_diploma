/*
 * DC_Motor_Module.c
 *
 *  Created on: Apr 15, 2024
 *      Author: Q
 */
#include "DC_Motor_Module.h"
#include <stdlib.h>
#include <stdio.h>

int DC_speed = 0;

/*define states */
enum
{
	DC_IDLE,
	DC_BUSY
}DC_State_et;

/* define a State as pointer to function return void and take nothing */
void (*DC_State)(void);

void DC_Init(void)
{
	/*init DC Motor driver*/
	printf(".....DC Motor is initialized \n");
}
/* connection */

STATE_Define(DC_Idle)
{
	 /*State name*/
	DC_State_et = DC_IDLE ;

	printf("DC_Idle State : speed = %d\n",DC_speed);
}
STATE_Define(DC_Busy)
{
	 /*State name*/
	DC_State_et = DC_BUSY ;

	printf("DC_Busy State : speed = %d\n",DC_speed);
	DC_State = STATE_Symbol(DC_Idle);
}


void DC_Set_Speed(int speed)
{
	DC_speed = speed;
	DC_State = STATE_Symbol(DC_Idle);

}
