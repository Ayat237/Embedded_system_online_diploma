/*
 * mainEx1.c
 * Object : EX3(pointer)
 * Author: Ayat mohamed
 */


#include<stdio.h>
#include<string.h>

int main()
{
	int *ptr;
	int No;
	int iteration;
	printf("Input the number of elements to store in the array (max 15) :\n");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&No);
	printf("Input %d number of elements in the array :\n",No);
	for(iteration = 0 ; iteration < No ; iteration++)
	{
			printf("element_%d: ",iteration+1);
			fflush(stdin);
			fflush(stdout);
			scanf("%d",(ptr+iteration));
	}
	printf("The elements of array in reverse order are :\n");
	for(iteration = No-1 ; iteration >= 0 ; iteration--)
	{
			printf("element_%d: %d\n",iteration+1,*(ptr+iteration));
	}
	return 0;
}


