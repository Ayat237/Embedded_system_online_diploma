/*
 * mainEx1.c
 * Object : EX1(pointer)
 * Author: Ayat mohamed
 */


#include<stdio.h>
#include<string.h>

int main()
{
	char *ptr="A";
	int iteration;
	for(iteration = 0 ; iteration < 26 ; iteration++)
	{
		if((*ptr >= 'A')&&((*ptr <= 'Z')))
		{
			printf("%c ",*ptr+iteration);
		}
	}
	return 0;
}
