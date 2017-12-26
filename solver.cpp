#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm_ext/push_back.hpp>
#include "solver.hpp"
#include "math.h"
#include "assert.h"

// produces a vector containing the values lower to upper not including
// upper in some random order.
std::vector<int> getShuffledVals(int lower, int upper){
  assert(upper > lower);
  std::vector<int> vals(upper - lower);
  std::mt19937 r{std::random_device{}()};
  boost::push_back(vals, boost::irange(lower, upper));
  std::shuffle(std::begin(vals), std::end(vals), r);
  return vals;
}

int solveSudoku(Board& board){
  loc location;
  if(!getEmptyLocation(board, &location)){
    // there were no empty locations on the board!
    return 1;
  }
  // location now contains the row and col of an empty space
  // loop over all possible values to fill space with

  // using this to iterate through values in a random order
  std::vector<int> vals = getShuffledVals(1, DIM + 1);
  for(int val : vals){
    if(isSafe(board, location, val)){
      board[location.row][location.col] = val;
      // if we can solve the board with the updated value
      // return 1
      if(solveSudoku(board)){
        return 1;
      }
      // can't solve board with the value we inserted, reset it
      // to empty
      board[location.row][location.col] = EMPTY;
    }
  }
  // if we try all values and we can't find a solution, return 0.
  return 0;
}

void countHelper(Board& board, int& count){
  loc location;
  if(!getEmptyLocation(board, &location)){
    // board is solved, increment the number of solutions
    count++;
    return;
  }
  for(int val = 1; val <= DIM; val ++){
    if(isSafe(board, location, val)){
      board[location.row][location.col] = val;
      countHelper(board, count);
      board[location.row][location.col] = EMPTY;
    }
  }
}

int countSolutions(Board& board){
  int count = 0;
  countHelper(board, count);
  return count;
}

loc *getEmptyLocation(Board board, loc *ptr){
  for(int i = 0; i < DIM; i ++){
    for(int j = 0; j < DIM; j ++){
      if(board[i][j] == EMPTY){
        ptr->row = i;
        ptr->col = j;
        return ptr;
      }
    }
  }
  return NULL;
}

int isSafe(Board board, loc location, int val){
  return !inCol(board, location.col, val) && !inRow(board, location.row, val)
    && !inBox(board, location, val);
}

int inCol(Board board, int col, int val){
  for(int i = 0; i < DIM; i ++){
    if(board[i][col] == val){
      return 1;
    }
  }
  return 0;
}

int inRow(Board board, int row, int val){
  for(int i = 0; i < DIM; i ++){
    if(board[row][i] == val){
      return 1;
    }
  }
  return 0;
}

int inBox(Board board, loc location, int val){
  // box is square with side length sqrt(DIM)
  int sizeOfBox = (int) sqrt(DIM);
  int row = (location.row / sizeOfBox) * sizeOfBox;
  int col = (location.col / sizeOfBox) * sizeOfBox;
  assert(row + sizeOfBox <= DIM && row >= 0);
  assert(col + sizeOfBox <= DIM && col >= 0);
  for(int i = 0; i < sizeOfBox; i ++){
    for(int j = 0; j < sizeOfBox; j ++){
      if(board[i + row][j + col] == val){
        return 1;
      }
    }
  }
  return 0;
}

int verifyBoard(Board board){
  for(int i = 0; i < DIM; i ++){
    for(int j = 0; j < DIM; j ++){
      // we remove the value from the board then check
      // if we can insert it at its location.
      int bval = board[i][j];
      board[i][j] = EMPTY;
      loc location = {i, j};
      if(!isSafe(board, location, bval)){
        // if we cannot insert the value safely, we restore the board
        // to its original state and then return 0.
        board[i][j] = bval;
        return 0;
      }
      // otherwise just fix the board and keep going.
      board[i][j] = bval;
    }
  }
  // if we make it through all the cells we can return 1.
  return 1;
}
