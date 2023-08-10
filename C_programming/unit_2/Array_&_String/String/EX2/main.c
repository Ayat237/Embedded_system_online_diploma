/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX2 (String)
 */
# include<stdio.h>
# include <stdlib.h>
# include <string.h>

int main ()
{
	char string[100];
    int i;
    int counter = 0;
	printf("enter the string : \n");
	fflush(stdout);
	fflush(stdin);
    gets(string);

	while(string[i] !=0)
	{
			counter +=1;
			i++;
	}
	printf("length of string  : %d", counter);
	return 0;
}

