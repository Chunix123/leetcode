//
// Created by zyc on 3/14/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "swapNodesinPairs.h"


struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
struct ListNode* swapPairs(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode *pTemp;
    pTemp = head;

    head = head->next;
    pTemp->next = head->next;
    head->next = pTemp;
    head->next->next = swapPairs(head->next->next);

    return head;
}
*/

struct ListNode* swapPairs(struct ListNode* head)
{
    if(!head || !head->next)
        return head;

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *prev = &dummy;
    struct ListNode *p = dummy.next;
    struct ListNode *next = p->next;

    while(p != NULL && next != NULL)
    {
        prev->next = next;
        p->next = next->next;
        next->next = p;
        prev = p;

        p = p->next;
        if(p != NULL)
            next = p->next;
    }

    return dummy.next;
}

int swapPairs_main()
{

    return 0;
}