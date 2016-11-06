/**
 * https://leetcode.com/problems/longest-common-prefix/
 */

#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int size;
    char* p, *q;
    char* result;
    q = strsSize > 0 ? strs[0] : "\0";
    size = strlen(q) + 1;
    result = (char*)malloc(sizeof(char)*size);
    memcpy(result, q, size);
    
    while (--strsSize >= 0) {
        for (p = result, q = strs[strsSize]; *p && *q && *p == *q; p++, q++);
        *p = 0;
    }
    return result;
}

#include <stdio.h>
int main(int argc, char** argv) {
    char* result = longestCommonPrefix(argv + 1, argc - 1);
    printf("result=%s\n", result);
    free(result);
    return 0;
}