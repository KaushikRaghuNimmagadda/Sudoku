#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "board.hpp"


// takes in a file and turns it into a string.
// taken from https://stackoverflow.com/questions/116038/what-is-the-best-way-to-read-an-entire-file-into-a-stdstring-in-c
std::string slurp(std::ifstream& in) {
  std::stringstream sstr;
  sstr << in.rdbuf();
  return sstr.str();
}


void printBoard(Board board, std::ostream& output){
  for(int i = 0; i < DIM; i ++){
    for(int j = 0; j < DIM; j ++){
      output << board[i][j] << " ";
    }
    output << std::endl;
  }
}

// parsing logic taken from: // https://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring
Board loadBoard(std::ifstream& source){
  std::vector<int> vals;
  // now we have the file read in as a string.
  // silly that we go from stringstream to string back to stringstream here,
  // can be simplified.
  std::string str = slurp(source);
  std::stringstream ss(str);
  int i;
  while(ss >> i){
    vals.push_back(i);
    // ignore commas and spaces
    if(ss.peek() == ',' || ss.peek() == ' '){
      ss.ignore();
    }
  }
  Board b;
  for(int i = 0; i < DIM; i ++){
    for(int j = 0; j < DIM; j ++){
      b[i][j] = vals.at(i * DIM + j);
    }
  }
  return b;
}
