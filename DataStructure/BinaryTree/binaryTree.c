//
// Created by zyc on 3/22/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

#define MAXSIZE 100


struct NodeTree;

typedef struct NodeTree {
    int val;
    struct NodeTree *left;
    struct NodeTree *right;
} TreeNode;


//1. 二叉树的节点个数
int countNodes(TreeNode *root)
{
    if(root == NULL)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}

//2.1 前序遍历
void preorderHelper(TreeNode* root, int *value, int *len)
{
    if(root == NULL)
        return;

    value[(*len)++] = root->val;

    preorderHelper(root->left, value, len);
    preorderHelper(root->right, value, len);
}

int* preorderTraversal(TreeNode* root, int* returnSize)
{
    if(root == NULL)
        return 0;

    int *value = malloc(sizeof(int) * MAXSIZE);

    preorderHelper(root, value, returnSize);

    return value;
}

/*
//非递归方式
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *R, i = 0, j = 0;
    struct TreeNode **stack, *p;

    R = (int*) malloc (sizeof(int) * MAX_SIZE);
    stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAX_SIZE);
    p = root;

    while(p || j > 0)
    {
        if(p)
        {
            R[i++] = p->val;
            stack[j++] = p;
            p = p->left;
        }
        else
        {
            p = stack[--j];
            p = p->right;
        }
    }
    *returnSize = i;

    return R;
}
*/

//2.2 中序遍历
void inorderHelper(TreeNode* root, int *value, int* size)
{
    if(root == NULL)
        return;

    inorderHelper(root->left, value, size);
    value[(*size)++] = root->val;
    inorderHelper(root->right, value, size);
}

int* inorderTraversal(TreeNode* root, int* returnSize)
{
    if(root == NULL)
        return 0;

    int *value = malloc(sizeof(int) * MAXSIZE);

    inorderHelper(root, value, returnSize);

    return value;
}

/*
//非递归方式
int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *ret = (int*)malloc(sizeof(int) * MAXSIZE);
    int num = 0;

    struct TreeNode *stack[MAXSIZE] = {0};
    int top = -1;

    while (root != NULL || top >= 0) {
        if (root != NULL) {
            top++;
            stack[top] = root;
            root = root->left;
        } else {
            root = stack[top];
            top--;

            ret[num] = root->val;
            num++;

            root = root->right;
        }
    }

    *returnSize = num;

    return ret;
}
 */

//2.3 后续遍历
void postorderHelper(TreeNode* root, int *value, int* size)
{
    if(root == NULL)
        return;

    postorderHelper(root->left, value, size);
    postorderHelper(root->right, value, size);
    value[(*size)++] = root->val;
}

int* postorderTraversal(TreeNode* root, int* returnSize)
{
    if(root == NULL)
        return 0;

    int *value = malloc(sizeof(int) * MAXSIZE);

    postorderHelper(root, value, returnSize);

    return value;
}

/*
//非递归方式
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

//3. 二叉树的深度
int GetDepth(TreeNode* root)
{
    if(root == NULL)
        return 0;

    int depthLeft = GetDepth(root->left) + 1;
    int depthRight = GetDepth(root->right) + 1;

    return depthLeft > depthRight ? depthLeft : depthRight;
}

//4. 二叉树中叶子节点的个数
int countLeafNodes(TreeNode* root)
{
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    return (countLeafNodes(root->left) + countLeafNodes(root->right));
}

//5. 二叉树第k层的节点个数
int countKthLevel(TreeNode* root, int k)
{
    if(root == NULL || k < 1)
        return 0;

    if(k == 1)
        return 1;

    return countKthLevel(root->left, k - 1) + countKthLevel(root->right, k - 1);
}



int binaryTree_main()
{
    printf("Hello, World!\n");
    //countNodes();

    return 0;
}