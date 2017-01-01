/**
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* result = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
    int idx1, idx2;
    for(idx1 = 0, idx2 = numbersSize - 1; idx1 < idx2;) {
        if((numbers[idx1] + numbers[idx2]) > target) {
            idx2--;
        }
        else if((numbers[idx1] + numbers[idx2]) < target) {
            idx1++;
        }
        else {break;}
    }
    result[0] = idx1+1;
    result[1] = idx2+1;
    return result;
}