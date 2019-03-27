//
// Created by zyc on 3/27/19.
//

#include <stdio.h>
#include <assert.h>
#include "string.h"


char* Memcpy(void *dest, const void *src, size_t len)
{
    if(dest == NULL || src == NULL)
        return NULL;

    void *ret = dest;

    if(dest <= src || (char *)dest >= (char *)src + len)
    {
        while(len--)
        {
            *(char *)dest = *(char *)src;
            dest = (char *)dest + 1;
            src = (char *)src + 1;
        }
    }
    else
    {
        src = (char *)src + len - 1;
        dest = (char *)dest + len - 1;

        while(len--)
        {
            *(char *) dest = *(char *) src;
            dest = (char *) dest - 1;
            src = (char *) src - 1;
        }
    }

    return ret;
}

char *Strcpy(char *dest, const char *src)
{
    assert(dest != NULL && src != NULL);

    char *temp = dest;

    while((*dest++ = *src++) != '\0');

    return temp;
}


int string_main()
{
    printf("Hello !");

    return 0;
}