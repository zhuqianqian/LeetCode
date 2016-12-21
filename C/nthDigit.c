/**
 * https://leetcode.com/problems/nth-digit/
 */
int findNthDigit(int n) {
    long step[] = { 0, 9, 180, 2700, 36000, 450000, 5400000, 63000000, 720000000, 8100000000, 90000000000 };
    int digits[] = { 0,1,2,3,4,5,6,7,8,9,10};
    int tens[] = { 0, 1, 10, 100, 1000,10000,100000,1000000,10000000,100000000,1000000000 };
    char str[12];
    int i;
    long nn = n;
    for (i = 1; nn > 0; i++) { nn -= step[i]; }
    i--;
    n = nn+step[i];
    n--;
    sprintf(str, "%d", n / digits[i] + tens[i]);
    return (int)(str[n%digits[i]]-'0');
}