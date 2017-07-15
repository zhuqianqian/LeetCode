/**
*https://leetcode.com/problems/jump-game
*/

bool canJump(int* nums, int numsSize) {
    int farthest = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] + i) > farthest) {
            farthest = (nums[i] + i);
        }
        if (nums[i] == 0 && farthest <= i) {
            break;
        }
    }
    return farthest >= (numsSize - 1);
}