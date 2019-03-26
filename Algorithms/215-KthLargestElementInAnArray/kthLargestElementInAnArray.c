//
// Created by zyc on 3/26/19.
//

#include <stdlib.h>
#include "kthLargestElementInAnArray.h"


/*
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int findKthLargest(int* nums, int numsSize, int k)
{
    int i, j, max = nums[0], len = 0;
    int arr[k];

    memset(arr, 0, k * sizeof(int));

    for(i = 0; i < k; i++)
        arr[i] = nums[i];

    qsort(arr, k, sizeof(int), cmpfunc);

    for(i = k; i < numsSize; i++)
    {
        if(nums[i] > arr[0])
        {
            arr[0] = nums[i];
            qsort(arr, k, sizeof(int), cmpfunc);
        }
    }

    return arr[0];
}
*/

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int findKthLargest(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    return nums[k - 1];
}

int findKthLargest_main()
{

    return 0;
}
