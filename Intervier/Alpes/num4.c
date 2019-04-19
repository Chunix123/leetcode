//
// Created by zyc on 19-4-18.
//
/*回形遍历（螺旋遍历）实现
 * Question: Given a 2D array / matrix of integers. Write a program to print the elements
 * in spiral order. Consider a matrix as show in the diagram to the right.
 * The desired output of the program should be as: 1,2,3,4,8,12,16,20,19,18,17,13,9,5,6, 7,11,15,14,10.
 */
#include "num4.h"

#include <stdio.h>


#include <stdio.h>
#include <stdlib.h>


void qerm(int **a, int row, int col, int rowlen, int collen)
{
    int i1, i2, j1, j2;

    if(row < rowlen && col < collen){
        for(j1 = col; j1 < collen; j1++)
            printf("%d ", a[row][j1]);
        for(i1 = row + 1; i1 < rowlen; i1++)
            printf("%d ", a[i1][collen - 1]);
        for(j2 = collen - 2; j2 >= col; j2--)
            printf("%d ", a[rowlen - 1][j2]);
        for(i2 = rowlen - 2; i2 >= row + 1; i2--)
            printf("%d ", a[i2][col]);
    }
    else
        return;

    qerm(a, row + 1, col + 1, rowlen - 1, collen - 1);
}

int num4_main(int argc , char *argv[])
{
    if(argc != 3)
    {
        printf("Using m * n\n");
        return -1;
    }

    int i, j;
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    int **arr = malloc(sizeof(char*) * m);

    for(i = 0; i < m; i++){
        arr[i] = malloc(sizeof(char) * n);

        for(j = 0; j < n; j++){
            arr[i][j] = i * m + (j + 1);
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");

    qerm(arr, 0, 0, 4, 4);
    printf("\n");

    free(arr);

    return 0;
}
