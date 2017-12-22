#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "board.hpp"

// attempts to solve a give sudoku board. If it's solvable, 1 is returned
// and board is correctly filled in. Otherwise, 0 is returned.
int solveSudoku(Board& board);

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

// takes in a board and checks if it is solved.
// returns 1 if the board is solved and 0 if it isn't.
int verifyBoard(Board board);
