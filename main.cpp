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

	//initialize 2D array of actual input so i can deal with commas
	char** inputboard = new char*[18];
	for(int i = 0; i < 9; ++i)
	{
		inputboard[i] = new char[18];
	}

	//read map from file and assign to 2D array
	for(int row = 0; row < 9; ++row)
	{
		for(int column = 0; column < 18; ++column)
		{
			fileIn >> text;
			inputboard[row][column] = text;
		}
	}

	//deal with commas by assigning actual sudoku array to every other input array
	for (int row = 0; row < 9; ++row)
	{
		board[row][0] = inputboard[row][0] - '0';
		board[row][1] = inputboard[row][2] - '0';
		board[row][2] = inputboard[row][4] - '0';
		board[row][3] = inputboard[row][6] - '0';
		board[row][4] = inputboard[row][8] - '0';
		board[row][5] = inputboard[row][10] - '0';
		board[row][6] = inputboard[row][12] - '0';
		board[row][7] = inputboard[row][14] - '0';
		board[row][8] = inputboard[row][16] - '0';
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