//
// Created by zyc on 3/11/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "removeElement.h"


/*
int removeElement(int* nums, int numsSize, int val)
{
    if (!numsSize)
        return numsSize;

    int result = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
            nums[result++] = nums[i];
    }

    return result;
}
*/


int removeElement(int* nums, int numsSize, int val)
{
    if(nums == NULL)
        return 0;

    int i, len = 0;
    //printf("%d\n", numsSize);

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] == val)
            continue;
        else
            nums[len++] = nums[i];

        //printf("%d-%d-%d-%d-%d ", i, nums[i], nums[len - 1], val, len);
    }

    if(numsSize > len)
        nums[len] = '\0';
    //printf("\n%d\n", len);

    return len;
}

int removeElement_main()
{
    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int len = sizeof(nums) / sizeof(int);
    int i, val = 2;

    int num = removeElement(nums, len, val);
    printf("%d\n", num);
    for(i = 0; i < num; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
