#include "generator.hpp"
#include "solver.hpp"

Board makeSudoku(Difficulty dif){
  Board b;
  return b;
}

Board makeSolved(){
  Board b;
  for(int i = 0; i < DIM; i ++){
    for(int j = 0; j < DIM; j ++){
      b[i][j] = EMPTY;
    }
  }
  // take advantage of solve filling in our board
  solveSudoku(b);
  return b;
}
