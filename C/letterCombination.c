/*
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *
 * 2015/12/30
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myStrCpy(char *src, char *dest, char append) {
    char *p = src, *q = dest;
    while (*q++ = *p++);
    *(q-1) = append;
    *q = 0;
}

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
/* Dynamic programming approach */
char** letterCombinations(char* digits, int* returnSize) {
    char **result = NULL;
    *returnSize = 1;
    char map[][5] = { " ", "",  "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    int lengths[] = {1,0,3,3,3,3,3,4,3,4};
    char *p = digits, *q;
    int  len = 1, i, cur, loop, index;
    while (*p) { *returnSize *= lengths[*p - '0']; p++; len++; }
    p = digits;
   
    if (*p && *returnSize > 0) {
        result = (char **)malloc(sizeof(char*) * *returnSize);

        for (i = cur = 0, q = map[*p - '0']; *q; q++) {
            result[i] = (char*)malloc(sizeof(char) * len);
            result[i][0] = *q; result[i][1] = 0;
            cur++; i++;
        }
        p++;
        index = 1;
        while (*p) {
            q = map[*p - '0'];
            q++;
            loop = cur;
            while (*q) {
                for (i = 0; i < loop; ++i) {
                    result[i + cur] = (char*)malloc(sizeof(char)*len);
                    myStrCpy(result[i], result[i + cur], *q);
                }
                cur += loop;
                q++;
            }
            q = map[*p - '0'];
            for (i = 0; i < loop; ++i) {
                result[i][index] = *q;
                result[i][index + 1] = 0;
            }
            p++; index++;
        }
    }
    return result;
}

/* Backtracking approach */
char** letterCombinationsB(char* digits, int* returnSize) {
    char **result = NULL, **w = NULL;
    *returnSize = 1;
    char map[][5] = { " ", "",  "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    int lengths[] = {1,0,3,3,3,3,3,4,3,4};
    char *p = digits, *q;
    int  len = 1, i, j;
    while (*p) { 
        *returnSize *= lengths[*p - '0'];        
        w = (char **)realloc(w, sizeof(char *) * len);
        w[len - 1] = map[*p - '0'];
        len++;   p++;  
    }
    p = digits;   
    if (w) {
        result = (char **)malloc(sizeof(char*) * *returnSize);
        for (i = 0; i < *returnSize; i++) {
            result[i] = (char*)malloc(sizeof(char) * len);
            for (q = result[i], j = 0; j < len-1; j++) {
                *q++ = *(w[j]);
            }
            *q = 0;
            for (j = len - 2; j >= 0; j--) {
                w[j]++;
                if (*(w[j])) {
                    break;
                }
                else {
                    w[j] = map[digits[j]-'0'];
                }
            }
        }
    }
    else {
        *returnSize = 0;
    }
    free(w);
    return result;
}
