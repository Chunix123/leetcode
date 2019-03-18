//
// Created by zyc on 3/18/19.
//
/* 142. Linked List Cycle II
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
    To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
    Note: Do not modify the linked list.
    Example 1:
    Input: head = [3,2,0,-4], pos = 1
    Output: tail connects to node index 1
    Explanation: There is a cycle in the linked list, where tail connects to the second node.
 */

#include "linkedListCycleII.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
struct ListNode *detectCycle(struct ListNode *head)
{
    if(!head || !head->next)
        return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    bool first = false;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast && first)
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }

        first = true;
    }

    return NULL;
}

int detectCycle_main()
{

    return 0;
}

