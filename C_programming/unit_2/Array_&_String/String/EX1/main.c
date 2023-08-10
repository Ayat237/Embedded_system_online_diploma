/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX1 (String)
 */
# include<stdio.h>
# include <stdlib.h>
# include <string.h>

int main ()
{
	char string[100];
	char character;
    int i;
    int counter = 0;
	printf("enter the string : \n");
	fflush(stdout);
	fflush(stdin);
    gets(string);
    printf("enter the character to find frequency :\n");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&character);
	for (i = 0 ; i < strlen(string) ; i++)
	{
		if(character == string[i])
		{
			counter +=1;
		}
		else
		{

		}
	}
	printf("frequency of %c : %d",character , counter);
	return 0;
}

