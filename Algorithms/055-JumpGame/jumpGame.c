//
// Created by zyc on 3/25/19.
//

#include <stdbool.h>
#include <zconf.h>
#include "jumpGame.h"


/*
bool canJump(int* nums, int numsSize)
{
    if(nums == NULL || numsSize < 2)
        return true;

    int i, steps = 0, sum = 0;

    for(i = numsSize - 2; i >= 0; i--)
    {
        if(nums[i] > steps && nums[i] > sum)
        {
            steps = 0;
            sum = 0;

        }
        else
        {
            sum++;
            steps++;
        }

        if(i == 0 && steps == 0 && sum == 0)
            return true;
    }

    return false;
}
*/

bool canJump(int* nums, int numsSize)
{
    if(nums == NULL || numsSize < 2)
        return true;

    int leftmostIndex = numsSize - 1;

    for (int i = numsSize - 2; i >= 0; i--)
    {
        if (leftmostIndex <= i + nums[i])
            leftmostIndex = i;
    }

    return leftmostIndex == 0;
}

int canJump_main()
{

    return 0;
}