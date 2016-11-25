/**
 * https://leetcode.com/problems/find-the-difference/
 */

/* Same idea with Single Number */
char findTheDifference(char* s, char* t) {
    char ans = 0;
    while(*s) { ans ^= *s; s++; }
    while(*t) { ans ^= *t; t++; }
    return ans;
}