/*
 * https://leetcode.com/problems/minimum-path-sum/
 */
 
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int *dp = (int*)malloc(sizeof(int)*gridRowSize*gridColSize);
    memset(dp, 0, gridRowSize*gridColSize*sizeof(int));
    int i, j;
    dp[0]=**grid;
    for(i = 1; i < gridRowSize; i++) {
        dp[gridColSize*i] = dp[gridColSize*(i-1)] + grid[i][0];
    }
    for(j = 1; j < gridColSize; j++) {
        dp[j] = dp[j-1] + grid[0][j];
    }
    for(i = 1; i < gridRowSize; i++) {
        for(j = 1; j < gridColSize; j++) {
            dp[i*gridColSize + j] = grid[i][j] + (dp[(i-1)*gridColSize + j] > dp[gridColSize*i+j-1] ? 
            dp[gridColSize*i+j-1] : dp[(i-1)*gridColSize + j]);
        }
    }
    int re = dp[gridRowSize*gridColSize-1]
    free(dp);
    return re;
}