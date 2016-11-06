/*
* https://leetcode.com/problems/sort-colors/
*
* 2016/01/09
*/

#include <stdio.h>
#include <stdlib.h>

void sortColors(int* nums, int numsSize) {
    int c[3] = { 0 }, i;
    for (i = 0; i < numsSize; (c[nums[i++]])++);
    for (i = 0; i < c[0]; nums[i++] = 0);
    for (c[1]+=c[0]; i < c[1]; nums[i++] = 1);
    for (c[2]+=c[1]; i < c[2]; nums[i++] = 2);
}

void sortColors2(int* nums, int numsSize) {
    int bg, en, i;
    for (bg = i = 0, en = numsSize - 1; i <= en; ++i) {
        if (nums[i] == 0) { nums[bg] = 0; nums[i] = nums[bg++]; }
        else if (nums[i] == 2) { nums[i--] = nums[en]; nums[en--] = 2; }
    }
}

int main(int argc, char **argv) {
    int i;
    if (argc < 2) {
        printf("sortColor <color1> [color2] [...] [colorN]\n");
        return 0;
    }

    int *a = (int *)malloc(sizeof(int) * (argc - 1));
    for (i = 0; i < argc - 1; ++i) {
        a[i] = atoi(argv[i + 1]);
    }
    sortColors2(a, argc - 1);
    for (i = 0; i < argc - 1; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    free(a);
    return 0;
}