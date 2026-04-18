#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

void initializeBoard(int **board, int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard(int **board, int rows, int cols) {
    int i, j;

    printf("\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (board[i][j] == 0)
                printf(". ");
            else
                printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void freeBoard(int **board, int rows) {
    int i;

    for (i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);
}
