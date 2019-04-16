//
// Created by zyc on 19-4-16.
//
/*71. Simplify Path
 * Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.



Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
 *
 */
#include "simplifyPath.h"


/*
char* simplifyPath(char* path)
{
    if(path == NULL)
        return NULL;

    int len = strlen(path);
    char *result = malloc(sizeof(char) * (len + 1));
    int i = -1;
    int start = 1, end = 1;

    while(path[end] != '\0')
    {
        while(path[end] != '/' && path[end] != '\0')
            ++end;

        if(start == end || (start + 1 == end && path[start] == '.')){

        }
        else if(start + 2 == end && (path[start] == '.' && path[start + 1] == '.')){
            while(i >= 0 && (result[i] != '/'))
                --i;

            if(i >= 0)
                --i;
        }
        else{
            result[++i] = '/';
            memcpy(result + i + 1, path + start, end - start);
            i += end - start;
        }

        if(path[end] == '\0')
            break;

        start = end + 1;
        end = start;
    }

    if(i == -1){
        result = (char *)realloc(result, 2);
        result[++i] = '/';
    }
    else{
        result = (char *)realloc(result, i + 2);
    }

    result[i + 1] = '\0';

    return result;
}
*/

char* simplifyPath(char* path)
{
    int top = -1;
    int i, j;

    for(i = 0; path[i] != '\0'; ++i)
    {
        path[++top] = path[i];

        if(top >= 1 && path[top - 1] == '/' && path[top] == '.' && (path[i + 1] == '/' || path[i + 1] == '\0'))
        {
            top -= 2;
        }
        else if(top >= 2 && path[top - 2] == '/' && path[top - 1] == '.' && path[top] == '.' && (path[i + 1] == '/' || path[i + 1] == '\0'))
        {
            for(j = top - 3; j >= 0; --j)
            {
                if(path[j] == '/')
                    break;
            }
            if(j < 0)
            {
                top = -1;
            }
            else
            {
                top = j - 1;
            }
        }
        else if(path[top] == '/' && path[i + 1] == '/')
            --top;
    }

    if(top > 0)
    {
        if(path[top] == '/') path[top] = '\0';
        else path[top + 1] = '\0';
    }
    else if(top == 0)
    {
        path[top + 1] = '\0';
    }
    else
    {
        path[0] = '/';
        path[1] = '\0';
    }

    return path;
}

int simplifyPath_main()
{

    return 0;
}