//
// Created by zyc on 4/2/19.
//
/* 23. Merge k Sorted Lists
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
    Example:
    Input:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    Output: 1->1->2->3->4->4->5->6
 */

#include <zconf.h>
#include "mergekSortedLists.h"


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

static struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if( (l1 == NULL) && (l2 == NULL))
        return NULL;
    else if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;

    if(l1->val > l2->val)
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
    else
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }

    return NULL;
}


static struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if(listsSize == 0)
        return NULL;
    else if(listsSize == 1)
        return lists[0];
    else if(listsSize == 2)
        return mergeTwoLists(lists[0], lists[1]);

    //divide and conquor if listsSize is still > 3
    return mergeTwoLists(mergeKLists(lists, listsSize/2), mergeKLists(lists+listsSize/2, listsSize - listsSize/2));
}

/*
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if(listsSize <= 0)
        return NULL;

    if(listsSize == 1)
        return lists[0];

    struct ListNode *left = mergeKLists(lists, listsSize / 2);
    struct ListNode *right = mergeKLists(lists + listsSize / 2, listsSize - listsSize / 2);

    struct ListNode dummy;
    struct ListNode *p = &dummy;

    while(left != NULL & right != NULL)
    {
        if(left->val < right->val)
        {
            p->next = left;
            p = p->next;
            left = left->next;
        }
        else
        {
            p->next = right;
            p = p->next;
            right = right->next;
        }
    }

    if(left != NULL)
        p->next = left;
    else
        p->next = right;

    return dummy.next;
}
*/


/*
struct HEAP {
    int val;
    int idx;
};

struct HEAP *heap;

int heapSize = 0;

void heapPush(int val, int idx)
{
    int cur = heapSize;

    heap[heapSize].val = val;
    heap[heapSize].idx = idx;
    ++heapSize;

    while (cur > 0 && heap[cur].val < heap[(cur - 1) / 2].val)
    {
        struct HEAP temp;

        temp = heap[cur];
        heap[cur] = heap[(cur - 1) / 2];
        heap[(cur - 1) / 2] = temp;

        cur = (cur - 1) / 2;
    }
}

int heapPop()
{
    int ret = heap[0].idx;
    int cur = 0;

    --heapSize;

    heap[0] = heap[heapSize];

    while (cur * 2 + 1 < heapSize)
    {
        int child = cur * 2 + 1;

        if (cur * 2 + 2 < heapSize && heap[cur * 2 + 1].val > heap[cur * 2 + 2].val)
            child = cur * 2 + 2;

        if (heap[cur].val > heap[child].val)
        {
            struct HEAP temp;

            temp = heap[cur];
            heap[cur] = heap[child];
            heap[child] = temp;

            cur = child;
        }
        else
        {
            break;
        }
    }

    return ret;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{

    struct ListNode* head = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* cur = head;

    cur->next = 0;

    heap = (struct HEAP *)malloc(sizeof(struct HEAP) * listsSize);

    struct ListNode** curs = (struct ListNode *)malloc(sizeof(struct ListNode) * listsSize);

    for (int i = 0; i < listsSize; ++i)
    {
        curs[i] = lists[i];

        if (lists[i] != 0)
            heapPush(lists[i]->val, i);
    }

    while (heapSize > 0)
    {

        int idx = heapPop();

        cur->next = curs[idx];
        curs[idx] = curs[idx]->next;

        if (curs[idx] != 0)
            heapPush(curs[idx]->val, idx);

        cur = cur->next;
    }

    free(heap);

    return head->next;
}
*/

int mergeKLists23_main()
{

    return 0;
}