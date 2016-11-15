/*
 * https://leetcode.com/problems/next-permutation/
 */

void nextPermutation(int* nums, int numsSize) {
    int* p = nums + numsSize - 1;
    int* end = p;
    int temp;
    while(p > nums && x <= *(p-1)) {
        if(*p <= *(p-1)) {break;}
    }
    int* w = p;
    w = p-1;
    if(p > nums) {
        while(1) {
            if(*p > *w) {break;}
            p++;
        }
        temp = *w; *w = *p; *p = temp;
    }
}