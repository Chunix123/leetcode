//
// Created by zyc on 3/15/19.
//
/* 234. Palindrome Linked List
 * Given a singly linked list, determine if it is a palindrome.
 *   Example 1:
 *   Input: 1->2
 *   Output: false
 *   Example 2:
 *   Input: 1->2->2->1
 *   Output: true
 */

#include "palindromeLinkedList.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

struct ListNode* findMiddle(struct ListNode* head)
{
    struct ListNode *p = head, *q = head;

    while(q && q->next)
    {
        p = p->next;
        q = q->next->next;
    }

    return p;
}

struct ListNode* reverseLink(struct ListNode* head)
{
    struct ListNode *prev = NULL;

    while(head)
    {
        struct ListNode *temp = head;
        head = head->next;
        temp->next = prev;
        prev = temp;
    }

    return prev;
}

bool isPalindrome2(struct ListNode* head)
{
    if(!head || !head->next)
        return true;

    struct ListNode* pMid = findMiddle(head);
    struct ListNode* pRev = reverseLink(pMid);

    for(; head != pMid; head = head->next, pRev = pRev->next)
    {
        if (head->val != pRev->val)
            return false;
    }

    return true;
}

int isPalindrome2_main()
{

    return 0;
}