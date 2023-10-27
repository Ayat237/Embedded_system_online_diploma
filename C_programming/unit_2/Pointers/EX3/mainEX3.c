/*
 * mainEx1.c
 * Object : EX3(pointer)
 * Author: Ayat mohamed
 */


#include<stdio.h>
#include<string.h>

int main()
{
	char *ptr="w3resource";
	int iteration;
	printf("Input a string :%s\n",ptr);
	printf("Reverse of the string is :");
	for(iteration = 9 ; iteration >=0 ; iteration--)
	{
			printf("%c",*(ptr+iteration));
	}
	return 0;
}


