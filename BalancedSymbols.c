#include "BalancedSymbols.h"
#include "stack.h"
#include "queue.h"
#include <stdio.h>

#define MULTIPLIER		10

Queue* GQ = NULL;

uint8_t MatchingParanthesisCheck( uint8_t u8_openBracket , uint8_t u8_closeBracket )
{
	uint8_t u8_status = FALSE;
	
	
	if ((u8_openBracket == '(') && (u8_closeBracket == ')'))
		u8_status = TRUE;
	
	if ((u8_openBracket == '{') && (u8_closeBracket == '}'))
		u8_status = TRUE;
	
	if ((u8_openBracket == '[') && (u8_closeBracket == ']'))
		u8_status = TRUE;
	
	return u8_status;
}

uint8_t BalancedParanthesisCheck(uint8_t u8_array[] )
{
	
	uint8_t u8_status = FALSE;
	uint8_t u8_breakFlag = FALSE;
	
	Stack* st_ParanthesisStack = createStack(100*sizeof(u8_array[STARTING_INDEX]));
	GQ = createQueue(100*sizeof(u8_array[STARTING_INDEX]));
	
	
	uint16_t u16_arrayIndex ;
	
	for (u16_arrayIndex = STARTING_INDEX ; u16_arrayIndex< st_ParanthesisStack->u16_capacity ; u16_arrayIndex++)
	{
		if ((u8_array[u16_arrayIndex]!='(') && (u8_array[u16_arrayIndex]!='{') && (u8_array[u16_arrayIndex]!='[') &&
		    (u8_array[u16_arrayIndex]!=')') && (u8_array[u16_arrayIndex]!='}') && (u8_array[u16_arrayIndex]!=']') && (u8_array[u16_arrayIndex]!=EMPTY_ARRAY))
		{
			enqueue(GQ,u8_array[u16_arrayIndex]);
		}
		
		else if ((u8_array[u16_arrayIndex]=='(') || (u8_array[u16_arrayIndex]=='{') || (u8_array[u16_arrayIndex]=='['))
		{
			push(st_ParanthesisStack , u8_array[u16_arrayIndex]);
		}
		
		else if ((u8_array[u16_arrayIndex]==')') || (u8_array[u16_arrayIndex]=='}') || (u8_array[u16_arrayIndex]==']'))
		{
			if (MatchingParanthesisCheck( pop(st_ParanthesisStack), u8_array[u16_arrayIndex]))
				u8_status = TRUE;
			
			else if (!MatchingParanthesisCheck( pop(st_ParanthesisStack), u8_array[u16_arrayIndex]))
			{
				u8_status = FALSE;
				break;
			}
		}		
	}
	
	return u8_status;
	
}

sint16_t EquationEvaluation(void)
{
	sint16_t s16_result = NO_EQUATION;
	sint16_t s16_DQd_data = EMPTY_QUEUE;
	uint16_t u16_Index = STARTING_INDEX;
	uint8_t u8_array[100] = {EMPTY_ARRAY};
	uint8_t u8_firstTimeFlag = TRUE;
	
	while(!QisEmpty(GQ))
	{
		
		if(u8_firstTimeFlag)
		{
			u8_firstTimeFlag = FALSE;
			for (u16_Index = STARTING_INDEX;  ; u16_Index++)
			{
				s16_DQd_data = dequeue(GQ);
				
				if ( s16_DQd_data >= '0' && s16_DQd_data <= '9' )
				{
					u8_array[u16_Index] = s16_DQd_data;
				}
				else
				{
					s16_result += integrize(u8_array);
					u16_Index = STARTING_INDEX;
					break;
				}
			}
		}
		
		
		if ( s16_DQd_data == '+')
		{
			for (u16_Index = STARTING_INDEX;  ; u16_Index++)
			{
				s16_DQd_data = dequeue(GQ);
				if ( s16_DQd_data >= '0' && s16_DQd_data <= '9' )
				{
					u8_array[u16_Index] = s16_DQd_data;
				}
				else
				{
					s16_result += integrize(u8_array);
					u16_Index = STARTING_INDEX;
					break;
				}
			}
			
		}
		
		else if ( s16_DQd_data == '-')
		{
			for (u16_Index = STARTING_INDEX;  ; u16_Index++)
			{
				s16_DQd_data = dequeue(GQ);
				if ( s16_DQd_data >= '0' && s16_DQd_data <= '9' )
				{
					u8_array[u16_Index] = s16_DQd_data;
				}
				else
				{
					s16_result -= integrize(u8_array);
					u16_Index = STARTING_INDEX;
					break;
				}
			}
			
		}
		
		else if ( s16_DQd_data == '*')
		{
			for (u16_Index = STARTING_INDEX;  ; u16_Index++)
			{
				s16_DQd_data = dequeue(GQ);
				if ( s16_DQd_data >= '0' && s16_DQd_data <= '9' )
				{
					u8_array[u16_Index] = s16_DQd_data;
				}
				else
				{
					s16_result *= integrize(u8_array);
					u16_Index = STARTING_INDEX;
					break;
				}
			}
			
		}
		
		else if ( s16_DQd_data == '/')
		{
			for (u16_Index = STARTING_INDEX;  ; u16_Index++)
			{
				s16_DQd_data = dequeue(GQ);
				if ( s16_DQd_data >= '0' && s16_DQd_data <= '9' )
				{
					u8_array[u16_Index] = s16_DQd_data;
				}
				else
				{
					s16_result /= integrize(u8_array);
					u16_Index = STARTING_INDEX;
					break;
				}
			}
		}
	}
	
	return s16_result;
}

uint16_t integrize(uint8_t* u8_array)
{
	uint16_t u16_result = NO_EQUATION;
	uint16_t u16_Index = STARTING_INDEX;
	
	for (u16_Index = STARTING_INDEX; u8_array[u16_Index] != EMPTY_ARRAY; u16_Index++)
	{
		u16_result = (u16_result * MULTIPLIER) + (u8_array[u16_Index] - ASCII_ZERO);
		u8_array[u16_Index]=EMPTY_ARRAY;
	}
	return u16_result;
}

