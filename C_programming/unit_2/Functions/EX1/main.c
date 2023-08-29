/*
 *  main.c
 *  Created on: Aug 17, 2023
 *  Author: Ayat Mohamed
 */

#include <stdio.h>
int PrimeNumbers(int number);

int main()
{
	int number1 ,number2;
	int clickOn =0;
	int flag;
	int iterator;
	printf("enter the two numbers intervals :\n");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&number1);
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&number2);
	/* check on interval */
	if(number1>number2)
	{
		printf("No prime numbers in this interval \nIf you want to swap this number click on 1 else click on 0:\n");
		fflush(stdin);
			fflush(stdout);
			scanf("%d",&clickOn);
			/* if the user click on 1 ,the interval will be swapped ,
			and we will get the prime numbers between them */
			if(clickOn == 1)
			{
				number1 = number1 + number2;//n1 = 10 + 30 = 40
				number2 = number1 - number2;//n2 = 40 - 30 = 10
				number1 = number1 - number2;//n1 = 40 - 10 = 30
				// n1 = 30 and n2 = 10
			}
			else
			{
				/* if user click on 0 */
				printf("the program is ended\n");
				return 0;
			}

	}
	/* print the prime number between two interval */
	printf("Prime numbers between %d and %d = ",number1,number2);
	for(iterator = number1 ;iterator < number2 ;iterator++)
	{
		flag =	PrimeNumbers(iterator);

		if(flag == 0)
		{
			printf("%d  ",iterator);
		}
	}
	return 0 ;
}


int PrimeNumbers(int number)
{
	int flag = 0 ;
	int iterator = 0;

	for (iterator = 2 ; iterator <= number/2 ; iterator ++)
	{
		if (number % iterator == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
