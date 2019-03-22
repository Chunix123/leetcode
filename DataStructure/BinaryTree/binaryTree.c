//
// Created by zyc on 3/22/19.
//

#include <stdio.h>
#include "binaryTree.h"


struct NodeTree;

typedef struct NodeTree {
    int val;
    struct NodeTree *left;
    struct NodeTree *right;
} TreeNode;

int countNodes(TreeNode *root)
{
    if(root == NULL)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}

void PreOrderTraverse(TreeNode *root)
{
    if(root == NULL)
        return;


}

int binaryTree_main()
{
    printf("Hello, World!\n");
    //countNodes();

    return 0;
}