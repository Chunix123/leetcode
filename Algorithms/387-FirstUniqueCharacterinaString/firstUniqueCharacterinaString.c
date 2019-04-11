//
// Created by zyc on 19-4-11.
//
/* 387. First Unique Character in a String
 * Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
    Examples:
    s = "leetcode"
    return 0.
    s = "loveleetcode",
    return 2.
    Note: You may assume the string contain only lowercase letters.
 */
#include "firstUniqueCharacterinaString.h"
#include <string.h>


int firstUniqChar(char* s)
{

    int i;
    int len = strlen(s);
    int times[26];

    memset(times, 0, sizeof(int) * 26);

    for(i = 0; i < len; i++){
        times[s[i] - 'a']++;
    }

    for(i = 0; i < len; i++)
    {
        if(times[s[i] - 'a'] == 1)
            return i;
    }

    return -1;
}

/*
int firstUniqChar(char* s)
{
    int times[256] = {0};
    int i = 0;

    while (s[i]) {
        times[s[i]]++;
        i++;
    }

    i = 0;

    while (s[i]) {
        if (times[s[i]] == 1) {
            return i;
        }
        i++;
    }

    return -1;
}
*/

int firstUniqChar_main()
{


    return 0;
}
