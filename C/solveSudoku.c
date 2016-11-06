/*
 * https://leetcode.com/problems/sudoku-solver/
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution.
 *
 * 2015/12/21
 */
 
#include <stdio.h>

int stacki[81];
int stackj[81];

int si = 0;

#define STACK_PUSH(sa,sb) {stacki[si] = (sa); stackj[si] = (sb); si++;}
#define STACK_POP(sa,sb) {si--; (sa) = stacki[si]; (sb) = stackj[si];}

int check(char **board, int row, int column, int boardRowSize, int boardColSize) {
    char x = board[row][column];
    int i,j;
    int cord[][3] = { {0, 1 ,2}, {-1,0,1}, {-2,-1,0} };
    if (x == '.') {
        return 0;
    }
    for (i = 0; i < boardColSize; i++) {
        if (board[row][i] == x && i != column) {
            return 0;
        }
    }
    for (i = 0; i < boardRowSize; i++) {
        if(board[i][column] == x && i != row) {
            return 0;
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[row + cord[row % 3][i]][column + cord[column % 3][j]] == x &&
                cord[row % 3][i] != 0 && cord[column % 3][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

/* DFS algorithm*/
void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    int i, j; 
    int back = 0;
    si = 0;
    
    for (i = 0; i < boardRowSize;) {
        for (j = 0; j < boardColSize;) {
            if (board[i][j] != '.' && !back) {
                back = 0;
                j++; continue;
            }
            else {
                STACK_PUSH(i, j);
                board[i][j] = board[i][j] == '.' ? '1' : board[i][j] + 1;
                if (board[i][j] > '9') {
                    board[i][j] = '.';
                    STACK_POP(i, j);
                }
                if (!check(board, i, j, boardRowSize, boardColSize)) {
                    back = 1;
                    STACK_POP(i, j);
                }
                else { j++; back = 0; }
            }
        }
        if (j == boardColSize) { i++; }
    }
}

/* Maybe a human like algorithm*/
void solveSudokuAI(char ** board, int boardRowSize, int boardColSize) {

}

int main(int argc, char ** argv) {
    int i;
    if (argc != 10) {
        printf("Solve Sudoku <line1> <line2> ... <line9>\n");
        return 0;
    }
    solveSudoku(argv+1, 9, 9);
    for (i = 1; i < 10; ++i) {
        printf("%s\n", *(argv+i));
    }
}
