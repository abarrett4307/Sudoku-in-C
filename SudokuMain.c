//Justin Li
//Abigail Yun
//Tony Barret
//Paulene Mendoza Morrison
//Nicolas Chamaki
//04-19-2026
//CS2600 Final Project Progress Check

#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

int main() {
    int rows = 9, cols = 9;
    int **board;

    board = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        board[i] = malloc(cols * sizeof(int));
    }

    initializeBoard(board, rows, cols);

    int col, value;
    int row = 0;

    while (row != -1)
    {
        printBoard(board, rows, cols);

        // letting users stop entering values with -1
        printf("Enter a row value (0-8, enter -1 to quit): ");
        scanf("%d", &row);

        if (row != -1)
        {
            // 0-8 because of array indexing
            printf("Enter a column value (0-8): ");
            scanf("%d", &cols);

            printf("Enter value (1-9): ");
            scanf("%d", &value);

            // validating if the values recieved from the user make sense before being placed in the board
             if (row >= 0 && row < 9 && cols >= 0 && cols < 9 && value >= 1 && value <= 9) {
                if (board[row][cols] != 0) {
                    printf("That position is already taken.\n");
                }
                else if (isValidMove(board, row, cols, value)) {
                        board[row][cols] = value;
                 }
                 else {
                    printf("That number already exists in another row, column, or box.\n");
                 }
              }
                else {
                    printf("Please enter value (1-9).\n");
                }
            }
    }
    freeBoard(board, rows);

    return 0;
}


