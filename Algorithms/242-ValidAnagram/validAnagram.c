//
// Created by zyc on 19-4-12.
//
/* 242. Valid Anagram
 * Given two strings s and t , write a function to determine if t is an anagram of s.
    Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true
    Example 2:
    Input: s = "rat", t = "car"
    Output: false
    Note:
    You may assume the string contains only lowercase alphabets.
    Follow up:
    What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */
#include <stdbool.h>
#include <string.h>
#include "validAnagram.h"


bool isAnagram(char* s, char* t)
{
    int lens = strlen(s);
    int lent = strlen(t);

    if(lens != lent)
        return false;

    int i;
    int counts[256] = {0};

    for(i = 0; i < lens; i++)
        counts[s[i]]++;

    for(i = 0; i < lent; i++)
        counts[t[i]]--;

    for(i = 0; i < lens; i++){
        if(counts[s[i]] != 0)
            return false;
    }

    return true;
}

int isAnagram_main()
{

    return 0;
}

