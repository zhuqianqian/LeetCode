/*
 *https://leetcode.com/problems/maximum-subarray/
 *https://leetcode.com/problems/maximum-product-subarray/
 *
 * 2015/12/29
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int(*fptr)(int*, int);

int maxSubArray(int *nums, int numsSize) {
    int s, t, i;
    s = INT_MIN;
    t = 0;
    for (i = 0; i < numsSize; ++i) {
        if (t < 0) { t = 0; }
        t += nums[i];
        s = s > t ? s : t;
    }
    return s;
}

int maxProduct(int* nums, int numsSize)
{
    int s = INT_MIN;
    int h, t, i, max;
    h = t = 1;
    for (i = 0; i < numsSize; ++i) {
        h *= nums[i];
        t *= nums[numsSize - i - 1];
        max = h > t ? h : t;
        if (!h) { h = 1; }
        if (!t) { t = 1; }
        s = max > s ? max : s;
    }
    return s;
}

int main(int argc, char **argv) {
    int i;
    fptr func;
    if (argc < 3) {
        printf("maxSubArray <option> <number1> [number2] [...] [numberN]\n"\
            "<option> can be product or sum");
        return 0;
    }
    if (strcmp(argv[1], "product") == 0) {
        func = &maxProduct;
    }
    else if (strcmp(argv[1], "sum") == 0) {
        func = &maxSubArray;
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
