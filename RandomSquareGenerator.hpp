#ifndef RAND_SQGEN_H
#define RAND_SQGEN_H

#include <vector>
#include <algorithm>
#include "SquareGenerator.hpp"
#include "assert.h"

class RandomSquareGenerator : public SquareGenerator {
public:
  RandomSquareGenerator(){
    items = getAllCoords();
    index = 0;
    // shuffle list
    std::mt19937 r{std::random_device{}()};
    std::shuffle(std::begin(items), std::end(items), r);
  }

  RandomSquareGenerator(std::vector<std::pair<int, int>> elts){
    items = elts;
    index = 0;
    // can't pass in empty vector
    assert(elts.size() > 0);
  }

  bool isDone() override;
  std::pair<int, int> nextSquare() override;
private:
  std::vector<std::pair<int, int>> items;
  int index;

  std::vector<std::pair<int, int>> getAllCoords();
};

#endif
