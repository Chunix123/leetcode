//
// Created by zyc on 3/13/19.
//

#include "reverseLinkedList.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

/*
struct ListNode* reverseList(struct ListNode* head)
{
    if(!head || !head->next)
        return head;

    int len = 0;
    struct ListNode *p = head;

    while(p != NULL)
    {
        len++;
        p = p->next;
    }

    int *nums;
    nums = malloc(sizeof(int) * len);
    p = head;
    int i = 0;

    while(p != NULL)
    {
        nums[i++] = p->val;
        p = p->next;
    }

    i = 0;
    p = head;
    for(i = 0; i < len; i++)
    {
        p->val = nums[len - i - 1];
        p = p->next;
    }

    return head;
}
*/

struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* prev = NULL;

    while (head != NULL)
    {
        struct ListNode* temp = head;
        head = head->next;
        temp->next = prev;
        prev = temp;
    }

    return prev;
}

int reverseList_main()
{

    return 0;
}