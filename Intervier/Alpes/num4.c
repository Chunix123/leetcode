//
// Created by zyc on 19-4-18.
//

#include "num4.h"

#include <stdio.h>


void qerm(int a[][4], int row, int col, int rowlen, int collen)
{
    int i1, i2, j1, j2;

    if(row < rowlen && col < collen)
    {
        for(j1 = col; j1 < collen; j1++)
            printf("%d ", a[row][j1]);
        for(i1 = row + 1; i1 < rowlen; i1++)
            printf("%d ", a[i1][collen - 1]);
        for(j2 = collen - 1; j2 > col; j2--)
            printf("%d ", a[rowlen - 1][j2]);
        for(i2 = rowlen - 1; i2 > row + 1; i2--)
            printf("%d ", a[i2][col]);
    }
    else
        return;

    qerm(a, row + 1, col + 1, rowlen - 1, collen - 1);
}

int num4_main()
{
    int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    qerm(arr, 0, 0, 4, 4);
    printf("\n");

    return 0;
}
