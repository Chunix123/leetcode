//
// Created by zyc on 3/26/19.
//
/* 128. Longest Consecutive Sequence
    Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
    Your algorithm should run in O(n) complexity.
    Example:
    Input: [100, 4, 200, 1, 3, 2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 */

#include <zconf.h>
#include <stdlib.h>
#include "longestConsecutiveSequence.h"




int compareHelper(const void* p, const void* q)
{
    //return *((int*)a) - *((int*)b);
    int l = *(const int*)p;
    int r = *(const int*)q;

    if(l < r)
        return -1;
    if(l == r)
        return 0;

    return 1;
}

int longestConsecutive(int* nums, int numsSize)
{
    if(nums == NULL || numsSize < 2)
        return numsSize;

    qsort(nums, numsSize, sizeof(int), compareHelper);

    int i, max = 0, temp = 1;

    for(i = 1; i < numsSize; i++)
    {
        if(nums[i] == nums[i - 1])
            continue;

        if(nums[i] == nums[i - 1] + 1)
            temp++;
        else
        {
            max = (max > temp) ? max : temp;
            temp = 1;
        }
    }

    return (max > temp) ? max : temp;
}

int longestConsecutive_main()
{
    int nums[10] = {12,2,5,4,3,1,0,11,2,3};

    longestConsecutive(nums, 10);

    return 0;
}

