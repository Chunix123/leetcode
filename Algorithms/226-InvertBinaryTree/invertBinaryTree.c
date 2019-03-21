//
// Created by zyc on 3/21/19.
//
/* 226. Invert Binary Tree
 * Invert a binary tree.
    Example:
    Input:
         4
       /   \
      2     7
     / \   / \
    1   3 6   9
    Output:
         4
       /   \
      7     2
     / \   / \
    9   6 3   1
 */
#include "invertBinaryTree.h"
#include <stdio.h>

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
/*
struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root == NULL)
        return NULL;


    struct TreeNode *temp;

    temp = root->left;
    root->left = root->right;
    root->right = temp;

    if(root->left != NULL)
        invertTree(root->left);
    if(root->right != NULL)
        invertTree(root->right);

    return root;
}
*/

struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root == NULL)
        return NULL;

    struct TreeNode *temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
}

int invertTree_main()
{

    return 0;
}