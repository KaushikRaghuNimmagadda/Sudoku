#include "SnakeGenerator.hpp"
#include "board.hpp"
#include "assert.h"

bool SnakeGenerator::isDone(){
  return done;
}

std::pair<int, int> SnakeGenerator::nextSquare(){
  assert(!done);
  std::pair<int, int> tmp = square;
  if(square.first == 8 && square.second >=7){
    // we are at the end of the board.
    done = true;
  } else {
    int newCol;
    int newRow;
    if(square.first % 2 == 0){
      // on an even row, going right to left
      newCol = (square.second == 0) ? square.second : square.second - 1;
    } else {
      // on an odd row, going left to right
      newCol = (square.second == 8) ? square.second : square.second + 1;
    }
    // if our column hasn't changed, we must increment the row. Otherwise
    // the row remains the same.
    newRow = (newCol == square.second) ? square.first + 1 : square.first;
    square = std::make_pair(newRow, newCol);
  }
  return tmp;
}
