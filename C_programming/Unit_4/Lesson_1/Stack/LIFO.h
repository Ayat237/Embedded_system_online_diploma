/*
 *  LIFO.h
 *  Created on: Feb 24, 2024
 *  Author: Ayat Mohamed
 */

#ifndef LIFO_H_
#define LIFO_H_

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> type definitions <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
typedef struct
{
	unsigned int length;  /* length of buffer */
	unsigned int count;   /* counter to count items into buffer */
	unsigned int *base;   /* base pointer points to the first element of buffer */
	unsigned int *head;   /* head pointer points to the current element if the stack */

}LIFO_Buffer_t;

/* status of buffer */
typedef enum
{
	NO_ERROR_STACK,  /* if stack has no error return 0 */
	FULL_STACK,      /* if stack is full return 1 */
	EMPTY_STACK,     /* if stack is empty return 2 */
	NULL_STACK,      /* if stack is not exist return 3*/
}LIFO_Status_t;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> APIS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/* Description : add item into stack
 * Inputs : address of LIFO_buffer to know what is the place you want to add the item ,
   and the data you want to store it into stack
 * Output : the status of stack */
LIFO_Status_t LIFO_Add_Item(LIFO_Buffer_t *Stack_buff,unsigned int item);

/* Description : pop(delete) item from stack
 * Inputs : address of LIFO_buffer to know what is the place you want to pop the item ,
   and the data you want to delete it from stack as a pointer
 * Output : the status of stack */
LIFO_Status_t LIFO_Pop_Item(LIFO_Buffer_t *Stack_buff,unsigned int *item);

/* Description : initialize stack
 * Inputs : address of LIFO_buffer to know what is the place you want to initialize the item ,
   the buffer (array) you want to initialize it ,and length of buffer
 * Output : the status of stack */
LIFO_Status_t LIFO_Init(LIFO_Buffer_t *Stack_buff,unsigned int* buff ,unsigned int length);

#endif /* LIFO_H_ */
