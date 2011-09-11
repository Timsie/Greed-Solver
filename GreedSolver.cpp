#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstdlib>

#include "GreedTree.h"

using namespace std;

void printMatrix (greedMatrix array)
{
	for (int r = 0; r < 22; r++)
	{
		for (int c = 0; c < 80; c++)
		{
			cout << array.get(r,c);
		}
		cout << endl;
	}
}

int main (int argc, char ** argv)
{
	cout << "Welcome to the Greed solver" << endl;

	/* check arg count */
	if (argc < 4)
	{
		cout << "\tUsage: ./GreedSolver [board file] [x start] [y start]" << endl;
		return 0;
	}

	/* starting position for the game */
	int startx = atoi(argv[2]);
	int starty = atoi(argv[3]);

	char nextVal = 0;

	/* row and column counters for populating board array */
	int rowMax = 22;
	int colMax = 80;
	int row = 0;
	int col = 0;

	/* array representing the board */
	greedMatrix boardArray;

	/* open board file */
	cout << "\tReading board from " << argv[1] << endl;
	FILE * board = fopen (argv[1], "r");

	/* make sure it's open */
	if (NULL == board)
	{
		cout << "\tUnable to open file " << argv[1]
			 << " for reading. Please make sure it exists." << endl;

		return 0;
	}

	/* read the board into an array */
	while (fscanf(board, "%c", &nextVal) != EOF)
	{
		if (row > rowMax)
		{
			/* end of the columns, we're at the maximum */
			/* this shouldn't happen, if it does we bail */
			cout << "\tERROR: read in too many rows. Exiting." << endl;
			return 0;
		}
		if (col >= colMax)
		{
			/* end of the row, reset to the beginning of the next */
			col = 0;
			row ++;
		}
		
		/* newlines need not apply */
		if (nextVal != '\n')
		{
			boardArray.get(row,col) = atoi(&nextVal);
			col ++;
		}
	}

	cout << "\tYou are starting at coordinates (" 
		 << startx << ", " << starty << ")" << endl;
	
	cout <<"\tBuilding move tree..." << endl;

	GreedTree* tree = new GreedTree(startx, starty, boardArray);
	(*tree).buildTree();

	return 1;
}
