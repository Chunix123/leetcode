//
// Created by zyc on 19-4-29.
//
/*771. Jewels and Stones
 * You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
 */
#include "JewelsandStones.h"


int numJewelsInStones(char * J, char * S)
{
    int i, j;
    int count = 0;

    for (i = 0; J[i] != '\0'; i++){
        for (j = 0; S[j] != '\0'; j++){
            if (J[i] == S[j]){
                count++;
            }
        }
    }

    return count;
}

/*
int numJewelsInStones(char* J, char* S)
{
    int result_num = 0;
    char* src = J;
    char* dst = S;

    int i,j;

    if ((J == NULL) || (S = NULL))
        return -1;

    for (i = 0; i < 50; i++){
        if (src[i] == '\0')
            break;

        for (j=0;j<50;j++){
            if (dst[j] == '\0')
                break;
            if (src[i] == dst[j]) {
                //printf("test %c:%c\n", src[i], dst[j]);
                result_num++;
            }
        }
    }

    return result_num;
}
*/

int numJewelsInStones_main()
{

    return 0;
}