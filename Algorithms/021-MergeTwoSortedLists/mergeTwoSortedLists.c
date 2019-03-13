//
// Created by zyc on 3/13/19.
//

#include <zconf.h>
#include "mergeTwoSortedLists.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(l1 == NULL && l2 == NULL)
        return NULL;

    struct ListNode ls, *tail = &ls;
    ls.next = NULL;

    while(l1 != NULL || l2 != NULL)
    {
        struct ListNode *node = malloc(sizeof(*node));
        node->next = NULL;
        tail->next = node;
        tail = node;

        if(l1 != NULL)
        {
            if(l2 != NULL)
            {
                if(l1->val < l2->val)
                {
                    node->val = l1->val;
                    l1 = l1->next;
                }
                else
                {
                    node->val = l2->val;
                    l2 = l2->next;
                }
            }
            else
            {
                node->val = l1->val;
                l1 = l1->next;
            }
        }
        else
        {
            node->val = l2->val;
            l2 = l2->next;
        }
    }

    return ls.next;
}


int mergeTwoLists_main()
{


    return 0;
}
