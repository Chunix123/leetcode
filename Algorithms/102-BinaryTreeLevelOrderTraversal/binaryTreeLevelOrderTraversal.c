//
// Created by zyc on 3/23/19.
//

#include "binaryTreeLevelOrderTraversal.h"
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
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAXSIZE 100

void levelOrderHelper(struct TreeNode* root, int** columnSizes, int* returnSize, int depth, int*** result)
{
    if(root == NULL)
        return;

    if(*returnSize < depth + 1)
    {
        *returnSize = depth + 1;

        //initalize
        (*result) = realloc((*result), (depth + 1) * sizeof(int*));
        (*result)[depth] = NULL;

        *columnSizes = realloc(*columnSizes, (depth + 1) * sizeof(int));
        (*columnSizes)[depth] = 0;
    }


    (*result)[depth] = realloc((*result)[depth], ((*columnSizes)[depth] + 1) * sizeof(int*));
    (*result)[depth][(*columnSizes)[depth]] = root->val;
    ++(*columnSizes)[depth];


    levelOrderHelper(root->left, columnSizes, returnSize, depth + 1, result);
    levelOrderHelper(root->right, columnSizes, returnSize, depth + 1, result);
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    if(root == NULL)
    {
        *returnSize = 0;
        return 0;
    }

    int **result = NULL;

    *returnSize = 0;
    levelOrderHelper(root, columnSizes, returnSize, 0, &result);

    return result;
}


/*
typedef struct _queue_node
{
    void *val;
    struct _queue_node *next;
    struct _queue_node *pre;
} queue_node;

typedef struct _queue
{
    int num;
    struct _queue_node *head;
    struct _queue_node *tail;
} queue;

void queue_init(queue *q);
bool queue_is_empty(queue *q);
int queue_length(queue *q);
bool queue_push(queue *q, void *val);
queue_node *queue_pop(queue *q);
void queue_destory(queue *q);


void queue_init(queue *q)
{
    q->num = 0;
    q->head = NULL;
    q->tail = NULL;

    return;
}

bool queue_is_empty(queue *q){
    return q->num == 0;
}

int queue_length(queue *q)
{
    return q->num;
}

bool queue_push(queue *q, void *val)
{
    queue_node *node = malloc(sizeof(queue_node));
    if (!node)
    {
        return false;
    }

    node->val = val;
    node->next = q->head;
    node->pre = NULL;

    if (q->head)
    {
        q->head->pre = node;
    }
    else
    {
        q->tail = node;
    }

    q->head = node;

    q->num++;

    return true;
}

queue_node *queue_pop(queue *q)
{
    if (!q->tail)
    {
        return NULL;
    }

    queue_node *node = q->tail;

    q->tail = q->tail->pre;

    if (!q->tail)
    {
        q->head = NULL;
    }

    q->num--;

    return node;
}

void queue_destory(queue *q)
{
    queue_node *node = q->head;
    queue_node *tmp = NULL;
    while (node)
    {
        tmp = node;
        node = node->next;
        free(tmp);
    }

    q->num = 0;
    q->head = NULL;
    q->tail = NULL;
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int **r = malloc(sizeof(int *) * 1000);
    *columnSizes = malloc(sizeof(int) * 1000);

    if (!root)
    {
        *returnSize = 0;
        *columnSizes[0] = 0;
        return r;
    }

    int level = 0;
    int *t;

    struct TreeNode *tree_node;

    queue q;
    queue *qp = &q;
    queue_node *n;

    queue_init(qp);
    queue_push(qp, root);

    while (!queue_is_empty(qp))
    {
        int l = queue_length(qp);
        (*columnSizes)[level] = l;
        t = malloc(sizeof(int) * l);
        r[level] = t;

        for (int i = 0; i < l; i++)
        {
            n = queue_pop(qp);
            tree_node = (struct TreeNode *)n->val;
            r[level][i] = tree_node->val;

            if (tree_node->left)
            {
                queue_push(qp, tree_node->left);
            }
            if (tree_node->right)
            {
                queue_push(qp, tree_node->right);
            }
        }
        level++;
    }

    queue_destory(qp);

    *returnSize = level;

    return r;
}
*/

int levelOrder_main()
{

    return 0;
}