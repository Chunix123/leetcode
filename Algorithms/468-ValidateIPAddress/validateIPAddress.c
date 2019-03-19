//
// Created by zyc on 3/19/19.
//
/* 468. Validate IP Address
 * Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
    IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;
    Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.
    IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).
    However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.
    Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.
    Note: You may assume there is no extra space or special characters in the input string.
      Example 1:
    Input: "172.16.254.1"
    Output: "IPv4"
    Explanation: This is a valid IPv4 address, return "IPv4".
      Example 2:
    Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"
    Output: "IPv6"
    Explanation: This is a valid IPv6 address, return "IPv6".
      Example 3:
    Input: "256.256.256.256"
    Output: "Neither"
    Explanation: This is neither a IPv4 address nor a IPv6 address.
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "validateIPAddress.h"


/*
bool isIPv4(char* IP)
{
    int count, cal;
    char* str;
    char rec[50], ori[50], *prt = rec;

    sprintf(ori, "%s", IP);

    for(str = strtok(IP, "."), count = 0; str; str = strtok(NULL,"."), count++)
    {
        for(char *p = str; *p != '\0'; p++)
            if (!isdigit(*p))
                return false;

        if (count == 4)
            return false;

        if ((cal = atoi(str)) > 255)
            return false;

        prt += sprintf(prt, "%d.", cal);
    }

    if (count != 4)
        return false;

    *(prt-1) = *prt;

    return !strcmp(rec, ori);
}

bool isIPv6(char* IP)
{
    int count, len; char* str;
    char rec[50], ori[50], *prt = rec;

    sprintf(ori, "%s", IP);

    for(str = strtok(IP, ":"), count = 0; str; str = strtok(NULL, ":"), count++)
    {
        len = 0;

        for(char *p = str; *p != '\0'; p++, len++)
            if (!isxdigit(*p))
                return false;

        if (len > 4)
            return false;

        prt += sprintf(prt, "%s:", str);
    }

    if (count != 8)
        return false;

    *(prt-1) = *prt;

    return !strcmp(rec, ori);
}

char* validIPAddress(char* IP)
{
    int len = strlen(IP);
    char *res = malloc(sizeof(char) * 10);

    if (len > 8 * 4 + 7)
        sprintf(res, "Neither");
    else if (isIPv4(IP))
        sprintf(res, "IPv4");
    else if (isIPv6(IP))
        sprintf(res, "IPv6");
    else sprintf(res, "Neither");

    return res;
}
*/


bool isIPv4(char *IP, int len)
{
    int i, j;
    int count = 0, slow = 0, fast = 0;

    for(i = 0; i < len; i++)
    {
        if((IP[i] >= '0' && IP[i] <= '9') || IP[i] == '.')
        {
            if(IP[len - 1] == '.')
                return false;

            if(IP[i] != '.')
            {
                if(count == 3)
                {
                    //printf("%d-%d ", fast, len);
                    if(len - fast <= 0)
                        return false;
                    if(len - fast > 3)
                        return false;

                    int j = len - 1, sum = 0, su = 1;
                    for(; j >= fast; j--)
                    {
                        if(len - fast > 1)
                            if(IP[j] == '0')
                                return false;
                        sum += (IP[j] - '0') * su;
                        su *= 10;
                    }
                    //printf("%d\n", sum);

                    if(sum > 255)
                        return false;

                    count++;
                }

                fast++;
            }
            else
            {
                //printf("%d-%d ", slow, fast);
                if(fast - slow <= 0)
                    return false;
                if(fast - slow > 3)
                    return false;

                int j = fast - 1, sum = 0, su = 1;
                for(; j >= slow; j--)
                {
                    if(fast - slow > 1)
                        if(IP[j] == '0')
                            return false;

                    sum += (IP[j] - '0') * su;
                    su *= 10;
                }
                //printf("%d\n", sum);

                if(sum > 255)
                    return false;

                fast++;
                slow = fast;
                count++;
            }
        }
        else
            return false;
    }

    return true;
}

// "2001:0db8:85a3:0:0:8A2E:0370:7334"
// "20EE:FGb8:85a3:0:0:8A2E:0370:7334"
bool isIPv6(char *IP, int len)
{
    int i, j;
    int count = 0, slow = 0, fast = 0;

    for(i = 0; i < len; i++)
    {
        if((IP[i] >= '0' && IP[i] <= '9') || (IP[i] >= 'a' && IP[i] <= 'f') || (IP[i] >= 'A' && IP[i] <= 'F') || IP[i] == ':')
        {
            if(IP[len - 1] == ':')
                return false;

            if(IP[i] != ':')
            {
                if(count == 7)
                {
                    //printf("%d-%d ", fast, len);

                    if(len - fast <= 0)
                        return false;
                    if(len - fast > 4)
                        return false;

                    count++;
                }

                fast++;
            }
            else
            {
                //printf("%d-%d ", slow, fast);

                if(fast - slow <= 0)
                    return false;
                if(fast - slow > 4)
                    return false;

                fast++;
                slow = fast;
                count++;
            }
        }
        else
            return false;
    }

    return true;

}

char* validIPAddress(char* IP)
{
    if(!*IP || !IP)
        return "Neither";

    int len = strlen(IP);

    if(len < 7)
        return "Neither";

    if(len > 40)
        return "Neither";

    if(IP[0] == ':' || IP[0] == '.')
        return "Neither";

    int i, flag1 = 0, flag2 = 0;

    for(i = 0; i < len; i++)
    {
        if(IP[i] == '.')
            flag1++;
        if(IP[i] == ':')
            flag2++;
    }

    //printf("%d %d\n", flag1, flag2);
    if(flag1 > 0 && flag2 > 0)
        return "Neither";
    if(flag1 != 3 && !flag2)
        return "Neither";
    if(flag2 != 7 && !flag1)
        return "Neither";

    if(isIPv4(IP, len))
        return "IPv4";
    if(isIPv6(IP, len))
        return "IPv6";

    return "Neither";
}

int validIPAddress_main()
{

    return 0;
}