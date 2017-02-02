/**
 * https://leetcode.com/problems/spiral-matrix/
 * https://leetcode.com/problems/spiral-matrix-ii/
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int* result = NULL;
    int total = matrixColSize * matrixRowSize;
    if (total > 0) {
        result = (int*)malloc(sizeof(int)*total);
        int i, j=0;
        int is, ie, js, je;
        is = 0; js = 0;
        je = matrixColSize - 1; ie = matrixRowSize - 1;
        while (j < total) {
            for (i = js; i <= je && j < total; i++) { result[j++] = matrix[is][i]; }
            for (i = is + 1; i <= ie && j < total; i++) { result[j++] = matrix[i][je]; }
            for (i = je - 1; i >= js && j < total; i--) { result[j++] = matrix[ie][i]; }
            for (i = ie - 1; i > is && j < total; i--) { result[j++] = matrix[i][js]; }
            is++; js++; ie--; je--;
        }
    }
    return result;
}

/**
* Return an array of arrays.
* Note: The returned array must be malloced, assume caller calls free().
*/
int** generateMatrix(int n) {
    int **result = (int**)malloc(sizeof(int*)*n);
    int i, k;
    for (i = 0; i < n; i++) {
        result[i] = (int*)malloc(sizeof(int)*n);
    }
    int start, end;
    k = 1; start = 0; end = n-1;
    while (k <= n*n) {
        for (i = start; i <= end; i++) { result[start][i] = k++; }
        for (i = start+1; i <= end; i++) { result[i][end] = k++; }
        for (i = end-1; i >= start; i--) { result[end][i] = k++; }
        for (i = end-1; i > start; i--) { result[i][start] = k++; }
        start++; end--;
    }
    return result;
}