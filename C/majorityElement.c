/**
 * https://leetcode.com/problems/majority-element/
 */
 
 /**
  * Count bit solution
  * */
int majorityElement(int* nums, int numsSize) {
    int ans = 0;
    int cnt, i, j, mask;
    for(i = 0; i < 32; i++) {
        cnt = 0;
        mask = 1 << i;
        for(j = 0; j < numsSize; j++) {
            if(nums[j]&mask) {
                cnt++;
            }
        }
        if(cnt > numsSize / 2) {
            ans |= mask;
        }
    }
    return ans;
}