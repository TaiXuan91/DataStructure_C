#pragma once

//DuNode has two pointer.It's used in BiTree and doubly linked list.

#include<stdlib.h>

#include"PredefinedValueAndType.h"

//Types
typedef struct DuNode{
	ElemType data;
	struct DuNode *prior, *next;
}DNode;
//In Bitree,prior is left,next is right.

//Operations
DNode *CreateDuNode(ElemType e);
//Create a DuNode,return its address.

ElemType DeleteDuNode(DNode **p);
//Free the node which *p point,and set *p  to NULL(for safe).
//Return data of the node.