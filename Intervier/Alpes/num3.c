//
// Created by zyc on 19-4-18.
//

#include "num3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool re_match(const char *target_string, const char *re_string)
{
    int i, j;
    int lenta = strlen(target_string);
    int lenre = strlen(re_string);

    if(lenre > lenta)
        return false;

    for(i = 0; i < lenta; i++)
    {
        bool isEqual = false;
        int cnt = 0;

        for(j = 0; j < lenre; j++)
        {

            if(re_string[j] == '*' || target_string[i + cnt] == re_string[j])
            {
                isEqual = true;
                cnt++;
            }
            else
            {
                isEqual = false;
                break;
            }
        }

        if(isEqual)
            return true;
    }

    return false;
}

int num3_main()
{
    char *target_string = "xxabcdefgh";
    char *re_string[] = {"abc", "abc*", "abc+"};

    bool ret = false;
    int i;

    for(i = 0; i < sizeof(re_string) / sizeof(re_string[0]); i++)
    {
        ret = re_match(target_string, re_string[i]);
        printf("re_result, %s: %d\n", re_string[i], ret);
    }

    return 0;
}
