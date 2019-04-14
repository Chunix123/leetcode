//
// Created by zyc on 19-4-14.
//
/* 9. Palindrome Number
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
 */
#include <stdbool.h>
#include "palindromeNumber.h"


/*
bool isPalindrome(int x)
{
    if(x < 0)
        return false;

    int cnt = 0, temp = x;

    while(temp / 10 > 0){
        cnt++;
        temp /= 10;
    }

    while(cnt > 0){

        //printf("%d %d %d %d \n", x, cnt, x % 10, x / (int)pow(10, cnt));
        if(x % 10 == x / (int)pow(10, cnt)){
            x /= 10;
            //printf("%d ", x);
            cnt--;
            x -= x / (int)pow(10, cnt) * (int)pow(10, cnt);
            //printf("%d \n", x);
            cnt--;

            if(cnt == 0)
                return true;
        }
        else
            return false;
    }

    return true;
}
*/

bool isPalindrome9(int x)
{
    if ( x < 0 || x > 0 && x % 10 == 0) {
        return false;
    } else if (x == 0) {
        return true;
    } else {
        int revertedNum = 0;

        while (x > revertedNum) {
            revertedNum = revertedNum * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNum || x == revertedNum / 10;
    }
}


int isPalindrome9_main()
{


    return 0;
}
