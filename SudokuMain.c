// Justin Li
// Abigail Yun
// Tony Barrett
// Paulene Mendoza Morrison
// Nicolas Chamaki
// 05-04-2025
// CS2600 Final Project

#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
#include "Puzzle.h"

void printMenu(void);

int main(void) {
    int **board;
    int **original;
    int choice = 0;
    Move move;

    board = createBoard();
    original = createBoard();

    if (board == NULL || original == NULL) {
        freeBoard(board);
        freeBoard(original);
        return 1;
    }

    // Try loading puzzle from file first
    if (!loadPuzzle("puzzle.txt", board)) {
        printf("Could not load puzzle.txt. Using default puzzle.\n");
        loadDefaultPuzzle(board);
    }

    // Save starting puzzle so fixed values cannot be changed
    copyBoard(original, board);

    while (choice != 4) {
        printBoard(board);
        printMenu();

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter row (0-8): ");
            scanf("%d", &move.row);

            printf("Enter column (0-8): ");
            scanf("%d", &move.col);

            printf("Enter value (1-9): ");
            scanf("%d", &move.value);

            // Basic range check
            if (move.row < 0 || move.row >= SIZE ||
                move.col < 0 || move.col >= SIZE ||
                move.value < 1 || move.value > SIZE) {

                printf("Invalid input. Try again.\n");
            }

            // Prevent changing original puzzle numbers
            else if (original[move.row][move.col] != 0) {
                printf("That spot is part of the puzzle.\n");
            }

            // Prevent overwriting user's own placed values
            else if (board[move.row][move.col] != 0) {
                printf("That spot is already filled.\n");
            }

            // Check Sudoku row, column, and box rules
            else if (isValidMove(board, move.row,
                                 move.col, move.value)) {

                board[move.row][move.col] = move.value;
                printf("Move accepted.\n");

                if (isBoardFull(board)) {
                    printf("Board is full. Puzzle complete!\n");
                    choice = 4;
                }
            }

            else {
                printf("Invalid move. Duplicate found.\n");
            }
        }

        else if (choice == 2) {
            // Reset board back to original puzzle
            copyBoard(board, original);
            printf("Puzzle reset.\n");
        }

        else if (choice == 3) {
            printf("Zeros or dots are empty spaces.\n");
            printf("Enter row, column, and value to play.\n");
            printf("Rows and columns use numbers 0 through 8.\n");
        }

        else if (choice == 4) {
            printf("Exiting game.\n");
        }

        else {
            printf("Invalid menu choice.\n");
        }
    }

    freeBoard(board);
    freeBoard(original);

    return 0;
}

void printMenu(void) {
    printf("\nMenu\n");
    printf("1. Enter move\n");
    printf("2. Reset puzzle\n");
    printf("3. Instructions\n");
    printf("4. Quit\n");
}
