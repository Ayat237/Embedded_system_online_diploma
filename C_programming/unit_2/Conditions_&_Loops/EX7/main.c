/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX6 (Assignment two)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{
	int number;
	printf("Enter an integer :");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&number);
	int factorial = 1;
	int iteration = 0;
	if (number == 0 || number == 1)
	{
		printf("factorial = 1");
	}
	else if (number < 0)
	{
		printf("factorial of negative number is not exist");
	}
	else
	{
		for(iteration = number ; iteration >=1 ; iteration --)
		{
			factorial *= iteration;
		}
		printf("factorial = %d",factorial);
	}

	return 0;
}

