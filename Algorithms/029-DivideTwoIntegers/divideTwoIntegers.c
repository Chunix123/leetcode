//
// Created by zyc on 19-4-9.
//
/* 29. Divide Two Integers
 *Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
    Return the quotient after dividing dividend by divisor.
    The integer division should truncate toward zero.
    Example 1:
    Input: dividend = 10, divisor = 3
    Output: 3
    Example 2:
    Input: dividend = 7, divisor = -3
    Output: -2
    Note:
    Both dividend and divisor will be 32-bit signed integers.
    The divisor will never be 0.
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/


#include <dnet.h>
#include <stdlib.h>
#include <slcurses.h>
#include "divideTwoIntegers.h"

/* Time Limit Exceeded
int divide(int dividend, int divisor)
{
    if(dividend == INT_MAX && divisor == 1)
        return INT_MAX;

    if(dividend == INT_MAX && divisor == -1)
        return INT_MIN + 1;

    if(dividend == INT_MIN && divisor == 1)
        return INT_MIN;

    if(dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    bool flag = false;
    bool flagd = false, flags = false;

    if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        flag = true;

    int result = 0;

    int absdividend;
    int absdivisor;

    if(dividend == INT_MIN)
    {
        flagd = true;
        absdividend = INT_MAX;
    }
    else
        absdividend = abs(dividend);

    if(divisor == INT_MIN)
    {
        flags = true;
        absdivisor = INT_MAX;
    }
    else
        absdivisor = abs(divisor);


    while(absdividend >= absdivisor)
    {
        result += 1;
        absdividend -= absdivisor;
    }

    if(flag)
        result = -result;

    if(flagd && divisor == 1)
        result -= 2;
    else if(flagd && divisor > 1)
        result -= 1;

    if(flagd && flags)
        result += 1;

    return result;
}
*/

int divide(int dividend, int divisor)
{
    bool sign = dividend < 0 == divisor < 0;
    int64_t dvd = llabs((int64_t) dividend), dvs = llabs((int64_t) divisor);

    int64_t ret = 0;

    while (dvd >= dvs)
    {
        int64_t sub = dvs, count = 1;
        while (dvd >= sub)
        {
            sub <<= 1;
            count <<= 1;
        }

        dvd -= sub >> 1;
        ret += count >> 1;
    }

    if (ret > INT_MAX)
        return sign ? INT_MAX : INT_MIN;

    return (int) (sign ? ret : -ret);
}

int divide29_main()
{

    return 0;
}


