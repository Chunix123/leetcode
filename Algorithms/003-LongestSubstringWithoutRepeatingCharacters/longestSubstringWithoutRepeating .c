//
// Created by zyc on 3/31/19.
//

#include <memory.h>
#include "longestSubstringWithoutRepeating .h"


/*
int lengthOfLongestSubstring(char* s)
{
    int len = strlen(s);

    if(len < 1)
        return 0;

    int i, j, k;
    bool repeat = false;
    int temp, maxlen = -1;

    for(i = 0; i < len; i++)
    {
        temp = 1;
        repeat = false;
        j = i + 1;

        while(j < len && !repeat)
        {
            k = i;
            while(k < j)
            {
                if(s[k] != s[j])
                {
                    k++;
                }
                else
                {
                    repeat = true;
                    break;
                }
            }
            if(k == j)
            {
                j++;
                temp++;
            }
        }
        maxlen = maxlen < temp ? temp : maxlen;
    }

    return maxlen;
}
*/
/*
int lengthOfLongestSubstring(char* s)
{
    int maxlen = 0, currentlen = 0;
    int numChar[128], i, j, start = 0;

    memset(numChar, 0, sizeof(numChar));

    for (i = 0; s[i] != '\0'; i++)
    {
        if (++numChar[s[i]] == 2)
        {
            if (currentlen > maxlen)
                maxlen = currentlen;

            for (j = start; j < i; j ++)
            {
                if (s[i] == s[j])
                {
                    numChar[s[j]] = 1;
                    start = j + 1;
                    break;
                }
                else
                {
                    currentlen--;
                    numChar[s[j]] = 0;
                }
            }
        }
        else
        {
            currentlen++;
        }

        if (currentlen > maxlen)
        {
            maxlen = currentlen;
        }
    }

    return maxlen;
}
*/

/*
int lengthOfLongestSubstring(char* s)
{
    char seen[255];

    memset(seen, 0, sizeof(seen));

    int len = strlen(s);
    int best = 0;

    for (int i = 0; i < len; i++)
    {
        if (len - i <= best)
            break;

        int current = 0;
        for (int j = i; j < len; j++)
        {
            if (seen[s[j]])
                break;

            seen[s[j]] = 1;
            current++;
        }

        memset(seen, 0, sizeof(seen));
        best = best > current ? best : current;
    }

    return best;
}
*/

int lengthOfLongestSubstring(char* s)
{
    int i = 0, j = 0;
    int max_len = 0;
    int map[128];

    memset(map, -1, sizeof(int)*128);

    while (s[j])
    {
        if (map[s[j]] < i)
        {
            map[s[j]] = j;
        }
        else
        {
            i = map[s[j]] + 1;
            map[s[j]] = j;
        }

        if (j - i + 1 > max_len)
            max_len = j - i + 1;

        j++;
    }

    return max_len;
}

/*
int lengthOfLongestSubstring(char* s)
{

    int len = strlen(s);
    int *set = (int*)malloc(128 * sizeof(int));

    memset(set, 0, 128 * sizeof(int));

    int i = 0, j = 0;

    int maxlen = 0;

    while(i < len && j < len)
    {
        if(!set[s[j]])
        {
            set[s[j++]] = 1;

            if(j - i >= maxlen)
                maxlen = j - i;
        }
        else
        {
            set[s[i++]] = 0;
        }
    }

    return maxlen;
}
*/

int lengthOfLongestSubstring_main()
{


    return 0;
}