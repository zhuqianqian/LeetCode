/*
 * https://leetcode.com/problems/rotate-image/
 */

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    //assert(matrixRowSize==matrixColSize);
    int n = matrixRowSize-1;
    int i, j, t;
    for(i = 0; i < matrixRowSize/2; i++) {
        for(j = i; j < n-i; j++) {
            t = matrix[i][j];
            matrix[i][j] = matrix[n-j][i];
            matrix[n-j][i] = matrix[n-i][n-j];
            matrix[n-i][n-j] = matrix[j][n-i];
            matrix[j][n-i] = t;
        }
    }
}