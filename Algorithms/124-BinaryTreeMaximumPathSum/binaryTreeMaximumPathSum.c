//
// Created by zyc on 3/26/19.
//
/* 124. Binary Tree Maximum Path Sum
    Given a non-empty binary tree, find the maximum path sum.
    For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
    Example 1:
    Input: [1,2,3]
           1
          / \
         2   3
    Output: 6
    Example 2:
    Input: [-10,9,20,null,null,15,7]
       -10
       / \
      9  20
        /  \
       15   7

    Output: 42
 */
#include <zconf.h>
#include "binaryTreeMaximumPathSum.h"


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int max(int x, int y)
{
    return x > y ? x : y;
}

int maxPathSumHelper(struct TreeNode *root, int *result)
{
    if(root == NULL)
        return 0;

    int left = max(0, maxPathSumHelper(root->left, result));
    int right = max(0, maxPathSumHelper(root->right, result));

    *result = max(*result, root->val + left + right);

    return root->val + max(left, right);
}

int maxPathSum(struct TreeNode* root)
{
    if(root == NULL)
        return 0;

    int result = INT_MIN;

    maxPathSumHelper(root, &result);

    return result;
}

int maxPathSum_main()
{

    return 0;
}