//
// Created by zyc on 3/20/19.
//

#include <stdlib.h>
#include <string.h>
#include "plusOne.h"

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int i, j, len = 0, carry = 1;
    int *result = malloc((digitsSize + 2) * sizeof(int));

    for(i = digitsSize - 1; i >= 0; i--)
    {
        int num = digits[i] + carry;

        carry = num / 10;
        num = num % 10;
        result[len++] = num;
    }

    if(carry)
        result[len++] = 1;

    for(i = 0, j = len - 1; i < j; i++, j--)
    {
        int temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }

    *returnSize = len;

    return result;
}

int plusOne_main()
{

    return 0;
}