#include "RandomSquareGenerator.hpp"
#include "board.hpp"

std::vector<std::pair<int, int>> RandomSquareGenerator::getAllCoords(){
  std::vector<std::pair<int, int>> vec;
  for(int i = 0; i < DIM; i ++){
    for(int j = 0; j < DIM; j ++){
      vec.push_back(std::make_pair(i, j));
    }
  }
  return vec;
}

bool RandomSquareGenerator::isDone(){
  return index >= items.size();
}

std::pair<int, int> RandomSquareGenerator::nextSquare(){
  assert(!isDone());
  std::pair<int, int> elt = items.at(index);
  index ++;
  return elt;
}
