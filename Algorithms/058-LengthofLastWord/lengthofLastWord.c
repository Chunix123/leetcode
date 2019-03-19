//
// Created by zyc on 3/19/19.
//

#include "lengthofLastWord.h"
#include <string.h>


int lengthOfLastWord(char* s)
{
    /* 1.
    if (!s || !*s)
        return 0;

    int wordLen = 0;
    int cnt = 0;

    for (; *s != '\0'; s++)
    {
        if (isalpha(*s))
            cnt++;

        if (!isalpha(*s))
        {
            if (cnt > 0)
                wordLen = cnt;

            cnt = 0;
        }
    }

    return cnt > 0 ? cnt : wordLen;
    */

    int i, ans = 0;

    for(i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
            ans++;
        else if (ans)
            return ans;
    }

    return ans;
}

int lengthOfLastWord_main()
{

    return 0;
}