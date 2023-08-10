/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX3 (Array)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{
	int n , location , element;
	printf("enter no of element:\n");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&n);
	int arr[100];
	int i;
	for (i= 0 ;i < n ; i++)
	{
		printf("enter number %d : ",i);
		fflush(stdout);
		fflush(stdin);
		scanf("%d",&arr[i]);
	}
	printf("enter the element to be inserted :\n");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&element);
	printf("enter the location :\n");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&location);
	for (i= n-1 ;i >=location ; i--)
	{
		arr[i+1] = arr[i];
	}
	arr[location] = element ;
	for (i= 0 ;i <= n ; i++)
		{
			printf("%d " , arr[i]);
		}
	return 0;
}

