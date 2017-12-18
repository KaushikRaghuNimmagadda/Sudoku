#include <stdio.h>
#include <iostream>


#define EMPTY 0

// this must be a square number
#define DIM 9

// define board, indexed as [row][col]
typedef int Board[DIM][DIM];

typedef struct loc {
  int row;
  int col;
} loc;

// attempts to solve a give sudoku board. If it's solvable, 1 is returned
// and board is correctly filled in. Otherwise, 0 is returned.
int solveSudoku(Board board);

int isSafe(Board board, loc location, int val);

int inCol(Board board, int col, int val);

int inRow(Board board, int row, int val);

// the location is the box's starting row and col
int inBox(Board board, loc location, int val);

// takes in a board and a pointer to a loc struct.
// updates that pointer to contain the location of
// the next empty board square if there is one, returns
// null otherwise
loc *getEmptyLocation(Board board, loc *ptr);

// prints out the board to the output stream passed in
void printBoard(Board board, std::ostream& output);
