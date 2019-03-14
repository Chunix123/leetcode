//
// Created by zyc on 3/14/19.
//
/* 203. Remove Linked List Elements
 *  Remove all elements from a linked list of integers that have value val.
    Example:
    Input:  1->2->6->3->4->5->6, val = 6
    Output: 1->2->3->4->5
 */
#include <stdio.h>
#include <stdlib.h>
#include "removeLinkedListElements.h"


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
    if(!head)
        return NULL;

    struct ListNode ls, *prev;

    prev = &ls;
    ls.next = head;

    while(head != NULL)
    {
        if(head->val != val)
        {
            struct ListNode *node = malloc(sizeof(*node));
            node->next = NULL;
            prev->next = node;
            prev = node;
            node->val = head->val;
        }
        else
        {
            prev->next = head->next;
        }

        head = head->next;
    }

    return ls.next;
}

int removeElements_main()
{

    return 0;
}