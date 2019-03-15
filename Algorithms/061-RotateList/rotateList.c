//
// Created by zyc on 3/15/19.
//
/* 61. Rotate List
 *  Given a linked list, rotate the list to the right by k places, where k is non-negative.
    Example 1:
    Input: 1->2->3->4->5->NULL, k = 2
    Output: 4->5->1->2->3->NULL
    Explanation:
    rotate 1 steps to the right: 5->1->2->3->4->NULL
    rotate 2 steps to the right: 4->5->1->2->3->NULL
 */

#include "rotateList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct ListNode {
    int val;
    struct ListNode *next;
};

/*
struct ListNode* getLinkEnd(struct ListNode* head)
{
    struct ListNode* next = NULL;

    while(head)
    {
        if(!head->next)
        {
            next = head;
            //printf("%d %d\n", head->val, next->val);
            return next;
        }
        head = head->next;
    }

    return next;
}

void printList(struct ListNode *head)
{
    while(head)
    {
        printf("%d ", head->val);
        head= head->next;
    }
    printf("\n");

    return;
}
*/

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if(!k)
        return head;

    if(!head || !head->next)
        return head;

    int i, len = 1;
    struct ListNode *p = head;

    while(p->next != NULL)
    {
        p = p->next;
        len++;
    }

    p->next = head;

    k = len - k % len;

    for(i = 0; i < k; i++)
        p = p->next;

    head = p->next;
    p->next = NULL;

    return head;
}

int rotateRight_main()
{

    return 0;
}