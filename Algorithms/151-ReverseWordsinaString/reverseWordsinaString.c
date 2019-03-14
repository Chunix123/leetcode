//
// Created by zyc on 3/14/19.
//
/* 151. Reverse Words in a String
 * Given an input string, reverse the string word by word.
    Example 1:
    Input: "the sky is blue"
    Output: "blue is sky the"
    Example 2:
    Input: "  hello world!  "
    Output: "world! hello"
    Explanation: Your reversed string should not contain leading or trailing spaces.
    Example 3:
    Input: "a good   example"
    Output: "example good a"
    Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reverseWordsinaString.h"

/*
char* reverseStr(char *s)
{
    int i, len = strlen(s);

    for(i = 0; i < len / 2; i++)
    {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }

    return s;
}

char* reverseWords(char* s)
{
    int i = 0, begin = 0, end = 0;
    int len = strlen(s);
    char temp;

    s = reverseStr(s);

    while(s[i])
    {
        if(s[i] != ' ')
        {
            begin = i;

            while(s[i] && s[i] != ' ')
                i++;

            i -= 1;
            end = i;
        }

        while(begin < end)
        {
            temp = s[begin];
            s[begin] = s[end];
            s[end] = temp;
            begin++;
            end--;
        }

        i++;
    }

    return s;
}
*/
void reverseStr(char *s, int first, int last)
{
    while(first < last)
    {
        char tmp = s[first];
        s[first++] = s[last];
        s[last--] = tmp;
    }
}

char* reverseWords(char* s)
{
    int i, last = 0, now = 0;

    while(s[now])
    {
        while(s[now] == ' ')
            now++;

        last = now;

        while(s[now] != ' ' && s[now] != '\0')
            now++;

        reverseStr(s, last, now - 1);
    }

    reverseStr(s, 0, now - 1);
    //printf("%s\n", s);

    last = 0;
    for (i = 0; i < now; i++)
    {
        //!isblank(s[i])
        if ((s[i] != ' ') || (last && s[last - 1] != s[i]))
            s[last++] = s[i];
    }
    s[last] = 0;
    if (last && s[last - 1] == ' ')
        s[last - 1] = 0;

    return s;
}


int reverseWords_main()
{
    char s[] = "  the sky is  blue!  ";

    printf("%s\n", reverseWords(s));

    return 0;
}