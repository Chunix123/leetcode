//
// Created by zyc on 3/21/19.
//
/* 437. Path Sum III
 * You are given a binary tree in which each node contains an integer value.
    Find the number of paths that sum to a given value.
    The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
    The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
    Example:
    root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
          10
         /  \
        5   -3
       / \    \
      3   2   11
     / \   \
    3  -2   1
    Return 3. The paths that sum to 8 are:
    1.  5 -> 3
    2.  5 -> 2 -> 1
    3. -3 -> 11
 */

#include "pathSumIII.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int helper(struct TreeNode *node, int sum)
{
    if(node == NULL)
        return 0;

    int res = 0;

    if(sum == node->val)
        res++;

    res += helper(node->left, sum - node->val);
    res += helper(node->right, sum - node->val);

    return res;
}

int pathSum3(struct TreeNode *root, int sum)
{
    if(root == NULL)
        return 0;

    return helper(root, sum)+ pathSum3(root->left, sum) + pathSum3(root->right, sum);
}

int pathSum3_main()
{

    return 0;
}
