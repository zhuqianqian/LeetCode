/*
 * https://leetcode.com/problems/ugly-number/
 * https://leetcode.com/problems/ugly-number-ii/
 */
 
bool isUgly(int num) {
    if(num <= 0) {
        return false;
    }
    while(num != 1) {
        if(num % 2 == 0) { num /= 2; }
        else if(num % 3 ==0 ) {num /= 3;}
        else if(num %5 == 0) {num /= 5;}
        else {
            return false;
        }
    }
    return true;
}

/* Ugly Number II */

int min(int a, int b, int c) {
    if (a < b) {
        if (a < c) return a;
        return c;
    }
    if (b > c) return c;
    return b;
}

int nthUglyNumber(int n) {
    if (n < 0) return 0;
    int* ugly = (int*)malloc(sizeof(int)*(n + 1));
    ugly[1] = 1;
    int i, ans;
    int x[3] = { 1,1,1 };
    int n2 = 2, n3 = 3, n5 = 5;
    for (i = 2; i <= n; i++) {
        ugly[i] = min(n2, n3, n5);
        if (ugly[i] == n2) n2 = ugly[++x[0]] * 2;
        if (ugly[i] == n3) n3 = ugly[++x[1]] * 3;
        if (ugly[i] == n5) n5 = ugly[++x[2]] * 5;
    }
    ans = ugly[n];
    free(ugly);
    return ans;
}