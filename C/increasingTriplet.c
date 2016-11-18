/**
* https://leetcode.com/problems/increasing-triplet-subsequence/
*/

bool increasingTriplet(int* nums, int numsSize) {
    int first, second, i;
    first = second = INT_MAX;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] <= first) { first = nums[i]; }
        else if (nums[i] <= second) { second = nums[i]; }
        else { return true; }
    }
    return false;
}