//
// Created by zyc on 3/24/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "001-twoSum.h"


/* 1. Two Sum
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    Example:
    Given nums = [2, 7, 11, 15], target = 9,
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
int* twoSum(int* nums, int numsSize, int target)
{
    if(numsSize < 1)
        return NULL;

    int i, j;
    int *result = malloc(sizeof(int) * 2);

    for(i = 0; i < numsSize - 1; i++)
    {
        for(j = i + 1; j < numsSize; j++)
        {
            if(target == (nums[i] + nums[j]))
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return NULL;
}
*/


struct mapNode
{
    int key;
    int value;
    struct mapNode *next;
};

struct _mapObject
{
    struct mapNode **nodes;
    int modValue;
};

typedef struct _mapObject mapObject;

bool initMap(mapObject* map, int numberOfNodes)
{
    if(map == NULL)
        return false;

    (*map).modValue = numberOfNodes;
    (*map).nodes = calloc(numberOfNodes, sizeof(struct mapNode*));

    return true;
}

bool addToMap(mapObject* map, int key, int value)
{
    if(map == NULL)
        return false;

    int boxNumber = abs(key) % (*map).modValue;
    struct mapNode **boxPointer = &(*map).nodes[boxNumber];

    while(*boxPointer != NULL && (*(*boxPointer)).key != key)
        boxPointer = &((*(*boxPointer)).next);

    if((*boxPointer) == NULL)
        (*boxPointer) = calloc(1, sizeof(struct mapNode));

    (*(*boxPointer)).key = key;
    (*(*boxPointer)).value = value;

    return true;
}

bool hasKeyInMap(mapObject* map, int key)
{
    if(map == NULL)
        return false;

    int boxNumber = abs(key) % (*map).modValue;
    struct mapNode *boxPointer = (*map).nodes[boxNumber];

    while(boxPointer != NULL && (*boxPointer).key != key)
        boxPointer = (*boxPointer).next;

    if(boxPointer == NULL)
        return false;

    return (*boxPointer).key == key;
}

bool getKeyFromMap(mapObject* map, int key, int* value)
{
    if(map == NULL)
        return false;

    int boxNumber = abs(key) % (*map).modValue;
    struct mapNode *boxPointer = (*map).nodes[boxNumber];

    while(boxPointer != NULL && (*boxPointer).key != key)
        boxPointer = (*boxPointer).next;

    if(boxPointer == NULL)
        return false;

    if((*boxPointer).key == key)
    {
        (*value) = (*boxPointer).value;
        return true;
    }

    return false;
}

bool freeMap(mapObject* map)
{
    if(map == NULL)
        return true;

    for(int i=0; i < (*map).modValue; i++)
    {
        struct mapNode *boxPointer = (*map).nodes[i];
        struct mapNode *nextPointer;
        while(boxPointer != NULL)
        {
            nextPointer = (*boxPointer).next;
            free(boxPointer);
            boxPointer = nextPointer;
        }
    }
    free(map);
    map = NULL;

    return true;
}

int* twoSum(int* nums, int numsSize, int target)
{
    int* result = calloc(2, sizeof(int));;
    mapObject* map = malloc(sizeof(mapObject));
    initMap(map, 4 * 1024);

    for(int i = 0; i <numsSize; i++)
    {
        if(hasKeyInMap(map, nums[i]))
        {
            getKeyFromMap(map, nums[i], &result[0]);
            result[1] = i;
            return result;
        }
        else
        {
            int rest = target - nums[i];
            addToMap(map, rest, i);
        }

    }
    freeMap(map);

    return result;
}

int twoSum_main()
{

    return 0;
}