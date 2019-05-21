//
// Created by zyc on 19-5-21.
//
/*485. Max Consecutive Ones
 * Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
 */
#include "MaxConsecutiveOnes.h"


int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int max = 0, sum = 0;
    int i;

    for(i = 0; i < numsSize; i++)
    {
        sum = (sum + nums[i]) * nums[i];

        if(max < sum)
        {
            max = sum;
        }
    }

    return max;
}

/*
int findMaxConsecutiveOnes(int* nums, int numsSize) {

    int maxcon = 0;
    int currentCon = 0;

    for (int i = 0 ; i < numsSize ; i++)
    {
        if (nums[i])
        {
            currentCon++;
            maxcon = (currentCon > maxcon) ? currentCon : maxcon;
        }
        else
        {
            currentCon = 0;
        }
    }

    return maxcon;
}
*/

int findMaxConsecutiveOnes_main()
{

    return 0;
}