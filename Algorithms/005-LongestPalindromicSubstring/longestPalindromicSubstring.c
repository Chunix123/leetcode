//
// Created by zyc on 4/1/19.
//
/* 5. Longest Palindromic Substring
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
    Example 1:
    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.
    Example 2:
    Input: "cbbd"
    Output: "bb"
 */

#include <stdlib.h>
#include <memory.h>
#include "longestPalindromicSubstring.h"


char *longestPalindrome(char *s)
{
    int i, j, k, sLen, start, max_len, new_len;
    char *res;

    if (!s)
        return NULL;

    start = 0;
    max_len = 1;
    new_len = 0;
    sLen = strlen(s);

    for (i = 0; i < sLen;)
    {
        if (sLen - i < max_len / 2)
            break;

        j = i, k = i;

        while (k < sLen - 1 && s[k + 1] == s[k])
            ++k;

        i = k + 1;

        while (k < sLen - 1 && j > 0 && s[j - 1] == s[k + 1])
            ++k, --j;

        new_len = k - j + 1;

        if (new_len > max_len)
        {
            max_len = new_len;
            start = j;
        }
    }

    res = malloc(sizeof(char) * (max_len + 1));
    strncpy(res, s + start, max_len);
    res[max_len] = '\0';

    return res;
}

int longestPalindrome_main()
{

    return 0;
}