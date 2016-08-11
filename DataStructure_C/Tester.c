#include<stdio.h>
#include"ListNode.h"

int main() {
	LNode *p;
	p = CreateNode(112);
	printf("data:%d,next:%x\n", p->data, p->next);
	printf("data:%d", FreeNode(&p));
	getchar();
	return 0;
}