#ifndef BOARD_H
#define BOARD_H

#include <boost/array.hpp>


#define EMPTY 0

// this must be a square number
#define DIM 9

// define board, indexed as [row][col]
// maybe should switch this to a multiarray
typedef boost::array<boost::array<int, DIM>, DIM> Board;

typedef struct loc {
  int row;
  int col;
} loc;


// prints out the board to the output stream passed in
void printBoard(Board board, std::ostream& output);

// loads board from file stream
Board loadBoard(std::ifstream& source);

#endif
