/***
 * https://leetcode.com/problems/remove-element/
 */

int removeElement(int* nums, int numsSize, int val) {
    int retSize = numsSize;
    int* end = nums + retSize - 1;
    while (end >= nums) {
        if (*end == val) { 
            retSize--; end--; continue;
        }
        if (*nums == val) {
            *nums = *end;
            end--;
            retSize--;
        }
        nums++; 
    }
    return retSize;
}
