/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX4 (Assignment one)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{

	float number1;
	float number2;
	float Multiply = 0 ;
	printf("Enter two number :");
	fflush(stdout);
	fflush(stdin);
	scanf("%f %f",&number1,&number2);
	Multiply = number1 * number2;
	printf("multiplication = %f",Multiply);

	return 0;
}
