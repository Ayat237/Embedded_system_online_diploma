/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX2 (Assignment two)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{

	float number1;
	float number2;
	float number3;
	printf("Enter a number1 and number2 and number3 : ");
	fflush(stdout);
	fflush(stdin);
	scanf("%f %f %f",&number1,&number2,&number3);
	if((number1 > number2) && (number1 > number3))
	{
		printf("largest number = %f",number1);
	}
	else if ((number2 > number1) && (number2 > number3))
	{
		printf("largest number = %f",number2);
	}
	else
	{
		printf("largest number = %f",number3);
	}
	return 0;
}
