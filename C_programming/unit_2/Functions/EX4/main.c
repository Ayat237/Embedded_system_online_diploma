/*
 *  main.c
 *  Created on: Aug 17, 2023
 *  Author: Ayat Mohamed
 */
#include <stdio.h>
#include <stdlib.h>
int  power_number(int number,int iteration);

int main ()
{
	int x = power_number(3,3);
	printf("power = %d",x);
	return 0;
}

int power_number(int number,int iteration)
{
	if(iteration == 0)
		return 1;
	else
        return number * power_number(number,iteration-1);
	/*
	 3*power(3,3)= 27
	               3*power(3,2)=9
	                             3*power(3,1)=3 */
}
