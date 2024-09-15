/*
 * main.c
 * Created on: Apr 14, 2024
 * Author: Ayat Mohamed
 */
#include <stdlib.h>
#include <stdio.h>
#include "CA_Module.h"
#include "DC_Motor_Module.h"
#include "Ultrasonic_Module.h"

void setup()
{
	US_Init();
	DC_Init();
	/*set states pointers for each block*/
	CA_State = STATE_Symbol(CA_Waiting);
	DC_State = STATE_Symbol(DC_Idle);
	US_State = STATE_Symbol(US_Busy);
}
int main()
{
	volatile int delay = 0;
	/* to begin from waiting state */
	setup();
	while(1)
	{
		/* to make a transitions between states*/
		US_State();
		DC_State();
		CA_State();
		/* delay */
		for(delay = 0 ; delay <5000 ; delay ++);
	}
	return 0;
}

