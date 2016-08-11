#include"ListNode.h"

LNode *CreateNode(ElemType e) {
	LNode *p;

	p = (LNode *)malloc(sizeof(LNode));
	p->data = e;
	p->next = NULL;
	return p;
}

ElemType FreeNode(LNode **p) {
	ElemType e;

	e = (*p)->data;
	free(*p);
	*p=NULL;
	return e;
}