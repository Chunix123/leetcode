//
// Created by zyc on 19-4-18.
//

#include "num5.h"
#include <stdio.h>


void reverseStr(char *s, int start, int end)
{
    while(start < end)
    {
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

char *reverserWords(char *s)
{
    int i, last = 0, now = 0;

    while(s[now])
    {
        while(s[now] == ' ')
            now++;

        last = now;

        while(s[now] != ' ' && s[now] != '\0')
            now++;

        reverseStr(s, last, now - 1);
    }

    reverseStr(s, 0, now - 1);

    // - ' '
    last = 0;

    for(i = 0; i < now; i++)
    {
        if((s[i] != ' ') || (last && s[last - 1] != s[i]))
            s[last++] = s[i];
    }
    s[last] = 0;

    if(last && s[last - 1] == ' ')
        s[last - 1] = 0;

    return s;
}

int num5_main()
{
    char s[] = "I am a student.";

    char *str = reverserWords(s);
    printf("%s\n", str);

    return 0;
}
