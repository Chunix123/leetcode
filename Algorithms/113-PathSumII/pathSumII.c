//
// Created by zyc on 3/21/19.
//

#include <zconf.h>
#include <string.h>
#include <stdlib.h>
#include "pathSumII.h"



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
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(struct TreeNode *node, int sum, int *stack, int len, int **results, int *sizes, int *count)
{
    if(node == NULL)
        return;

    sum -= node->val;

    if(node->left == NULL && node->right == NULL && sum == 0)
    {
        results[*count] = malloc((len + 1) * sizeof(int));
        memcpy(results[*count], stack, len * sizeof(int));
        results[*count][len] = node->val;
        sizes[*count] = len + 1;
        (*count)++;
        return;
    }

    stack[len] = node->val;
    dfs(node->left, sum, stack, len + 1, results, sizes, count);
    dfs(node->right, sum, stack, len + 1, results, sizes, count);
}

int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize)
{
    if(root == NULL)
    {
        *returnSize = 0;
        return 0;
    }

    int level = 1000, cap = 2000;
    int **results = malloc(cap * sizeof(int*));
    int *stack = malloc(level * sizeof(int));
    *columnSizes = malloc(cap * sizeof(int));

    dfs(root, sum, stack, 0, results, *columnSizes, returnSize);

    return results;
}

int pathSum2_main()
{

    return 0;
}