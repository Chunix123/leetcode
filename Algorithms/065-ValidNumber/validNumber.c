//
// Created by zyc on 19-4-18.
//
/*65. Valid Number
 * Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
 */
#include <stdbool.h>
#include "validNumber.h"


/*
//Bug
bool verifyChar(char c)
{
    if(c >= '0' && c <= '9')
        return true;
    else if(c == '-' || c == '+')
        return true;
    else if(c == 'e' || c == '.')
        return true;

    return false;
}

bool isNumber(char* s)
{
    int i, len = strlen(s);
    int isE = false, isR = false, isL = false, isP = false, isNum = false;

    if(len == 0)
        return false;

    if(len == 1){
        if(s[0] >= '0' && s[0] <= '9')
            return true;
        else
            return false;
    }

    while(s[len - 1] == ' ')
        len--;

    while(*s == ' '){
        len--;
        *s++;
    }

    //printf("%d\n", len);

    for(i = 0; i < len; i++){

        if(s[0] == 'e')
            return false;
        if(s[len - 1] == 'e')
            return false;
        else if(verifyChar(s[i])){
            if(s[i] == '+'){
                if(isR)
                    return false;
                if(isL)
                    return false;
                isR = true;
            }
            else if(s[i] == '-'){
                if(isL)
                    return false;
                if(isR)
                    return false;
                isL = true;
            }
            else if(s[i] == '.'){
                if(isP || isE)
                    return false;
                isP = true;
            }
            else if(s[i] == 'e'){
                if(isE)
                    return false;
                isE = true;
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                isNum = true;
            }
        }
        else{
            return false;
        }
    }

    if(!isNum)
        return false;

    return true;
}
*/

int readdigit(char** s, bool allowSign)
{
    int count = 0;

    if (allowSign) {
        if ('+' == **s || '-' == **s) {
            ++*s;
        }
    }
    while ('0' <= **s && **s <= '9') {
        ++*s;
        count++;
    }

    return count;
}

void skipblank(char** s)
{
    while (' ' == **s) {
        ++*s;
    }
}

bool isNumber(char* s)
{
    int count = 0, fcount = 0;

    skipblank(&s);

    count = readdigit(&s, true);

    if ('.' == *s) {
        s++;
        fcount = readdigit(&s, false);
    }

    if (('e' == *s || 'E' == *s) && (count + fcount)) {
        s++;
        if (!(count = readdigit(&s, true))) {
            return false;
        }
    }

    skipblank(&s);

    return (count + fcount) && !*s;
}

int isNumber_main()
{

    return 0;
}
