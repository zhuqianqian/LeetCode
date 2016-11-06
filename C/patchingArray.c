/**
 * https://leetcode.com/problems/patching-array/
 */

/**
 * Given the number at i, if array nums[0..i] can form 
 * any number from 1..X, there is no need to patch any
 * new element to form the numbers from 1..(X+num[i+1])
 * Given a number X, 1 <= X <= n, if sum(nums[0..i]) < X
 * and nums[i+1] > X, patch X and the patched array
 * would cover all the numbers up to sum(nums[0..i])+X.
 *
 * Need to consider overflow for the sum.
 */
int minPatches(int* nums, int numsSize, int n) {
    long long x;
    int patch, i;
    x = 0;
    i = patch = 0;
    do {
        if (i >= numsSize || nums[i] > (x + 1)) {
            patch++;
            x = x * 2 + 1;
        }
        else {
            x += nums[i++];
        }
    } while (x < n);
    return patch;
}

#include <stdio.h>
#include "utils/leetcode.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        return 0;
    }
    int* list = argv2Ints(argc - 2, argv + 2);
    printf("Patch: %d\n",
        minPatches(list, argc - 2, atoi(argv[1])));
    return 0;
}