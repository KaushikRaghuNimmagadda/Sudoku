#ifndef GENERATOR_H
#define GENERATOR_H

#include <utility>
#include <unordered_map>
#include "board.hpp"
#include "solver.hpp"

typedef enum {EASY, MEDIUM, HARD} Difficulty;

struct pair_hash {
  template <class T1, class T2>
  std::size_t operator () (const std::pair<T1,T2> &p) const {
    return DIM * p.first + p.second;
  }
};

typedef std::unordered_map<std::pair<int, int>, int, pair_hash> dig_map;

// produces a sudoku puzzle with a specified difficulty
Board makeSudoku(Difficulty dif);

// produces a filled in sudoku board
Board makeSolved();

// produces an empty sudoku board
Board makeEmpty();

// takes in a board and counts how many squares are filled in
int numGivens(Board b);

// given a board, calculates the lower bound on the number of
// filled in squares in rows/cols
int lowerBoundRowColGivens(Board b);
#endif
