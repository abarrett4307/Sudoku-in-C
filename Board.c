#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

void initializeBoard(int **board, int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = 0;
        }
    }
}

void printBoard(int **board, int rows, int cols)
{
    int i, j;

    printf("\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (board[i][j] == 0)
            {
                printf(". ");
            }
            else
            {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

void freeBoard(int **board, int rows)
{
    int i;

    for (i = 0; i < rows; i++)
    {
        free(board[i]);
    }
    free(board);
}

int isValidMove(int **board, int row, int cols, int num)
{
    int i, j;
    int startRow, startCols;

//checking row
    for (i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
        {
            return 0;
        }
    }

// checking column
    for (i = 0; i < 9; i++)
    {
        if (board[i][cols] == num)
        {
            return 0;
        }
    }

    startRow = (row / 3) * 3;
    startCols = (cols / 3) * 3;

// checking the 3 x 3 boxes
    for (i = startRow; i < startRow + 3; i++)
    {
        for (j = startCols; j < startCols + 3; j++)
        {
            if (board[i][j] == num)
            {
                return 0;
            }
        }
    }

    return 1;
}