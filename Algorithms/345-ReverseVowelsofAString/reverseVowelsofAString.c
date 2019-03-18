//
// Created by zyc on 3/19/19.
//

#include <stdbool.h>
#include <string.h>
#include "reverseVowelsofAString.h"



bool checkVowels(char c)
{
    switch(c){
        case 'a':
            return true;
        case 'e':
            return true;
        case 'i':
            return true;
        case 'o':
            return true;
        case 'u':
            return true;
        case 'A':
            return true;
        case 'E':
            return true;
        case 'I':
            return true;
        case 'O':
            return true;
        case 'U':
            return true;
        default:
            return false;
    }
}

/*
char* reverseVowels(char* s)
{
    int len = strlen(s);

    if(len < 2)
        return s;

    int i, j = 0;
    char vowels[len];

    memset(vowels, 0, len);

    for(i = 0; i < len; i++)
    {
        if(checkVowels(s[i]))
            vowels[j++] = s[i];
    }

    for(i = 0; i < len; i++)
    {
        if(checkVowels(s[i]))
            s[i] = vowels[--j];
    }

    return s;
}
*/

char* reverseVowels(char* s)
{
    int length = strlen(s);

    if(length <= 1)
        return s;

    int i = 0;
    int j = length - 1;

    while(i < j)
    {
        while(!checkVowels(s[i]) && i != length -1)
            i++;

        while(!checkVowels(s[j]) && j != 0 )
            j--;

        if(i < j && checkVowels(s[i]) && checkVowels(s[j]))
        {
            s[i] = s[i] ^ s[j];
            s[j] = s[i] ^ s[j];
            s[i] = s[i] ^ s[j];
        }

        i++;
        j--;
    }

    return s;
}

int reverseVowels_main()
{

    return 0;
}