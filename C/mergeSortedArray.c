/**
 * https://leetcode.com/problems/merge-sorted-array/
 */ 
void merge(int* nums1, int m, int* nums2, int n) {
    int*w, *p1, *p2;
    w = nums1 + m + n - 1;
    p1 = nums1 + m - 1;
    p2 = nums2 + n - 1;
    while(p1 >= nums1 && p2 >= nums2) {
        if(*p1 > *p2) {
            *w = *p1;
            p1--;
        }
        else {
            *w = *p2;
            p2--;
        }
        w--;
    }
    if(p1 < nums1) {
        memcpy(nums1, nums2, sizeof(int)*(p2-nums2+1));
    }
}