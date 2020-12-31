//============================================================================
// Name        : Sudoku.h
// Author      : Alejandro Fernández Camello
// Version     : 1.0
// Copyright   : GPL-3.0
// Description : General interface of a sudoku that can have different range of numbers
//============================================================================

#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<bool> > vvb;
typedef unsigned short int usi;

class Sudoku{

private:

	vector< vector<usi> > matrix;
	usi _size;
	usi root;

	usi getSquare(usi r,usi c);
	usi getRoot(usi n);

	void inputStream(istream &inputStream);
	void outputStream(ostream &outputStream);

	void updateSelect(vvb &rows, vvb &cols, vvb &squares);
	void solveEasy(vvb &rows, vvb &cols, vvb &squares);
	bool solveR(usi r, usi c, vvb &rows, vvb &cols, vvb &squares);

public:

	//PRE: _size == a*a, a > 1
	//POST: this -> _size == size && this -> root == a
	//DESC: Constructor for the class Sudoku
	//COMPLEXITY: O(n^2) SoP: _size
	Sudoku(usi _size);

	//PRE:
	//POST:
	//DESC: Returns the number of possible number that can have the sudoku
	//COMPLEXITY: O(1) SoP:
	usi size();

	//PRE: The file must have an appropriate format
	//POST:
	//DESC: Read from a file with name filename the information needed to initialize the sudoku
	//COMPLEXITY: O(n^2) SoP: size()
	void inputFile(string filename);

	//PRE: The console must have an appropriate format
	//POST:
	//DESC: Read from the console the information needed to initialize the sudoku
	//COMPLEXITY: O(n^2) SoP: size()
	void inputConsole();

	//PRE: The sudoku must be correct initialized
	//POST: If solve() == true get a solution of the sudoku
	//DESC: If there is any solution for the sudoku it will return true and the solution, otherwise false
	//COMPLEXITY: O(n^(n*n)) SoP: size()
	bool solve();

	//PRE: Execute before solve() with solve() returning true
	//POST:
	//DESC: Save in a file with name filename the solution of the sudoku
	//COMPLEXITY: O(n^2) SoP: size()
	void save(string filename);

	//PRE: Execute before solve() with solve() returning true
	//POST:
	//DESC: Print the solution of the sudoku in the console
	//COMPLEXITY: O(n^2) SoP: size()
	void print();

};





#endif /* SUDOKU_H_ */
