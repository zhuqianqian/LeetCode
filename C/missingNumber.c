/*
 * https://leetcode.com/problems/missing-number/
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
 * find the one that is missing from the array.
 *
 * 2015/12/31
 */

int missingNumber(int* nums, int numsSize) {
    int totalExpected = numsSize * (numsSize + 1) / 2;
    int totalActual = 0, i;
    for(i = 0; i < numsSize; ++i) {
        totalActual += nums[i];
    }
    return (totalExpected - totalActual);
}

/*
 * As the numers range from [0, n], it can be converted to another
 * problem: singleNumber, given an array of numers, where only one 
 * of them appears once while others twice, find that single one.
 * This problem can be solved by using XOR.
 **/
 int missingNumberXor(int *nums, int numsSize) {
     int ans, i;
     for(i = ans = 0; i < numsSize; ++i) {
         ans ^= i ^ nums[i];
     }
     return ans^i;
 }
