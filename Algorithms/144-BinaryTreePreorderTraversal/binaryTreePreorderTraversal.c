//
// Created by zyc on 3/22/19.
//
/* 144. Binary Tree Preorder Traversal
 * Given a binary tree, return the preorder traversal of its nodes' values.
    Example:
    Input: [1,null,2,3]
       1
        \
         2
        /
       3
    Output: [1,2,3]
 *
 */

#include "binaryTreePreorderTraversal.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void preorderHelper(struct TreeNode* root, int *value, int *len)
{
    if(root == NULL)
        return;

    value[*len] = root->val;
    *len += 1;

    preorderHelper(root->left, value, len);
    preorderHelper(root->right, value, len);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    if(root == NULL)
        return 0;

    int *value = malloc(sizeof(int) * 1000);

    preorderHelper(root, value, returnSize);

    return value;
}

/*
#define MAX_SIZE 100

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *R, i = 0, j = 0;
    struct TreeNode **stack, *p;

    R = (int*) malloc (sizeof(int) * MAX_SIZE);
    stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAX_SIZE);
    p = root;

    while(p || j > 0)
    {
        if(p)
        {
            R[i++] = p->val;
            stack[j++] = p;
            p = p->left;
        }
        else
        {
            p = stack[--j];
            p = p->right;
        }
    }
    *returnSize = i;

    return R;
}
*/


int preorderTraversal_main()
{

    return 0;
}