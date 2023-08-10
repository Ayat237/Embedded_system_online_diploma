/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX3 (String)
 */
# include<stdio.h>
# include <stdlib.h>
# include <string.h>

int main ()
{
	char string[100];
	char copy[100];
	int i;
	printf("enter the string : \n");
	fflush(stdout);
	fflush(stdin);
	gets(string);

	for (i = 0 ; i < strlen(string) ; i++)
	{
		copy[i] = string[strlen(string)-1-i];
	}
	copy[i]=0;
	printf("reverse string is  : %s",copy);

	return 0;
}

