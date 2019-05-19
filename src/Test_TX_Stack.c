#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Test_Code.h"

#include "TX_Stack.h"

bool Test_TX_Stack(){
    TX_Stack_Stack *myStack = TX_Stack_Init();
    TX_Anytype_AnytypeElement e;
    char buffer[50];
    printf("Start Stack Test:\n");
    printf("Is stack empty? %d\n", TX_Stack_IsEmpty(myStack));
    e = TX_Stack_Pop(myStack);
    printf("Test Stack\n");
    TX_Anytype_ShowElement(e, buffer);
    printf("first: %s\n", buffer);
    e.data.bool_value = true;
    e.type = TX_BOOL;
    TX_Stack_Push(myStack, e);
    e.data.bool_value = false;
    e.type = TX_BOOL;
    TX_Stack_Push(myStack, e);
    e.data.float_value = 3.1415;
    e.type = TX_FLOAT;
    TX_Stack_Push(myStack, e);
    e.data.integer_value = 2524;
    e.type = TX_INTEGER;
    TX_Stack_Push(myStack, e);
    e = TX_Stack_Pop(myStack);
    TX_Anytype_ShowElement(e, buffer);
    printf("second: %s\n", buffer);
    e.data.float_value = 20.1415f;
    e.type = TX_FLOAT;
    TX_Stack_Push(myStack, e);
    e.data.float_value = 5.15;
    e.type = TX_FLOAT;
    TX_Stack_Push(myStack, e);
    printf("Is stack empty? %d\n", TX_Stack_IsEmpty(myStack));
    int ii = 2;
    do{
        ii++;
        e = TX_Stack_Pop(myStack);
        TX_Anytype_ShowElement(e, buffer);
        printf("%d: %s\n",ii, buffer);
    }while (e.type!=TX_NONE);
    return true;
}

