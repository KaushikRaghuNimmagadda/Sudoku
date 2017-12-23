#include "solver.hpp"
#include "assert.h"

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
  if(argc != 2){
    std::cout << "please supply the name of the board file as input."
              << std::endl;
    return 1;
  }
  std::ifstream ifs;
  ifs.open(argv[1]);
  Board b = loadBoard(ifs);
  printBoard(b, std::cout);
  // std::cout << "num solutions: " << countSolutions(b) << std::endl;
  if(solveSudoku(b)){
    assert(verifyBoard(b));
    std::cout << std::endl;
    printBoard(b, std::cout);
  } else {
    std::cout << "Board not solvable" << std::endl;
  }
  std::cout << "DONE" << std::endl;
  return 0;
}
