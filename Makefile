###############################################################################
# Makefile
##############################################################################

GreedSolver: GreedSolver.cpp GreedNode.o GreedTree.o
	g++ -ggdb -Wall -o GreedSolver GreedSolver.cpp GreedNode.o GreedTree.o    

GreedNode.o:
	g++ -ggdb -Wall -c GreedNode.cpp

GreedTree.o:
	g++ -ggdb -Wall -c GreedTree.cpp

clean: 
	rm -f solver GreedNode.o GreedTree.o a.out
