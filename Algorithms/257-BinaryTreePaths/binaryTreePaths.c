//
// Created by zyc on 19-4-11.
//
/* 257. Binary Tree Paths
 * Given a binary tree, return all root-to-leaf paths.
    Note: A leaf is a node with no children.
    Example:
    Input:

       1
     /   \
    2     3
     \
      5
    Output: ["1->2->5", "1->3"]
    Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 */

#include "binaryTreePaths.h"
#include <stddef.h>
#include <stdlib.h>
#include "asprintf.h"


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void binaryTreePathsHelper(struct TreeNode* root, char*** result, int* returnSize, char* path)
{
    if (!root)
        return;

    char* newpath = NULL;

    if (!root->left && !root->right) {
        asprintf(&newpath, "%s%d", path, root->val);
        *result = (char*) realloc(*result, ++(*returnSize) * sizeof(char**));
        (*result)[*returnSize-1] = newpath;
        return ;
    }

    asprintf(&newpath, "%s%d->", path, root->val);

    binaryTreePathsHelper(root->left, result, returnSize, newpath);
    binaryTreePathsHelper(root->right, result, returnSize, newpath);

    free(newpath);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    if (!root)
        return NULL;

    char** result = NULL;

    binaryTreePathsHelper(root, &result, returnSize, "");

    return result;
}


int binaryTreePaths_main()
{

    return 0;
}
