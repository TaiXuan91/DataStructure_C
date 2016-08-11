#include<stdio.h>
#include"DuNode.h"

int main() {
	DNode *p;
	//List L;

	p = CreateDuNode(33);
	
	
	printf("data:%d,prior:%x,next:%x\n", p->data,p->prior,p->next);
	printf("data:%d\n", DeleteDuNode(&p));
	

	getchar();
	return 0;
}