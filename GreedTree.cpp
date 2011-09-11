#include "GreedTree.h"

GreedTree::GreedTree(int x, int y, greedMatrix brd)
{
	startX = x;
	startY = y;

	board = brd;	
}

GreedTree::~GreedTree()
{
}

void GreedTree::buildTree()
{
	int initial = 500;
	int matrixSize = initial;
	int lastIdx = 1;

	GreedNode** tree = (GreedNode**)malloc(initial * sizeof(GreedNode*));
	tree[0] = new GreedNode(0, NULL, 0, (GreedNode::Direction)NULL);

	GreedNode node;
	greedMatrix matrix;
	GreedNode::Location loc;
	for (int i = 0; i < lastIdx; i++) 
	{
		node = *tree[i];
		matrix = node.getClearedMatrix();
		loc = node.getLocation();

		switch(node.getDirectionCameFrom())
		{
			case GreedNode::ABOVE:
				break;
			case GreedNode::BELOW:
				break;
			case GreedNode::LEFT:
				break;
			case GreedNode::RIGHT:
				break;
		}
	}

}
