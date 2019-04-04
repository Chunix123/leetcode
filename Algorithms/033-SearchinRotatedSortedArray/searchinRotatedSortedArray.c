//
// Created by zyc on 4/5/19.
//
/* 33. Search in Rotated Sorted Array
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
    (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
    You are given a target value to search. If found in the array return its index, otherwise return -1.
    You may assume no duplicate exists in the array.
    Your algorithm's runtime complexity must be in the order of O(log n).
    Example 1:
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4
    Example 2:
    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1
 */


int search(int* nums, int numsSize, int target)
{
    if(numsSize <= 0)
        return -1;

    int start = 0, end = numsSize - 1;

    while(start + 1 < end)
    {
        int mid = start + (end - start) / 2;

        if(nums[mid] <= nums[start])
        {
            if(nums[mid] <= target && nums[end] >= target)
                start = mid;
            else
                end = mid;
        }
        else
        {
            if(nums[start] <= target && nums[mid] >= target)
                end = mid;
            else
                start = mid;
        }
    }

    if(nums[start] == target)
        return start;
    if(nums[end] == target)
        return end;

    return -1;
}

int search_main()
{


    return 0;
}