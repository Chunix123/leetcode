//
// Created by zyc on 19-4-21.
//
/*17. Letter Combinations of a Phone Number
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
 */
#include <stdlib.h>
#include <string.h>
#include <libzvbi.h>
#include "LetterCombinationsofaPhoneNumber.h"
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void letterHelper(char **strs, int len, char **result, char *temp, int index, int *top)
{
    int i;
    char *letters;

    if(index == len){
        letters = (char*)malloc(sizeof(char) * (len + 1));
        temp[index] = 0;
        strcpy(letters, temp);

        result[*top] = letters;
        (*top)++;

        return;
    }

    for(i = 0; i < strlen(strs[index]); i++){
        temp[index] = strs[index][i];
        letterHelper(strs, len, result, temp, index + 1, top);
    }
}

char** letterCombinations(char* digits, int* returnSize)
{
    char map[10][5] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int i, len = 0, num = 1, top = 0;

    if(!digits[len]){
        *returnSize = 0;
        return NULL;
    }

    while(digits[len]){
        if(digits[len] == '7' || digits[len] == '9')
            num *= 4;
        else if(digits[len] != '0' || digits[len] != '1')
            num *= 3;

        len++;
    }

    char **strs = (char**)malloc(sizeof(char*) * len);

    for(i = 0; i < len; i++)
        strs[i] = map[digits[i] - '0'];

    char **result = (char**)malloc(sizeof(char*) * num);
    char *temp = (char*)malloc(sizeof(char) * (len + 1));

    letterHelper(strs, len, result, temp, 0, &top);
    *returnSize = top;

    return result;
}

/*
#define MAXCHAR 4

char phone[8][MAXCHAR+1] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void all_comb(char *digits, int indx, int dlen, char **out, int *oindx, char *tstr)
{
    if (indx == dlen) {
        strcpy(out[*oindx], tstr);
        *oindx = *oindx + 1;
        return;
    }

    int i, dindx = digits[indx] - '2';
    char *str = &phone[dindx];
    int slen = strlen(str);

    for (i = 0; i < slen; i++) {
        tstr[indx] = str[i];
        all_comb(digits, indx+1, dlen, out, oindx, tstr);
    }
}

char** letterCombinations(char* digits, int* returnSize)
{
    int i, olen = 0, dlen = strlen(digits);

    if (dlen == 0) {
        *returnSize = 0;
        return NULL;
    }

    int ncomb = pow(MAXCHAR, dlen);

    char **out = (char **)calloc(ncomb, sizeof (char *));

    for (i = 0; i < ncomb; i++)
        out[i] = (char *)calloc(dlen+1, sizeof (char));

    char *tstr = (char *)calloc(dlen+1, sizeof (char));
    tstr[dlen] = '\0';

    all_comb(digits, 0, dlen, out, &olen, tstr);
    *returnSize = olen;

    return (out);
}
*/

int letterCombinations_main()
{

    return 0;
}