#include "generator.hpp"
#include "solver.hpp"
#include "SquareGenerator.hpp"

#define MIN(a,b) ((a) < (b) ? a : b)

Board makeEasy();

Board makeMedium();

Board makeHard();

void digHoles(Board& b);

Board makeSudoku(Difficulty dif){
  Board b = makeSolved();
  return b;
}

Board makeSolved(){
  Board b = makeEmpty();
  solveSudoku(b);
  return b;
}

Board makeEmpty(){
  Board b;
  for(int i = 0; i < DIM; i ++){
    for(int j = 0; j < DIM; j ++){
      b[i][j] = EMPTY;
    }
  }
  return b;
}

// this function should also maybe take in another function that
// determines if we are done with the board yet. The while loop would
// end if we run out of squares or if the function is true at some point.
void digHoles(Board& b, SquareGenerator gen){
  dig_map dug;
  while(!gen.isDone()){
    std::pair<int, int> square = gen.nextSquare();
  }
}

int numGivens(Board b){
  int count = 0;
  for(int i = 0; i < DIM; i ++){
    for(int j = 0; j < DIM; j ++){
      count = (b[i][j] != EMPTY) ? count + 1 : count;
    }
  }
  return count;
}

int lowerBoundRowColGivens(Board b){
  int lbRow = 0;
  int lbCol = 0;
  for(int i = 0; i < DIM; i ++){
    int rowCount = 0;
    int colCount = 0;
    for(int j = 0; j < DIM; j ++){
      rowCount = (b[i][j] != EMPTY) ? rowCount + 1 : rowCount;
      colCount = (b[j][i] != EMPTY) ? colCount + 1 : colCount;
    }
    lbRow = MIN(lbRow, rowCount);
    lbCol = MIN(lbCol, colCount);
  }
  return MIN(lbRow, lbCol);
}
