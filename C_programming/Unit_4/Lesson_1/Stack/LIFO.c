/*
 * LIFO.c
 *
 * Created on: Feb 24, 2024
 * Author: Ayat MOhamed
 */
#include <stdio.h>
#include "LIFO.h"

LIFO_Status_t LIFO_Add_Item(LIFO_Buffer_t *Stack_buff,unsigned int item)
{
	/* check if stack is valid */
	if((Stack_buff->base== NULL) || (Stack_buff->head == NULL) )
	{
		return NULL_STACK;
	}
	/* check if stack is full */
	else if(Stack_buff->count == Stack_buff->length)
	{
		return FULL_STACK;
	}
	else   /* add value */
	{
		*(Stack_buff->head)= item; /*add item to head */
		Stack_buff->head ++;       /*increment the head pointer to point the next element */
		Stack_buff->count ++;      /*increment counter */
		return NO_ERROR_STACK;
	}
}

LIFO_Status_t LIFO_Pop_Item(LIFO_Buffer_t *Stack_buff,unsigned int *item)
{
	/* check if stack is valid */
	if((Stack_buff->base== NULL) || (Stack_buff->head == NULL) )
	{
		return NULL_STACK;
	}
	/* check if stack is empty */
	else if(Stack_buff->count == 0)
	{
		return EMPTY_STACK;
	}
	else
	{
		Stack_buff->head --;/*decrement the head pointer to point the next element */
		*item = *(Stack_buff->head); /*get the deleted value */
		Stack_buff->count --;      /*decrement counter */
		return NO_ERROR_STACK;
	}
}

LIFO_Status_t LIFO_Init(LIFO_Buffer_t *Stack_buff,unsigned int* buff ,unsigned int length)
{
	if(buff == NULL)
	{
		return NULL_STACK;
	}
	else
	{
		Stack_buff->base = buff;
		Stack_buff->head = buff;
		Stack_buff->length = length;
		Stack_buff->count = 0;
		return NO_ERROR_STACK;
	}

}
