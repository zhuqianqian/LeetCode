/**
 * https://leetcode.com/problems/excel-sheet-column-number/
 * https://leetcode.com/problems/excel-sheet-column-title/
 */

int titleToNumber(char* s) {
    int ans = 0;
    while (*s) {
        ans = 26 * ans + (*s - 64);
        s++;
    }
    return ans;
}

/**
 * The largest 32-bit unsigned integer can at most occupies 7
 * letters. So a 8 long char array is large enough to hold the
 * data, including the trailing 0.
 */
char slots[8];
char* convertToTitle(int n) {
    slots[7] = 0;
    char *s = slots + 7;
    while (n>0) {
        s--; n--;
        *s = n % 26 + 'A';
        n = n / 26;
    }
    return s;
}