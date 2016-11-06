/**
 * https://leetcode.com/problems/string-to-integer-atoi/
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

/* Passed on Leetcode (4ms/1047 cases), but it may fail
 * to meet the requirement for outputing INT_MAX/INT_MIN
 * in case of overflow. Reason is the length of long may
 * the same as int.
 */
int myAtoi(char* str) {
    long v;
    int sign;
    v = 0; sign = 1;
    while (*str && *str <= ' ') str++;
    if (*str && *str == '+' || *str == '-') {
        sign = *str == '+' ? 1 : -1;
        str++;
    }
    while (*str && *str <= '9' && *str >= '0') {
        v = v * 10 + *str++ - '0';
        if (v > INT_MAX) {
            return sign > 0 ? INT_MAX : INT_MIN;
        }
    }
    return v * sign;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        printf("%d = %d\n", atoi(argv[1]), myAtoi(argv[1]));
        return 0;
    }
}