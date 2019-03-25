//
// Created by zyc on 3/26/19.
//

#include "majorityElement.h"

/*
int majorityElement(int* nums, int numsSize)
{
    int i, count = 0, candidate = 0;

    for(i = 0; i < numsSize; i++)
    {
        if(count == 0)
            candidate = nums[i];

        count += (nums[i] == candidate) ? 1 : -1;
    }

    return candidate;
}
*/


int countInRange(int *nums, int num, int lo, int hi)
{
    int i, count = 0;

    for(i = lo; i <= hi; i++)
    {
        if(nums[i] == num)
            count++;
    }

    return count;
}

int majorityHelper(int *nums, int lo, int hi)
{
    if(lo == hi)
        return nums[lo];

    int mid = (hi - lo) / 2 + lo;
    int left = majorityHelper(nums, lo, mid);
    int right = majorityHelper(nums, mid + 1, hi);

    if(left == right)
        return left;

    int leftCount = countInRange(nums, left, lo, hi);
    int rightCount = countInRange(nums, right, lo, hi);

    return leftCount > rightCount ? left : right;
}

int majorityElement(int* nums, int numsSize)
{
    return majorityHelper(nums, 0, numsSize - 1);
}

int majorityElement_main()
{


    return 0;
}
