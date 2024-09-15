/*
 * main.c
 * Created on: Apr 14, 2024
 * Author: Ayat Mohamed
 */
#include "CA_version1.h"
#include <stdlib.h>
#include <stdio.h>

void setup()
{
	/*set states pointers for each block*/
	CA_State = STATE_Symbol(CA_Waiting);
}
int main()
{
	volatile int delay = 0;
	/* to begin from waiting state */
	setup();
	while(1)
	{
		/* to make a transitions between states*/
		CA_State();
		/* delay */
		for(delay = 0 ; delay <5000 ; delay ++);
	}
	return 0;
}

