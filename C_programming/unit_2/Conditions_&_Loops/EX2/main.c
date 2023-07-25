/*
 *  main.c
 *  Created on: Jul 17, 2023
 *  Author: ayat mohamed
 *  object : EX2 (Assignment two)
 */
# include<stdio.h>
# include <stdlib.h>

int main()
{

	char ch;
	printf("Enter an Alphabet  :");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&ch);
	char is_vowel_small = (ch == 'i') || (ch == 'o') || (ch == 'u') || (ch == 'a') || (ch == 'e');
	char is_vowel_capital = (ch == 'I') || (ch == 'O') || (ch == 'U') || (ch == 'A') || (ch == 'E');
	if (is_vowel_small)
	{
		printf("%c is a small vowel",ch);
	}
	else if(is_vowel_capital)
	{
		printf("%c is a capital vowel",ch);
	}
	else
	{
		printf("%c is a constant",ch);
	}

	return 0;
}
