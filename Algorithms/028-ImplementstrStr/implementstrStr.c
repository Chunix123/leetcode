//
// Created by zyc on 3/14/19.
//

#include <stdbool.h>
#include <string.h>
#include "implementstrStr.h"


int strStr(char* haystack, char* needle)
{
    int lena = strlen(haystack);
    int lenb = strlen(needle);
    int i, j;

    if(lenb == 0)
        return 0;

    for(i = 0; i < lena; i++)
    {
        bool flag = true;

        if(needle[0] == haystack[i])
        {
            for(j = 1; j < lenb; j++)
            {
                if(i + j < lena)
                {
                    if(haystack[i + j] != needle[j])
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    return -1;
                }
            }

            if(flag)
            {
                return i;
            }
        }
    }

    return -1;
}

int strStr_main()
{

    return 0;
}