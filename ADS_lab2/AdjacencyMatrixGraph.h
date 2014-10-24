#include <vector>
#include <iostream>

#include "Graph.h"

using namespace std;

class AdjacencyMatrixGraph: 
	public Graph
{
public:
	
	 int addEdge(int,int) override;
	 int removeEdge(int, int) override;	 	 
	 int areConnected(int,int) override;	 
	 void show() override; 

	 /*
	 creates a graph with given number of vertices and no edges
	 */
	 AdjacencyMatrixGraph(int n=0);
	 /*
	 creates a copy of a given graph
	 */
	 AdjacencyMatrixGraph(const AdjacencyMatrixGraph&);
	 
	 ~AdjacencyMatrixGraph();

/* second lab */
	 int getVerticesCount() override;
	 int getEdgesCount() override;	
	 int getDegree(int) override;	
	 int addVertex() override;	
	 int removeVertex(int) override;
	 list<int>* getNeighbors(int) override;


private:
	/*adjacency matrix*/
	vector< vector<bool> > data;
	//some useful methods
	void int_desc(int* i1, int* i2);
};