//
// Created by zyc on 19-4-11.
//
/* 258. Add Digits
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
    Example:
    Input: 38
    Output: 2
    Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
                 Since 2 has only one digit, return it.
    Follow up:
    Could you do it without any loop/recursion in O(1) runtime?
 *
 */
#include "addDigits.h"

int addDigits(int num)
{
    if(num < 10)
        return num;

    while(num > 9)
        num = num / 10 + num % 10;

    return num;
}

/*
int addDigits(int num)
{
    if (num == 0)
        return 0;
	else if ((num % 9) == 0)
        return 9;
	else
        return (num % 9);
}
*/

int addDigits_main()
{

    return 0;
}