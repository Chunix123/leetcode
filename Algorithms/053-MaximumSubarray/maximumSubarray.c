//
// Created by zyc on 19-4-14.
//
/* 53. Maximum Subarray
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */
#include <dnet.h>
#include "maximumSubarray.h"


/*
#define max(a, b) ((a)>(b) ? (a) : (b))

int maxSubArray(int* nums, int numsSize)
{
    if (numsSize == 0)
			return 0;

    int dp = 0;
    int dp1 = 0;
    int res = INT_MIN;

    for (int i = 0; i < numsSize; i++){
        dp = max(nums[i], dp1 + nums[i]);
        res = max(dp, res);
        dp1 = dp;
    }

    return res;
}
*/

int maxSubArray(int* nums, int numsSize)
{
    int i, sum = 0;
    int result = INT_MIN;

    for (i = 0; i < numsSize; i++) {

        sum += nums[i];

        if(sum > result)
            result = sum;

        if(sum < 0)
            sum = 0;
    }

    return result;
}


int maxSubArray_main()
{

    return 0;
}
