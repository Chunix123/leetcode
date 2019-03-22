//
// Created by zyc on 3/23/19.
//

#include "binaryTreePostorderTraversal.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


#define MAXSIZE 100

/*
void inorderHelper(struct TreeNode* root, int *value, int* size)
{
    if(root == NULL)
        return;

    inorderHelper(root->left, value, size);
    inorderHelper(root->right, value, size);
    value[(*size)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    if(root == NULL)
        return 0;

    int *value = malloc(sizeof(int) * MAXSIZE);

    inorderHelper(root, value, returnSize);

    return value;
}
*/


/*
struct stack
{
	struct TreeNode *tree;
	struct stack *next;
};

void push(struct stack **head, struct TreeNode *t)
{
	struct stack *temp = (struct stack *)malloc(sizeof(struct stack));

	temp->tree = (struct TreeNode*)malloc(sizeof(struct TreeNode));;
	temp->tree = t;
	temp->next = (*head);
	*head = temp;
}

struct TreeNode *pop(struct stack **head)
{
	struct TreeNode *tree = (*head)->tree;
	struct stack *node = *head;
	*head = (*head)->next;

	free(node);
	return tree;
}

int is_empty(struct TreeNode *node)
{
	return (node == NULL);
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    struct stack *s1 = NULL, *s2 = NULL;
	struct TreeNode *node = 0;
	int cnt = 0, *arr = NULL;

    if(root == NULL)
        return NULL;
	push(&s1, root);

	while(!is_empty(s1))
	{
		node = pop(&s1);
		push(&s2, node);
		if(node->left != NULL)
			push(&s1, node->left);
		if(node->right != NULL)
			push(&s1, node->right);
	}

    while (!is_empty(s2))
    {
        node = pop(&s2);
		cnt++;
        *returnSize = cnt;
		if(arr == NULL)
				arr = (int*)malloc(sizeof(int));
			else
				arr = realloc(arr, *returnSize*sizeof(int));
		arr[cnt-1] = node->val;
	}

	return arr;
}
*/

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *array     = NULL;
    int *tempArray = NULL;
    int tempSize   = 0;

    array     = (int *) malloc(sizeof(int));
    tempArray = (int *) malloc(sizeof(int));

    if(NULL != root)
    {
        tempArray = postorderTraversal(root->left, &tempSize);

        if(tempSize)
        {
            array = (int*)realloc(array, ((*returnSize) + (tempSize)) * (sizeof(int)));
            memcpy(&array[*returnSize], tempArray, tempSize * (sizeof(int)) );
            (*returnSize) += tempSize;
            tempSize = 0;
        }

        tempArray = postorderTraversal(root->right, &tempSize);

        if(tempSize)
        {
            array = (int*)realloc(array, ((*returnSize) + (tempSize)) * (sizeof(int)));
            memcpy(&array[*returnSize], tempArray, tempSize * (sizeof(int)));
            (*returnSize) += tempSize;
            tempSize = 0;
        }
        array = (int*)realloc(array, ((*returnSize) + 1) * (sizeof(int)));
        array[*returnSize] = root->val;
        (*returnSize)++;

    }

    free(tempArray);

    return array;
}

int postorderTraversal_main()
{


    return 0;
}
