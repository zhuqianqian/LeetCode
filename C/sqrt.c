/**
 * https://leetcode.com/problems/sqrtx/
 */

int mySqrt(int x) {
    long long low = 1, high = 1 + x / 2;
    long long mid;
    if (x <= 0) return x;
    do {
        mid = (low + high) / 2;
        if( mid * mid == x){ low = mid; break; }
        else if (mid * mid > x) { high = mid; }
        else { low = mid; }
    } while (high - low > 1);
    return low;
}

#include <stdio.h>
#include <string.h>
int main(int argc, char** argv) {
    if (argc > 1) {
        printf("sqrt(%d)=%d", atoi(argv[1]), mySqrt(atoi(argv[1])));
    }
    return 0;
}