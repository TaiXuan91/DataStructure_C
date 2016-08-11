#include<stdio.h>
#include"List.h"

int main() {
	LNode *p;
	List L;

	L = InitList();
	ListInsert(L, 1, 3);
	ListInsert(L, 1, 2);
	p=CreateNode(123);
	ListNodeInsert(L, 2, p);
	printf("%d\n", GetListElem(L,3));
	printf("data:%d,next:%x\n", p->data, p->next);
	

	printf("%d\n", ListDelete(L,2));
	ClearList(&L);

	printf("%d\n", ListEmpty(L));

	getchar();
	return 0;
}