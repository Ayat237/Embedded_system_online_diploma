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
	int summ = 0;
	int iteration = 0;
	for(iteration = 1 ; iteration <= number ; iteration ++)
	{
		summ += iteration;
	}
	printf("sum = %d",summ);

	return 0;
}



