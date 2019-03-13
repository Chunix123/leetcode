//
// Created by zyc on 3/13/19.
//

#include <zconf.h>
#include <stdio.h>
#include <stdlib.h>
#include "removeNthNodeFromEndofList.h"

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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if(head == NULL)
        return NULL;

    int len = 0, i = 0;
    struct ListNode *p = head;

    while(p != NULL)
    {
        len++;
        p = p->next;
    }

    if(n > len)
        return NULL;

    struct ListNode dummy;
    struct ListNode *node;

    len = len - n;
    //printf("%d\n", len);
    node = &dummy;
    dummy.next = head;
    p = head;

    while(p != NULL)
    {
        if(i == len)
        {
            //node->next = p;
            p = p->next;
            node->next = p;
            //continue;
        }

        node = p;

        i++;
        if(p != NULL)
            p = p->next;
    }

    return dummy.next;
}

int removeNthFromEnd_main()
{


    return 0;
}