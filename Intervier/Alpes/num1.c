//
// Created by zyc on 19-4-18.
//
/* 打印全排列问题：给定一个数n，要求打印123...n的所有全排列.例如n=4，则所有的全排列为：
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
......
4 1 2 3
一共4!=24个.
*/

#include <stdio.h>
#include <stdlib.h>
#include "num1.h"

//1.
/*
int perm()
{
    int i, j, k;
    int cnt = 0;

    for (i = 1; i < 5; i++) {
        for (j = 1; j < 5; j++) {
            for (k = 1; k < 5; k++) {
                if (i != j && i != k && j != k) {
                    cnt++;
                    printf("%d%d%d\n", i, j, k);
                }
            }
        }
    }

    printf("%d\n", cnt);
}

int numOne_main()
{
    perm();

    return 0;
}
*/

//2.

int cnt = 0;


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void perm(int *arr, int k, int n)
{
    int i;

    if(k == n){
        for(i = 0; i < n; i++)
            printf("%d", arr[i]);
        printf("\n");
        cnt++;
    }
    else{
        for(i = k; i < n; i++){
            swap(&arr[k], &arr[i]);
            perm(arr, k + 1, n);
            swap(&arr[k], &arr[i]);
        }
    }
}

int numOne_main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage ./main m n\n");
        return -1;
    }

    int i;
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    int* arr = (int *)malloc(sizeof(int) * m);

    for (i = 0; i < m; i++)
        arr[i] = i + 1;

    perm(arr, 0, n);
    printf("%d\n", cnt);

    free(arr);

    return 0;
}
