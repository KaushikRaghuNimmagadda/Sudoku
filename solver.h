#include <stdio.h>
#include <assert.h>

#define EMPTY 0

#define DIM 9

typedef int BOARD[DIM][DIM];

typedef struct loc {
  int row;
  int col;
} loc;

int isSafe(BOARD board, loc location, int val);

int inCol(BOARD board, int col, int val);

int inRow(BOARD board, int row, int val);

int inBox(BOARD board, loc location, int val);

// takes in a board and a pointer to a loc struct.
// updates that pointer to contain the location of
// the next empty board square if there is one, returns
// null otherwise
loc *getEmptyLocation(BOARD board, loc *ptr);
