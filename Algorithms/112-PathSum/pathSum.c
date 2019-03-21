//
// Created by zyc on 3/21/19.
//
/* 112. Path Sum
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
    Note: A leaf is a node with no children.
    Example:
    Given the below binary tree and sum = 22,
          5
         / \
        4   8
       /   / \
      11  13  4
     /  \      \
    7    2      1
    return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */
#include <stdbool.h>
#include <stdio.h>
#include <zconf.h>
#include "pathSum.h"


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
bool hasPathSum(struct TreeNode* root, int sum)
{
    if (root == NULL)
        return false;

    int value = root->val;

    if(root->left == NULL && root->right == NULL)
        return sum == value ? true : false;

    if(root->left != NULL)
    {
        bool isHas = hasPathSum(root->left, sum - value);
        if(isHas)
            return true;
    }

    if(root->right != NULL)
    {
        return hasPathSum(root->right, sum - value);
    }

    return false;
}
*/

bool hasPathSum(struct TreeNode* root, int sum)
{
    if(root == NULL){
        return false;
    }
    else if(root->left == NULL && root->right == NULL && root->val == sum){
        return true;
    }
    else{
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
}

int hasPathSum_main()
{

    return 0;
}