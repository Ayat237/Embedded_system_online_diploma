/*
 * main.c
 * Created on: Feb 24, 2024
 * Author: Ayat Mohamed
 */
#include "LIFO.h"
#include <stdio.h>
#include <stdlib.h>

/* static memory allocation */
unsigned int buffer1[5];

int main()
{
	int i ;
	unsigned int temp =0;
	/* define two stack */
	LIFO_Buffer_t UART_STACK , I2C_STACK;
	/* dynamic memory allocation */
	unsigned int *buffer2 = (unsigned int*)malloc(5*sizeof(unsigned int)); /* 5*4 = 20byte */
	/* initialize two stack */
	LIFO_Init(&UART_STACK ,buffer1,5); /* buffer1 == &buffer1[0] */
	LIFO_Init(&I2C_STACK ,buffer2,5);

	for( i = 0 ; i < 7 ; i ++)
	{
		switch(LIFO_Add_Item(&UART_STACK , i))
		{
		case NO_ERROR_STACK :
			printf("UART item no %d = %d\n",i,i+1);
			break;
		case FULL_STACK :
			printf("[ERROR!!] UART stack is full,You can not add any item\n");
			break;
		case NULL_STACK :
			printf("[ERROR!!] UART stack is not exist\n");
			break;
		}

	}
	for( i = 0 ; i < 7 ; i ++)
	{
		switch(LIFO_Pop_Item(&UART_STACK , &temp))
		{
		case NO_ERROR_STACK:
			printf("UART deleted item %d = %d\n",i,temp+1);
			break;
		case EMPTY_STACK :
			printf("[ERROR!!] UART stack is empty ,You can not delete any item\n");
			break;
		case NULL_STACK :
			printf("[ERROR!!] UART stack is not exist\n");
			break;
		}

	}
	return 0;
}
