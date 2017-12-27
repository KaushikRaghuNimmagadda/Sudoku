#include "SkipSquareGenerator.hpp"
#include "assert.h"

bool SkipSquareGenerator::isDone(){
  return gen.isDone();
}

std::pair<int, int> SkipSquareGenerator::nextSquare(){
  assert(!isDone());
  gen.nextSquare();
  return gen.nextSquare();
}
