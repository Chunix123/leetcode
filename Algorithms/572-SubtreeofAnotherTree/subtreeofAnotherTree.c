//
// Created by zyc on 3/23/19.
//

#include "subtreeofAnotherTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


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

bool isSubtreeHelper(struct TreeNode* s, struct TreeNode* t)
{
    if(!s && !t)
        return true;

    if(!s || !t || s->val != t->val)
        return false;

    return isSubtreeHelper(s->left, t->left) && isSubtreeHelper(s->right, t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
    if(isSubtreeHelper(s, t) || (s && isSubtree(s->left, t)) || (s && isSubtree(s->right, t)))
        return true;

    return false;
}

int isSubtree_main()
{

    return 0;
}
