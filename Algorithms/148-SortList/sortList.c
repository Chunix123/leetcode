//
// Created by zyc on 3/17/19.
//

#include "sortList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



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
/*
void quick_sort(int *arr, int begin, int end)
{
    if(begin < end)
    {
        int i = begin, j = end, target = arr[begin];

        while(i < j)
        {
            while(i < j && arr[j] > target)
                j++;

            if(i < j)
                arr[i++] = arr[j];

            while(i < j && arr[i] < target)
                i++;

            if(i < j)
                arr[j] = arr[i];
        }

        target = arr[i];
        quick_sort(arr, begin, i - 1);
        quick_sort(arr, i + 1, end);
    }

    return;
}
*/

struct ListNode* getMiddle(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

struct ListNode *merge(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode dummy;
    struct ListNode *tail = &dummy;

    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
    }

    if(l1)
        tail->next = l1;
    if(l2)
        tail->next = l2;

    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head)
{
    if(!head || !head->next)
        return head;

    struct ListNode *middle = getMiddle(head);
    struct ListNode *next = middle->next;
    middle->next = NULL;

    return merge(sortList(head), sortList(next));;
}

int sortList_main()
{

    return 0;
}