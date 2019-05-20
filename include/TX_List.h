#include <stddef.h>
#include <stdbool.h>

#include "TX_Anytype.h"

// infact this structure is implement of queue and linked list
#ifndef TX_LIST
#define TX_LIST

typedef struct TX_List_Node
{
    /* Linked list node */
    TX_Anytype_AnytypeElement data;
    struct TX_List_Node *next;
}TX_List_Node;


typedef struct  TX_List_List
{
    /* Linked list data structure */
    // as head node
    size_t length;
    // If the type is none, this is a generic list.
    // other wise type is the type of every node in the list.
    TX_Anytype_Typenumber type; 
    TX_List_Node *head;
}TX_List_List;

// Initialize a List
TX_List_List *TX_List_Init();

// Destroy the List
void TX_List_Destroy(TX_List_List *l);

// The index p starts at 1 (1 implies the first node, not the head node.)
// Insert a node into p position
void TX_List_Insert(TX_List_List *l, TX_Anytype_AnytypeElement e, size_t p);

// Get a copy of node which in p position
TX_Anytype_AnytypeElement TX_List_GetNodeValue(TX_List_List *l, size_t p);

// Delete a node at position p
void TX_List_Delete(TX_List_List *l, size_t p);

// Append
void TX_List_Append(TX_List_List *l, TX_Anytype_AnytypeElement e);

// Prepend
void TX_List_Preppend(TX_List_List *l, TX_Anytype_AnytypeElement e);

// Delete first node
void TX_List_DeleteFirst(TX_List_List *l);

// Delete last node
void TX_List_DeleteLast(TX_List_List *l);

// merge two list by input sequence, l2 will be destroyed
void TX_List_MergeTwoLists(TX_List_List *l1, TX_List_List *l2);

// traverse
void TX_List_Traverse(TX_List_List *l, void (*f)(TX_Anytype_AnytypeElement e));

// Show the List
void TX_List_ShowList(TX_List_List *l);

// is list empty
bool TX_List_IsEmpty(TX_List_List *l);

#endif