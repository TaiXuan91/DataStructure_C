#include<stdio.h>
#include"List.h"

int main() {
	List L,L0;
	LNode *p;

	L = InitList();
	ListInsert(L, 1, 11);
	ListInsert(L, 2, 12);
	ListInsert(L, 3, 13);
	ListInsert(L, 4, 14);

	p=ListNodeTear(L, 3);
	L0 = ListCut(L, 3);
	ListAppend(L0, L);
	printf("data:%d,prior:,next:%x\n", p->data,p->next);

	//ElemType e;

	//CreateElem(e);
	//e->f = 3.454;
	//printf("elem:%f",e->f);
	//DeleteElem(e);
	//
	getchar();
	return 0;
}