/**
 * https://leetcode.com/problems/perfect-squares/
 */

int numSquares(int n) {
    if(n <= 0) {
        return 0;
    }
    int *dp = (int*)malloc(sizeof(int)*(n+1));
    dp[0] = 0; dp[1] = 1;
    int i, min, j, k;
    for(i = 2; i <= n; i++) {
        min = INT_MAX;
        j = 1; k = j*j;
        while(i-k>=0) {
            if(dp[i-k]<min) min = dp[i-k];
            j++; k= j*j;
        }
        dp[i] = min+1;
    }
    min = dp[n];
    free(dp);
    return min;
}