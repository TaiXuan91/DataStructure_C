#pragma once

//This part based on  ListNode.
//Tip1:I think the linked list is more appropriate to achieve the linear structure. 
//Because the sequence list additionally requires elements match the  natural number one by one . 
//But the set of real numbers, etc., does not necessarily have this feature.
//If you need Sequence List, you can use SequenceList.h & SequenceList.c.
//Tip2:This is singly linked list.Doubly linked list see DuList.h & DuList.c.

#include<stdbool.h>

#include"ListNode.h"

//Types
typedef struct ListNode *List;
//List is just a alias of pointer to ListNode.
//It point the head node of a list.
//An empty list just have a head node.
//The data of the head node should be ElemTypeEmpty.

//Operations
List InitList();
//Create an empty list.

void DestroyList(List *L);
//Destroy the List *L .Condition:List exist.

void ClearList(List *L);
//Condition: L exist.

bool ListEmpty(List L);
//If the list is a empty list,return true.
//Empty list also has a head node.

int ListLength(L);
//Return the length of the list.
//The length of the list that just have a head node.

LNode *GetPriorNode(List L,int i);
//Return the address of the prior of the node on position i in the list.
//i>=0.Can't get head node's prior.
//If the list is empty,return head node.
//If i>list length,return the last one's.

LNode *GetNode(List L, int i);
//Return the address of the node on position i in the list.

LNode *GetNextNode(List L, int i);
//Return the address of the next of the node on position i in the list.

void ListInsert(List L, int i, ElemType e);
//insert a node before the node whose position is i.
//(i>0,the head node's position is 0.)
//If i>length of the list,append the LNode to the tail.

ElemType ListDelete(List L, int i);
//Delete the node on position i.Return its data .
//i!=0.
//If i is bigger than the length of the list,e equal to ElemTypeEmpty.

int LocateNode(List L, LNode *p);
//return the position of the node in the list.
//If there isn't p in L.Return 0.

int LocateElem(List L, ElemType e, bool(*compare)());
//For ewery node p in L.If compare(p->data,e)return turn,return the position of p.
//Only return  first node to meet the requirements.
//bool compare(ElemType u,ElemType e) //u is data part of Node.

void ListTraverse(List L, int (*visit)());
//Status visti(ElemType e);
//Use visti() with every node's data.

void ListNodeInsert(List L,int i,LNode *p);
//Insert node which p point into L. 
//Before the node whose position is i in original L.

ElemType GetListElem(List L, int i);
//Return the data of node i.



