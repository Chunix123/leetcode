//
// Created by zyc on 3/6/19.
//
/* 137. Single Number II
 * Given a non-empty array of integers, every element appears three times except for one,
 * which appears exactly once. Find that single one.
 * Example 1:
 *  Input: [2,2,3,2]
 *  Output: 3
 * Example 2:
 *  Input: [0,1,0,1,0,1,99]
*   Output: 99
 */

#include <stdio.h>
#include "singleNumber2.h"


int singleNumber2(int *nums, int numsSize)
{
    int i, low = 0, high = 0;

    for(i = 0; i < numsSize; i++)
    {
        low = (low ^ nums[i]) & ~high;
        high = (high ^ nums[i]) & ~low;
    }

    return low;
}


int singleNumber2_main(int argc, char **argv)
{
    int nums[] = {0, 1, 0, 1, 0, 1, 99};

    //printf("%ld\n", sizeof(nums) / sizeof(int));
    printf("%d\n", singleNumber2(nums, sizeof(nums) / sizeof(int)));

    return 0;
}

