#include "std_types.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

node* head = (node*)malloc(sizeof(node));
uint32_t ListLength = EMPTY_LIST;

void AddNode(u32 val)
{
	
	if (ListLength == EMPTY_LIST)
	{
		head->u32_value = u32_val ;
		head->Next  = NULL; 
	}
	
	
	else
	{
		node *last;
		
		
		node *new = (node*) malloc(sizeof(node));
		
		
		new -> u32_value = val;
		
		new -> Next  = NULL;
		
		last = &head;
		
		
		while( (last -> Next) != NULL )
		{
			last = (last -> Next);
		}
		
		last -> Next = new;
	}
	
	
	ListLength++;
	
	return;
}

void PrintLinkedList(void)
{
	printf("\n\n----------------------\n");
	
	if (ListLength > EMPTY_LIST)
	{
		node *Last = &head;
		uint32_t u32_localIterator  = START;
		
		
		printf("Node Number %d = %d\n", u32_localIterator,Last -> u32_value);
	
		
		while ((Last -> Next) != NULL)
		{
			u32_localIterator++;
			Last = Last -> Next;
			printf("Node Number %d = %d\n", u32_localIterator,Last -> u32_value);
		}
	}
	
	else
	{
		printf("List is Empty\n");
	}
	
	printf("----------------------\n\n\n");
}