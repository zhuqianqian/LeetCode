/*
 * https://leetcode.com/problems/house-robber/
 * https://leetcode.com/problems/house-robber-ii/
 *
 * 2015/12/30
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int(*fptr)(int*, int);

int rob(int* nums, int numsSize) {
    int i, v1, v2, t;

    for (i = v1 = v2 = 0; i < numsSize; ++i) {
        t = v1 + nums[i];
        v1 = v2;
        if (t > v2) {
            v2 = t;
        }
    }   
    return v2;
}

int rob2(int* nums, int numsSize) {
    int i, v1, v2, t, m1, m2;
    if (numsSize == 1) {
        return nums[0];
    }
    for (v1 = v2 = i = 0; i < numsSize - 1; ++i) {
        t = v1 + nums[i];
        v1 = v2;
        if (t > v2) { v2 = t; }
    }
    for (m1 = m2 = 0, i = 1; i < numsSize; ++i) {
        t = m1 + nums[i];
        m1 = m2;
        if (t > m2) { m2 = t; }
    }
    return m2 > v2 ? m2 : v2;
}

int main(int argc, char **argv) {
    int i;
    fptr func;
    if (argc < 3) {
        printf("Rob <option> <number1> [number2] [...] [numberN]\n"\
            "<option> can be street or circle");
        return 0;
    }
    if (strcmp(argv[1], "street") == 0) {
        func = &rob;
    }
    else if (strcmp(argv[1], "circle") == 0) {
        func = &rob2;
    }
    else {
        printf("Invalid option %s", argv[1]);
        return 0;
    }
    int *a = (int *)malloc(sizeof(int) * (argc - 2));
    for (i = 0; i < argc - 2; ++i) {
        a[i] = atoi(argv[i + 2]);
    }
    printf("%d\n", func(a, argc-2));
    free(a);
    return 0;
}
