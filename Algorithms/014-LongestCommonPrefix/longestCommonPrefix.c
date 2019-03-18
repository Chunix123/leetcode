//
// Created by zyc on 3/18/19.
//

#include "longestCommonPrefix.h"


/*char* longestCommonPrefix(char** strs, int strsSize) {
    char *commonPrefix;
    unsigned int currLength;
    unsigned int lowestLength = -1;

    for (int i = 0; i < strsSize; ++i) {
        currLength = strlen(strs[i]);
        if (currLength < lowestLength) {
            lowestLength = currLength;
        }
    }

    if (lowestLength == -1) lowestLength = 0;
    commonPrefix = (char *)malloc(sizeof(char) * (lowestLength + 1));
    memset(commonPrefix, 0, lowestLength + 1);

    for (int i = 0; i < lowestLength; ++i) {
        for (int j = 1; j < strsSize; ++j) {
            if (strs[0][i] != strs[j][i]) {
                return commonPrefix;
            }
        }
        commonPrefix[i] = strs[0][i];
    }

    return commonPrefix;
}
*/

char* longestCommonPrefix(char** strs, int strsSize)
{
    int i, j;
    char* str = strs[0];

    if(strsSize == 0)
        return "";

    for(i = 1; i < strsSize; i++)
    {
        j = 0;

        while(str[j] && strs[i][j] && str[j] == strs[i][j])
            j++;

        str[j] = '\0';
    }

    return str;
}

int longestCommonPrefix_main()
{

    return 0;
}