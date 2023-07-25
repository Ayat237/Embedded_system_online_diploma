/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX5 (Assignment one)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{

	char ch ;
	printf("Enter the character :");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&ch);
	printf("ASCII value of %c = %d",ch,ch);

	return 0;
}
