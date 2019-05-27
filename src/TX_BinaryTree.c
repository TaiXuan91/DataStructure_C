#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "TX_Anytype.h"
#include "TX_BinaryTree.h"
#include "TX_Stack.h"


// Init 
TX_BinaryTree_Tree *TX_BinaryTree_Init(TX_Anytype_AnytypeElement rootData){
    TX_BinaryTree_Tree *root = (TX_BinaryTree_Tree *)malloc(sizeof(TX_BinaryTree_Tree));
    root->data = rootData;
    root->deepth = 1;
    root->hasLeftChild = false;
    root->left = NULL;
    root->hasRightChild = false;
    root->right = NULL;
    return root;
}

// Destroy
void TX_BinaryTree_Destroy(TX_BinaryTree_Tree *root){
    if(root==NULL){
        return;
    }
    if(root->hasLeftChild){
        TX_BinaryTree_Destroy(root->left);
    }
    if(root->hasRightChild){
        TX_BinaryTree_Destroy(root->right);
    }
    free(root);
}

// Insert
// false means insertion failed
bool TX_BinaryTree_Insert(TX_BinaryTree_Tree *root, TX_BinaryTree_Child lr, TX_BinaryTree_Tree *subtree){
    if(lr==left && (!root->hasLeftChild)){
        TX_BinaryTree_Tree *temp = root->left;
        root->hasLeftChild = true;
        root->left = subtree;
        //threaded binary tree
        TX_BinaryTree_Tree *mostLeft = subtree;
        while(mostLeft->hasLeftChild)mostLeft = mostLeft->left;
        mostLeft->left = temp;
        TX_BinaryTree_Tree *mostRight = subtree;
        while(mostRight->hasRightChild)mostRight = mostRight->right;
        mostRight->right = root;
    }
    if(lr==right && (!root->hasRightChild)){
        TX_BinaryTree_Tree *temp = root->right;
        root->hasRightChild = true;
        root->right = subtree;
        //threaded binary tree
        TX_BinaryTree_Tree *mostRight = subtree;
        while(mostRight->hasRightChild)mostRight = mostRight->right;
        mostRight->right = temp;
        TX_BinaryTree_Tree *mostLeft = subtree;
        while(mostLeft->hasLeftChild)mostLeft = mostLeft->left;
        mostLeft->left = root;
    }
    root->deepth = root->deepth>=(subtree->deepth+1)?root->deepth:(subtree->deepth+1);
    return true;
}

// Cut child from a tree
TX_BinaryTree_Tree *TX_BinaryTree_Cut(TX_BinaryTree_Tree *root, TX_BinaryTree_Child lr){
    TX_BinaryTree_Tree *child;
    if(lr==left){
        if(!(root->hasLeftChild))return NULL;
        child = root->left;
        //threaded
        TX_BinaryTree_Tree *mostLeft = child;
        while(mostLeft->hasLeftChild)mostLeft = mostLeft->left;
        root->left = mostLeft->left;
        mostLeft->left = NULL;
        root->hasLeftChild = false;
        TX_BinaryTree_Tree *mostRight = child;
        while(mostRight->hasRightChild)mostRight = mostRight->right;
        mostRight->right = NULL;
        // change deepth
        if(root->hasRightChild){
            root->deepth = root->right->deepth+1;
        }
        else
        {
            root->deepth = 1;
        }
        
    }
    if(lr==right){
        if(!(root->hasRightChild))return NULL;
        child = root->right;
        //threaded
        TX_BinaryTree_Tree *mostRight = child;
        while(mostRight->hasRightChild)mostRight = mostRight->right;
        root->right = mostRight->right;
        mostRight->right = NULL;
        root->hasRightChild = false;
        TX_BinaryTree_Tree *mostLeft = child;
        while(mostLeft->hasLeftChild)mostLeft = mostLeft->left;
        mostLeft->left = NULL;
        if(root->hasLeftChild){
            root->deepth = root->left->deepth+1;
        }
        else
        {
            root->deepth = 1;
        }
        
    }
    return child;
}

// Delete left child or right child
void TX_BinaryTree_Delete(TX_BinaryTree_Tree *root, TX_BinaryTree_Child lr){
    TX_BinaryTree_Tree *temp = TX_BinaryTree_Cut(root, lr);
    TX_BinaryTree_Destroy(temp);
}

// Show Tree
void TX_BinaryTree_Show(TX_BinaryTree_Tree *root,size_t indent){
    char buffer[50]={'\0'};
    for(size_t i=0; i<indent;i++){
        printf("  ");
    }
    TX_Anytype_ShowElement(root->data, buffer);
    printf("|%s|\n",buffer);
    if(!(root->hasLeftChild || root->hasRightChild)){
        return;
    }
    if(root->hasLeftChild){
        TX_BinaryTree_Show(root->left, indent+1);
    }
    else{
        for(size_t i=0; i<indent+1;i++){
        printf("  ");
        }
        printf("left empty\n");
    }
    if(root->hasRightChild){
        TX_BinaryTree_Show(root->right, indent+1);
    }
    else{
        for(size_t i=0; i<indent+1;i++){
        printf("  ");
        }
        printf("right empty\n");
    }
}

// Preorder Traverse Recursion
void TX_BinaryTree_LevelOrderTraverse(TX_BinaryTree_Tree *root){
    TX_Stack_Stack *s1 = TX_Stack_Init();
    TX_Stack_Stack *s2 = TX_Stack_Init();
    TX_Anytype_AnytypeElement e;
    e.type = TX_VOID_POINTER;
    if(root!=NULL){
        e.data.void_pointer_value = root;
        TX_Stack_Push(s1, e);
    }
    else{return;}
    printf("traverse the tree:\n");
    while (!TX_Stack_IsEmpty(s1))
    {
        while(!TX_Stack_IsEmpty(s1)){
            e = TX_Stack_Pop(s1);
            TX_BinaryTree_Tree *current = (TX_BinaryTree_Tree *)e.data.void_pointer_value;
            printf(" %d ", current->data.data.integer_value);
            if(current->hasLeftChild){
                e.data.void_pointer_value = current->left;
                TX_Stack_Push(s2, e);
            }
            if(current->hasRightChild){
                e.data.void_pointer_value = current->right;
                TX_Stack_Push(s2, e);
            }
        }
        while(!TX_Stack_IsEmpty(s2)){
            e = TX_Stack_Pop(s2);
            TX_Stack_Push(s1, e);
        }
    }
    TX_Stack_Destroy(s1);
    TX_Stack_Destroy(s2);
}


void TX_BinaryTree_PreOrderTraverse(TX_BinaryTree_Tree *root){
    TX_Stack_Stack *s1 = TX_Stack_Init();
    TX_Anytype_AnytypeElement e;
    e.type = TX_VOID_POINTER;
    if(root!=NULL){
        e.data.void_pointer_value = root;
        TX_Stack_Push(s1, e);
    }
    else{return;}
    printf("traverse the tree:\n");
    while (!TX_Stack_IsEmpty(s1))
    {
        e = TX_Stack_Pop(s1);
        TX_BinaryTree_Tree *current = (TX_BinaryTree_Tree *)e.data.void_pointer_value;
        printf(" %d ", current->data.data.integer_value);
        if(current->hasRightChild){
                e.data.void_pointer_value = current->right;
                TX_Stack_Push(s1, e);
        }
        if(current->hasLeftChild){
                e.data.void_pointer_value = current->left;
                TX_Stack_Push(s1, e);
        }
    }
    TX_Stack_Destroy(s1);
}

// Inorder Traverse Recursion
void TX_BinaryTree_InOrderTraverse(TX_BinaryTree_Tree *root){
    TX_Stack_Stack *s1 = TX_Stack_Init();
    TX_Anytype_AnytypeElement e;
    e.type = TX_VOID_POINTER;
    TX_BinaryTree_Tree *current;
    if(root==NULL){
       return;
    }
    current = root;
    e.data.void_pointer_value = current;
    TX_Stack_Push(s1, e);
    while(current->hasLeftChild){
    e.data.void_pointer_value = current;
    TX_Stack_Push(s1, e);
    current = current->left;
    }
    printf("traverse the tree:\n");
    while (!TX_Stack_IsEmpty(s1))
    {
        e = TX_Stack_Pop(s1);
        current = (TX_BinaryTree_Tree *)e.data.void_pointer_value;
        printf(" %d ", current->data.data.integer_value);
        if(current->hasRightChild){
            e.data.void_pointer_value = current->right;
            TX_Stack_Push(s1, e);
            while(current->hasLeftChild){
                current = current->left;
                e.data.void_pointer_value = current;
                TX_Stack_Push(s1, e);
            }
        }
    }
    TX_Stack_Destroy(s1);
}

// Postorder Traverse Recursion
void TX_BinaryTree_PostOrderTraverse(TX_BinaryTree_Tree *root){
    TX_Stack_Stack *s1 = TX_Stack_Init();
    TX_Stack_Stack *s2 = TX_Stack_Init();
    TX_Anytype_AnytypeElement e1;
    e1.type = TX_VOID_POINTER;
    TX_Anytype_AnytypeElement e2; //tag left visited
    e2.type = TX_BOOL;
    TX_BinaryTree_Tree *current;
    current = root;
    while(current != NULL || !TX_Stack_IsEmpty(s1)){
        if(current != NULL){
            while(current->hasLeftChild){
            e1.data.void_pointer_value = current;
            e2.data.bool_value = false;
            TX_Stack_Push(s1, e1);
            TX_Stack_Push(s2, e2);
            current = current->left;
            }
            if(current->hasRightChild){
            e1.data.void_pointer_value = current;
            e2.data.bool_value = true;
            TX_Stack_Push(s1, e1);
            TX_Stack_Push(s2, e2);
            current = current->right;
            continue;
            }
        }
        else{
            e1 = TX_Stack_Pop(s1);
            e2 = TX_Stack_Pop(s2);
            current = (TX_BinaryTree_Tree *)e1.data.void_pointer_value;
            if(!(e2.data.bool_value)){
                if(current->hasRightChild){
                    e1.data.void_pointer_value = current;
                    e2.data.bool_value = true;
                    TX_Stack_Push(s1, e1);
                    TX_Stack_Push(s2, e2);
                    current = current->right;
                    continue;
                }
            }
        }
        printf(" %d ", current->data.data.integer_value);
        current = NULL;
    }
}
