//
// Created by zyc on 3/20/19.
//

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "validParentheses.h"


bool isValid(char* s)
{
    int len = strlen(s);
    int flag = -1;
    char stack[len + 2];

    while(*s)
    {
        if(')' == *s)
        {
            if(flag >= 0 && stack[flag--] == '(');
            else return false;
        }
        else if(']' == *s)
        {
            if(flag >= 0 && stack[flag--] == '[');
            else return false;
        }
        else if('}' == *s)
        {
            if(flag >= 0 && stack[flag--] == '{');
            else return false;
        }
        else
        {
            stack[++flag] = *s;
        }
        s++;
    }

    return -1 == flag;
}

int isValid_main()
{

    return 0;
}