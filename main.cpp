#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <list>

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

	//find all of the rows with problems
	int* validRows = new int[9];

	for (int row = 0; row < 9; ++row)
	{
		int temp [9];
		for (int column = 0; column < 9; ++column)
		{
			temp[column] = board[row][column];
		}
		sort(temp, temp + 9);
		int goal[9];
		for (int i = 0; i < 9; ++i)
		{
			goal[i] = i+1;
		}

		int sum = 0;

		for (int i = 0; i < 9; ++i)
		{
			if (goal[i] == temp[i])
			{
				sum++;
			}
		}

		if (sum == 9)
		{
			validRows[row] = 1;
		}
		else
		{
			validRows[row] = 0;
		}
	}

	int allRowCheck = 0;
	for (int i = 0; i < 9; ++i)
	{
		if (validRows[i] == 1)
		{
			allRowCheck++;
			if (allRowCheck == 9)
			{
				cout<<"all rows are gung ho captain"<<endl;
			}
		}
		else
		{
			cout<<"row "<<i + 1<<" is not loving life right now"<<endl;
		}
	}

	//find all of the columns with problems
	int* validColumns = new int[9];

	for (int column = 0; column < 9; ++column)
	{
		int temp [9];
		for (int row = 0; row < 9; ++row)
		{
			temp[row] = board[row][column];
		}
		sort(temp, temp + 9);
		int goal[9];
		for (int i = 0; i < 9; ++i)
		{
			goal[i] = i+1;
		}

		int sum = 0;

		for (int i = 0; i < 9; ++i)
		{
			if (goal[i] == temp[i])
			{
				sum++;
			}
		}

		if (sum == 9)
		{
			validColumns[column] = 1;
		}
		else
		{
			validColumns[column] = 0;
		}
	}

	int allColumnCheck = 0;
	for (int i = 0; i < 9; ++i)
	{
		if (validColumns[i] == 1)
		{
			allColumnCheck++;
			if (allColumnCheck == 9)
			{
				cout<<"all columns are gung ho captain"<<endl;
			}
		}
		else
		{
			cout<<"column "<<i + 1<<" is not loving life right now"<<endl;
		}
	}

	int* validGrids = new int[9];
	int currGrid = 0;

	for (int row = 0; row < 9; row += 3)
	{
		for (int column = 0; column < 9; column += 3)
		{
			int temp [9];
			temp[0] = board[row][column];
			temp[1] = board[row][column+1];
			temp[2] = board[row][column+2];
			temp[3] = board[row+1][column];
			temp[4] = board[row+1][column+1];
			temp[5] = board[row+1][column+2];
			temp[6] = board[row+2][column];
			temp[7] = board[row+2][column+1];
			temp[8] = board[row+2][column+2];

			sort(temp, temp + 9);

			int goal[9];
			for (int i = 0; i < 9; ++i)
			{
				goal[i] = i+1;
			}

			int sum = 0;

			for (int i = 0; i < 9; ++i)
			{
				if (goal[i] == temp[i])
				{
					sum++;
				}
			}

			if (sum == 9)
			{
				validGrids[currGrid] = 1;
			}
			else
			{
				validGrids[currGrid] = 0;
			}
			++currGrid;
		}
	}

	int allGridCheck = 0;
	for (int i = 0; i < 9; ++i)
	{
		if (validGrids[i] == 1)
		{
			allGridCheck++;
			if (allGridCheck == 9)
			{
				cout<<"all grids are gung ho captain"<<endl;
			}
		}
		else
		{
			cout<<"grid "<<i + 1<<" is not loving life right now"<<endl;
		}
	}

	fileIn.close();

	return 0;
}