#include "Graph.h"

using namespace std;

class AdjacencyListGraph: 
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
	 AdjacencyListGraph(int n=0);
	 /*
	 creates a copy of a given graph
	 */
	 AdjacencyListGraph(const AdjacencyListGraph&);
	 
	 ~AdjacencyListGraph();


	 /* second lab
	 int getVerticesCount() override;
	 int getEdgesCount() override;	
	 int getDegree(int) override;	
	 int addVertex() override;	
	 int removeVertex(int) override;
	 list<int>* getNeighbors(int) override;
*/

private:
	/*adjacency list*/
};