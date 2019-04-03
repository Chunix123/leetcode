//
// Created by zyc on 4/3/19.
//
/* 189. Rotate Array
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
    Example 1:
    Input: [1,2,3,4,5,6,7] and k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]
    Example 2:
    Input: [-1,-100,3,99] and k = 2
    Output: [3,99,-1,-100]
    Explanation:
    rotate 1 steps to the right: [99,-1,-100,3]
    rotate 2 steps to the right: [3,99,-1,-100]
 *
 */
#include "rotateArray.h"

/*
void rotate(int* nums, int numsSize, int k)
{
    int i;
    int *result = malloc(sizeof(int) * numsSize);

    for(i = 0; i < numsSize; i++)
    {
        result[(i + k) % numsSize] = nums[i];
    }

    memcpy(nums, result, sizeof(int) * numsSize);

    free(result);
}
*/

void rotateHelper(int* nums, int start, int end)
{
    while(start < end)
    {
        int temp = nums[start];
        nums[start++] = nums[end];
        nums[end--] = temp;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    k = k % numsSize;
    rotateHelper(nums, 0, numsSize - 1);
    rotateHelper(nums, 0, k - 1);
    rotateHelper(nums, k, numsSize - 1);
}

int rotate_main()
{


    return 0;
}
