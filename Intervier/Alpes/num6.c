//
// Created by zyc on 19-4-18.
//

#include "num6.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printf_arr(int *arr, int len)
{
    int i;

    for(i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

//1.
void sort_arr(int *arr, int len)
{
    int i, tmp[len];
    int num = 0, cnt = 0;

    memset(tmp, 0, len * sizeof(int));

    for(i = 0; i < len; i++)
    {
        if(arr[i] % 2)
            arr[cnt++] = arr[i];
        else
            tmp[num++] = arr[i];
    }

    for(i = 0; i < num; i++)
        arr[cnt++] = tmp[i];
}

/*
//2.
void sort_arr(int *arr, unsigned int len)
{
    if(arr == NULL || len == 0)
        return;

    int *start = arr;
    int *end = arr + len - 1;

    while(start < end)
    {
        while(start < end && (*start & 0x01) != 0)
            start++;

        while(start < end && (*end & 0x01) == 0)
            end--;

        if(start < end)
        {
            int temp = *start;
            *start = *end;
            *end = temp;
        }
    }
}
 */

int num6_main()
{
    int i, arr[] = {0,1,2,3,4,5,6,7,8,9};

    sort_arr(arr, 10);
    printf_arr(arr, 10);

    return 0;
}
