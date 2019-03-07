//
// Created by zyc on 3/7/19.
//
/* 344. Reverse String
 *  Write a function that reverses a string. The input string is given as an array of characters char[].
 *  Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 *  You may assume all the characters consist of printable ascii characters.
 *   Example 1:
 *     Input: ["h","e","l","l","o"]
 *     Output: ["o","l","l","e","h"]
 *   Example 2:
 *     Input: ["H","a","n","n","a","h"]
 *     Output: ["h","a","n","n","a","H"]
 */

#include <stdio.h>
#include <string.h>
#include "reverseString.h"


void reverseString(char* s, int sSize)
{
    int end = sSize - 1;
    int start = 0;

    while(start < end)
    {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
    printf("%s\n", s);
}

/*
void reverseString(char* s, int sSize)
{
    int i;
    char c;

    for(i = 0; i < sSize / 2; i++)
    {
        c = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize- i - 1] = c;
    }

    printf("%s\n", s);
}
*/

int reverseString_main()
{
    char s[] = {"Hannah"};
    reverseString(s, 6);

    return 0;
}
