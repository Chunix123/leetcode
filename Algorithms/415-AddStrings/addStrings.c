//
// Created by zyc on 3/19/19.
//

#include "addStrings.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void reverseStrs(char *s, int len)
{
    int i = 0, j = len - 1;

    while(i < j)
    {
        char temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
}

char* addStrings(char* num1, char* num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int i, j, len = 0;
    int lens = len1 + len2 + 1;
    char *sum = malloc(lens * sizeof(char));
    int flag = 0;

    memset(sum, 0 , lens);

    for(i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--)
    {
        int temp = 0;

        if(i >= 0)
            temp += num1[i] - '0';

        if(j >= 0)
            temp += num2[j] - '0';

        if(flag)
            ++temp;

        flag = temp / 10;
        temp = temp % 10;

        sum[len++] = temp + '0';
    }

    if(flag)
    {
        sum[len] = '1';
        len += 1;
    }

    //sum[++len] = '\0';
    //for(i = 0; i <= len; i++)
    //printf("%d-%c \n", i, sum[i]);

    reverseStrs(sum, len);

    return sum;
}

int addStrings_main()
{

    return 0;
}