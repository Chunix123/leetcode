//
// Created by zyc on 3/13/19.
//

#include <stdbool.h>
#include <zconf.h>
#include <stdlib.h>
#include <stdio.h>
#include "addTwoNumber.h"


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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    bool flag = false;
    int num = 0;
    struct ListNode ls, *tail = &ls;
    ls.next = NULL;

    while(l1 != NULL || l2 != NULL)
    {
        struct ListNode *node = malloc(sizeof(*node));
        node->next = NULL;
        tail->next = node;
        tail = node;

        if(l1 != NULL && l2 != NULL)
            num = l1->val + l2->val;
        else if(l1 != NULL && l2 == NULL)
            num = l1->val;
        else if(l1 == NULL && l2 != NULL)
            num = l2->val;

        if(flag)
        {
            num += 1;
            flag = false;
        }
        node->val = num % 10;

        if(num >= 10)
            flag = true;

        if(l1 != NULL)
            l1 = l1->next;
        if(l2 != NULL)
            l2 = l2->next;

        if(l1 == NULL && l2 == NULL)
        {
            if(flag)
            {
                struct ListNode *nod = malloc(sizeof(*nod));
                nod->next = NULL;
                nod->val = 1;
                tail->next = nod;
            }
        }
    }

    return ls.next;
}

int addTwoNumbers_main()
{


    return 0;
}