#include <iostream>
#include <cstdlib>

#include "GreedNode.h"

#ifndef _GREEDTREE_H
#define _GREEDTREE_H

class GreedTree
{
	public:
		//default constructor
		GreedTree();

		//constructor
		GreedTree(int x, int y, greedMatrix brd);

		//Destructor
		~GreedTree();

		//will build and populate a tree full of possible moves
		void buildTree();
	private:
		//where cursor starts on the board, x position
		int startX;

		//where cursor starts on the board, y position
		int startY;

		//represents the game board
		greedMatrix board;
};

#endif
