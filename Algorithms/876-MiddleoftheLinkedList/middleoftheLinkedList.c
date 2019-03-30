//
// Created by zyc on 3/30/19.
//

#include <zconf.h>
#include "middleoftheLinkedList.h"


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
struct ListNode* middleNode(struct ListNode* head)
{
    if(head == NULL)
        return NULL;

    struct ListNode *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int middleNode_main()
{

    return 0;
}