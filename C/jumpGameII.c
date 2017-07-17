/**
* https://leetcode.com/problems/jump-game-ii
*/

int jump(int* nums, int numsSize) {
    if (numsSize < 1) {
        return 0;
    }
    int *dp = (int*)malloc(sizeof(int)*numsSize);
    dp[numsSize - 1] = 0;
    for (int i = numsSize - 2; i >= 0; i--) {
        dp[i] = INT_MAX - 1;
        for (int j = 1; j <= nums[i] && (i + j) < numsSize; j++) {
            if ((1 + dp[i + j]) < dp[i]) {
                dp[i] = 1 + dp[i + j];
            }
        }
    }
    return dp[0];
}