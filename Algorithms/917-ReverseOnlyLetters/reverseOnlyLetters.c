//
// Created by zyc on 3/24/19.
//
/* 917. Reverse Only Letters
 * Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.
    Example 1:
    Input: "ab-cd"
    Output: "dc-ba"
    Example 2:
    Input: "a-bC-dEf-ghIj"
    Output: "j-Ih-gfE-dCba"
    Example 3:
    Input: "Test1ng-Leet=code-Q!"
    Output: "Qedo1ct-eeLg=ntse-T!"
 */


#include <memory.h>
#include <stdbool.h>
#include "reverseOnlyLetters.h"

/*
bool isLetter(char s)
{
    if((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
        return true;

    return false;
}

void reverseStr(char *s, int len)
{
    int i;

    for(i = 0; i < len / 2; i++)
    {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

char* reverseOnlyLetters(char* S)
{
    if(S == NULL)
        return NULL;

    int len = strlen(S);

    if(len < 2)
        return S;

    int i, lena = 0, lenb = 0;
    char str[len], strl[len];

    memset(str, 0, len);
    memset(strl, 0, len);

    for(i = 0; i < len; i++)
    {
        if(isLetter(S[i]))
            strl[lena++] = S[i];
        else
            str[lenb++] = S[i];

    }

    reverseStr(strl, lena);

    lena = 0, lenb = 0;

    for(i = 0; i < len; i++)
    {
        if(isLetter(S[i]))
            S[i] = strl[lena++];
        else
            S[i] = str[lenb++];
    }
    //printf("%s\n", S);

    return S;
}
*/

bool is_letter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char* reverseOnlyLetters(char* S)
{
    int start = 0;
    int end = strlen(S) - 1;

    while (start < end)
    {
        if (is_letter(*(S+start)) && is_letter(*(S+end)))
        {
            char t = *(S + start);
            *(S + start) = *(S + end);
            *(S + end) = t;
            start++;
            end--;
        }

        while (!is_letter(*(S+start)) && start < end)
            start++;
        while (!is_letter(*(S+end)) && start < end)
            end--;
    }

    return S;
}

int reverseOnlyLetters_main()
{

    return 0;
}

