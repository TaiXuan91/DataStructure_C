#pragma once

//This part defined  the structure of node of the list.
//ps:I think  node is also one type data structure.

#include<stdlib.h>

#include"PredefinedValueAndType.h"

//Types
typedef struct ListNode{
	ElemType data;
	struct ListNode * next;
}LNode;
//List point the head node of the list.
//Head node isn't the first node in the list,but point the first of the list.
//Head node can simplify the deletion of the first node.

//Operations
LNode *CreateNode(ElemType e);
//Create a node,return its address.

ElemType FreeNode(LNode **p);
//Free the node which *p point,and set *p  to NULL(for safe).
//Return data of the node.
