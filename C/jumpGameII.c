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
    int ans = dp[0];
    free(dp);
    return ans;
}

int jumpOpt(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return 0;
    }
    int farthest = nums[0];
    int jump = 1;
    int farAt = nums[0];
    for (int i = 1; i < numsSize - 1; i++) {
        if (nums[i] + i > farthest) {
            farthest = nums[i] + i;
        }
        if (farAt == i) {
            jump++;
            farAt = farthest;
        }
    }
    return jump;
}