/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX1 (Assignment two)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{

	int number;
	printf("Enter an integer you want two check :");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&number);
	if (number %2 == 1)
	{
		printf("%d is odd",number);
	}
	else
	{
		printf("%d is even",number);
	}

	return 0;
}
