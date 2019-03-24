//
// Created by zyc on 3/24/19.
//

#include <stdlib.h>
#include "4Sum.h"

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXSIZE 1000

/*
void quick_sort(int *nums, int left, int right)
{
    if(left < right)
    {
        int i = left, j = right, target = nums[left];

        while(i < j)
        {
            while(i < j && nums[j] > target)
                j--;
            if(i < j)
                nums[i++] = nums[j];

            while(i < j && nums[i] < target)
                i++;
            if(i < j)
                nums[j] = nums[i];
        }

        nums[i] = target;
        quick_sort(nums, left, i - 1);
        quick_sort(nums, i + 1, right);
    }
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize)
{
    if(nums == NULL && numsSize < 0)
        return NULL;

    if(numsSize < 4)
    {
        *returnSize = 0;
        return NULL;
    }

    int **result = malloc(sizeof(int *) * MAXSIZE);
    int i, j, m, n, len = 0;

    quick_sort(nums, 0, numsSize - 1);

    for(i = 0; i < numsSize - 3; i++)
    {
        if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
  			break;

        for(j = i + 1; j < numsSize - 2; j++)
        {
            for(m = j + 1; m < numsSize - 1; m++)
            {
                for(n = m + 1; n < numsSize; n++)
                {
                    if(target == (nums[i] + nums[j] + nums[m] + nums[n]))
                    {
                        bool flag = false;
                        int temp;

                        for(temp = 0; temp < len; temp++)
                        {
                            if((result[temp][0] == nums[i]) && (result[temp][1] == nums[j]) && (result[temp][2] == nums[m]) && (result[temp][3] == nums[n]))
                            {
                                flag = true;
                                break;
                            }
                        }

                        if((len == 0) || !flag)
                        {
                            *(result + len) = malloc(sizeof(int) * 4);
                            result[len][0] = nums[i];
                            result[len][1] = nums[j];
                            result[len][2] = nums[m];
                            result[len][3] = nums[n];
                            //printf("%d %d %d %d\n", result[len][0], result[len][1], result[len][2], result[len][3]);
                            len++;
                        }
                    }
                }
            }
        }
    }

    *returnSize = len;

    return result;
}
*/


int comparator(const void *const a, const void *const b)
{
    register int l = *(const int *const)a;
    register int r = *(const int *const)b;

    return l - r;
}

int** fourSum(int *const nums, const int numsSize, const int target, int *const returnSize)
{
    if (numsSize < 4)
        return 0;

    qsort(nums, numsSize, sizeof(int), comparator);

    int count = 0;
    int **res = 0;

    for (int i = 0; i != numsSize - 3; ++i)
    {
        if (i != 0 && nums[i] == nums[i-1])
            continue;

        if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
            break;

        if (nums[i] + nums[numsSize-3] + nums[numsSize-2] + nums[numsSize-1] < target)
            continue;

        for (int j = i + 1; j != numsSize - 2; ++j)
        {
            if (j != i + 1 && nums[j] == nums[j-1])
                continue;

            if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)
                break;

            if (nums[i] + nums[j] + nums[numsSize-2] + nums[numsSize-1] < target)
                continue;

            int lo = j + 1, hi = numsSize - 1;
            const int sum = target - nums[i] - nums[j];

            do {
                const int cur = nums[lo] + nums[hi];
                if (cur < sum) {
                    ++lo;
                } else if (cur == sum) {
                    ++count;
                    res = realloc(res, sizeof(int *) * count);
                    res[count - 1] = (int*)malloc(4 * sizeof(int));
                    res[count - 1][0] = nums[i];
                    res[count - 1][1] = nums[j];
                    res[count - 1][2] = nums[lo];
                    res[count - 1][3] = nums[hi];
                    do {
                        ++lo;
                    } while (lo < hi && nums[lo] == nums[lo-1]);
                    do {
                        --hi;
                    } while (lo < hi && nums[hi] == nums[hi+1]);
                } else {
                    --hi;
                }

            } while (lo < hi);
        }
    }

    *returnSize = count;

    return res;
}

int fourSum_main()
{

    return 0;
}
