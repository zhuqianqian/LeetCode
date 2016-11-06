/*
 * https://leetcode.com/problems/reverse-bits/
 * Reverse bits of a given 32 bits unsigned integer.
 * 2015/03/19
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Submit on LeetCode Begin */
/* 4ms */
uint32_t reverseBits_std(uint32_t n) {
    uint32_t result = 0;
    int i;
    for (i = 0; i < 32; i++)
    {
        if ((n & (1 << i)))
            result |= 1 << (31 - i);
    }
    return result;
}

/* Optimized solution: 3ms */
uint32_t reverseBits_fast(uint32_t n) {
    uint32_t result = 0;
    uint32_t masks[] =
      { 0x00000001, 0x00000002, 0x00000004, 0x00000008,
        0x00000010, 0x00000020, 0x00000040, 0x00000080,
        0x00000100, 0x00000200, 0x00000400, 0x00000800,
        0x00001000, 0x00002000, 0x00004000, 0x00008000,
        0x00010000, 0x00020000, 0x00040000, 0x00080000,
        0x00100000, 0x00200000, 0x00400000, 0x00800000,
        0x01000000, 0x02000000, 0x04000000, 0x08000000,
        0x10000000, 0x20000000, 0x40000000, 0x80000000 };
    int i;
    for (i = 0; i < 32; i++)
    {
        if ((n & masks[i]))
            result |= masks[31-i];
    }
    return result;
}

/* Test */
int main(int argc, char ** argv) {
    if (argc < 2) {
        printf("reverseBits <integer>\n");
        return 0;
    }
    uint32_t n = atoi(argv[1]);    
    printf("reverseBits of %u is %u.\n", n, reverseBits_std(n));
    printf("reverseBits of %u is %u.\n", n, reverseBits_fast(n));
    return 0;
}