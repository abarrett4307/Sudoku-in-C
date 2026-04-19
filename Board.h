#ifndef BOARD_H
#define BOARD_H

void initializeBoard(int **board, int rows, int cols);
void printBoard(int **board, int rows, int cols);
void freeBoard(int **board, int rows);

int isValidMove(int **board, int row, int cols, int num);

#endif

