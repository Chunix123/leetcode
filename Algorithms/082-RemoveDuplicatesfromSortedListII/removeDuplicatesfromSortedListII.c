//
// Created by zyc on 3/13/19.
//

#include <zconf.h>
#include <stdio.h>
#include <stdlib.h>
#include "removeDuplicatesfromSortedListII.h"

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

struct ListNode* deleteDuplicates2(struct ListNode* head) {
    struct ListNode dummy;
    struct ListNode *p = head, *next = head, *prev;

    prev = &dummy;
    dummy.next = head;

    while(p != NULL)
    {
        while (next != NULL && next->val == p->val)
        {
            next = next->next;
        }

        if(p->next = next)
        {
            prev = p;
        }
        else
        {
            prev->next = next;
        }

        p = next;
    }

    return dummy.next;
}

int deleteDuplicates2_main(int argc, char **argv)
{
    int i;
    struct ListNode *head = NULL;
    struct ListNode *prev = NULL;
    struct ListNode *p;

    for(i = 0; i < argc - 1; i++)
    {
        p = malloc(sizeof(*p));
        p->val = atoi(argv[i + 1]);
        p->next = NULL;
        if(head == NULL)
        {
            head = p;
            prev = head;
        }
        else
        {
            prev->next = head;
            prev = p;
        }
    }

    //p = deleteDuplicates2(head);
    while(head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");

    return 0;
}