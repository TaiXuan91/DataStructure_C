#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "TX_List.h"
#include "TX_Anytype.h"

// Initialize a List
TX_List_List *TX_List_Init(){
    TX_List_List *l = (TX_List_List *) malloc(sizeof(TX_List_List));
    l->length = 0;
    // l->next = NULL;
    // Initialize the head node 
    TX_List_Node *headnode = (TX_List_Node *)malloc(sizeof(TX_List_Node));
    headnode->data = TX_Anytype_GetNone();
    headnode->next = NULL;
    l->head = headnode;
    return l;
}

// Destroy the List
void TX_List_Destroy(TX_List_List *l){
    TX_List_Node *tempnode = NULL;
    while (l->head!=NULL){
        tempnode = l->head;
        l->head = l->head->next;
        free(tempnode);
    }
    free(l);
}

// Insert a node into p position
void TX_List_Insert(TX_List_List *l, TX_Anytype_AnytypeElement e, size_t p){
    // if p>l->length
    if (p>l->length){
        TX_List_Append(l, e);
    }
    TX_List_Node *prenode;
    prenode = l->head;
    for(size_t i=1; i<=l->length; i++){
        if(i==p){
            TX_List_Node *newnode = (TX_List_Node *)malloc(sizeof(TX_List_Node));
            newnode->data = e;
            newnode->next = prenode->next;
            prenode->next = newnode;
            l->length += 1;
            break;
        }
        prenode = prenode->next;
    }
}

// Get the value of node which in p position
TX_Anytype_AnytypeElement TX_List_GetNodeValue(TX_List_List *l, size_t p){
    if (p>l->length){
        return TX_Anytype_GetNone();
    }
    TX_List_Node *index;
    index = l->head;
    for(size_t i=1; i<=l->length;i++){
        index = index->next;
        if(i==p){
            return index->data;
        }
    }
    return TX_Anytype_GetNone();
}

// Delete a node at position p
void TX_List_Delete(TX_List_List *l, size_t p){
    // if p>l->length
    if (p>l->length){
        return;
    }
    TX_List_Node *prenode;
    prenode = l->head;
    for(size_t i=1; i<=l->length; i++){
        if(i==p){
            TX_List_Node *tempnode;
            tempnode = prenode->next;
            prenode->next = tempnode->next;
            free(tempnode);
            l->length -= 1;
            break;
        }
        prenode = prenode->next;
    }
}

// Append
void TX_List_Append(TX_List_List *l, TX_Anytype_AnytypeElement e){
    TX_List_Node *index = l->head;
    while(index->next!=NULL){
        index = index->next;
    }
    TX_List_Node *newnode = (TX_List_Node *)malloc(sizeof(TX_List_Node));
    newnode->data = e;
    newnode->next = NULL;
    index->next = newnode;
    l->length += 1;
}

// Prepend
void TX_List_Preppend(TX_List_List *l, TX_Anytype_AnytypeElement e){
    TX_List_Node *head = l->head;
    TX_List_Node *newnode = (TX_List_Node *)malloc(sizeof(TX_List_Node));
    newnode->data = e;
    newnode->next = head->next;
    head->next = newnode;
    l->length += 1;
}

// Delete first node
void TX_List_DeleteFirst(TX_List_List *l){
    if(l->length<=0)
        return;
    TX_List_Node *tempnode = l->head->next;
    l->head->next = tempnode->next;
    free(tempnode);
    l->length -= 1;
}

// Delete last node
void TX_List_DeleteLast(TX_List_List *l){
    TX_List_Node *prenode = l->head;
    while(prenode->next->next!=NULL){
        prenode = prenode->next;
    }
    TX_List_Node *tempnode;
    tempnode = prenode->next;
    free(tempnode);
    prenode->next = NULL;
    l->length -= 1;
}

// merge two list by input sequence
void TX_List_MergeTwoLists(TX_List_List *l1, TX_List_List *l2){
    TX_List_Node *index = l1->head;
    while(index->next!=NULL){
        index = index->next;
    }
    index->next = l2->head->next;
    l1->length = (l1->length)+(l2->length);
    free(l2->head);
    free(l2);
}

// traverse
void TX_List_Traverse(TX_List_List *l, void (*f)(TX_Anytype_AnytypeElement e)){
    TX_List_Node *index = l->head;
    while(index->next!=NULL){
        index = index->next;
        f(index->data);
    }
}

// Show the List
void TX_List_ShowList(TX_List_List *l){
    printf("-----------\n");
    printf("List:\n");
    TX_List_Traverse(l, TX_Anytype_ShowElementLine);
    printf("----------\n");
}

