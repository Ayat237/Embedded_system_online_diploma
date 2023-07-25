/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX4(Assignment two)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{

	float number;
	printf("Enter an integer number :");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&number);
	if (number > 0)
	{
		printf("%.2f is positive",number);
	}
	else if (number < 0)
	{
		printf("%.2f is negative",number);
	}
	else
	{
		printf("you entered zero",number);
	}

	return 0;
}
