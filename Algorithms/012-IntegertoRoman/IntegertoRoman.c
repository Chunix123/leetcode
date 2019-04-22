//
// Created by zyc on 19-4-22.
//
/*12. Integer to Roman
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */
#include "IntegertoRoman.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
#define Roman_count 13
#define Length 128

struct romanItem
{
    int number;
    char *roman;
};

char* intToRoman(int num)
{
    char *result = (char*)malloc(sizeof(char) * Length);
    //result[0] = '\0';
    memset(result, 0, sizeof(char) * Length);

    int i, temp = 0;
    struct romanItem roman_str[Roman_count] = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, \
                             {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"},   \
                             {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};

    for(i = Roman_count - 1; i>=0; i--){
        temp = num / roman_str[i].number;

        while(temp > 0){
            strcat(result, roman_str[i].roman);
            temp--;
        }

        num %= roman_str[i].number;
    }

    return result;
}
*/

char* intToRoman(int num) {
    char *result;
    int i, counter;

    result = (char*)malloc(256);
    memset(result, 0, 256);

    // M
    i = num/1000;
    if(i > 0){
        for(counter = 0; counter < i; counter++){
            strcat(result, "M");
        }
    }

    // C
    num = num % 1000;
    i = num / 100;
    if(i > 0){
        if(i == 9){
            strcat(result, "CM");
        }else if(i == 4){
            strcat(result, "CD");
        }else{
            if(i >= 5)
                strcat(result, "D");
            i = i % 5;
            for(counter = 0; counter < i; counter++)
                strcat(result, "C");
        }
    }

    //X
    num = num % 100;
    i = num / 10;
    if(i > 0){
        if(i == 9){
            strcat(result, "XC");
        }else if(i == 4){
            strcat(result, "XL");
        }else{
            if(i >= 5)
                strcat(result, "L");
            i = i % 5;
            for(counter = 0; counter < i; counter++)
                strcat(result, "X");
        }
    }

    //I
    num = num % 10;
    i = num;
    if(i > 0){
        if(i == 9){
            strcat(result, "IX");
        }else if(i == 4){
            strcat(result, "IV");
        }else{
            if(i >= 5)
                strcat(result, "V");
            i = i % 5;
            for(counter = 0; counter < i; counter++)
                strcat(result, "I");
        }
    }

    return result;
}

int intToRoman_main()
{

    return 0;
}
