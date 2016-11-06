#include <string.h>
#include <stdlib.h>

/**
 * 16ms for 88 cases on Leetcode.
 */
int findPalindrome(char* s, char* b, char* f, char** l, char** r, int len) {
    int t;
    while (*f && f >= s && *b == *f) { b--; f++; }
    t = f - b - 1;
    if (t > len) {
        *l = b + 1;
        *r = f - 1;
    }
    else t = len;
    return t;
}
char* longestPalindrome(char* s) {
    int max = 0, t;
    char* ml, *mr, *p, *q;
    p = ml = mr = s;
    while (*p) {
        q = p + 1;
        if (*q && (*q == *p || *q == *(p-1))) {
            if (*q == *p) {
                max = findPalindrome(s, p, p+1, &ml, &mr, max);
            }
            if (*q == *(p - 1)) { 
                max = findPalindrome(s, p-1, p+1, &ml, &mr, max);
            }
        }
        p++;
    }
    p = (char*)malloc(sizeof(char)*(max + 1));
    for (q = p; ml <= mr; ) {
        *q++ = *ml++;
    }
    *q = 0;
    return p;
}

#include <stdio.h>

int main(int argc, char** argv) {
    char* r = longestPalindrome(argv[1]);
    printf("Longest Palindomic Substring is: %s\n", r);
    free(r);
    return 0;
}

