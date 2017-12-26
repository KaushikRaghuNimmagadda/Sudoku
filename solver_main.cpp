#include <iostream>
#include <fstream>
#include "solver.hpp"

int main(int argc, char *argv[]){
  if(argc != 2){
    std::cerr << "Usage: ./solver 'sudoku_file'" << std::endl;
    std::cerr << "Output will be written to 'solved_sudoku_file'" << std::endl;
    return 1;
  }
  std::ifstream ifs;
  ifs.open(argv[1]);
  Board b = loadBoard(ifs);
  printBoard(b, std::cout);
  std::cout << "Attempting to solve" << std::endl;
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
