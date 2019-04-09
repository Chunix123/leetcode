//
// Created by zyc on 19-4-10.
//
/* 100. Same Tree
 *  Given two binary trees, write a function to check if they are the same or not.
    Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
 *
 */
#include "sameTree.h"
#include <stdbool.h>
#include <stddef.h>



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(p == NULL && q == NULL)
        return true;

    if(p == NULL || q == NULL)
        return false;

    if(p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

/*
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (!p && !q)
        return true;

    if (!p && q)
        return false;

    if (p && !q)
        return false;

    if (p->val != q->val)
        return false;

    if (false == isSameTree(p->left, q->left))
        return false;

    if (false == isSameTree(p->right, q->right))
        return false;

  return true;
}
*/

int isSameTree_main()
{


    return 0;
}
