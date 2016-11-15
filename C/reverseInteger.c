/*
 * https://leetcode.com/problems/reverse-integer/
 */

int reverse(int x) {
    long re = 0;
    while(x) {
        re = re*10 + x%10;
        x/=10;
    }
    return re <= INT_MAX && re >= INT_MIN ? re : 0;
}