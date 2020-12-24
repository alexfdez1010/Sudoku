/*
 * Sudoku.cpp
 *
 *  Created on: 24 dic. 2020
 *      Author: alejandro
 */

#include "Sudoku.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef vector< vector<bool> > vvb;
typedef unsigned short int usi;

Sudoku::Sudoku(usi _size) {
	matrix.assign(_size,vector<usi>(_size));
	this ->_size = _size;
	this -> root = getRoot(_size);
}

usi Sudoku::size() {
	return _size;
}

void Sudoku::inputFile(string filename) {
	fstream file;
	file.open(filename, ios :: in);
	if(file.is_open()){
		inputStream(file);
		file.close();
	}
	else{
		cout << "The file can´t be opened or doesn´t exists\n";
	}
}

void Sudoku::inputConsole(){
	inputStream(cin);
}

bool Sudoku::solve() {
	vvb rows(size(),vector<bool>(size(),false));
	vvb cols(size(),vector<bool>(size(),false));
	vvb squares(size(),vector<bool>(size(),false));
	updateSelect(rows,cols,squares);
	solveEasy(rows,cols,squares);
	return solveR(0,0,rows,cols,squares);
}

void Sudoku::solveEasy(vvb &rows, vvb &cols, vvb &squares) {
	usi i,j,number,count,last,square;
	bool finish = false;
	while(!finish){
		finish = true;
		for(i = 0;i < size();i++){
			for(j = 0;j < size();j++){
				if(matrix[i][j] == 0){
					count = 0;
					square = getSquare(i,j);
					for(number = 1;number <= size();number++){
						if(!rows[i][number-1] && !cols[j][number-1] && !squares[square][number-1]){
							count++;
							last = number;
						}
					}
					if(count == 1){
						matrix[i][j] = last;
						rows[i][last-1] = true;
						cols[j][last-1] = true;
						squares[square][last-1] = true;
						finish = false;
					}
				}

			}
		}
	}

}

void Sudoku::save(string filename) {
	fstream file;
	file.open(filename, ios :: out | ios :: trunc);
	if(file.is_open()){
		outputStream(file);
		file.close();
	}
	else{
		cout << "The file can´t be opened/created\n";
	}
}

usi Sudoku::getSquare(usi r,usi c) {
	return root*(r/root) + c/root;
}

usi Sudoku::getRoot(usi n) {
	usi m;
	usi a = 0;
	usi b = n+1;
	while(b != a+1){
		m = (a+b) / 2;
		if(m*m <= n){
			a = m;
		}
		else{
			b = m;
		}
	}
	return a;
}

bool Sudoku::solveR(usi r, usi c, vvb &rows, vvb &cols, vvb &squares) {
	usi number,square,row,col;
	bool isSolve;

	isSolve = false;
	row = (c == size()-1)? r+1 : r;
	col = (c == size()-1)? 0 : c+1;

	if(matrix[r][c] == 0){

		square = getSquare(r,c);

		for(number = 1;number <= size() && !isSolve;number++){

			if(!rows[r][number-1] && !cols[c][number-1] && !squares[square][number-1]){

				matrix[r][c] = number;
				rows[r][number-1] = true;
				cols[c][number-1] = true;
				squares[square][number-1] = true;

				if(r == size()-1 && c == size()-1){
					isSolve = true;
				}

				else{
					isSolve |= solveR(row,col,rows,cols,squares);
					if(!isSolve){
						matrix[r][c] = 0;
						rows[r][number-1] = false;
						cols[c][number-1] = false;
						squares[square][number-1] = false;
					}
				}
			}
		}
	}
	else{
		if(r == size()-1 && c == size()-1){
			isSolve = true;
		}
		else{
			isSolve = solveR(row,col,rows,cols,squares);
		}
	}
	return isSolve;
}

void Sudoku::updateSelect(vvb &rows, vvb &cols, vvb &squares) {
	usi i,j,number,square;
	for(i = 0;i < size();i++){
		for(j = 0;j < size();j++){
			number = matrix[i][j];
			square = getSquare(i,j);
			if(number != 0){
				rows[i][number-1] = true;
				cols[j][number-1] = true;
				squares[square][number-1] = true;
			}
		}
	}
}

void Sudoku::print() {
	outputStream(cout);
}

void Sudoku::inputStream(istream &inputStream) {
	usi i,j;
	try{
		for(i = 0;i < size();i++){
			for(j = 0;j < size();j++){
				inputStream >> matrix[i][j];
			}
		}
	}
	catch(exception &e){
		cerr << "The format of the console/file is incorrect";
	}
}

void Sudoku::outputStream(ostream &outputStream) {
	usi i,j;
	for(i = 0;i < size();i++){
		for(j = 0;j < size();j++){
			outputStream << matrix[i][j] << " ";
		}
		outputStream << endl;
	}

}
