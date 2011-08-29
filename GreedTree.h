#include <iostream>
#include <cstdlib>

#include "GreedNode.h"

#ifndef _GREEDTREE_H
#define _GREEDTREE_H

class GreedTree
{
	public:
		GreedTree(int x, int y, greedMatrix& brd);

		~GreedTree();

		void buildTree();
	private:
		int m_nextNodeId;

		int startX;

		int startY;

		greedMatrix board;
};

#endif
