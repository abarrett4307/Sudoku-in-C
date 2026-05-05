#ifndef BOARD_H
#define BOARD_H

#define SIZE 9

typedef struct {
    int row;
    int col;
    int value;
} Move;

int **createBoard(void);
void freeBoard(int **board);
void copyBoard(int **dest, int **src);
void printBoard(int **board);

int isBoardFull(int **board);
int isValidMove(int **board, int row, int col, int value);

#endif
