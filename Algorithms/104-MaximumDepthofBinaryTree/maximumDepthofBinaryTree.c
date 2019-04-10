//
// Created by zyc on 19-4-10.
//
/* 104. Maximum Depth of Binary Tree
 * Given a binary tree, find its maximum depth.
    The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
    Note: A leaf is a node with no children.
    Example:
    Given binary tree [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    return its depth = 3.
 */

#include "maximumDepthofBinaryTree.h"
#include <stddef.h>


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

int maxDepth(struct TreeNode* root)
{
    if(root == NULL)
        return 0;

    int value_left  = maxDepth(root->left);
    int value_right = maxDepth(root->right);

    return 1 + (value_left > value_right ? value_left : value_right);
}


int maxDepth_main()
{

    return 0;
}