//
// Created by zyc on 3/10/19.
//

#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include "addBinary.h"


/*
char* addBinary(char* a, char* b)
{
    int la = strlen(a), lb = strlen (b);
    char c = 0;
    int l;
    char* res;

    l = 2 + (la < lb ? lb : la);

    res = (char*)malloc(sizeof(char)*l);

    memset(res, '0', sizeof(char)*l);
    res[--l] = '\0';

    while(l--)
    {
        c += (la > 0 ? a[--la] - '0' : 0) + (lb > 0 ? b[--lb] - '0' : 0);

        res[l] = c % 2 + '0';
        c /= 2;
    }
    if(res[0] == '0')
        res++;

    return res;
}
*/

char* addBinary(char* a, char* b)
{
    int i, j , bit = 0;
    int lena = strlen(a);
    int lenb = strlen(b);
    int maxlen = (lena > lenb) ? lena + 1 : lenb + 1;
    char *str = malloc((maxlen + 1) * sizeof(char));

    printf("%d %d %d\n", lena, lenb, maxlen);
    str[maxlen] = '\0';
    str[maxlen - 1] = '\0';

    int len = 0, na = 0, nb = 0;
    for(i = lena - 1, j = lenb - 1; bit || i >= 0 || j >= 0; i--, j--)
    {
        printf("%d-%d ", i, j);
        na = (i >= 0 ? (a[i] - '0') : 0);
        nb = (j >= 0 ? (b[j] - '0') : 0);
        str[len++] = (na ^ nb ^ bit) + '0';
        bit = ((bit + na + nb) >= 2 ? 1 : 0);
        printf("%d-%d-%c ", na, nb, str[len - 1]);
    }
    printf("\n");
    //len--;
    printf("%d %s\n", len, str);

    for(i = 0; i < len / 2; i++)
    {
        printf("%d ", i);
        char c = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = c;
        printf("%c %c\n", str[i], str[len - 1 - i]);
    }
    printf("%s\n", str);

    return str;
}


int addBinary_main()
{
    char *a = "1";
    char *b = "0";

    printf("%s\n", addBinary(a, b));

    return 0;
}
