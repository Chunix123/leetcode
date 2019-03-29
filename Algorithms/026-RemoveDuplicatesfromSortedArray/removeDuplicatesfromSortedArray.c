//
// Created by zyc on 3/29/19.
//
/* 26. Remove Duplicates from Sorted Array
 * Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

    Example 1:

    Given nums = [1,1,2],

    Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

    It doesn't matter what you leave beyond the returned length.
    Example 2:

    Given nums = [0,0,1,1,1,2,2,3,3,4],

    Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

    It doesn't matter what values are set beyond the returned length.
 *
 */
#include "removeDuplicatesfromSortedArray.h"



/*
int removeDuplicates(int* nums, int numsSize)
{
    int i, len = 1, target;

    if(numsSize < 1)
        return 0;

    target = nums[0];

    for(i = 1; i < numsSize; i++)
    {
        if(target != nums[i])
        {
            target = nums[i];
            nums[len++] = nums[i];
        }
    }

    //printf("%d\n", len);

    return len;
}
*/

int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize <= 1)
        return numsSize;

    int result = 0;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[i - 1])
            nums[++result] = nums[i];
    }

    return result + 1;
}

int removeDuplicates_main()
{

    return 0;
}
