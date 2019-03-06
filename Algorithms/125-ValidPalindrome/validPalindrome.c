//
// Created by zyc on 3/6/19.
//

#include <stdbool.h>
#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include "validPalindrome.h"


/*
inline char lower(char c){ return (c|' '); }
inline bool a2z(char c){ return lower(c)<='z' && lower(c) >= 'a'; }
inline bool isnum(char c){ return c>='0' && c<='9'; }

bool isPalindrome(char* s)
{
    char* e;
    for(e=s; *e!='\0'; e++){}
    while(e>s){
        if(!a2z(*e) && !isnum(*e)){
            e--;
            continue;
        }
        if(!a2z(*s) && !isnum(*s)){
            s++;
            continue;
        }
        if(lower(*e) != lower(*s)) return 0;
        e--;
        s++;
    }
    return 1;
}
*/
/*
bool isPalindrome(char* s) {

    int start=0;
    int end = strlen(s)-1;
    int i, flag=0;


    // Assumptions : String contains alphanumeric character + spaces
    //               Ignore casing

    while(start<end){

        if( isalnum(s[start]) && isalnum(s[end]) ){
            if (tolower(s[start]) != tolower(s[end])){
                flag = 1;
                break;
            }
            start++;
            end--;
        }

        if( !isalnum(s[start]))
            start++;
        if( !isalnum(s[end]))
            end--;
    }

    if(flag == 1)
        return 0;
    else
        return 1;
}
*/

bool isPalindrome(char *s)
{
    if(s == NULL)
        return true;

    int i, j = 0, sum = 0;

    sum = strlen(s);

    char str[sum+1];
    memset(str, 0, sum+1);

    for(i = 0; i < sum; i++)
    {
        if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            str[j] = s[i];

            if(s[i] >= 'A' && s[i] <= 'Z')
                str[j] += 'a' - 'A';

            j += 1;
        }
    }
    printf("%s\n", str);

    sum = strlen(str);
    for(i = 0; i < sum / 2; i++)
    {
        if(str[i] != str[sum - i - 1])
            return false;
    }

    return true;
}

int isPalindrome_main(int argc, char **argv)
{
    char s[] = {"A man, a plan, a canal: Panama"};
    //char s[] = {"race a car"};
    //char *s = NULL;
    printf("%s\n", isPalindrome(s) ? "true" : "false");

    return 0;
}
