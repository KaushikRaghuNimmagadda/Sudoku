#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "generator.hpp"
#include "board.hpp"

int main(int argc, char *argv[]){
  if(argc != 2 && argc != 3){
    std::cerr << "Usage: ./generator [difficulty] 'output_file'" << std::endl;
    std::cerr << "Board will be written to 'output_file'" << std::endl;
    return 1;
  }

  Difficulty d = EASY;
  if(argc == 3){
    std::string userDifficulty = std::string(argv[1]);
    // lowercase the string
    std::transform(userDifficulty.begin(), userDifficulty.end(), userDifficulty.begin(), ::tolower);
    if (userDifficulty == "easy"){
      d = EASY;
    } else if(userDifficulty == "medium"){
      d = MEDIUM;
    } else if(userDifficulty == "hard"){
      d = HARD;
    } else {
      std::cerr << "Difficulty must be 'easy', 'medium', or 'hard'" << std::endl;
      exit(1);

    }
  }
  std::cout << "MAKING NEW BOARD" << std::endl;
  Board m = makeSudoku(d);
  std::ofstream ofs;
  ofs.open(argv[argc - 1], std::ofstream::trunc);
  printBoard(m, ofs);
  std::cout << "DONE" << std::endl;
  return 0;
}
