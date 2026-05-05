#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

int **createBoard(void) {
    int **board = malloc(SIZE * sizeof(int *));

    if (board == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i < SIZE; i++) {
        board[i] = malloc(SIZE * sizeof(int));

        if (board[i] == NULL) {
            printf("Memory allocation failed.\n");

            for (int j = 0; j < i; j++) {
                free(board[j]);
            }

            free(board);
            return NULL;
        }
    }

    return board;
}

void freeBoard(int **board) {
    if (board == NULL) {
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        free(board[i]);
    }

    free(board);
}

void copyBoard(int **dest, int **src) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

void printBoard(int **board) {
    printf("\n");
    printf("    0 1 2   3 4 5   6 7 8\n");
    printf("  +-------+-------+-------+\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d | ", i);

        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                printf(". ");
            } else {
                printf("%d ", board[i][j]);
            }

            if ((j + 1) % 3 == 0) {
                printf("| ");
            }
        }

        printf("\n");

        if ((i + 1) % 3 == 0) {
            printf("  +-------+-------+-------+\n");
        }
    }
}

int isBoardFull(int **board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int isValidMove(int **board, int row, int col, int value) {
    int boxRow;
    int boxCol;

    // Check row
    for (int j = 0; j < SIZE; j++) {
        if (board[row][j] == value) {
            return 0;
        }
    }

    // Check column
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == value) {
            return 0;
        }
    }

    // Find top-left corner of the 3x3 box
    boxRow = row - row % 3;
    boxCol = col - col % 3;

    // Check 3x3 box
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (board[i][j] == value) {
                return 0;
            }
        }
    }

    return 1;
}
