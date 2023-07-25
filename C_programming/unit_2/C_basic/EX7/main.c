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
	printf("Enter number1 and number2 :");
	fflush(stdout);
	fflush(stdin);
	scanf("%f %f",&number1,&number2);
	number1 = number1 + number2;
	number2 = number1 - number2;
	number1 = number1 - number2; ;
	printf("After swapping, value of number1 = %f \nAfter swapping, value of number2 = %f",number1,number2);

	return 0;
}
