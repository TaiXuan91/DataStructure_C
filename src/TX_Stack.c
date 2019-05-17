#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#include "TX_Stack.h"
#include "TX_Anytype.h"

//Initial a stack
TX_Stack_Stack *TX_Stack_Init(){
    TX_Stack_Stack *theStack;
    theStack = (TX_Stack_Stack *)malloc(sizeof(TX_Stack_Stack));
    theStack->stack = (TX_Anytype_AnytypeElement *)malloc(sizeof(TX_Anytype_AnytypeElement)*TX_BASE_STACK_SIZE);
    theStack->top = 0;
    theStack->stack_size = TX_BASE_STACK_SIZE;
    return theStack;
}

//Destroy a stack
void TX_Stack_Destroy(TX_Stack_Stack *s){
    free(s->stack);
    free(s);
}

//Push a element
void TX_Stack_Push(TX_Stack_Stack *s, TX_Anytype_AnytypeElement e){
    // !!! No check about full stack. should relloc
    s->top += 1;
    s->stack[s->top] = e;
}

//Pop a element
TX_Anytype_AnytypeElement TX_Stack_Pop(TX_Stack_Stack *s){
    if(TX_Stack_IsEmpty(s)){
        TX_Anytype_AnytypeElement e;
        e.type = TX_NONE;
        return e;}
    else{
        s->top -= 1;
        return s->stack[(s->top)+1];
    }

}

//Determines whether it is empty stack
bool TX_Stack_IsEmpty(TX_Stack_Stack *s){
    return (s->top<=0);
}