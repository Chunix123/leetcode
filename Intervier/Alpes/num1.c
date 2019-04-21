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
#include <string.h>
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

int num1_main(int argc, char *argv[])
{
    perm();

    return 0;
}
*/

//2. Not use
/*
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

int num1_main(int argc, char *argv[])
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
*/

//3.
/*
int cnt = 0;

int qerm(int *arr, int *tmp, int n, int m, int len)
{
    int i, j;

    if(m == 1)
    {
        for(i = 0; i < n; i++)
        {
            tmp[len - m] = arr[i];

            for(j = 0; j < len; j++)
                printf("%d ", tmp[j]);
            printf("\n");
            cnt++;
        }

        return 0;
    }

    for(i = 0; i < n - m + 1; i++)
    {
        tmp[len - m] = arr[i];
        qerm(arr + i + 1, tmp, n - i - 1, m - 1, len);
    }
}

int num1_main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Using ./main n m\n");
        return -1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    if(m > n || n < 1 || m < 1)
    {
        printf("Input n m is error!\n");
        return -1;
    }

    int i;
    int *arr = (int*)malloc(sizeof(int) * n);
    int *tmp = (int*)malloc(sizeof(int) * m);

    for(i = 0; i < n; i++)
        arr[i] = i + 1;

    qerm(arr, tmp, n, m, m);
    printf("%d\n", cnt);

    free(arr);
    free(tmp);

    return 0;
}
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Print_arr_n(int arr[],int n)
{
    int i;

    for(i=0;i<n-1;i++)
        printf("%d,",arr[i]);
    printf("%d\n",arr[i]);
}

void QuanPaiLei(int n,int m)
{
    int count = 0;
    int arr[100];
    int i = 0, j = 0;
    int flag = 1;//用于判断数组中是否有重复的数,为1时没有，否则为0;

    arr[0] = 1;

    while(1)
    {
        flag = 1;
        for(j = 0; j < i; j++){//每次输出前都要，判断是否有重复；
            if(arr[i]==arr[j]){
                flag=0;
                break;
            }
        }
        if(flag == 1 && i == m-1){
            Print_arr_n(arr, m);
            count++;
        }
        if(flag == 1 && i < m - 1){
            i++;
            arr[i] = 1;////每个都要从1开始
            continue;
        }
        while(arr[i] == n)
            i--;
        if(i >= 0)
            arr[i]++;
        else
            break;
    }

    printf("count = %d\n",count);
}

int num1_main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Using ./main n m\n");
        return -1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    if(m > n || m < 1 || n < 1)
    {
        printf("Input n m is error!\n");
        return -1;
    }

    int i;
    int *arr = (int*)malloc(sizeof(int) * n);

    for(i = 0; i < n; i++)
        arr[i] = i + 1;

    QuanPaiLei(n, m);

    return 0;
}
