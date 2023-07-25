/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX6 (Assignment two)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{

	char op ;
	float num1;
	float num2;
	float ans=0.0;
	printf("enter operator either + or - or * or / :");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&op);
	printf("enter two operands :");
	fflush(stdout);
	fflush(stdin);
	scanf("%f %f",&num1 ,&num2);
	switch (op)
	{
	case '+':
	    ans = num1+num2;
	    printf("%.1f %c %.1f = %.1f",num1,op ,num2,ans);
	    break;
	case '-':
	    ans = num1-num2;
	    printf("%.1f %c %.1f = %.1f",num1,op ,num2,ans);
	     break;
	case '*':
	    ans = num1*num2;
	    printf("%.1f %c %.1f = %.1f ",num1,op ,num2,ans);
	     break;
	case '/':
	     ans = num1/num2;
	     printf("%.1f %c %.1f = %.1f",num1,op ,num2,ans);
	     break;
	default:
	        printf("invalid operator");
	    break;
 }
	return 0;
}
