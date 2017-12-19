#include "solver.hpp"

typedef boost::array<boost::array<int, 3>, 2> T;


Board ARR =
  {3, 0, 6, 5, 0, 8, 4, 0, 0,
    5, 2, 0, 0, 0, 0, 0, 0, 0,
      0, 8, 7, 0, 0, 0, 0, 3, 1,
        0, 0, 3, 0, 1, 0, 0, 8, 0,
          9, 0, 0, 8, 6, 3, 0, 0, 5,
            0, 5, 0, 0, 9, 0, 6, 0, 0,
              1, 3, 0, 0, 0, 0, 2, 5, 0,
                0, 0, 0, 0, 0, 0, 0, 7, 4,
                  0, 0, 5, 2, 0, 6, 3, 0, 0};

int main(int argc, char *argv[]){
  T test = {1, 2, 3, 4, 5, 6};
  for(int i = 1; i < argc; i ++){
    std::cout << argv[i] << std::endl;
  }
  for(int i = 0; i < 2; i ++){
    for(int j = 0; j < 3; j ++){
      std::cout << test[i][j] << std::endl;
    }
  }

  printBoard(ARR, std::cout);
  std::cout << "DONE" << std::endl;
  return 0;
}
