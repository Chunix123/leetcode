//
// Created by zyc on 19-4-15.
//
/* 557. Reverse Words in a String III
 * Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 */
#include "ReverseWordsinaStringIII.h"
#include <string.h>


/*
void reverse(char *s, int start, int end)
{
    while(start < end)
    {
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

char* reverseWords(char* s)
{
    //while(*s == ' '){
    //    s++;
    //}
    //printf("%s ", s);

    int len = strlen(s);
    int i, j, k;

    for(i = 0; i < len; i++){

        while(s[i] == ' '){
            i++;
        }

        j = i;

        while(s[i] != '\0' && s[i] != ' '){
            i++;
        }

        k = i - 1;

        reverse(s, j, k);
    }

    return s;
}
*/

void reverse557(char *s, int begin, int end)
{
    while (begin < end) {
        s[begin] ^= s[end];
        s[end]   ^= s[begin];
        s[begin] ^= s[end];
        begin++;
        end--;
    }
}

char* reverseWords557(char* s)
{
    int i;
    int s_len = strlen(s);
    int begin = 0;

    for (i = 0; i <= s_len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverse557(s, begin, i - 1);
            begin = i + 1;
        }
    }

    return s;
}

/*
void swap(char *s, int a, int b)
{
    char temp;
    int i = a, j = b;

    if( a < 0 || b < 0 )
        return;

    for(; i <= (a+b)/2; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

char* reverseWords(char* s)
{
    int len = strlen(s);

    if(len <= 1)
        return s;

    int i = 0;
    int start = i;
    int end = 0;

    for(;i < len; i++)
    {
        if(s[i] == ' ')
        {
            end = i - 1;
            swap(s, start, end);
            start = i + 1;
        }
    }

    if(start < i)
    {
        end = i - 1;
        swap(s, start, end);
    }

    return s;
}
*/

int reverseWords557_main()
{


    return 0;
}
