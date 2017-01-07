/**
 * https://leetcode.com/problems/spiral-matrix/
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