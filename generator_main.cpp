#include <iostream>
#include <fstream>
#include "generator.hpp"
#include "board.hpp"

int main(int argc, char *argv[]){
  if(argc != 2){
    std::cerr << "Usage: ./generator 'output_file'" << std::endl;
    std::cerr << "Board will be written to 'output_file'" << std::endl;
    return 1;
  }

  std::cout << "MAKING NEW BOARD" << std::endl;
  Board m = makeSudoku(EASY);
  std::ofstream ofs;
  ofs.open(argv[1], std::ofstream::trunc);
  printBoard(m, ofs);
  std::cout << "DONE" << std::endl;
  return 0;
}
