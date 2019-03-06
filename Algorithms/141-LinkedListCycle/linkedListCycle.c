//
// Created by zyc on 3/6/19.
//

/** 141. Linked List Cycle
 *  Given a linked list, determine if it has a cycle in it.
 *  To represent a cycle in the given linked list, we use an
 *  integer pos which represents the position (0-indexed) in
 *  the linked list where tail connects to. If pos is -1, then
 *  there is no cycle in the linked list.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include <zconf.h>
#include <malloc.h>
#include <stdlib.h>
#include "linkedListCycle.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
    if(head == NULL && head->next == NULL)
        return false;

    struct ListNode *p0 = head;
    struct ListNode *p1 = head;

    do{
        p0 = p0->next;
        p1 = p1->next->next;
    }while(p1 != NULL && p1->next != NULL && p1 != p0);

    return p1 == p0 ? true : false;
}


int hasCycle_main(int argc, char **argv)
{
    int i, num;
    struct ListNode *head = NULL, *p, *prev;

    num = argc - 1;

    for(i = 0; i < num; i++)
    {
        p = malloc(sizeof(*p));
        p->val = atoi(argv[i + 1]);
        p->next = NULL;

        if(head == NULL)
            head = p;
        else
            prev->next = p;

        prev = p;
    }
    p->next = head;

    printf("%s\n", hasCycle(head) ? "true" : false);

    return 0;
}
