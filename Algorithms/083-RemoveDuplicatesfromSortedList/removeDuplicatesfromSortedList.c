//
// Created by zyc on 3/13/19.
//

#include <zconf.h>
#include <stdlib.h>
#include <stdio.h>
#include "removeDuplicatesfromSortedList.h"


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

/*
struct ListNode* deleteDuplicates(struct ListNode* head)
{
 	for(struct ListNode *cur = head; cur != NULL; cur = cur->next)
 		for(struct ListNode *check = cur->next; check != NULL; check = check->next)
 			if(cur->val == check->val)
 				cur->next = check->next;

 	return head;

}
*/

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(head == NULL)
        return NULL;

    int num;
    struct ListNode ls, *tail = &ls;

    while(head != NULL)
    {
        if(num != head->val)
        {
            struct ListNode *node = malloc(sizeof(*node));
            node->next = NULL;
            tail->next = node;
            tail = node;

            node->val = head->val;
            num = node->val;
            head = head->next;
        }
        else
        {
            head = head->next;
            continue;
        }
    }

    return ls.next;
}

int deleteDuplicates_main()
{

    return 0;
}
