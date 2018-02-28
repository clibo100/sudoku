#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include "Calc.h"

using namespace std;

int main()
{
	char text;
	ifstream fileIn;

	cout<< "enter file name: (example: file.txt)" << '\n';
	string filename;
	cin>>filename;

	fileIn.open(filename);

	//initialize 2D array of sudoku map
	int** board = new int*[9];
	for(int i = 0; i < 9; ++i)
	{
		board[i] = new int[9];
	}

	//read map from file and assign to 2D array
	for(int row = 0; row < 9; ++row)
	{
		for(int column = 0; column < 9; ++column)
		{
			fileIn >> text;
			board[row][column] = text - '0';
		}
	}

	//print out board
	cout<< '\n' << "Given board: " << '\n';
	for(int row = 0; row < 9; ++row)
	{
		for(int column = 0; column < 9; ++column)
		{
			if (column != 2 && column != 5)
			{
				cout<<board[row][column]<<" ";
			}
			else
			{
				cout<<board[row][column]<<"  ";
			}
		}
		if (row != 2 && row != 5)
		{
			cout<<'\n';
		}
		else
		{
			cout<<'\n'<<'\n';
		}
	}

	cout<<'\n';

	Calc calc;
	int* validRows = calc.checkRows(board);
	int* validColumns = calc.checkColumns(board);
	int* validGrids = calc.checkGrids(board);

	fileIn.close();

	return 0;
}