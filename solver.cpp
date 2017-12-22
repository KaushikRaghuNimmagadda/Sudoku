#include <string>
#include <sstream>
#include "solver.hpp"
#include "math.h"
#include "assert.h"


// takes in a file and turns it into a string.
// taken from https://stackoverflow.com/questions/116038/what-is-the-best-way-to-read-an-entire-file-into-a-stdstring-in-c
std::string slurp(std::ifstream& in) {
  std::stringstream sstr;
  sstr << in.rdbuf();
  return sstr.str();
}


int solveSudoku(Board& board){
  loc location;
  if(!getEmptyLocation(board, &location)){
    // there were no empty locations on the board!
    return 1;
  }
  // location now contains the row and col of an empty space
  // loop over all possible values to fill space with
  for(int val = 1; val <= DIM; val ++){
    if(isSafe(board, location, val)){
      board[location.row][location.col] = val;
      // if we can solve the board with the updated value
      // return 1
      if(solveSudoku(board)){
        return 1;
      }
      // can't solve board with the value we inserted, reset it
      // to empty
      board[location.row][location.col] = EMPTY;
    }
  }
  // if we try all values and we can't find a solution, return 0.
  return 0;
}

loc *getEmptyLocation(Board board, loc *ptr){
  for(int i = 0; i < DIM; i ++){
    for(int j = 0; j < DIM; j ++){
      if(board[i][j] == EMPTY){
        ptr->row = i;
        ptr->col = j;
        return ptr;
      }
    }
  }
  return NULL;
}

int isSafe(Board board, loc location, int val){
  return !inCol(board, location.col, val) && !inRow(board, location.row, val)
    && !inBox(board, location, val);
}

int inCol(Board board, int col, int val){
  for(int i = 0; i < DIM; i ++){
    if(board[i][col] == val){
      return 1;
    }
  }
  return 0;
}

int inRow(Board board, int row, int val){
  for(int i = 0; i < DIM; i ++){
    if(board[row][i] == val){
      return 1;
    }
  }
  return 0;
}

int inBox(Board board, loc location, int val){
  // box is square with side length sqrt(DIM)
  int sizeOfBox = (int) sqrt(DIM);
  int row = (location.row / sizeOfBox) * sizeOfBox;
  int col = (location.col / sizeOfBox) * sizeOfBox;
  assert(row + sizeOfBox <= DIM && row >= 0);
  assert(col + sizeOfBox <= DIM && col >= 0);
  for(int i = 0; i < sizeOfBox; i ++){
    for(int j = 0; j < sizeOfBox; j ++){
      if(board[i + row][j + col] == val){
        return 1;
      }
    }
  }
  return 0;
}

void printBoard(Board board, std::ostream& output){
  for(int i = 0; i < DIM; i ++){
    for(int j = 0; j < DIM; j ++){
      output << board[i][j] << " ";
    }
    output << std::endl;
  }
}

// parsing logic taken from:
// https://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring
Board loadBoard(std::ifstream& source){
  std::vector<int> vals;
  // now we have the file read in as a string.
  // silly that we go from stringstream to string back to stringstream here,
  // can be simplified.
  std::string str = slurp(source);
  std::cout << str << std::endl;
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

int verifyBoard(Board board){
  for(int i = 0; i < DIM; i ++){
    for(int j = 0; j < DIM; j ++){
      // we remove the value from the board then check
      // if we can insert it at its location.
      int bval = board[i][j];
      board[i][j] = EMPTY;
      loc location = {i, j};
      if(!isSafe(board, location, bval)){
        // if we cannot insert the value safely, we restore the board
        // to its original state and then return 0.
        board[i][j] = bval;
        return 0;
      }
      // otherwise just fix the board and keep going.
      board[i][j] = bval;
    }
  }
  // if we make it through all the cells we can return 1.
  return 1;
}

int main2(int argc, char *argv[]){
  if(argc != 2){
    std::cerr << "Usage: ./solver 'sudoku_file'" << std::endl;
    std::cerr << "Output will be written to 'solved_sudoku_file'" << std::endl;
    return 1;
  }
  std::cout << "DONE" << std::endl;
  return 0;
}
