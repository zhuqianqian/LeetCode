/**
 * https://leetcode.com/problems/maximal-square/
 */
 
int min(int a, int b, int c) {
    if(a < b) {
        return  a < c ? a : c;
    }
    return b < c ? b : c;
}

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    int *dp, i, j, ans;
    int x,y,z;
    ans = INT_MIN;
    if(matrixRowSize > 0 && matrixColSize > 0) {
        dp = (int*)malloc(sizeof(int)*matrixRowSize * matrixColSize);
        for(i = 0; i < matrixColSize; i++) {
            if(matrix[0][i] == '1') { ans = dp[i] = 1;  }
            else dp[i] = 0;
        }
        for(i = 1; i < matrixRowSize; i++) {
            if(matrix[i][0] == '1') { ans = dp[i*matrixColSize] = 1; }
            else dp[i*matrixColSize] = 0;
        }
        for(i = 1; i < matrixRowSize; i++) {
            for(j = 1; j < matrixColSize; j++) {
                x = dp[(i-1)*matrixColSize + j-1];
                y = dp[i*matrixColSize + j - 1];
                z = dp[(i - 1)*matrixColSize + j];
                if(matrix[i][j] == '1') {
                    x = dp[i*matrixColSize + j] = 1 + min(x,y,z);
                    if(x > ans) { ans = x; }
                }
                else { dp[i*matrixColSize + j] = 0; }
            }
        }
    }
    return ans > 0 ? ans*ans : 0;
}