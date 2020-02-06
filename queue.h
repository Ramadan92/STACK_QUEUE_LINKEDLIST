#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "std_types.h"

typedef struct queue{
	
	sint16_t s16_Front , s16_Rear , s16_Size;
	
	uint16_t u16_Capacity;
	
	sint16_t* s16_Array;
}Queue;

#define EMPTY_QUEUE				0
#define STARTING_INDEX 	 		0
#define FRONT_OF_EMPTY_QUEUE   -1

/**
* Description : Creates the queue and it's control block
* @param: u16_capacity : Unisgned variable to determine the size of the queue
* @return: pointer to the queue's control block 
**/
Queue* createQueue(uint16_t u16_capacity);

/**
* Description : Checks if the queue is full
* @param: st_stack : pointer to the queue desired to be checked
* @return: queue boolian status : 
*					0 -> FALSE
*					1 -> TRUE
**/
uint8_t QisFull(Queue* Q);

/**
* Description : Checks if the queue is empty
* @param: st_stack : pointer to the queue desired to be checked
* @return: queue boolian status : 
*					0 -> FALSE
*					1 -> TRUE
**/
uint8_t QisEmpty(Queue* Q);

/**
* Description : Enqueues a new element to the rear of the queue
* @param: st_stack : Pointer to the queue desired to enqueue the element into
* @param: s16_data : The data to be enqueued in the queue 
**/
void enqueue(Queue* Q , sint16_t s16_data);

/**
* Description : Dequeues the front element in the queue
* @param: st_stack : Pointer to the queue desired to dequeue it's front element
* @return: the element to be dequeued from the queue
**/
sint16_t dequeue(Queue* Q);

#endif
	