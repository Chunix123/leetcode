//
// Created by zyc on 3/13/19.
//

#include "deleteNodeinaLinkedList.h"

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

void deleteNode(struct ListNode* node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}

int deleteNode_main()
{

    return 0;
}
