/**
 * https://leetcode.com/problems/factorial-trailing-zeroes/
 */
int trailingZeroes(int n) {
    int result;
    long x, powerFive = 5;
    for(result = 0, x = n/powerFive; x > 0; ) {
        result += x;
        powerFive *= 5;
        x = n/powerFive;
    }
    return result;
}