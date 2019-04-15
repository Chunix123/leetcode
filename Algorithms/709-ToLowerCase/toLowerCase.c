//
// Created by zyc on 19-4-15.
//
/*709. To Lower Case
 * Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"
 */
#include "toLowerCase.h"


/*
char* toLowerCase(char* str)
{
    int len = strlen(str);
    int i;

    for(i = 0; i < len; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';
    }

    return str;
}
*/

char* toLowerCase(char* str)
{
    int i;

    for(i = 0; str[i]; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';
    }

    return str;
}

int toLowerCase_main()
{


    return 0;
}
