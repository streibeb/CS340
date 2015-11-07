//***************************************************************************
//Names: Nicholas Kowalchuk, Brayden Streibal, Evan Boyle
//Created: October 17th, 2015
//Last Modified: October 18th, 2015
//Purpose: Creates a connected graph and determines the weight and then
//		   creates a transition matrix based on the graph and generates
//         an output file of the transition matrix.
//***************************************************************************

#include <fstream>
#include <iostream>
#include "connectedGraph.h"

using namespace std;

int main ()
{
	ifstream input;
	ofstream outFile;
	Leader graph[(NODEAMOUNT+1)];
	float transitionMatrix[(NODEAMOUNT+1)][(NODEAMOUNT+1)];

	input.open("input.txt");
	outFile.open("transitionMatrix.txt");

	if (!(input))
	{
		cout << endl << endl << "ERROR: FILE UNABLE TO OPEN" << endl << endl;
		return 1;
	}

	//Create the directed graph
	CarlyRaeConnectedGraph(graph, input);
	VertexWeightTraversal(graph);
	
	//for testing
	//PrintConnectedGraph(graph);

	//Create the transition matrix
	CreateTransitionMatrix(graph, transitionMatrix);
	WriteTransitionMatrix(transitionMatrix, outFile);

	return 0;
}