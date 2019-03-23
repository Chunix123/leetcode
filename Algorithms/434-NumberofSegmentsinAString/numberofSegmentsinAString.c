//
// Created by zyc on 3/23/19.
//
/* 434. Number of Segments in a String
 * Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
    Please note that the string does not contain any non-printable characters.
    Example:
    Input: "Hello, my name is John"
    Output: 5
 */

#include <stdlib.h>
#include <memory.h>
#include "numberofSegmentsinAString.h"


int countSegments(char* s)
{
    if(s == NULL)
        return 0;

    int len = strlen(s);
    int i, res = 0;

    while(i < len && s[i] == ' ')
        i++;

    if(i == len)
        return 0;

    while(i < len)
    {
        while(i < len && s[i] != ' ')
            i++;

        res++;

        while(i < len && s[i] == ' ')
            i++;
    }

    return res;
}

int countSegments_main()
{

    return 0;
}