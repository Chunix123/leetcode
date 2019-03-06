//
// Created by zyc on 3/6/19.
//
/* 136.Single Number
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 *   Example 1:
 *     Input: [2,2,1]
 *     Output: 1
 *   Example 2:
 *     Input: [4,1,2,1,2]
 *     Output: 4
 */

#include "singleNumber.h"
#include <stdio.h>


int singleNumber(int *nums, int numsSize)
{
    int num = 0, i;

    for(i = 0; i < numsSize; i++)
    {
        num = num ^ nums[i];
    }

    return num;
}


int singleNumber_main(int argc, char **argv)
{
    int nums[] = {4, 1, 2, 2, 1};

    //printf("%ld\n", sizeof(nums) / sizeof(int));
    printf("%d\n", singleNumber(nums, sizeof(nums) / sizeof(int)));

    return 0;
}

