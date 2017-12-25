#include "SnakeGenerator.hpp"

class SkipSquareGenerator : public SquareGenerator {
public:
  // pass in false if you want to start at (0, 0), true
  // if you want to start at (0, 1).
  SkipSquareGenerator(bool offset){
    gen = offset ? SnakeGenerator(std::make_pair(0, 1)) : SnakeGenerator();
  }
  bool isDone() override;
  std::pair<int, int> nextSquare() override;
private:
  SnakeGenerator gen;
};
