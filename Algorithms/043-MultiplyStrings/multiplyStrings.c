//
// Created by zyc on 19-4-9.
//
/* 43. Multiply Strings
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
    Example 1:
    Input: num1 = "2", num2 = "3"
    Output: "6"
    Example 2:
    Input: num1 = "123", num2 = "456"
    Output: "56088"
    Note:
    The length of both num1 and num2 is < 110.
    Both num1 and num2 contain only digits 0-9.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */
/*
         i --->    1   2   3   size m
         j --->        9   9   size n
         --------------------
                       2   7
                   1   8
                0  9
                   2   7
                1  8
             0  9
    -------------------------------
    res[idx] 0  1  2   3   4   size m+n
*/
#include "multiplyStrings.h"
#include <stdlib.h>
#include <string.h>


char* multiply(char* num1, char* num2)
{
    int lena = strlen(num1);
    int lenb = strlen(num2);

    int lenm = lena + lenb;
    char *result = malloc(sizeof(char) * lenm + 1);
    int i, j, res = 0;

    for(i = 0; i < lenm; i++)
        result[i] = '0';

    int begin = 0;

    for(i = lena - 1; i >= 0; i--)
    {
        int count = 0;
        res = begin++;

        for(j = lenb - 1; j >= 0; j--)
        {
            count += result[res] - '0';
            count += (num1[i] - '0') * (num2[j] - '0');
            result[res++] = '0' + count % 10;
            count /= 10;
        }

        if(count != 0)
            result[res++] = count + '0';
    }

    result[res] = '\0';

    int left = 0;
    int right = res - 1;

    while(left < right)
    {
        char temp = result[left];
        result[left++] = result[right];
        result[right--] = temp;
    }

    if(result[0] == '0')
        result[1] = '\0';

    return result;
}

int multiply_main()
{

    return 0;
}