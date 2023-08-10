/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX2 (Array)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{
	int n;
	printf("enter the number of data :");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&n);
	float arr[n];
	int i ;
	float sum = 0.0;
	float avg = 0.0;
	for (i= 0 ;i <n ; i++)
	{
		printf("enter number %d : ",i+1);
		fflush(stdout);
		fflush(stdin);
		scanf("%f",&arr[i]);
	}
	for (i= 0 ;i <n ; i++)
		{
			sum += arr[i];
		}
	avg = sum / n;
	printf("average = %f  ",avg);
	return 0;
}
