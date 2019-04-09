//
// Created by zyc on 19-4-10.
//
/* 101. Symmetric Tree
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
    For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
 */

#include <stdbool.h>
#include <stddef.h>
#include "symmetricTree.h"


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
bool isSymmetricHelper(struct TreeNode *left, struct TreeNode *right)
{
    if(left == NULL && right == NULL)
        return true;
    else if(left != NULL && right == NULL)
        return false;
    else if(left == NULL && right != NULL)
        return false;
    else if((left != NULL && right != NULL) && (left->val != right->val))
        return false;
    else
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if(root == NULL)
        return true;

    return isSymmetricHelper(root->left, root->right);
}


int isSymmetric_main()
{


    return 0;
}

