//
// Created by zyc on 3/7/19.
//
/* 316. Remove Duplicate Letters
 * Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
    Example 1:
      Input: "bcabc"
      Output: "abc"
    Example 2:
      Input: "cbacdcbc"
      Output: "acdb"
 */
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "removeDuplicateLetters.h"


// BUG Not use
/*
char* reverseStr(char *s)
{
    char *h = s;
    char *t = s;
    char ch;

    while(*t++);
    t--;
    t--;

    while(h < t)
    {
        ch = *h;
        *h++ = *t;
        *t-- = ch;
    }
    //printf("%s\n", s);

    return s;
}

char* removeDuplicateLetters(char* s)
{
    s = reverseStr(s);
    printf("%s\n", s);

    int i, j, k = 0, m;
    int len = strlen(s) - 1;
    int ss[len];
    bool flag = true;

    memset(ss, 0, len);

    for(i = 0; i <= len; i++)
    {
        for(j = i + 1; j <= len; j++)
        {
            printf("%c%c ", s[i], s[j]);
            if(s[i] == s[j])
            {
                printf("--> %d %c --> ", j, s[i]);
                printf("%d %d ", i, ss[i]);
                flag = true;

                for(m = 0; m < k; m++)
                {
                    if(ss[m] == i)
                    {
                        flag = false;
                    }
                }
                if(flag)
                {
                    ss[k++] = j;
                    printf("ss[%d]: %d\n", k - 1, j);
                }
                //ss[k++] = j;
            }
        }
        printf("\n");
    }

    int n = 0, lens = k--;//strlen(ss);
    char sr[len];

    for(i = 0; i < lens; i++)
    {
        printf("%d", ss[i]);
    }
    printf("\n");

    memset(sr, 0, len);
    printf("%s lens: %d\n", s, lens);

    for(i = 0; i <= len; i++)
    {
        flag = true;
        for(j = 0; j < lens; j++)
        {
            if(i == ss[j])
            {
                flag = false;
            }
        }
        if(flag)
        {
            printf("%d\n", i);
            sr[n++] = s[i];
        }
    }

    printf("%s\n", sr);
    s = reverseStr(sr);
    printf("%s\n", sr);

    return s;
}
*/

// 4ms
/*
char* removeDuplicateLetters(char *s)
{
    if(s == NULL)
        return NULL;

    int spaceLen = 26;
    int *count=(int *)malloc(spaceLen * sizeof(int));//用来统计字符串s中每个字符出现的次数
    if(count == NULL)
        exit(EXIT_FAILURE);

    memset(count, 0, spaceLen * sizeof(int));//初始化为零
    int len = strlen(s);

    for(int i = 0; i < len; i++)
        count[s[i]-'a']++;

    //将flag中为true的字符组合起来返回即可
    //开辟一段空间来保存结果
    char *res = (char *)malloc(spaceLen * sizeof(char*));
    if(res == NULL)
        exit(EXIT_FAILURE);

    bool *isExistInRes = (bool *)malloc(spaceLen * sizeof(bool));//用来标识结果是否已经存在了该字符
    if(isExistInRes == NULL)
        exit(EXIT_FAILURE);

    memset(isExistInRes, false, spaceLen*sizeof(bool));//注意：一定要初始化为false

    char ch;
    char sc;
    int end = -1;
    for(int i = 0; i < len; i++)
    {
        ch = s[i];
        if(isExistInRes[ch-'a'])
        {
            count[ch-'a']--;
            continue;
        }
        //通过判断刚加入的这个元素是否应该加入，如果后面的元素小于刚刚加入的元素并且这个元素不是最后一次出现，则应该不加入
        while(end >= 0 && ((sc = res[end]) >= ch) && count[sc-'a'] > 0)
        {
            end--;
            isExistInRes[sc-'a'] = false;
        }
        res[++end] = ch;
        count[ch-'a']--;
        isExistInRes[ch-'a'] = true;
    }
    res[++end] = '\0';

    return res;
}
*/

// 4ms
char* removeDuplicateLetters(char* s)
{
    int len = strlen(s);
    if (len < 2)
        return s;

    int count[26] = {0}, choosen[26] = {0}, rlen = 0;
    for (int i = 0; i < len; i++)
    {
        count[s[i] - 'a']++;
        if (count[s[i] - 'a'] == 1)
            // get result string length
            rlen++;
    }

    char* result = (char*)malloc(sizeof(char) * (rlen + 1));
    for (int i = 0, j = 0; i < len; i++)
    {
        count[s[i] - 'a']--;
        if (choosen[s[i] - 'a'])
            continue;
        // while s[i] less than choosen char in result and has enough count
        // replace the choosen one
        while (j > 0 && s[i] < result[j - 1] && count[result[j - 1] - 'a'] > 0)
        {
            choosen[result[j - 1] - 'a'] = 0;
            j--;
        }
        // fill result string
        result[j++] = s[i];
        choosen[s[i] - 'a'] = 1;
    }
    result[rlen] = '\0';
    return result;
}

// 8ms
/*
char* removeDuplicateLetters(char *s)
{
    int size = strlen(s), i, idx = 0;
    int last[128]; //a-z 26 is enough

    for(i = 0; i < size; i++)
    {
        last[s[i]] = i;
    }

    char *res = malloc(size* sizeof(char*));
    bool hava[128];

    memset(hava, 0, 128 * sizeof(bool));
    for(i = 0; i < size; i++)
    {
        char c = s[i];
        while(!hava[c] && idx > 0 && last[res[idx-1]] > i && c < res[idx-1])
        {
            hava[res[idx-1]] = false;
            idx--;
        }
        if(!hava[c])
        {
            hava[c] = true;
            res[idx++] = c;
        }
    }
    res[idx++] = '\0';

    return res;
}
*/


int removeDuplicateLetters_main()
{
    char s[] = "cbacdcbc"; //"bcabc";
    printf("%s\n", removeDuplicateLetters(s));

    return 0;
}
