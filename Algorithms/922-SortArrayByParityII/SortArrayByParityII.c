//
// Created by zyc on 19-5-7.
//
/*922. Sort Array By Parity II
 * Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.



Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.


Note:

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000
 */
#include "SortArrayByParityII.h"
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize)
{
    int i, odd = 1, even = 0;
    int *ret = (int *)malloc(sizeof(int) * ASize);

    *returnSize = ASize;

    for(i = 0; i < *returnSize; i++){
        if(A[i] % 2 == 0){
            ret[even] = A[i];
            even += 2;
        }
        else{
            ret[odd] = A[i];
            odd += 2;
        }
    }

    return ret;
}

int sortArrayByParityII_main()
{

    return 0;
}