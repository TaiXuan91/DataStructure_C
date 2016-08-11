#include"DuNode.h"

DNode *CreateDuNode(ElemType e) {
	DNode *p;

	p = (DNode *)malloc(sizeof(DNode));
	p->data = e;
	p->prior = NULL;
	p->next = NULL;
	return p;
}

ElemType DeleteDuNode(DNode **p) {
	ElemType e;

	e = (*p)->data;
	free(*p);
	*p = NULL;
	return e;
}