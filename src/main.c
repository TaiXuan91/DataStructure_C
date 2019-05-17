#include <stdio.h>
#include <stdbool.h>

#include "TX_Anytype.h"
#include "TX_Stack.h"

int main(){
    bool x =true;
    TX_Stack_Stack *myStack = TX_Stack_Init();
    TX_Anytype_AnytypeElement e;
    // e.data.integer_value = 12;
    e = TX_Stack_Pop(myStack);
    printf("%d\n",e.data.integer_value);
    printf("%d\n",e.type);
    e.data.integer_value = 12;
    e.type = TX_INTEGER;
    TX_Stack_Push(myStack, e);
    e.data.bool_value = true;
    e.type = TX_BOOL;
    TX_Stack_Push(myStack, e);
    e.data.char_value = 'C';
    e.type = TX_CHAR;
    TX_Stack_Push(myStack, e);
    e.data.float_value = 3.1415;
    e.type = TX_FLOAT;
    TX_Stack_Push(myStack, e);
    e = TX_Stack_Pop(myStack);
    printf("%f\n",e.data.float_value);
    printf("%d\n",e.type);
    e = TX_Stack_Pop(myStack);
    printf("%c\n",e.data.char_value);
    printf("%d\n",e.type);
    e = TX_Stack_Pop(myStack);
    printf("%d\n",e.data.integer_value);
    printf("%d\n",e.type);
    e = TX_Stack_Pop(myStack);
    printf("%d\n",e.data.integer_value);
    printf("%d\n",e.type);
    e = TX_Stack_Pop(myStack);
    printf("%d\n",e.data.integer_value);
    printf("%d\n",e.type);
    e = TX_Stack_Pop(myStack);
    printf("%d\n",e.data.integer_value);
    printf("%d\n",e.type);
    e = TX_Stack_Pop(myStack);
    printf("%d\n",e.data.integer_value);
    printf("%d\n",e.type);
    for(int i=0; i<10; i++){
        printf("%d\n",i);
        printf("%d\n",x);
    }
    getchar();
    return 0;
}

