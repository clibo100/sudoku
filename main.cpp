#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

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
	for(int row = 0; row < 9; ++row)
	{
		for(int column = 0; column < 9; ++column)
		{
			cout<<board[row][column]<<" ";
		}
		cout<<'\n';
	}

	//find all of the rows with problems
	stack<int> wrongRows;

	int count = 1;
	for (int row = 0; row < 9; ++row)
	{
		int sum = 0;
		for (int column = 0; column < 9; ++column)
		{
			sum += board[row][column];
		}

		if (sum != 45)
		{
			wrongRows.push(row);
		}
		else
		{
			int* doesExist = new int[10];
			for (int i = 1; i < 10; ++i)
			{
				for (int column = 0; column < 9; ++column)
				{
					if (i == board[row][column])
					{
						doesExist[i] = true;
					}
				}
			}

			bool beenPushed = false;

			for (int i = 0; i < 9; ++i)
			{
				if (doesExist[i] == false)
				{
					if (beenPushed == false)
					{
						wrongRows.push(row);
						beenPushed = true;
						cout<<"AAAAAAAAAAAAAAAAAAAAA"<<count<<endl;
						++count;
					}
				}
				else
				{
					cout<<"lets see what this does"<<count<<endl;
					++count;
				}
			}
		}
	}

	//find all the columns with problems
	stack<int> wrongColumns;

	for (int column = 0; column < 9; ++column)
	{
		int sum = 0;
		for (int row = 0; row < 9; ++row)
		{
			sum += board[row][column];
		}

		if (sum != 45)
		{
			wrongColumns.push(column);
		}
	}

	fileIn.close();

	return 0;
}