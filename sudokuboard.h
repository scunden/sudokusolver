/************************************************************************

    File: sudokuboard.h
    Author: Steven Cunden
    Date: October 2nd, 2017

    Declaration of a simple array-based sudokuboard class.

************************************************************************/

#include <string>

class sudokuboard {

public:

	/*** Constructor ***/
	sudokuboard();
	// Initializes and empty sudoku board

	void place(size_t r, size_t c, char n); 
	// place numeral n at position (r,c)
	
	void print(); 
	// prints the board
	
	char get(size_t r, size_t c); 
	// returns n at position (r,c)
	
	void remove(size_t r, size_t c);
	// removes n at position (r,c)
	
	bool canPlace(size_t r, size_t c, char n); 
	// true iff the board would allow placing
	// n at (r,c)
	
	bool solved();
	// true iff there are no blank spots on the board

private:

	std::string board[9];
	// Board represented as array of 9, of type string
};