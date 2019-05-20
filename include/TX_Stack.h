#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#include "TX_Anytype.h"

#ifndef TX_STACK
#define TX_STACK

#define TX_BASE_STACK_SIZE 20

typedef struct TX_Stack_Stack
{
    /* Stack data structure */
    TX_Anytype_AnytypeElement *stack; // data
    size_t top; //bottom is 1. top==0 implies empty stack.
    size_t stack_size; //current max size of the stack.
}TX_Stack_Stack;

//Initial a stack
TX_Stack_Stack *TX_Stack_Init();

//Destroy a stack
void TX_Stack_Destroy(TX_Stack_Stack *s);

//Push a element
void TX_Stack_Push(TX_Stack_Stack *s, TX_Anytype_AnytypeElement e);

//Pop a element
TX_Anytype_AnytypeElement TX_Stack_Pop(TX_Stack_Stack *s);

//Determines whether it is empty stack
bool TX_Stack_IsEmpty(TX_Stack_Stack *s);

// Return the number of elements in stack
size_t TX_Stack_MeasureSize(TX_Stack_Stack *s);

#endif