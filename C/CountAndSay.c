/*
 * https://leetcode.com/problems/count-and-say/
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...

 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * 2015/12/20
 */
 
#include <stdio.h>
#include <string.h>

/* A C solution, but the input can not be larger than 25, otherwise, the
 * static allocated string cannot hold the data. Maybe C++/Java/Python 
 * are better choices unless I dynamically allocate the memory for storing
 * the string here.
 */
char str_1[1000] = { 0 };
char str_2[1000] = { 0 };

char* countAndSay(int n) {
    int i, count;
    char *p, *q, *s1, *s2, *t;
    memset(str_1, 0, 1000);
    memset(str_2, 0, 1000);
    str_1[0] = '1';
    s1 = str_1; s2 = str_2;
    
    for (i = 1; i < n; ++i) {        
        for (p = s1 + 1, q = s2, count = 1; *p; p++) {
            if (*p == *(p - 1)) {
                count++;
            }
            else {
                *q++ = '0' + count;
                *q++ = *(p - 1);
                count = 1;
            }
        }
        *q++ = '0' + count;
        *q++ = *(p - 1);
        t = s1, s1 = s2; s2 = t;
        memset(s2, 0, 1000);
    }
    return s1;
}
