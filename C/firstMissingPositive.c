/*
 * https://leetcode.com/problems/first-missing-positive/
 */

/**
 * Suppose the N distinct numbers range from 1 to N
 * The sum should be N*(1+N)/2. Whenever a number is
 * out of the range (0,N], substract N from the sum 
 * and decrease N by 1 since now only N-1 numbers
 * could possibly fit in range (1, N). Otherwise,
 * just subtract the number from sum. Repeat until
 * the sum is less than 1, (sum+N) is the first 
 * missing number if it's positive, otherwise, 1 is.
 * 
 * Why? I just thought of this when I was in a meeting
 * and I will prove it later.
 */

/* the quiz does not say distinct numbers, so this
 * only works when nums contains distint numbers 
 */
int firstMissingPositive(int* nums, int numsSize) {
    int sum = numsSize * (numsSize + 1) / 2;
    int i = 0, 
        n = numsSize+1;
    while( i < numsSize) {
        if (*(nums + i) < n && *(nums + i) > 0) {
            sum -= *(nums + i);
        }
        else {
            n--;
            sum -= n;            
        }
        i++;
    }
    n += sum;
    return n > 0 ? n : 1;
}

/*
 */

#include "utils\leetcode.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int* nums = argv2Ints(argc-1, argv+1);
    printf("First Missing Positive Number: %d\n", 
        firstMissingPositive(nums, argc - 1));
    free(nums);
    return 0;
}