/*
* https://leetcode.com/problems/counting-bits/
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* countBits(int num, int* returnSize) {
    *returnSize = num + 1;
    int* result = (int*)malloc(sizeof(int)* *returnSize);
    int i, p2;
    result[0] = 0;
    p2 = 1;
    while (p2 <= num) {
        result[p2] = 1;
        for (i = 1; (i + p2) <= num && i < p2; ++i) {
            result[i + p2] = 1 + result[i];
        }
        p2 <<= 1;
    }
    return result;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("countBits <n>\n");
        return 0;
    }
    int* result, size, i;
    result = countBits(atoi(argv[1]), &size);
    for (i = 0; i < size; i++) {
        printf("%4d ", result[i]);
    }
    free(result);
}