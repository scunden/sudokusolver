/************************************************************************

    File: sudoku.cc
    Author: Steven Cunden
    Date: October 2nd, 2017

    Code solves a sudoku board by looking for the most constrained square 
    on the board and places the smallest number possible at that spot. Uses
    a stack to keep track of the squares for backtracking and replaces
    previous moves with smallest alternative, and does so until board
    is solved.

************************************************************************/

#include "sudokuboard.h"
#include "stack.h"
#include <iostream>
using namespace std;

void most_constrained (sudokuboard & board, size_t & current_row,
	size_t & current_column) 
{	// Looks for the most constrained square on the board

	// Records the count for least amount of moves
	size_t least_counter = 9;

	// Loops through all empty slots
	for (size_t r = 0; r < 9; r++) {

		for (size_t c = 0; c < 9; c++) {

			if (board.get(r,c) == '_') {

				// Checks and updates counter
				size_t counter = 0;

				for (char n = '1'; n <= '9'; n ++) {

					if (board.canPlace(r,c,n))
						counter++;
				}
				// Updates the most contraint square
				if (counter < least_counter) {

					least_counter = counter;
					current_row = r;
					current_column = c;

				}
			}
		}
	}
}

bool place_number_on_board (sudokuboard & board, stack & s, 
	size_t & current_row, size_t & current_column, char & current_val) 
{	// Checks if number can be placed in (r,c) spot
	// Return true if possible
	// Updates the stack by pushing (r,c) on top

	// To ensure a different number in the square
	current_val++;

	// Looks for the smallest possible value
	for (;current_val <= '9'; current_val++) {

		if (board.canPlace(current_row,current_column,current_val)) {

			board.place(current_row, current_column, current_val);
			s.push(current_row);
			s.push(current_column);
			return true;
		}
	}	
	return false;
}

void back_track (sudokuboard & board, stack & s, 
	size_t & current_row, size_t & current_column, char & current_val) 
{	// Updates (r,c), board[r][c] and the stack by popping it 

	current_column = s.top();
	s.pop();
	current_row = s.top();
	s.pop();
	current_val = board.get(current_row,current_column);

	// Removing the current value from the square to clear ir
	board.remove(current_row,current_column);
}

void solve_board (sudokuboard & board, stack & s) 
{	// Loops through all the squares of the board
	// Stops when board is completed

	// Constantly updates row and column values
	size_t current_row = 0;
	size_t current_column = 0;

	while (!board.solved()) {

		char current_val = '0';

		// Looks for the second most constrained square
		most_constrained(board,current_row,current_column);

		// Backtracks if number cannot be places	
		if (!place_number_on_board(board,s,current_row,
			current_column,current_val)) {

			bool backtracking = true;

			while (backtracking) {
				
				back_track(board,s,current_row,current_column,current_val);

				if (place_number_on_board(board, s, current_row,current_column,
					current_val)) 
					backtracking = false;
			}
		}
	}
}
// CITE: Got help during TA hours from Alex Dennis and Paul Magnus 
// DESC: Helped me fix a segmentation fault and recommended that 
// I passed the rows and columns by reference instead of making copies

int main() {
	sudokuboard board;
	stack s;

	// Used an input file for testing > input
	string input;
	for (size_t row = 0; row < 9; row++) {
		cin >> input;
		for (size_t col = 0; col < 9; col++) 
		{
			board.place(row,col, input[col]);
		}
	}
	solve_board(board,s);
	board.print();
}