//
// Created by zyc on 19-5-20.
//
/*520. Detect Capital
 * Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.


Example 1:

Input: "USA"
Output: True


Example 2:

Input: "FlaG"
Output: False


Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
 */
#include <stdbool.h>
#include <ctype.h>
#include "DetectCapital.h"


bool detectCapitalUse(char * word)
{
    if(!*word)
        return true;

    bool isUpp = true;
    bool x;
    int i = -1;

    while(*word)
    {
        i++;
        x = isupper(*word);

        if((!isUpp && x) || (i > 1 && !x && isUpp))
            return false;

        isUpp = isupper(*word++);
    }

    return true;
}


int detectCapitalUse_main()
{

    return 0;
}