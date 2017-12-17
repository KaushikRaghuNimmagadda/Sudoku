#include "solver.h"

loc *getEmptyLocation(BOARD board, loc *ptr){
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

int isSafe(BOARD board, loc location, int val){
  return inCol(board, location.col, val) && inRow(board, location.row, val)
    && inBox(board, location, val);
}
