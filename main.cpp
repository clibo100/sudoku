#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <list>
int* validRows = new int[9];
int* validColumns = new int[9];
int* validGrids = new int[9];
int** board = new int*[9];

using namespace std;

void WINAPI checkRows(int**& board)
{

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
				cout<<"all rows are correct"<<endl;
			}
		}
		else
		{
			cout<<"row "<<i + 1<<" has an error"<<endl;
		}
	}

	//return validRows;
}

void WINAPI checkColumns(int**& board)
{
	//find all of the columns with problems
	

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
				cout<<"all columns are correct"<<endl;
			}
		}
		else
		{
			cout<<"column "<<i + 1<<" has an error"<<endl;
		}
	}

	//return validColumns;
}

void WINAPI checkGrids(int**& board)
{
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
				cout<<"all grids are correct"<<endl;
			}
		}
		else
		{
			cout<<"grid "<<i + 1<<" has an error"<<endl;
		}
	}

	//return validGrids;
}

int main()
{
	char text;
	ifstream fileIn;

	cout<< "enter file name: (example: file.txt)" << '\n';
	string filename;
	cin>>filename;

	fileIn.open(filename);

	//initialize 2D array of sudoku map
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

	bool solved = false;
	int cycle = 1;

	while (!solved)
	{
		/*DWORD ThreadId;
		Handle ThreadHandle;*/
		cout<<"\nCycle:"<<cycle<<'\n'<<'\n';
		cycle++;
		//find all the invalid rows and columns and grids
		
		/*checkRows(board);
		checkColumns(board);
		checkGrids(board);*/
		cout<<endl;

		int wrongRowAmount = 0, wrongColumnAmount = 0;
		for (int i = 0; i < 9; ++i)
		{
			if (validRows[i] == 0)
			{
				wrongRowAmount++;
			}
			if (validColumns[i] == 0)
			{
				wrongColumnAmount++;
			}
		}

		if (wrongRowAmount == 0 && wrongColumnAmount == 0)
		{
			solved = true;
		}
		else
		{
			int goal[] = {1,2,3,4,5,6,7,8,9};
			int currRow, currColumn;
			int missingnumber;

			for (int i = 0; i < 9; ++i)
			{
				if (validRows[i] == 0)
				{
					currRow = i;
				}
				if (validColumns[i] == 0)
				{
					currColumn = i;
				}
			}

			int tempCurrRow[9];

			for (int column = 0; column < 9; ++column)
			{
				tempCurrRow[column] = board[currRow][column];
			}

			sort(tempCurrRow, tempCurrRow+9);

			for (int i = 0; i < 9; ++i)
			{
				if (goal[i] != tempCurrRow[i])
				{
					missingnumber = i+1;
				}
			}

			cout<<"Replacing "<<board[currRow][currColumn]<<" with "<<missingnumber<<" at row "<<currRow+1<<" column "<<currColumn+1<<'\n'<<endl;

			board[currRow][currColumn] = missingnumber;

			cout<<"Current Working Board: "<<endl;

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
		}
	}

	cout<<"Solved Board: "<<endl;
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



	fileIn.close();

	return 0;
}