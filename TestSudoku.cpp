/*
 * TestSudoku.cpp
 *
 *  Created on: 24 dic. 2020
 *      Author: alejandro
 */

#include "Sudoku.h"

int main(){
	Sudoku sudoku(16);
	sudoku.inputFile("sudoku2.txt");
	if(sudoku.solve()){
		cout << "Has solution" << endl;
		sudoku.save("sudokuSolution2.txt");
		sudoku.print();
	}

	return 0;
}


