/**
 * https://leetcode.com/problems/container-with-most-water/
 */

#include <stdio.h>
#include <stdlib.h>
#include "utils/leetcode.h"

/**
 * A most direct way, time out.
 */
int maxAreaStraight(int* height, int heightSize) {
    int area = 0;
    int i, j, temp;
    for (i = 0; i < heightSize; i++) {
        for (j = i + 1; j < heightSize; j++) {
            temp = (j - i) * (height[i] > height[j] ? height[j] : height[i]);
            if (temp > area) area = temp;
        }
    }
    return area;
}

int maxArea(int* height, int heightSize) {
    int* r = height + heightSize-1;
    int area = 0, t;
    while (--heightSize) {
        if (*r > *height) {
            t = heightSize * *height++;
        }
        else {
            t = heightSize * *r--;
        }
        if (t > area) area = t;
    }
    return area;
}

int main(int argc, char** argv) {
    int* heights = argv2Ints(argc - 1, argv + 1);
    printf("Result: %d\n", maxArea(heights, argc - 1));
    free(heights);
    return 0;
}

