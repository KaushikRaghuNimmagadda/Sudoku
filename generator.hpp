#include "board.hpp"
#include "solver.hpp"

typedef enum {EASY, MEDIUM, HARD} Difficulty;

// produces a sudoku puzzle with a specified difficulty
Board makeSudoku(Difficulty dif);


// produces a filled in sudoku board
Board makeSolved();
