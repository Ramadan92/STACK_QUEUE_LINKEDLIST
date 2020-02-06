#ifndef __STACK_H__
#define __STACK_H__

#include "std_types.h"

typedef struct stack {
	
	sint16_t s16_top ;
	
	uint16_t u16_capacity ;
	
	sint16_t* s16_array ;
}Stack;

#define TOP_OF_EMPTY_STACK -1

/**
* Description : Creates the stack and it's control block
* @param: u16_capacity : Unisgned variable to determine the size of the struct
* @return: pointer to the stack's control block 
**/
Stack* createStack (uint16_t u16_capacity);

/**
* Description : Checks if the stack is full
* @param: st_stack : pointer to the stack desired to be checked
* @return: stack boolian status : 
*					0 -> FALSE
*					1 -> TRUE
**/
sint16_t stackisFull(Stack* st_stack);

/**
* Description : Checks if the stack is empty
* @param: st_stack : pointer to the stack desired to be checked
* @return: stack boolian status : 
*					0 -> FALSE
*					1 -> TRUE
**/
sint16_t stackisEmpty(Stack* st_stack);

/**
* Description : Pushes a new element to the top of the stack
* @param: st_stack : Pointer to the stack desired to push the element into
* @param: s16_data : The data to be pushed in the stack 
**/
void push(Stack* st_stack , sint16_t s16_data);

/**
* Description : pops the top element in the stack
* @param: st_stack : Pointer to the stack desired to pop the element from
* @return: the element to be popped from the stack
**/
sint16_t pop(Stack* st_stack);

#endif

	