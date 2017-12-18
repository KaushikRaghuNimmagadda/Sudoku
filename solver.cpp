#include "solver.hpp"
#include "math.h"
#include "assert.h"

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
  assert(location.row + sizeOfBox < DIM && location.row >= 0);
  assert(location.col + sizeOfBox < DIM && location.col >= 0);
  for(int i = location.row; i < location.row + sizeOfBox; i ++){
    for(int j = location.col; i < location.col + sizeOfBox; j ++){
      if(board[i][j] == val){
        return 1;
      }
    }
  }
  return 0;
}

void printBoard(Board board, std::ostream& output){
  for(int i = 0; i < DIM; i ++){
    for(int j = 0; j < DIM; j ++){
      output << board[i][j] << " ";
    }
    output << std::endl;
  }
}
