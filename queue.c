#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* createQueue(uint16_t u16_capacity)
{
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	
	Q->u16_Capacity=u16_capacity;
	
	Q->s16_Size= EMPTY_QUEUE;
	
	Q->s16_Front = STARTING_INDEX;
	
	Q->s16_Rear = STARTING_INDEX;
		
	Q->s16_Array = (sint16_t*)malloc(u16_capacity*sizeof(sint16_t));
	
	return Q;
}

uint8_t QisFull(Queue* Q)
{
	uint8_t u8_status = FALSE;
	
	if (Q->s16_Size == Q->u16_Capacity)
		u8_status = TRUE;
	
	return u8_status;
}

uint8_t QisEmpty(Queue* Q)
{
	uint8_t u8_status = FALSE;
	
	if (Q->s16_Size == EMPTY_QUEUE)
		u8_status = TRUE;
		
	return u8_status;
}

void enqueue(Queue* Q , sint16_t s16_data)
{
	if (!(QisFull(Q)))
	{
		Q->s16_Array[Q->s16_Rear++]= s16_data;
		
		Q->s16_Size++;
		
		printf("Data (%d) is enqueued \n", s16_data);
	}
	
	else if (QisFull(Q))
		printf("Data (%d) is NOT enqueued , queue is full \n", s16_data);
	
	if (Q->s16_Rear >= Q->u16_Capacity)
		Q->s16_Rear = STARTING_INDEX;
	
}

sint16_t dequeue(Queue* Q)
{
	sint16_t s16_DQd_data = FRONT_OF_EMPTY_QUEUE;
	
	if(!(QisEmpty(Q)))
	{
		s16_DQd_data = Q->s16_Array[Q->s16_Front++];
		
		Q->s16_Size--;
	}
	
	else if (QisEmpty(Q))
		printf("There is no data to dequeue , Queue is empty \n ");
	
	if(Q->s16_Front >= Q->u16_Capacity)
		Q->s16_Front = STARTING_INDEX;
	
	return s16_DQd_data;
}