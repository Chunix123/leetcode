//
// Created by zyc on 19-4-15.
//
/*93. Restore IP Addresses
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
 */
#include "RestoreIPAddresses.h"
#include <string.h>
#include <stdlib.h>



//4ms
#define MAX 1024

void function(const char* s, int level, char* temp, int temp_index, char** result, int* returnSize)
{
    if (*s == '\0') {
        if (level != 4)
            return ;

        temp[--temp_index] = '\0';
        result[*returnSize] = (char*)malloc(sizeof(char)*(temp_index+1));
        strcpy(result[(*returnSize)++], temp);

        return ;
    }

    if (level == 4)
        return ;

    int count = 0;

    for (int i = 0; s[i] != '\0'; ++i) {
        count = count * 10 + s[i] - '0';

        if (count > 255)
            break;

        temp[temp_index++] = s[i];
        temp[temp_index] = '.';
        function(s + i + 1, level + 1, temp, temp_index + 1, result, returnSize);

        if (count == 0)
            break;
    }
}

char** restoreIpAddresses(char* s, int* returnSize)
{
    char** result = (char**)malloc(sizeof(char*)*MAX);

    *returnSize = 0;

    char* temp = (char*)malloc(sizeof(char)*(strlen(s)+4));

    function(s, 0, temp, 0, result, returnSize);
    free(temp);

    return result;
}

int restoreIpAddresses_main()
{

    return 0;
}
