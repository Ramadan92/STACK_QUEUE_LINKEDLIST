#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


Stack* createStack (uint16_t u16_capacity)
{
	Stack* st_stack = (Stack*)malloc(sizeof(Stack));
	
	st_stack->s16_top = TOP_OF_EMPTY_STACK;
	
	st_stack->u16_capacity = u16_capacity;
	
	st_stack->s16_array = (sint16_t*)malloc(u16_capacity * sizeof(Stack));
	
	printf("A stack of size %d is created succesfully \n", u16_capacity);
	
	return st_stack;
}

sint16_t stackisFull(Stack* st_stack)
{
	sint16_t s16_status = FALSE ;
	
	if (st_stack->s16_top == (st_stack->u16_capacity - 1))
		s16_status = TRUE;
	
	return s16_status;
}

sint16_t stackisEmpty(Stack* st_stack)
{
	sint16_t s16_status = FALSE ;
	
	if (st_stack->s16_top == TOP_OF_EMPTY_STACK)
		s16_status = TRUE;
	
	return s16_status;
}

void push(Stack* st_stack , sint16_t s16_data)
{
	
	if (stackisFull(st_stack))
		printf("The data (%d) is NOT pushed succesfully in the stack , stack is full\n", s16_data);
	
	else
	{
		++st_stack->s16_top;
		
		st_stack->s16_array[st_stack->s16_top] = s16_data;
		
		printf("The data (%d) is pushed succesfully in the stack \n", s16_data); 
	}
}

sint16_t pop(Stack* st_stack)
{
	sint16_t s16_data_to_be_popped = TOP_OF_EMPTY_STACK;
	
	if(stackisEmpty(st_stack))
		printf("sorry there is no data to pop , the stack is empty \n");
	
	else
	{
		s16_data_to_be_popped = st_stack->s16_array[st_stack->s16_top];
		
		--st_stack->s16_top;
	}
	
	return s16_data_to_be_popped;
}


