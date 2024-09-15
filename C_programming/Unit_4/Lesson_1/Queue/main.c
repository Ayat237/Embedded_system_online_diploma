/*
 * main.c
 *
 * Created on: Mar 9, 2024
 * Author: Ayat Mohamed
 */
#include "FIFO.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*[note] if you want to define a buffer , please use the DATA_TYPE to define the buffer */
/*create buffers */
DATA_TYPE UART_BUFFER[WIDTH];
int main()
{
	FIFO_Buffer_t UART_QUEUE;
	int i = 0 ;
	uint32_t temp = 0;
	Queue_Init(&UART_QUEUE ,UART_BUFFER ,5);
	if(Queue_Init(&UART_QUEUE ,UART_BUFFER ,5) == NO_ERROR_QUEUE)
	{
		printf("INITIALIZATION IS DONE :)\n");
	}
	for( i= 0 ; i < 7 ; i++)
	{
		switch(Queue_Add_Item(&UART_QUEUE , i+1))
		{
		case NO_ERROR_QUEUE :
			printf("An item %d has been added successfully\n",i+1);
			break;
		case FULL_QUEUE :
			printf("[ERROR!!] UART queue is full,You can not add any item\n");
			break;
		case NULL_QUEUE :
			printf("[ERROR!!] UART queue is not exist\n");
			break;
		}
	}
	Queue_Print_All(&UART_QUEUE);
	for( i= 0 ; i < 6 ; i++)
	{
		switch(Queue_Delete_Item(&UART_QUEUE , &temp))
		{
		case NO_ERROR_QUEUE :
			printf("An item %d has been deleted successfully\n",temp);
			break;
		case EMPTY_QUEUE :
			printf("[ERROR!!] UART queue is empty,You can not delete any item\n");
			break;
		case NULL_QUEUE :
			printf("[ERROR!!] UART queue is not exist\n");
			break;
		}
	}
	Queue_Print_All(&UART_QUEUE);

	return 0 ;
}
