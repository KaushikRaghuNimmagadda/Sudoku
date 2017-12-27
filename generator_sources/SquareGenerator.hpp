#ifndef SQGEN_H
#define SQGEN_H
#include <utility>

class SquareGenerator {
public:
  virtual ~SquareGenerator() {}

  virtual bool isDone() = 0;
  virtual std::pair<int, int> nextSquare() = 0;
};

#endif
