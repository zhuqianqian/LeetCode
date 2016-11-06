/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Given a string, find the length of the longest substring
 * without repeating characters. For example, the longest
 * substring without repeating letters for "abcabcbb" is "abc", 
 * which the length is 3. For "bbbbb" the longest substring
 * is "b", with the length of 1.
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int lengthOfLongestSubstring(char* s) {
    char* hash[128] = { NULL };
    int len = 0, max = INT_MIN;
    char *w;
    while (*s) {
        if (hash[*s] != NULL) {
            if (len > max) { max = len; }
            w = s - len;
            while (w < hash[*s]) { hash[*w] = NULL; w++; }
            len = s - hash[*s];
            hash[*s] = s;
        }
        else {
            hash[*s] = s; len++;
        }
        s++;
    }
    if (max < len) max = len;
    return max;
}

int lengthOfLongestSubstring2(char *s) {
    char *hash[128] = { NULL };
    int len = 0;
    char *end;
    for (end = s; *end; end++) {
        if (hash[*end] != NULL) {
            if (end - s > len) { len = end - s; }
            if (s <= hash[*end]) { s = hash[*end] + 1; }
        }
        hash[*end] = end;
    }
    return end - s > len ? end - s : len;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 0;
    }
    printf("%d\n", lengthOfLongestSubstring2(argv[1]));
    return 0;
}