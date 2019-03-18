//
// Created by zyc on 3/18/19.
//

#include "insertionSortList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
struct ListNode* insertionSortList2(struct ListNode* head)
{
    if(!head || !head->next)
        return head;

    struct ListNode dummy;
    struct ListNode *p0, *p, *p1;
    dummy.next = head;

    for (p0 = head, p = head->next; p != NULL; p0 = p, p = p->next)
    {
        if (p->val < p0->val)
        {
            p0->next = p->next;
            for (p1 = &dummy; p1 != p0; p1 = p1->next)
            {
                if (p1->next->val >= p->val)
                {
                    p->next = p1->next;
                    p1->next = p;
                    break;
                }
            }
            p = p0;
        }
    }

    return dummy.next;
}

int insertionSortList2_main()
{


    return 0;
}
