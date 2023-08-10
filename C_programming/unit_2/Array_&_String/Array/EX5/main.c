/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX5 (Array)
 */
# include<stdio.h>
# include <stdlib.h>


int main ()
{
	int search;
	int iteration ;
	int nums[10];
	for(iteration = 1 ; iteration <= 10 ; iteration ++)
	{
		printf("Enter number %d : ",iteration);
		fflush(stdout);
		fflush(stdin);
		scanf("%d",&nums[iteration]);
	}
	printf("Enter the value to search : ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&search);
	for(iteration = 1 ; iteration <= 10 ; iteration ++)
	{
		if (nums[iteration] == search )
		{
			break;
		}
	}
	if(iteration < 10)
	{
		printf("value is exist at element number %d",iteration);
	}
	else
	{
		printf("%d is not exist in numbers ",search);

	}
	return 0;
}
