//
// Created by zyc on 19-4-28.
//
/*905. Sort Array By Parity
 * Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.



Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.


Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
 */
#include "SortArrayByParity.h"
#include <string.h>
#include <stdlib.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
    int i;
    int begin = 0, end = ASize - 1;
    int *result = (int*)malloc(sizeof(int) * ASize);

    *returnSize = ASize;

    for(i = 0; i < ASize; i++){
        if(A[i] % 2 == 0)
            result[begin++] = A[i];
        else
            result[end--] = A[i];
    }

    return result;
}

/*
void swap(int *right, int *left)
{
    int temp = *right;
    *right = *left;
    *left = temp;
}

int* sortArrayByParity(int* A, int ASize, int* returnSize)
{

    int begin = 0;
    int end = ASize - 1;

    while(begin < end)
    {
        if((A[begin] % 2) == 0)
        {
            begin++;
        }
        else
        {
            swap(&A[begin], &A[end]);
            end--;
        }
    }

    *returnSize = ASize;

    return (A);
}
*/

int sortArrayByParity_main()
{

    return 0;
}
