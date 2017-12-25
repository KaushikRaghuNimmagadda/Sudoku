#include <utility>

class SquareGenerator {
public:
  virtual ~SquareGenerator() {}

  virtual bool isDone() = 0;
  virtual std::pair<int, int> nextSquare() = 0;
};
