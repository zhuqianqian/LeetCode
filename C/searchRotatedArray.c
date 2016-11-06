/*
* https://leetcode.com/problems/search-in-rotated-sorted-array/
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
*
* You are given a target value to search. If found in the array return 
* its index, otherwise return -1.
* You may assume no duplicate exists in the array.
*
* 2015/12/24
*/

#include <stdio.h>


/* recursive solution */
int search(int* nums, int numsSize, int target) {
    int mid, x;
    if (numsSize < 1) {
        return -1;
    }
    mid = numsSize / 2;
    if (*(nums + mid) == target) {
        return mid;
    }
    if (*(nums + mid) > *nums) {
        if (target < *(nums + mid) && target >= *nums) {
            return search(nums, mid, target);
        }
        else {
            x = search(nums + mid + 1, numsSize - mid - 1, target);
            return x == -1 ? -1 : mid + x + 1;
        }
    }
    else {
        if(target > *(nums+mid) && target <= *(nums+numsSize-1)) {
            x = search(nums + mid + 1, numsSize - mid - 1, target);
            return x == -1 ? -1 : mid + x + 1;
        }
        else {
            return search(nums, mid, target);
        }
    }
}

/* non-recursive solution */
int search2(int* nums, int numsSize, int target) {
    int mid, left, right;
    left = 0; right = numsSize;
    while (left < right) {
        mid = (right + left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > nums[left]) {
            if (target >= nums[left] && target < nums[mid]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        else {
            if (target <= nums[right - 1] && target > nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
    }
    return -1;
}
