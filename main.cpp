#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

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

	for(int row = 0; row < 9; ++row)
	{
		for(int column = 0; column < 9; ++column)
		{
			cout<<board[row][column]<<" ";
		}
		cout<<'\n';
	}

	fileIn.close();

	return 0;
}