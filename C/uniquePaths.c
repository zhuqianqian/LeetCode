/*
 * https://leetcode.com/problems/unique-paths/
 * https://leetcode.com/problems/unique-paths-ii/
 *
 * 2016/01/02
 */

#include <stdio.h>

#define M (101)
#define N (101)

/* Recursive solution, very slow of course. */
int uniquePathsR(int m, int n) {
    if (m == 1 || n == 1) {
        return 1;
    }
    return uniquePathsR(m - 1, n) + uniquePathsR(m, n - 1);
}

int uniquePaths(int m, int n) {
    int paths[M][N] = { 0 };
    int i, j;
    paths[0][1] = 1;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {         
            paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
        }
    }
    return paths[m][n];
}

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, 
    int obstacleGridColSize) {
    int paths[M][N] = { 0 };
    int i, j, f;
    paths[0][1] = !(obstacleGrid[0][0]);
    for (i = 1; i <= obstacleGridRowSize; i++) {
        for (j = 1; j <= obstacleGridColSize; j++) {
            if (obstacleGrid[i-1][j-1] == 1) {
                paths[i][j] = 0;
            }
            else {
                paths[i][j] = paths[i][j - 1] + paths[i - 1][j];
            }
        }
    }
    return paths[obstacleGridRowSize][obstacleGridColSize];
}

/* Faster way, the algorithm is the same though. The only difference is this 
 * method would process the initial status more quickly...
 */
int uniquePathsWithObstaclesF(int** obstacleGrid, int obstacleGridRowSize, 
    int obstacleGridColSize) {
    int paths[M][N] = { 0 };
    int i, j, f;
    for (i = 0; i < obstacleGridRowSize; ++i) {
        paths[i][0] = !(obstacleGrid[i][0]);
        if (obstacleGrid[i][0]) { break; }
    }
    for (i = 0; i < obstacleGridColSize; ++i) {
        paths[0][i] = !(obstacleGrid[0][i]);
        if (obstacleGrid[0][i]) { break; }
    }

    for (i = 1; i < obstacleGridRowSize; i++) {
        for (j = 1; j < obstacleGridColSize; j++) {
            if (obstacleGrid[i][j] == 1) {
                paths[i][j] = 0;
            }
            else {
                paths[i][j] = paths[i][j - 1] + paths[i - 1][j];
            }
        }
    }
    return obstacleGridRowSize && obstacleGridColSize ?
        paths[obstacleGridRowSize - 1][obstacleGridColSize - 1] : 0;
}
