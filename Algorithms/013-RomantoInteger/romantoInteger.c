//
// Created by zyc on 3/12/19.
//

#include "romantoInteger.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/*
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
*/

/*
int romanToInt(char* s)
{
    int i, len;
    int result = 0;

    len = strlen(s);

    for(i = 0;i < len; i++){
        switch(s[i])
        {
            case 'I':
                if(s[i + 1] == 'V'){
                    result += 4;
                    i++;
                    break;
                }
                else if(s[i + 1] == 'X'){
                    result += 9;
                    i++;
                    break;
                }
                else{
                    result += 1;
                    break;
                }
            case 'X':
                if(s[i + 1] == 'L'){
                    result += 40;
                    i++;
                    break;
                }
                else if(s[i + 1] == 'C'){
                    result += 90;
                    i++;
                    break;
                }
                else{
                    result += 10;
                    break;
                }
            case 'C':
                if(s[i + 1] == 'D'){
                    result += 400;
                    i++;
                    break;
                }
                else if(s[i + 1] == 'M'){
                    result += 900;
                    i++;
                    break;
                }
                else{
                    result += 100;
                    break;
                }
            case 'V':
                result += 5;
                break;
            case 'L':
                result += 50;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            default:
                break;
        }
    }

    return result;
}
*/

int romanToInt(char *s)
{
    int len = strlen(s);
    int map[256] = {0};

    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    int x = 1001;

    int result = 0;
    int i;

    for(i = 0; i < len; i++){
        if(map[s[i]] <= x)
            result += map[s[i]];
        else
            result += map[s[i]] - 2 * x;
        x = map[s[i]];
    }

    return result;
}

int remanToInteger()
{
    char str[] = "MCMXCIV";

    printf("%d\n", romanToInt(str));

    return 0;
}
