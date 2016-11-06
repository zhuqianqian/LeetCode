/*
* https://leetcode.com/problems/move-zeroes/
* Given an array nums, write a function to move all 0's to the
* end of it while maintaining the relative order of the non-zero
* elements.
*
* For example, given nums = [0, 1, 0, 3, 12], after calling your
* function, nums should be [1, 3, 12, 0, 0].
*
* Note:
* You must do this in-place without making a copy of the array.
* Minimize the total number of operations.
* 
* 2015/12/24
*/

#include <stdio.h>
#include <stdlib.h>


void moveZeroes(int* nums, int numsSize) {
    int zeroAt, i, temp;
    for (i = zeroAt = 0; i < numsSize; i++) {
        if (*(nums + i)) {
            if(i!=zeroAt) {
                temp = *(nums + i);
                *(nums + i) = *(nums + zeroAt);
                *(nums + zeroAt) = temp;
            }
            zeroAt++;
        }
    }
}
