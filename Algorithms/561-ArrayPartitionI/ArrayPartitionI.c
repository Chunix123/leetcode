//
// Created by zyc on 19-5-22.
//
/*561. Array Partition I
 * Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].
 */
#include "ArrayPartitionI.h"
#include <stdio.h>
#include <stdlib.h>


int comper(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int arrayPairSum(int* nums, int numsSize)
{
    int i, sum = 0;

    qsort(nums, numsSize, sizeof(int), comper);

    for(i = 0; i < numsSize; i += 2)
    {
        sum += nums[i];
    }

    return sum;
}


int arrayPairSum_main()
{


    return 0;
}