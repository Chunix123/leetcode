//
// Created by zyc on 19-4-24.
//
/*15. 3Sum
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */
#include "3Sum.h"
#include <stdlib.h>


/*
static int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int *get_3sum(int a, int b, int c)
{
    int *ret = (int *)malloc(sizeof(int) * 3);

    ret[0] = a;
    ret[1] = b;
    ret[2] = c;

    return ret;
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
    int i,start,end,sum;
    int size = 0;
    int count = 500;
    int **arr;

    qsort(nums,numsSize,sizeof(int),cmp);
    arr = (int **)malloc(sizeof(int *) * count);

    for(i = 0; i < numsSize - 2; ++i){
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        start = i + 1;
        end = numsSize - 1;

        while(start < end){
            sum = nums[i] + nums[start] + nums[end];

            if(start > i + 1 && nums[start-1] == nums[start]){
                ++start;
                continue;
            }

            if(sum == 0){
                arr[size++] = get_3sum(nums[i],nums[start],nums[end]);
                if(size == count){
                    count <<= 1;
                    arr = realloc(arr,sizeof(int *) * count);
                }
            }

            if(sum > 0)
                --end;
            else
                ++start;
        }
    }

    *returnSize = size;

    return arr;
}
*/

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define ARRAY_WIDTH 3
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 0;
    int allocSize = 128;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int **ret = (int **) malloc(sizeof(int *) * allocSize);

    for (int i = 0; i < numsSize; i++) {
        int front = i + 1;
        int back = numsSize - 1;
        int target = -nums[i];

        if (target < 0)
            break;

        while (front < back) {
            int sum = nums[front] + nums[back];
            if (sum > target) {
                back --;
                continue;
            }
            else if (sum < target) {
                front++;
                continue;
            }
            else {
                (*returnSize)++;
                if ((*returnSize) == allocSize) {
                    allocSize *= 2;
                    ret = (int **) realloc(ret, sizeof(int *) * allocSize);
                }
                ret[(*returnSize)-1] = (int *) malloc(sizeof(int) * 3);
                ret[(*returnSize)-1][0] = nums[i];
                ret[(*returnSize)-1][1] = nums[front];
                ret[(*returnSize)-1][2] = nums[back];
            }
            while (front+1 < numsSize && nums[front] == nums[front+1]) front++;
            while (back > 1 && nums[back] == nums[back-1]) back--;
            front ++;
        }
        while (i+1 < numsSize && nums[i] == nums[i+1]) i++;
    }

    return ret;
}

int threeSum_main()
{

    return 0;
}
