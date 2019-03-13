//
// Created by zyc on 3/13/19.
//

#include <zconf.h>
#include <stdio.h>
#include <stdlib.h>
#include "IntersectionofTwoLinkedLists.h"
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

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    int lena = 0, lenb = 0;
    struct ListNode *p = headA, *q = headB;

    while(p != NULL)
    {
        lena++;
        p = p->next;
    }
    while(q != NULL)
    {
        lenb++;
        q = q->next;
    }
    //printf("%d %d\n", lena, lenb);

    if(lena - lenb > 0)
    {
        while(lena - lenb > 0)
        {
            headA = headA->next;
            lena -= 1;
        }
    }
    else if(lenb - lena > 0)
    {
        while(lenb - lena > 0)
        {
            headB = headB->next;
            lenb -= 1;
        }
    }
    //printf("%d %d\n", lena, lenb);
    //printf("%d %d\n", headB->val, headB->next->val);


    for(; headA != NULL; headA = headA->next, headB = headB->next)
    {
        struct ListNode **a = &headA, **b = &headB;
        if(*a == *b)
        {
            //printf("%d\n", headA->val);

            //struct ListNode *node = malloc(sizeof(*node));
            //node->val = headA->val;
            //node->next = NULL;
            //tail->next = node;
            //tail = node;
            break;
        }
        else
        {
            continue;
        }

    }
    //printf("%d %d\n", headA->val, headA->next->val);

    return headA;
}

int getIntersectionNode_main()
{

    return 0;
}
