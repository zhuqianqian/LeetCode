/**
 * https://leetcode.com/problems/island-perimeter/ 
 */
 
int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int i, j, ans = 0;
    if(gridRowSize > 0 && gridColSize > 0) {
        ans = grid[0][0] * 4;
        for(i = 1; i < gridColSize; i++) {
            if(grid[0][i] == 1) { ans += 4 - grid[0][i-1] * 2;}
        }
        for(i = 1; i < gridRowSize; i++) {
            if(grid[i][0] == 1) { ans += 4 - grid[i-1][0] * 2;}
        }
        for(i = 1; i < gridRowSize; i++) {
            for(j = 1; j < gridColSize; j++) {
                if(grid[i][j] == 1) {
                    ans += 4 - (grid[i-1][j]+grid[i][j-1]) * 2;
                }
            }
        }
    }
    return ans;
}