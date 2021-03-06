//
// Created by zyc on 4/4/19.
//
/* 35. Search Insert Position
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
    You may assume no duplicates in the array.
    Example 1:
    Input: [1,3,5,6], 5
    Output: 2
    Example 2:
    Input: [1,3,5,6], 2
    Output: 1
    Example 3:
    Input: [1,3,5,6], 7
    Output: 4
    Example 4:
    Input: [1,3,5,6], 0
    Output: 0
 *
 */
#include "searchInsertPosition.h"


/*
int searchInsert(int* nums, int numsSize, int target)
{
    if(numsSize <= 0)
        return 0;

    if(target > nums[numsSize - 1])
        return numsSize;

    int i;

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] >= target)
            return i;
    }

    return 0;
}
*/

int searchInsert(int* nums, int numsSize, int target)
{
    int low, high, mid;

    low = 0; high = numsSize-1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (target < nums[mid])
            high = mid - 1;
        else if (target > nums[mid])
            low = mid + 1;
        else
            return mid;
    }

    return low;
}

int searchInsert_main()
{

    return 0;
}