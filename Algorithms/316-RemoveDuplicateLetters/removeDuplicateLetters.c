//
// Created by zyc on 3/7/19.
//
/* 316. Remove Duplicate Letters
 * Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
    Example 1:
      Input: "bcabc"
      Output: "abc"
    Example 2:
      Input: "cbacdcbc"
      Output: "acdb"
 */
#include <string.h>
#include <stdio.h>
#include "removeDuplicateLetters.h"


char* removeDuplicateLetters(char* s)
{
    char *h = s;
    char *t = s;
    char ch;

    while(*t++);
    t--;
    t--;

    while(h < t)
    {
        ch = *h;
        *h++ = *t;
        *t-- = ch;
    }

    printf("%s\n", s);

    int i, j, k = 0;
    int len = strlen(s) - 1;
    char ss[len];

    memset(ss, 0, len);

    for(i = 0; i < len; i++)
    {
        for(j = i; j < len; j++)
        {
            if(s[i] == s[j])
            {
                ss[j++] = j;
                printf("%d %c ", j, s[j]);
            }
        }
        printf("\n");
    }

    return s;
}


int removeDuplicateLetters_main()
{
    char s[] = "bcabc";
    removeDuplicateLetters(s);

    return 0;
}
