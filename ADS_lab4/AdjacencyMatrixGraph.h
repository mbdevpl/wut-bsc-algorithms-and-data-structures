#include <vector>
#include <queue>
#include <iostream>

#include "Graph.h"

using namespace std;

class AdjacencyMatrixGraph: 
	public Graph
{
public:
	 //lab2&3
	 AdjacencyMatrixGraph(int n=0);
	 AdjacencyMatrixGraph(const AdjacencyMatrixGraph&);
	 ~AdjacencyMatrixGraph();

	 int addEdge(int,int) override;
	 int removeEdge(int, int) override;	 	 
	 int areConnected(int,int) override;	 
	 void show() override; 

	 int getVerticesCount() override;
	 int getEdgesCount() override;	
	 int getDegree(int) override;	
	 int addVertex() override;	
	 int removeVertex(int) override;
	 list<int>* getNeighbors(int) override;

private:
	//adjacency matrix
	vector< vector<bool> > data;
	//some useful methods
	void int_desc(int* i1, int* i2);
};