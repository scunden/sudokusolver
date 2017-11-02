/************************************************************************

    File: sudokuboard.cc
    Author: Steven Cunden
    Date: October 2nd, 2017

    Implementation of a simple array-based sudokuboard class.

************************************************************************/

#include "sudokuboard.h"
#include <iostream>
using namespace std;

sudokuboard::sudokuboard() 
{	// Initializes and empty sudoku board

	for (size_t row = 0; row < 9; row++)
		board[row] = "_________";
}

void sudokuboard::place(size_t r, size_t c, char n)
{	// place numeral n at position (r,c)

	board[r][c] = n;
}
	
void sudokuboard::print()
{	// write the board to cout

	for (size_t row = 0; row < 9; row++)
		cout << board[row] << endl;
}
	
char sudokuboard::get(size_t r, size_t c) 
{	// return the numeral at position (r,c)

	return board[r][c];
}
	
void sudokuboard::remove(size_t r, size_t c)
{	// remove the numeral at position (r,c)

	board[r][c] = '_';
}
	
bool sudokuboard::canPlace(size_t r, size_t c, char n) 
{	// true iff the board would allow placing
	// n at (r,c)

	// If slot isn't empty, cannot place
	if (board[r][c] != '_')
		return false;
	
	// Check all the rows and columns for already presetn n
	for (size_t i = 0; i < 9; i++) {
		
		if (board[r][i] == n or board[i][c] == n) 
			return false;
	}

	// Check the 3x3 box (r,c) is in for already present n
	size_t box_row = r / 3 * 3;
	size_t box_col = c / 3 * 3;

	for (size_t row = box_row; row < box_row + 3; row++) {

		for (size_t col = box_col; col < box_col + 3; col++) {

			if (board[row][col] == n) 
				return false;
		}
	}
	// if all passed, n can be placed!
	return true;

	// CITE: box_row = r / 3 * 3 in class
	// DESC: Copied from warm up problem in class
}
	
bool sudokuboard::solved() 
{	// true iff there are no blank spots on the board

	// loops through all slots and looks for blanks
	for (size_t r = 0; r < 9; r++) {

		for (size_t c = 0; c < 9; c++) {

			if (board[r][c] == '_') 
				return false; // board is unsolved if blank is found
		}
	}
	// board is solved if no blank is found
	return true; 
}