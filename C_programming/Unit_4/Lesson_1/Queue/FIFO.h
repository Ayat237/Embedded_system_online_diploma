/*
 * FIFO.h
 *
 * Created on: Mar 9, 2024
 * Author: Ayat Mohamed
 */
#include <stdint.h>
#ifndef FIFO_H_
#define FIFO_H_
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> User Configurations <<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/* select the element type : uint8_t ,uint16_t ,uin32_t ,uint64_t ,.... */
#define DATA_TYPE  uint8_t

/* Buffer width */
#define WIDTH 5



/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> QUEUE BUFFER <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/* Queue data type*/
typedef struct
{
	DATA_TYPE *BASE;
	DATA_TYPE *HEAD;
	DATA_TYPE *TAIL;
	uint32_t COUNT;
	uint32_t LENGTH;
}FIFO_Buffer_t;

/* queue status */
typedef enum
{
	NO_ERROR_QUEUE,  /* if Queue has no error return 0 */
	FULL_QUEUE,      /* if Queue is full return 1 */
	EMPTY_QUEUE,     /* if Queue is empty return 2 */
	NULL_QUEUE,      /* if Queue is not exist return 3*/
}FIFO_Status_t;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> QUEUE APIS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

/* Description : initialize queue
 * Inputs : address of FIFO_buffer to know what is the place you want to initialize the item ,
   the buffer (array) you want to initialize it ,and length of buffer
 * Output : the status of queue */
FIFO_Status_t Queue_Init(FIFO_Buffer_t *Queue_Buffer , DATA_TYPE *Item ,uint32_t Length);

/* Description : add(Enqueue) item into queue
 * Inputs : address of FIFO_buffer to know what is the place you want to add the item ,
   ,and the data you want to store it into queue.
 * Output : the status of queue */
FIFO_Status_t Queue_Add_Item(FIFO_Buffer_t *Queue_Buffer , DATA_TYPE Item);

/* Description : Dequeue(delete) item from queue
 * Inputs : address of FIFO_buffer to know what is the place you want to Dequeue the item ,
   and the data you want to delete it from queue as a pointer
 * Output : the status of queue */
FIFO_Status_t Queue_Delete_Item(FIFO_Buffer_t *Queue_Buffer , DATA_TYPE *Item);

/* Description : check if queue is full or not
 * Inputs : address of FIFO_buffer
 * Output : the status of queue */
FIFO_Status_t Queue_Is_Full(FIFO_Buffer_t *Queue_Buffer);

/* Description : check if queue is empty or not
 * Inputs : address of FIFO_buffer
 * Output : the status of queue */
FIFO_Status_t Queue_Is_Empty(FIFO_Buffer_t *Queue_Buffer);

/* Description : print all elements in queue
 * Inputs : address of FIFO_buffer
 * Output : all data in queue */
void Queue_Print_All(FIFO_Buffer_t *Queue_Buffer);

#endif /* FIFO_H_ */
