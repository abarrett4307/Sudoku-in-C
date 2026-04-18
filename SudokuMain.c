#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 9, cols = 9;
    int **board;

    board = malloc(rows * sizeof(int *));
    
    for (int i = 0; i < rows; i++) {
        board[i] = malloc(cols * sizeof(int));
    }

    
    return 0;
}