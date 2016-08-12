#include<stdio.h>
#include"List.h"

int main() {
	List L;
	LNode *p;

	L = InitList();
	ListInsert(L, 1, 11);
	ListInsert(L, 2, 12);
	ListInsert(L, 3, NULL);
	ListInsert(L, 4, 14);
	p = ((L->next)->next)->next;
	
	printf("data:%d,prior:,next:%x\n", p->data,p->next);
	
	
	getchar();
	return 0;
}