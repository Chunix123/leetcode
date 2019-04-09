//
// Created by zyc on 19-4-10.
//
/* 50. Pow(x, n)
 * Implement pow(x, n), which calculates x raised to the power n (xn).
      Example 1:
    Input: 2.00000, 10
    Output: 1024.00000
      Example 2:
    Input: 2.10000, 3
    Output: 9.26100
      Example 3:
    Input: 2.00000, -2
    Output: 0.25000
    Explanation: 2-2 = 1/22 = 1/4 = 0.25
      Note:
    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−231, 231 − 1]
 */
#include <zconf.h>
#include "powxn.h"

/* Time Limit Exceeded
double myPow(double x, int n)
{
    bool sign = false;
    double result = 1.0;

    if(n == 0)
        return 1.0;

    if(n < 0)
    {
        n = abs(n);
        sign = true;
    }

    while(n > 0)
    {
        n--;
        result *= x;
    }

    if(sign)
        result = 1.0 / result;

    return result;
}
*/
/*
double power(double x, int n)
{
    if (n == 0)
        return 1;

    if (n == 1)
        return x;

    double half = power(x, n / 2);

    if (n % 2 == 0)
        return half * half;

    return x * half * half;
}

double myPow(double x, int n)
{
    if (n < 0)
        return 1 / power(x, -n);

    return power(x, n);
}
*/

double myPow(double x, int n)
{
    if (n == 0)
        return 1;

    double ret = 1;
    int64_t e = n;

    e = e > 0 ? e : -e;

    while (e > 0)
    {
        if (e & 1)
            ret = ret * x;
        x *= x;
        e >>= 1;
    }

    return n > 0 ? ret : 1 / ret;
}

int myPow_main()
{

    return 0;
}
