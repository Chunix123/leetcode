//
// Created by zyc on 19-4-11.
//
/* 283. Move Zeroes
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
    Example:
    Input: [0,1,0,3,12]
    Output: [1,3,12,0,0]
    Note:
    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.
 */
#include "moveZeroes.h"


void moveZeroes(int* nums, int numsSize)
{
    if(numsSize < 2)
        return;

    int i, count = 0, len = 0;

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] == 0)
        {
            count++;
        }
        else
        {
            nums[len++] = nums[i];
        }
    }

    for(i = 0; i < count; i++)
        nums[len++] = 0;
}

int moveZeroes_main()
{

    return 0;
}