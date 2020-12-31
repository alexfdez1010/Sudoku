//============================================================================
// Name        : TestSudoku.cpp
// Author      : Alejandro Fernández Camello
// Version     : 1.0
// Copyright   : GPL-3.0
// Description : Simple test to check if the algorithms work properly
//============================================================================

#include "Sudoku.h"

int main(){
	Sudoku sudoku(9);
	sudoku.inputFile("sudoku1.txt");
	sudoku.print();
	cout << endl;
	if(sudoku.solve()){
		sudoku.save("sudokuSolution1.txt");
		sudoku.print();
	}

	return 0;
}


