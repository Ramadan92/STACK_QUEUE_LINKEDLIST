#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H


#define EMPTY_LIST		0

typedef struct Node_type{
    uint32_t u32_value;
    node *Next;
}node;

/**
* Description : creates the linked list and adds a new node to the list
* @param: u32_val : data to be input to the node
**/
void AddNode(uint32_t u32_val);

/**
* Description : prints the linked list
**/
void PrintLinkedList(void);

#endif