#include <stddef.h>

#include "TX_Anytype.h"

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
    TX_List_Node *next;
}TX_List_List;

// Initialize a List
TX_List_List *TX_List_Init();

// Destroy the List
void TX_List_Destroy(TX_List_List *l);

// Insert a node into p position
void TX_List_Insert(TX_List_List *l, TX_List_Node *node, size_t p);

// Delete a node at position p
void TX_List_Delete(TX_List_List *l, size_t p);

// Append
void TX_List_Append(TX_List_List *l, TX_Anytype_AnytypeElement e);

// Prepend
void TX_List_Preppend(TX_List_List *l, TX_Anytype_AnytypeElement e);

#endif