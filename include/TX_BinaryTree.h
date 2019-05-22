#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#include "TX_Anytype.h"

#ifndef TX_BINARYTREE
#define TX_BINARYTREE

// Inorder threaded binary tree
typedef struct TX_BinaryTree_Tree{
    TX_Anytype_AnytypeElement data;
    size_t deepth; //The root node of the root node is not updated. Don't use it.
    bool hasLeftChild;
    struct TX_BinaryTree_Tree *left;
    bool hasRightChild;
    struct TX_BinaryTree_Tree *right;
}TX_BinaryTree_Tree;

typedef enum TX_BinaryTree_Child{
    left,
    right
}TX_BinaryTree_Child;

// Init 
TX_BinaryTree_Tree *TX_BinaryTree_Init(TX_Anytype_AnytypeElement rootData);

// Destroy
void TX_BinaryTree_Destroy(TX_BinaryTree_Tree *root);

// Insert
bool TX_BinaryTree_Insert(TX_BinaryTree_Tree *root, TX_BinaryTree_Child lr, TX_BinaryTree_Tree *subtree);

// Delete left child or right child
void TX_BinaryTree_Delete(TX_BinaryTree_Tree *root, TX_BinaryTree_Child lr);

// Cut child from a tree
TX_BinaryTree_Tree * TX_BinaryTree_Cut(TX_BinaryTree_Tree *root, TX_BinaryTree_Child lr);

// Show Tree
void TX_BinaryTree_Show(TX_BinaryTree_Tree *root,size_t indent);

// Preorder Traverse Recursion
void TX_BinaryTree_PreOrderTraverse(TX_BinaryTree_Tree *root);

// Inorder Traverse Recursion
void TX_BinaryTree_InOrderTraverse(TX_BinaryTree_Tree *root);

// Postorder Traverse Recursion
void TX_BinaryTree_PostOrderTraverse(TX_BinaryTree_Tree *root);

// No recursion traverse

#endif