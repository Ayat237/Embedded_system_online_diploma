/*
 *  main.c
 *  Created on: Aug 17, 2023
 *  Author: Ayat Mohamed
 */

#include <stdio.h>
void Reverse_Sentence(char *sentence);
int main()
{
    char sent [] = "margrop emosewa";
    printf("the sentence = ");
	Reverse_Sentence(sent);

	return 0 ;
}

void Reverse_Sentence(char *sentence)
{
	/* check the value of pointer if not equal 0 ,goto the next location in stack */
	if(*sentence != 0)
	{
		Reverse_Sentence(sentence+1);
		printf("%c",*sentence);
	}
}
