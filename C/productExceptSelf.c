/**
 * https://leetcode.com/problems/product-of-array-except-self/
 */ 

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* result;
    *returnSize = numsSize;
    if(numsSize > 0) {
        int i, r;
        result = (int*)malloc(sizeof(int)*numsSize);
        result[0] = 1;
        for(i = 1; i < numsSize; i++) {
            result[i] = result[i-1] * nums[i-1];
        }
        r = 1;
        for(i = numsSize-2; i >= 0; i--) {
            r *= nums[i+1];
            result[i] *= r;
        }
    }
    return result;
}