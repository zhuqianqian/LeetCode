/**
 * https://leetcode.com/problems/integer-break/
 */

int integerBreak(int n) {
    int init[] = {0, 0, 1, 2, 4, 6, 9};
    int ans = 0;
    if(n < 7) {
        return init[n];
    }
    switch(n%3) {
        case 0: ans = pow(3, n/3); break;
        case 1: ans = pow(3, (n-4)/3)*4; break;
        case 2: ans = pow(3, (n-2)/3)*2; break;
    }
    return ans;
}