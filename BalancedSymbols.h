#ifndef __BALANCEDSYMBOLS_H__
#define __BALANCEDSYMBOLS_H__

#include "std_types.h"

#define STARTING_INDEX 	 0
#define NO_EQUATION		 0
#define EMPTY_ARRAY		 0
#define ASCII_ZERO		'0'

/**
* Description : checks if the given paranthesis are matching
* @param: u8_openBracket : the ASCII value of the open bracket
* @param: u8_closeBracket : the ASCII value of the closed bracket
* @return: boolian:
*        1 -> TRUE
*        0 -> FALSE
**/
uint8_t MatchingParanthesisCheck(uint8_t u8_openBracket , uint8_t u8_closeBracket);

/**
* Description : checks if the given expression of paranthesis are balanced
* @param: u8_array[] : the array of characters containing the expression 
* @return: boolian:
*        1 -> TRUE
*        0 -> FALSE
**/
uint8_t BalancedParanthesisCheck(uint8_t u8_array[]);

/**
* Description : evaluates the equation in the expression linearly
* @return: value of the equation to be evaluated
**/
sint16_t EquationEvaluation(void);

/**
* Description : transforms a string of characters to an integer
* @return: value of the equation to be evaluated
* @param: u8_array : pointer to the array of characters
* @return: the integer value of the string
**/
uint16_t integrize(uint8_t* u8_array);

#endif