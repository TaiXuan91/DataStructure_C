#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Test_Code.h"

#include "TX_Anytype.h"
#include "TX_Stack.h"
#include "TX_List.h"

bool Test_TX_List(){
    TX_List_List *myList;
    myList = TX_List_Init();
    TX_Anytype_AnytypeElement e;
    printf("Begin List test!\n");
    printf("Is empty? %d\n",TX_List_IsEmpty(myList));
    e.data.integer_value = 2252;
    e.type = TX_INTEGER;
    TX_List_Append(myList, e);
    e.data.integer_value = 2263;
    e.type = TX_INTEGER;
    TX_List_Append(myList, e);
    e.data.integer_value = 2274;
    e.type = TX_INTEGER;
    TX_List_Preppend(myList, e);
    e.data.integer_value = 2285;
    e.type = TX_INTEGER;
    TX_List_Preppend(myList, e);
    e.data.integer_value = 2296;
    e.type = TX_INTEGER;
    TX_List_Append(myList, e);
    TX_List_ShowList(myList);
    printf("Is empty? %d\n",TX_List_IsEmpty(myList));
    printf("get second element\n");
    e = TX_List_GetNodeValue(myList, 2);
    TX_Anytype_ShowElementLine(e);
    printf("get first element\n");
    e = TX_List_GetNodeValue(myList, 1);
    TX_Anytype_ShowElementLine(e);
    printf("get third element\n");
    e = TX_List_GetNodeValue(myList, 3);
    TX_Anytype_ShowElementLine(e);
    printf("get fifth element\n");
    e = TX_List_GetNodeValue(myList, 5);
    TX_Anytype_ShowElementLine(e);
    printf("delete first\n");
    TX_List_DeleteFirst(myList);
    TX_List_ShowList(myList);
    printf("delete last\n");
    TX_List_DeleteLast(myList);
    TX_List_ShowList(myList);
    printf("insert test\n");
    e.data.bool_value = true;
    e.type = TX_BOOL;
    TX_List_Insert(myList, e, 20);
    e.data.float_value = 3.444;
    e.type = TX_FLOAT;
    TX_List_Insert(myList, e, 2);
    TX_List_ShowList(myList);
    printf("delete p position test\n");
    TX_List_Delete(myList, 34);
    TX_List_Delete(myList, 3);
    TX_List_ShowList(myList);
    TX_List_List *anothrList = TX_List_Init();
    e.data.integer_value = 12;
    e.type = TX_INTEGER;
    TX_List_Append(anothrList, e);
    e.data.integer_value = 13;
    TX_List_Append(anothrList, e);
    e.data.integer_value = 14;
    TX_List_Append(anothrList, e);
    e.data.integer_value = 15;
    TX_List_Insert(anothrList, e, 1);
    TX_List_MergeTwoLists(myList, anothrList);
    TX_List_ShowList(myList);
    printf("Test merge different type\n");
    anothrList = TX_List_Init();
    e.data.float_value = 12.24;
    e.type = TX_FLOAT;
    TX_List_Append(anothrList, e);
    e.data.char_value = 'A';
    e.type = TX_CHAR;
    TX_List_Append(anothrList, e);
    e.data.integer_value = 14;
    e.type = TX_INTEGER;
    TX_List_Append(anothrList, e);
    e.data.integer_value = 15;
    e.type = TX_INTEGER;
    TX_List_Insert(anothrList, e, 1);
    myList->type = TX_INTEGER;
    TX_List_MergeTwoLists(myList, anothrList);
    TX_List_ShowList(myList);
    return true;
}