/*
 * TestSudoku.cpp
 *
 *  Created on: 24 dic. 2020
 *      Author: alejandro
 */

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


