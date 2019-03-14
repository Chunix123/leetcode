//
// Created by zyc on 3/14/19.
//

#include "reverseLinkedListII.h"
#include <stdlib.h>
#include <stdio.h>

/** 92. Reverse Linked List II
 * Reverse a linked list from position m to n. Do it in one-pass.
    Note: 1 ≤ m ≤ n ≤ length of list.
    Example:
    Input: 1->2->3->4->5->NULL, m = 2, n = 4
    Output: 1->4->3->2->5->NULL
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    if(!head || !head->next || m == n)
        return head;

    int len = n - m + 1;
    struct ListNode dummy;
    struct ListNode *p = head;
    struct ListNode *prev = &dummy;

    prev->next = p;

    while(--m > 0)
    {
        prev = p;
        p = p->next;
    }

    struct ListNode *q = p->next;

    while(--len > 0)
    {
        p->next = q->next;
        q->next = prev->next;
        prev->next = q;

        q = p->next;
    }

    return dummy.next;
}

int reverseBetween_main()
{

    return 0;
}
