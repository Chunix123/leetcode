//
// Created by zyc on 19-4-18.
//
/* 2. 8*8
 *
 */
#include "num2.h"
#include <stdio.h>
#include <limits.h>


int num2_main()
{
    int arr[8][8] = {{6,8,7,8,4,9,4,3},{6,5,7,6,1,9,3,3},{9,3,5,1,7,6,3,8},{2,5,2,6,7,2,4,9},{6,7,1,6,4,7,1,3},{4,8,8,2,3,3,7,8},{5,2,3,5,9,4,9,2},{6,2,3,1,2,1,3,400}};

    int i, j;
    int min = INT_MAX, sum = 0;

    for(i = 0; i < 5; i++){
        sum = 0;

        for(j = 0; j < 5; j++){
            sum += arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3];
            sum += arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2] + arr[i+1][j+3];
            sum += arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2] + arr[i+2][j+3];
            sum += arr[i+3][j] + arr[i+3][j+1] + arr[i+3][j+2] + arr[i+3][j+3];

            //printf("%d %d %d %d\n", i, j, sum, min);
            min = min > sum ? sum : min;
        }
    }

    printf("%d\n", min);

    return 0;
}
