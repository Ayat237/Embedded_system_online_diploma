/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX3 (Assignment one)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{

	int number1;
	int number2;
	int sum = 0 ;
	printf("Enter two number :");
	fflush(stdout);
	fflush(stdin);
	scanf("%d %d",&number1,&number2);
	sum = number1 +number2;
	printf("sum = %d",sum);

	return 0;
}
