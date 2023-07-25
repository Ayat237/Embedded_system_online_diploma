/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX5 (Assignment two)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{

	char ch;
	printf("Enter an character  :");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&ch);
	if (isalpha(ch))
	{
		printf("%c is an alphabet",ch);
	}
	else
	{
		printf("%c is not alphabet",ch);
	}

	return 0;
}


