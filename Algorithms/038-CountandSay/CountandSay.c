//
// Created by zyc on 19-4-26.
//
/*38. Count and Say
 * The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.



Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
 */
#include <stdlib.h>
#include <string.h>
#include "CountandSay.h"


char* countAndSay(int n)
{
    if(n == 1)
        return "1";

    char *tmp, *cur = malloc(2);

    cur[0] = '1';
    cur[1] = 0;

    int i, j, len, idx, count;

    for(i = 2; i <= n; i++)
    {
        len = strlen(cur);
        tmp = malloc(len * 3);
        memset(tmp, 0, len * 3);
        count = 1;

        for(idx = 1, j = 0; idx < len; idx++)
        {
            if(cur[idx] == cur[idx - 1])
            {
                ++count;
            }
            else
            {
                tmp[j++] = '0' + count;
                tmp[j++] = cur[idx - 1];
                count = 1;
            }
        }

        tmp[j++] = '0' + count;
        tmp[j++] = cur[len - 1];

        free(cur);
        cur = tmp;
    }

    return cur;
}

/*
char* countAndSay(int n)
{
    char *out, *pre;
    int size, currNum, repeat, write;

    // Boundary condition
    if(n == 1) {
        out = malloc(sizeof(char) * 2);
        out[0] = '1';
        out[1] = '\0';
    } else {
        pre = countAndSay(n - 1);
        //printf("n = %d, pre = %s\n", n, pre);

        for(size = 0; *(pre+size); size++);
        //printf("pre_size = %d\n", size);

        out = malloc(sizeof(char) * (size * 2 + 1));

        out[2*size] = '\0';

        currNum = pre[0];
        repeat = 0;
        write = 0;
        do {
            if(*pre == currNum) {
                repeat++;
                //printf("do-if: currNum = %d, repeat = %d\n", currNum, repeat);
            } else {
                out[write++] = repeat + '0';
                out[write++] = currNum;
                currNum = *pre;
                repeat = 1;
                //printf("do-else: out = %s, currNum = %d, repeat = %d, write = %d\n", out, currNum, repeat, write);
            }
            pre++;
        } while(*pre);

        //printf("final: currNum = %d, repeat = %d\n", currNum, repeat);

        out[write++] = repeat + '0';
        out[write++] = currNum;
        out[write] = '\0';
    }

    //printf("out = %s\n\n", out);

    return out;
}
*/

int countAndSay_main()
{

    return 0;
}