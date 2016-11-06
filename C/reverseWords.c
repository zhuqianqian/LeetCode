/*
* https://leetcode.com/problems/reverse-words-in-a-string/
* Given an input string, reverse the string word by word.
*
* For example,
* Given s = "the sky is blue",
* return "blue is sky the".
*
* 2015/12/28
*/

#include <stdio.h>
#include <string.h>

#define SWAP(a, b, t) {t = a; a = b; b = t;}

void reverseWords(char *s) {
    char *p, *h, *t, c;
    int i, additionalSpace = 0;
    h = s;
    t = strlen(s) + h-1;
    while (*t == ' ') *t-- = 0; /* Remove tailing space */
    while (t > h) { /* Reverse the whole string */
        SWAP(*t, *h, c);
        t--; h++;
    }
    t = strlen(s) + s - 1 ;
    while (*t == ' ') *t-- = 0; /* Remove tailing space, which was original leading space */
    h = s;
    while (*h) { /* reverse each word */
        t = h - additionalSpace;
        while (*h && *h!= ' ') h++;
        for (p = h - 1, i = 0; i < additionalSpace && p > t; i++) {
            *t++ = *p;
            *p-- = ' ';
        }
        for (; p > t; p--, t++) {
            SWAP(*p, *t, c);
        }
        if (*h) {
            h++;
            while (*h && *h == ' ') { additionalSpace++; h++; }
        }
    }
    h--;
    while (*h == ' ') *h-- = 0;
}

int main(int argc, char **argv) {
    char s[] = "   a   b  c d   e  ";
    reverseWords(s);
    printf("%s/\n", s);
    return 0;
}
