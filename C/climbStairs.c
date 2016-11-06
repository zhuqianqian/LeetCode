int climbStairs(int n) {
    int i;
    int *dp = (int*)malloc(sizeof(int)*(n+1));
    for(i = 0; i < 3 && i <= n; i++) dp[i] = i;
    for(; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    i = dp[n];
    free(dp);
    return i;
}

int climbStairs(int n) {
    int i, nc, n1, n2;
    if(n < 3) {
        return n;
    }
    n1 = 2; n2 = 1;
    for(i = 3; i <= n; ++i) {
        nc = n1 + n2;
        n2 = n1; n1 = nc;
    }
    return nc;
}