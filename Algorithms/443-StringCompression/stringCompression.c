//
// Created by zyc on 19-4-12.
//
/* 443. String Compression
 * Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.


Follow up:
Could you solve it using only O(1) extra space?


Example 1:

Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".


Example 2:

Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.


Example 3:

Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.


Note:

All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.
 */

#include "stringCompression.h"


int compress(char* chars, int charsSize)
{
    if(charsSize <= 1)
        return charsSize;

    int i, j = 0, cnt = 1;

    for(i = 0; i < charsSize; i++){
        if((i != charsSize - 1) && (chars[i] == chars[i + 1])){
            cnt++;
        }
        else{
            if(cnt == 1){
                chars[j++] = chars[i];
                continue;
            }
            else{
                chars[j++] = chars[i];
                if(cnt / 1000 != 0){
                    chars[j++] = cnt / 1000 + '0';
                    cnt %= 1000;
                }
                if(cnt / 100 != 0){
                    chars[j++] = cnt / 100 + '0';
                    cnt %= 100;
                }
                if(cnt / 10 != 0){
                    chars[j++] = cnt / 10 + '0';
                    cnt %= 10;
                }
                chars[j++] = cnt + '0';
                cnt = 1;
            }
        }
    }

    return j;
}


int compress_main()
{

    return 0;
}