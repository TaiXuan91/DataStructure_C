#include"List.h"


List InitList() {
	LNode *head;//point head node
	head = CreateNode(ElemTypeEmpty);
	return head;
}

void DestroyList(List *L) {

	if (L == NULL) exit(INFEASIBLE);

	LNode *head = *L;
	LNode *p;

	if (head == NULL) return;//Do not have a head node.List does not exist.

	while (head->next != NULL) {
		p = head->next;
		FreeNode(&head);
		head = p;
	}
	FreeNode(&head);
	*L = NULL;
}

void ClearList(List *L) {
	DestroyList(L);
	*L = InitList();
}

bool ListEmpty(List L) {

	if (L == NULL) exit(INFEASIBLE);

	if (L->next == NULL)
		return true;
	else
		return false;
}

int ListLength(List L) {

	if (L == NULL) exit(INFEASIBLE);

	LNode *p=L;
	int i=0;
	while (p->next != NULL) {
		p = p->next;
		i++;
	}
	return i;
}

LNode *GetPriorNode(List L, int i) {
	LNode *p = L;
	int j;

	if (L == NULL) exit(INFEASIBLE);
	if (i <= 0) exit(INFEASIBLE);//Can't get head node's prior.

	for (j = 0; (j < i - 1) && (p->next); j++) {
		p = p->next;
	}
	
	return p;
}

LNode *GetNode(List L,int i){
	return GetPriorNode(L,i)->next;
}

LNode *GetNextNode(List L, int i) {
	return GetNode(L, i)->next;
}

void ListInsert(List L, int i, ElemType e) {
	
	LNode *p , *q;

	p = GetPriorNode(L, i);
	//Insert new node.
	q = p->next;
	p->next = CreateNode(e);
	p = p->next;
	p->next = q;
}

ElemType ListDelete(List L, int i) {

	LNode *p , *q;
	
	p = GetPriorNode(L, i);
	if (p->next == NULL) return ElemTypeEmpty;
	//Delete the node.
	q = p->next;//q point the node which should be deleted.
	p->next = q->next;
	return FreeNode(&q);
}

int LocateNode(List L, LNode *p) {

	if (L == NULL) exit(INFEASIBLE);

	int i = 0;
	while (L->next != NULL) {
		L = L->next;
		i++;
		if (L == p) return i;
	}
	return 0;
	
}

int LocateElem(List L, ElemType e, bool(*compare)()) {

	if (L == NULL) exit(INFEASIBLE);

	int i=0;

	if (!ListEmpty(L)) {
		L = L->next;
		i=1;
		do {
			if (compare(L->data, e)) return i;
			L = L->next;
			i++;
		} while (L != NULL);
		return 0;
	}
	else
	{
		return 0;
	}


}

void ListTraverse(List L, int(*visit)()) {

	if (L == NULL) exit(INFEASIBLE);

	if (!ListEmpty(L)) {
		L = L->next;
		do {
			visit(L->data);
			L = L->next;
		} while (L != NULL);
	}
	else
		return;
}

void ListNodeInsert(List L,int i,LNode *p) {
	LNode  *q;

	q = GetPriorNode(L, i);
	//Intert
	p->next = q->next;
	q->next = p;
}

ElemType GetListElem(List L, int i) {
	return GetNode(L, i)->data;
}
