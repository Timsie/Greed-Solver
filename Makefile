###############################################################################
# Makefile
##############################################################################

GreedSolver: GreedNode.o GreedTree.o
	g++ -Wall -o GreedSolver GreedSolver.cpp GreedNode.o GreedTree.o    

GreedNode.o:
	g++ -Wall -c GreedNode.cpp

GreedTree.o:
	g++ -Wall -c GreedTree.cpp

clean: 
	rm -f solver GreedNode.o GreedTree.o a.out
