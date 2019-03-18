//
// Created by zyc on 3/18/19.
//
/* 86. Partition List
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
    You should preserve the original relative order of the nodes in each of the two partitions.
    Example:
    Input: head = 1->4->3->2->5->2, x = 3
    Output: 1->2->2->4->3->5
 */

#include "partitionList.h"
#include <stdlib.h>
#include <stdio.h>

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
struct ListNode* partition(struct ListNode* head, int x)
{
    if(!head || !head->next)
        return head;

    struct ListNode dummy, dumax;
    struct ListNode *prev = &dummy, *prer = &dumax;

    struct ListNode *p = head;

    while(p != NULL)
    {
        if(p->val < x)
        {
            prev->next = p;
            prev = prev->next;
            prer->next = NULL;
        }
        else
        {
            prer->next = p;
            prer = prer->next;
            prev->next = NULL;
        }

        p = p->next;
    }

    prev->next = dumax.next;

    return dummy.next;
}

int partition_main()
{


    return 0;
}
