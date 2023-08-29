/*
 *  main.c
 *  Created on: Aug 17, 2023
 *  Author: Ayat Mohamed
 */

#include <stdio.h>
int Rec_Factorial(int number);

int main()
{
	int number;
	printf("enter the number to get factorial : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&number);
	int fact = Rec_Factorial(number);
	printf("factorial = %d",fact);
	return 0 ;
}

int Rec_Factorial(int number)
{
	/* hold the factorial number*/
	int factorial = 1;

	if (number == 0 || number == 1)
	{
		factorial = 1;
	}
	else
	{
		/*
		  5*4!-->
		         4*3!-->
		                3*2!-->
		                        2*1!-->
		                               1*0! = 5*5*3*2*1 = 120  */
		factorial = number*Rec_Factorial(number-1);
	}
	return factorial;
}
