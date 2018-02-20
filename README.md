# Sudoku

A sudoku solver I made for fun! Uses some Boost libraries so make sure those are installed appropriately.

## Build
'make' builds two executables in the build directory, solver and generator. To run the generator use
./generator [difficulty] output_file
where difficulty is either 'easy', 'medium', or 'hard'. To run the solver use
./solver board_file
