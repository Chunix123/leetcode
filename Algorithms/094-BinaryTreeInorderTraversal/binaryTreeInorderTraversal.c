//
// Created by zyc on 3/23/19.
//

#include "binaryTreeInorderTraversal.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
#define MAXSIZE 100

void inorderHelper(struct TreeNode* root, int *value, int* size)
{
    if(root == NULL)
        return;

    inorderHelper(root->left, value, size);
    value[(*size)++] = root->val;
    inorderHelper(root->right, value, size);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    if(root == NULL)
        return 0;

    int *value = malloc(sizeof(int) * MAXSIZE);

    inorderHelper(root, value, returnSize);

    return value;
}
*/

#define MAXSIZE 100

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *ret = (int*)malloc(sizeof(int) * MAXSIZE);
    int num = 0;

    struct TreeNode *stack[MAXSIZE] = {0};
    int top = -1;

    while (root != NULL || top >= 0) {
        if (root != NULL) {
            top++;
            stack[top] = root;
            root = root->left;
        } else {
            root = stack[top];
            top--;

            ret[num] = root->val;
            num++;

            root = root->right;
        }
    }

    *returnSize = num;

    return ret;
}

int inorderTraversal_main()
{

    return 0;
}
