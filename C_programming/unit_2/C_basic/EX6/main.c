/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX6 (Assignment one)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{

	float number1;
	float number2;
	float temp = 0 ;
	printf("Enter two number :");
	fflush(stdout);
	fflush(stdin);
	scanf("%f %f",&number1,&number2);
	temp = number1;
	number1 = number2 ;
	number2 = temp ;
	printf("After swapping, value of number1 = %f \nAfter swapping, value of number2 = %f",number1,number2);

	return 0;
}
