/*
 * FIFO.c
 *
 * Created on: Mar 9, 2024
 * Author: Ayat Mohamed
 */
#include "SMS.h"
#include "FIFO.h"
#include <stdio.h>
#include <stdint.h>

FIFO_Status_t Queue_Init(FIFO_Buffer_t *Queue_Buffer , DATA_TYPE *Item ,uint32_t Length)
{
	/*If queue is valid */
	if(Queue_Buffer == NULL )
	{
		return NULL_QUEUE;
	}
	else /*initialize queue buffer*/
	{
		Queue_Buffer->BASE = Item;
		Queue_Buffer->HEAD = Item;
		Queue_Buffer->TAIL = Item;
		Queue_Buffer->COUNT = 0;
		Queue_Buffer->LENGTH = WIDTH;
		return NO_ERROR_QUEUE;
	}
}

FIFO_Status_t Queue_Add_Item(FIFO_Buffer_t *Queue_Buffer , DATA_TYPE Item)
{

	/*check if queue is valid */
	if ((Queue_Buffer->BASE ==NULL) || (Queue_Buffer->HEAD ==NULL) || (Queue_Buffer->TAIL==NULL))
	{
		return NULL_QUEUE;
	}
	else if (Queue_Is_Full(Queue_Buffer)==FULL_QUEUE)
	{
		return FULL_QUEUE;
	}
	else
	{
		/* add item to head */
		*(Queue_Buffer->HEAD) = Item;
		/*check if head reach to the end of queue or not(circular)
		 * head = 0x05
		 * base = 0x00 , length = 5 --> head(0x05) == 0x00+(5*1) = 0x05
		 * i write (Queue_Buffer->BASE) to compare pointer to pointer*/
		if(Queue_Buffer->HEAD == ( Queue_Buffer->BASE +(Queue_Buffer->LENGTH*sizeof(DATA_TYPE))))
		{
			Queue_Buffer->HEAD = Queue_Buffer->BASE;
		}
		else
		{
			/* if not we will increment the HEAD */
			Queue_Buffer->HEAD ++;
		}
		Queue_Buffer->COUNT ++;/*increment the queue elements*/
		return NO_ERROR_QUEUE;
	}
}

FIFO_Status_t Queue_Delete_Item(FIFO_Buffer_t *Queue_Buffer , DATA_TYPE *Item)
{

	/*check if queue is valid */
	if ((Queue_Buffer->BASE ==NULL) || (Queue_Buffer->HEAD ==NULL) || (Queue_Buffer->TAIL==NULL))
	{
		return NULL_QUEUE;
	}
	else if (Queue_Is_Empty(Queue_Buffer)==EMPTY_QUEUE) /* check if queue is empty*/
	{
		return EMPTY_QUEUE;
	}
	else
	{
		/* to get the deleted item */
		*Item =*(Queue_Buffer->TAIL);
		/*check if  reach to tail the end of queue or not(circular)
		 * i write (Queue_Buffer->BASE) to compare pointer to pointer*/
		if(Queue_Buffer->TAIL == ( Queue_Buffer->BASE+(Queue_Buffer->LENGTH*sizeof(DATA_TYPE))))
		{
			Queue_Buffer->TAIL = Queue_Buffer->BASE;
		}
		else
		{
			/*if not , increment queue*/
			Queue_Buffer->TAIL ++;
		}
		Queue_Buffer->COUNT --; /*decrement the queue elements*/
		return NO_ERROR_QUEUE;
	}
}

FIFO_Status_t Queue_Is_Full(FIFO_Buffer_t *Queue_Buffer)
{
	/*check if queue is valid */
	if ((Queue_Buffer->BASE ==NULL) || (Queue_Buffer->HEAD ==NULL) || (Queue_Buffer->TAIL==NULL))
	{
		return NULL_QUEUE;
	}
	else if (Queue_Buffer->COUNT == Queue_Buffer->LENGTH) /* If queue is full */
	{
		return FULL_QUEUE;
	}
	else
	{
		return NO_ERROR_QUEUE;
	}
}

FIFO_Status_t Queue_Is_Empty(FIFO_Buffer_t *Queue_Buffer)
{
	/*check if queue is valid */
	if ((Queue_Buffer->BASE ==NULL) || (Queue_Buffer->HEAD ==NULL) || (Queue_Buffer->TAIL==NULL))
	{
		return NULL_QUEUE;
	}
	else if (Queue_Buffer->COUNT == 0) /* If queue is empty*/
	{
		return EMPTY_QUEUE;
	}
	else
	{
		return NO_ERROR_QUEUE;
	}
}


void Queue_Print_All(FIFO_Buffer_t *Queue_Buffer)
{
	/* define a pointer to pass through all elements of queue
	 * ,and also to make no change in the tail or head or base pointer*/
	DATA_TYPE *TEMP;
	int i = 0,j=0 ;
	if (Queue_Is_Empty(Queue_Buffer)==EMPTY_QUEUE)
	{
		printf(">>>>>Queue is Empty ,no elements to print<<<<<\n");
	}
	else
	{
		/* temp = tail because tail points the first element in a circular queue*/
		TEMP = Queue_Buffer->TAIL;
		printf(">>>>>>>>>>Students<<<<<<<<<<\n");
		for(i = 0 ; i < Queue_Buffer->COUNT ; i ++)
		{
			/* pass through all elements of queue*/
			printf("Student No %d : \n",i+1);
			printf("First Name : %s\n",TEMP->F_Name);
			printf("Last Name : %s\n",TEMP->L_Name);
			printf("ID : %d\n",TEMP->ID);
			printf("GPA : %.2f\n",TEMP->GPA);
			for(j = 0 ; j < Courses_NO ; j++)
			{
				printf("Course ID #%d : %d\n",j+1,TEMP->Course_ID[j]);
			}
			printf(">>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n");
			TEMP ++;
		}
	}

}



