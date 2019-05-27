#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

#include "Test_Code.h"
#include "TX_Anytype.h"
#include "TX_BinaryTree.h"

bool Test_TX_BinaryTree(){
    printf("Start Binary Tree Test\n");
    TX_Anytype_AnytypeElement e;
    e.type = TX_INTEGER;
    e.data.integer_value = 12;
    TX_BinaryTree_Tree *root;
    TX_BinaryTree_Tree *tree;
    root = TX_BinaryTree_Init(e);
    e.data.integer_value =234;
    tree = TX_BinaryTree_Init(e);
    TX_BinaryTree_Insert(root, right, tree);
    e.data.integer_value = 23;
    tree = TX_BinaryTree_Init(e);
    TX_BinaryTree_Insert(root, left, tree);
    tree = root;
    e.data.integer_value = 45;
    root = TX_BinaryTree_Init(e);
    TX_BinaryTree_Insert(root, right, tree);
    e.data.integer_value = 40;
    tree = TX_BinaryTree_Init(e);
    TX_BinaryTree_Insert(root, left, tree);
    e.data.integer_value = 32;
    TX_BinaryTree_Insert(tree, right, TX_BinaryTree_Init(e));
    TX_BinaryTree_Show(root,0);
    printf("after cut--------\n");
    tree = TX_BinaryTree_Cut(root, left);
    TX_BinaryTree_Insert(root->right->left, left,tree);
    TX_BinaryTree_Show(root, 0);
    printf("thread: node %d left is %d\n", tree->data.data.integer_value, tree->left->data.data.integer_value);
    printf("begin traverse test!\n");
    printf("level order\n");
    TX_BinaryTree_LevelOrderTraverse(root);
    printf("\npreorder\n");
    TX_BinaryTree_PreOrderTraverse(root);
    printf("\ninorder\n");
    TX_BinaryTree_InOrderTraverse(root);
    printf("\npostorder\n");
    TX_BinaryTree_PostOrderTraverse(root);
    return true;
}