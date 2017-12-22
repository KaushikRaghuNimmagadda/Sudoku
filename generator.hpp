#include "board.hpp"
#include "solver.hpp"

typedef enum {EASY, MEDIUM, HARD} difficulty;

// produces a sudoku puzzle with a specified difficulty
Board makeSudoku(difficulty dif);
