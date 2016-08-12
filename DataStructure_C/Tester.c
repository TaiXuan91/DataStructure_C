#include<stdio.h>
#include"List.h"

int main() {
	List L;
	LNode *p;

	L = InitList();
	ListInsert(L, 1, 11);
	ListInsert(L, 2, 12);
	ListInsert(L, 3, 13);
	ListInsert(L, 4, 14);

	p=ListNodeTear(L, 3);
	
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