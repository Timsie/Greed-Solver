#include <iostream>
#include <cstdlib>

#include "GreedNode.h"

#ifndef _GREEDTREE_H
#define _GREEDTREE_H

class GreedTree
{
	public:
		GreedTree(int startx, int starty, greedMatrix& board);

		~GreedTree();

		void buildTree();
	private:
		int m_nextNodeId;
};

#endif
