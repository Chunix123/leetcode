//
// Created by zyc on 19-4-23.
//
/*459. Repeated Substring Pattern
 * Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.



Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "RepeatedSubstringPattern.h"


bool repeatedSubstringPattern(char* s)
{
    int len = strlen(s);
    int i, j;

    for(i = len / 2; i != 0; i--){
        if(len % i == 0){
            for(j = i; j < len; j += i){
                if(memcmp(s, s + j, i) != 0)
                    break;
            }
            if(j == len)
                return true;
        }
    }

    return false;
}

int repeatedSubstringPattern_main()
{


    return 0;
}