/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX2 (Assignment one)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{

	//Write C Program to Print a Integer Entered by a User
	int number;
	printf("Enter the number : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&number);
	printf("the number is entered by user is : %d",number);

	return 0;
}
