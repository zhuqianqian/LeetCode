/*
 * https://leetcode.com/problems/n-queens/
 * https://leetcode.com/problems/n-queens-ii/
 *
 * 2016/01/04
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nf;

/* Common methods that are used to facilitate memory 
 * allocation/free/copy
 */
char ** newBoard(int n) {
    int i;
    char **w;
    w = (char **)malloc(sizeof(char *) * n);
    for (i = 0; i < n; i++) {
        w[i] = (char *)malloc(sizeof(char) * (n+1));
        memset(w[i], '.', n * sizeof(char));
        w[i][n] = 0;
    }
    return w;
}

void freeBoard(char **w, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free(w[i]);
    }
    free(w);
}

char **copyBoard(char **board, int n) {
    int i;
    char **w;
    w = (char **)malloc(sizeof(char *) * n);
    for (i = 0; i < n; i++) {
        w[i] = (char *)malloc(sizeof(char) * (n + 1));
        strcpy(w[i], board[i]);
    }
    return w;
}
/* End of common methods */

/* Method 1 to problem 1, initial submit without recursion, looks ugly */
int canPutQueen(char **board, int r, int c, int n ) {    
    int i, j;
    for (i = 0; i < r; i++) {
        if (board[i][c] == 'Q') {
            return 0;
        }
    }
    for (i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return 0;
        }
    }
    for (i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return 0;
        }
    }
    return 1;
}

#define STACK_PUSH(sa,sb) {stackr[si] = (sa); stackc[si] = (sb); si++;}
#define STACK_POP(sa,sb) {si--; (sa) = stackr[si]; (sb) = stackc[si];}
#define STACK_PEEK(sa,sb) {(sa) = stackr[si-1]; (sb) = stackc[si-1];}

 /**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char*** solveNQueens(int n, int* returnSize) {
    int i, j, k;
    int stackr[1024];
    int stackc[1024];
    int si = 0;
    char *** result = NULL;
    *returnSize = 0;
    char **w = newBoard(n);

    w[0][0] = 'Q';
    k = 2;
    STACK_PUSH(0, 0);
    while (si > 0) {
        STACK_PEEK(i, j);
        for (i += 1, j = k; j < n; j++) {
            if (canPutQueen(w, i, j, n)) {
                w[i][j] = 'Q';
                if (i == (n - 1)) {
                    /* A complete solution found! */
                    *returnSize += 1;
                    result = (char ***)realloc(result, sizeof(char **) * *returnSize);
                    result[*returnSize - 1] = copyBoard(w, n);
                    k = j + 1;
                    w[i][j] = '.';
                }
                else {
                    STACK_PUSH(i, j);
                    k = 0;
                }
                break;
            }
        }
        if (j >= n) {
            STACK_POP(i, j);
            w[i][j] = '.';
            k = j + 1;
            if (i == 0 && k < n) {
                w[i][k] = 'Q';
                STACK_PUSH(i, k);
                k = 0;
            }
        }
    }
    if (n == 1) {
        *returnSize = 1;
        result = (char ***)malloc(sizeof(char**));
        w[0][0] = 'Q';
        result[0] = w;
    }
    else {
        freeBoard(w, n);
    }
    return result;
}
/* End of method 1 to problem 1 */

/**
* Method 2 to problem 1 with recursion, looks better except the
* arguments are too many unless the three flag arrays are declared
* as global variables...
*/
void solveRecursively(int r, char **board, int *returnSize,
    int *cf, int *ldf, int *rdf, int n, char ****result) {
    if (r == n) {
        *returnSize += 1;
        *result = (char ***)realloc(*result, sizeof(char **) * *returnSize);
        (*result)[*returnSize - 1] = copyBoard(board, n);
        return;
    }
    int c;
    for (c = 0; c < n; ++c) {
        if (cf[c] || ldf[n - 1 - r + c] || rdf[r + c]) { continue; }
        board[r][c] = 'Q';
        cf[c] = ldf[n - 1 - r + c] = rdf[r + c] = 1;
        solveRecursively(r + 1, board, returnSize, cf, ldf, rdf, n, result);
        board[r][c] = '.';
        cf[c] = ldf[n - 1 - r + c] = rdf[r + c] = 0;
    }
}

/**
* Return an array of arrays of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
char*** solveNQueensR(int n, int* returnSize) {
    char *** result = NULL;
    *returnSize = 0;
    char **w = newBoard(n);
    int cf[64] = { 0 },
        rdf[128] = { 0 },
        ldf[128] = { 0 };
    solveRecursively(0, w, returnSize, cf, ldf, rdf, n, &result);

    free(w);
    return result;
}
/* End of method 2 */

/* Method 3 */

void solveRecursivelyB(char ****result, char **board, int *returnSize, 
    int r, int n, int rf, int ld, int rd) {
    if (r == n) {
        *returnSize += 1;
        *result = (char ***)realloc(*result, sizeof(char **) * *returnSize);
        (*result)[*returnSize - 1] = copyBoard(board, n);
        return;
    }
    int pos, lgpos, pf;
    for (pf = nf & ~(rf | ld | rd); pf; pf &= pf - 1) {
        pos = pf & -pf;
        lgpos = __builtin_ctz(pos);
        board[r][lgpos] = 'Q';
        solveRecursivelyB(result, board, returnSize, r + 1, n,
            rf | pos, (ld | pos) << 1, (rd | pos) >> 1);
        board[r][lgpos] = '.';
    }
}
/**
* Return an array of arrays of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
char*** solveNQueensB(int n, int* returnSize) {
    char *** result = NULL;
    *returnSize = 0;
    char **w = newBoard(n);
    nf = (1 << n) - 1;
    solveRecursivelyB(&result, w, returnSize, 0, n, 0, 0, 0);
    free(w);
    return result;
}
/* End of method 3 */

/* n-queens-ii*/
void countNQueensB(int *count, int rf, int ld, int rd) {
    if (rf >= nf) {
        *count += 1; return;
    }
    int pos, pf;
    for (pf = nf & ~(rf | ld | rd); pf; pf &= pf - 1) {
        pos = pf & -pf;        
        countNQueensB(count, rf | pos, (ld | pos) << 1, (rd | pos) >> 1);
    }
}
int totalNQueens(int n) {
    int result = 0;
    nf = (1 << n) - 1;
    countNQueensB(&result, 0, 0, 0);
    return result;
}

typedef char ***(*fptr)(int, int *);
 
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("SolveNQueen [-option] <n>\noption can be b, r or s; s is used by default\n");
        return 0;
    }
    fptr func = solveNQueens;
    int n = 0;
    if(argc > 2) {
       n = atoi(argv[2]);
       if(!strcmp(argv[1], "-s")) { func = solveNQueens; }
       else if(!strcmp(argv[1], "-r")) { func = solveNQueensR; }
       else if(!strcmp(argv[1], "-b")) { func = solveNQueensB; }
       else if(!strcmp(argv[1], "-c")) { func = NULL; }
       else { printf("Invalid option %s, default -s is used.\n", argv[1]); }
    }
    else {
        n = atoi(argv[1]);
    }     
    int size, i;
    char **w;
    char *** result;
    if (func != NULL) {
        result = func(n, &size);
        printf("%d answers to %d Queens problem:\n", size, n);
        while (size > 0) {
            size--;
            w = result[size];
            printf("\n");
            for (i = 0; i < n; ++i) {
                printf("%s\n", w[i]);
                free(w[i]);
            }
            free(w);
        }
        free(result);
    }
    else {
        printf("Total solutions to %d queens: %d", n, totalNQueens(n));
    }
}
