//
// Created by zyc on 3/27/19.
//

#include <zconf.h>
#include <stdlib.h>
#include <stdio.h>
#include "designLinkedList.h"


typedef struct LinkedList{
    int val;
    struct LinkedList *next;
} MyLinkedList;


void printLinkedList(MyLinkedList *obj)
{
    MyLinkedList *pst = obj->next;
    printf("[%d]--------",__LINE__);

    while (pst != NULL)
    {
        printf("%d,",pst->val);
        pst = pst->next;
    }
    printf("\n");
}

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate()
{
    MyLinkedList *head = (MyLinkedList*)malloc(sizeof(MyLinkedList));

    if(!head)
        return NULL;

    head->val = 0;
    head->next = NULL;

    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index)
{
    if(obj == NULL || obj->next == NULL)
        return -1;

    MyLinkedList *p = obj->next;
    int len = 0;

    //printLinkedList(obj);
    while(p != NULL)
    {
        if(len == index)
        {
            return p->val;
        }
        else
        {
            len++;
            p = p->next;
        }
    }

    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
    if(obj == NULL)
        return;

    MyLinkedList *node = (MyLinkedList*)malloc(sizeof(MyLinkedList));

    if(node == NULL)
        return;

    node->val = val;
    node->next = obj->next;
    obj->next = node;
    //printLinkedList(obj);

    return;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
    if(obj == NULL)
        return;

    MyLinkedList *head = obj->next;
    MyLinkedList *node = malloc(sizeof(MyLinkedList));

    if(node == NULL)
        return;

    node->val = val;
    node->next = NULL;

    while(head != NULL && head->next != NULL)
        head = head->next;

    head->next = node;
    //printLinkedList(obj);

    return;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
    if(obj == NULL || index < 0)
        return;

    MyLinkedList *node = malloc(sizeof(MyLinkedList));

    if(node == NULL)
        return;

    node->val = val;
    node->next = NULL;

    MyLinkedList *p = obj->next;

    if(index == 0)
    {
        node->next = obj->next;
        obj->next = node;
        return;
    }

    int len = 0;
    MyLinkedList *prev = obj;

    while(p != NULL && len < index)
    {
        prev = p;
        p = p->next;
        len++;
    }

    if(len == index)
    {
        node->next = p;
        prev->next = node;
    }

    //printLinkedList(obj);

    return;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
    if(obj == NULL || obj->next == NULL)
        return;

    if(index == 0)
    {
        MyLinkedList *p = obj->next;
        obj->next = p->next;
        free(p);
        p = NULL;
        return;
    }

    MyLinkedList *prev = obj, *node = obj->next;
    int len = 0;

    while(node != NULL && len < index)
    {
        len++;
        prev = node;
        node = node->next;
    }

    if(len == index && node != NULL)
    {
        prev->next = node->next;
        free(node);
        node = NULL;
    }
    //printLinkedList(obj);

    return;
}

void myLinkedListFree(MyLinkedList* obj)
{
    if(obj == NULL)
        return;

    MyLinkedList *p = obj->next;
    MyLinkedList *q = NULL;

    obj->next = NULL;

    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(p);
        p = NULL;
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */

int myLinkList_main()
{


    return 0;
}