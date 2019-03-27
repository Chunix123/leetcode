//
// Created by zyc on 3/27/19.
//

#include <stdbool.h>
#include <stdio.h>
#include "utilsHelper.h"


//1. Big_endian & Little_endian
union endian{
    int val;
    char c;
};

bool checkCPU()
{
    union endian A;
    A.val = 0x01;

    return A.c == 1;
}

void checkCPUPrint()
{
    bool isLittle = checkCPU();
    if(isLittle)
        printf("Little endian!\n");
    else
        printf("Big endian!\n");
}

//2. return 1+2+3+...+n
int sum_n(int n)
{
    return (1l + n) * n / 2;
}

//3.


int utilsHelper()
{
    checkCPUPrint();
    printf("%d\n", sum_n(5));

    return 0;
}
