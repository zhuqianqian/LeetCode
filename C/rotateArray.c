/*
* https://leetcode.com/problems/reverse-bits/
* Reverse bits of a given 32 bits unsigned integer.
* 2015/03/20
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Most straigt forward way, Space: O(n), Time: O(2n)*/
/* 10ms for 33 cases */
void rotate_copy(int nums[], int n, int k) {
    int r = k % n;
    int *copy = malloc(sizeof(int)*(n - r));
    int i = 0;
    int j = 0;
    while (i < n - r) {
        copy[i] = nums[i++];
    }
    for (i = n - r; i < n; ++i) {
        nums[j++] = nums[i];
    }
    for (i = 0; i < n - r; ++i) {
        nums[j++] = copy[i];
    }
    free(copy);
}

/* Repeatedly shift 1 position, Space: O(1), Time: O((k%n)n) */
/* Time: exceed limit on leetcode for one case */
void rotate_repeat(int nums[], int n, int k) {
    int i, j;
    int temp;
    int r = k % n;;
    for (i = 0; i < r; ++i) {
        temp = nums[n - 1];
        for (j = n - 1; j > 0; j--) {
            nums[j] = nums[j - 1];
        }
        nums[0] = temp;
    }
}

/* Carefully traverse the array to match the positions after rotate. */
/* Space: O(1), Time: O(n) */
/* 10ms for 33 cases*/
void rotate_traverse(int nums[], int n, int k) {
    int r = k % n;
    int head, curr, next, p, q;
    if (r) {
        p = n; q = r;
        while (p %= q ^= p ^= q ^= p); // get gcd of n and r.
        int loops = q;
        for (int i = 0; i < loops; ++i) {
            curr = i;
            head = nums[curr];
            next = n - r + i;
            while (next != i) {
                nums[curr] = nums[next];
                curr = next;
                next = next >= r ? next - r : next - r + n;
            }
            nums[curr] = head;
        }
    }
}


/* Test */
int main(int argc, char ** argv) {
    int nums[] = { 1, 2, 3, 4, 5, 6 };
    rotate_traverse(nums, 6, 4);
    for (int i = 0; i < 6; ++i) {
        printf(" %d ", nums[i]);
    }
    return 0;
}