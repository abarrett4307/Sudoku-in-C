all: sudoku

sudoku: SudokuMain.c Board.c Puzzle.c
	gcc -Wall -Wextra -o sudoku SudokuMain.c Board.c Puzzle.c

clean:
	rm -f sudoku
