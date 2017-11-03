# sudokusolver

Code solves a sudoku board by looking for the most constrained square 
on the board and places the smallest number possible at that spot. Uses
a stack to keep track of the squares for backtracking and replaces
previous moves with smallest alternative, and does so until board
is solved.

Class sudokuboard is provided to perform tasks on the board, such as placing,
removing, adding, and checking items.
