//
// Created by zyc on 3/12/19.
//

#include "romantoInteger.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



int getValue(char c)
{
    switch(c)
    {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
    }

    return 0;
}

int romanToInt(char* s)
{
    int i, sum = 0, len = strlen(s);
    char c;

    if(len < 1)
        return 0;

    for(i = 0; i < len; i++)
    {
        if(i == 0)
        {
            c = s[i];
            sum += getValue(s[i]);
            //printf("%d ", sum);
        }
        else
        {
            if(c == 'I')
            {
                switch(s[i])
                {
                    case 'V': sum += getValue(s[i]) - 2; break;
                    case 'X': sum += getValue(s[i]) - 2; break;
                    default: sum += getValue(s[i]);
                }
            }
            else if(c == 'X')
            {
                switch(s[i])
                {
                    case 'L': sum += getValue(s[i]) - 20; break;
                    case 'C': sum += getValue(s[i]) - 20; break;
                    default: sum += getValue(s[i]);
                }
            }
            else if(c == 'C')
            {
                switch(s[i])
                {
                    case 'D': sum += getValue(s[i]) - 200; break;
                    case 'M': sum += getValue(s[i]) - 200; break;
                    default: sum += getValue(s[i]);
                }
            }
            else
            {
                sum += getValue(s[i]);
            }
        }
        c = s[i];
        //printf("%c %d ", s[i], sum);
    }

    return sum;
}

int remanToInteger()
{
    char str[] = "MCMXCIV";

    printf("%d\n", romanToInt(str));

    return 0;
}
