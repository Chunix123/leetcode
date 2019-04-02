//
// Created by zyc on 4/2/19.
//
/* 7. Reverse Integer
 * Given a 32-bit signed integer, reverse digits of an integer.
    Example 1:
    Input: 123
    Output: 321
    Example 2:
    Input: -123
    Output: -321
    Example 3:
    Input: 120
    Output: 21
 */
#include <zconf.h>
#include <stdbool.h>
#include <stdlib.h>
#include "reverseInteger.h"


int reverse(int x)
{
    if(x == INT_MIN)
        return 0;

    int result = 0;
    bool flag = false;

    if(x < 0)
    {
        flag = true;
        x = abs(x);
    }

    result += (x % 10);

    while((x / 10) > 0)
    {
        if(result > INT_MAX / 10)
            return 0;

        result = (x / 10 % 10) + result * 10;
        x /= 10;
    }

    if(flag)
        result = -result;

    return result;
}

int reverse7_main()
{

    return 0;
}