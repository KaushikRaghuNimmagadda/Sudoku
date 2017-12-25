#ifndef SNAKE_GENERATOR_H
#define SNAKE_GENERATOR_H

#include <utility>
#include "SquareGenerator.hpp"

class SnakeGenerator : public SquareGenerator {
public:
  SnakeGenerator(){
    done = false;
    square = std::make_pair(0, 0);
  }

  SnakeGenerator(std::pair<int, int> start){
    done = false;
    square = start;
  }

  bool isDone() override;
  std::pair<int, int> nextSquare() override;
private:
  bool done;
  std::pair<int, int> square;
};

#endif
