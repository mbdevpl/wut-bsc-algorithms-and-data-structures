#include "AdjacencyMatrixGraph.h"
//#include "AdjacencyListGraph.h"  

#define GRAPH AdjacencyMatrixGraph
//#define GRAPH AdjacencyListGraph		(uncomment your graph type)


void main()
{
	GRAPH g1 = GRAPH(5);	

	g1.addEdge(0,1);
	g1.addEdge(1,2);
	g1.addEdge(2,3);
	g1.addEdge(1,3);
	g1.addEdge(3,4);
	g1.addEdge(0,4);
	
	if (g1.isBipartite())
		cout << "something is wrong for g1..." << endl;
	else
		cout << "g1 ok" << endl;
	

	GRAPH g2 = GRAPH(5);	

	
	if (!g2.isBipartite())
		cout << "something is wrong for g2..." << endl;
	else
		cout << "g2 ok" << endl;
	
	GRAPH g3 = GRAPH(4);	

	g3.addEdge(0,1);
	g3.addEdge(1,2);
	g3.addEdge(2,3);
	g3.addEdge(3,0);
	if (!g3.isBipartite())
		cout << "something is wrong for g3..." << endl;
	else
		cout << "g3 ok" << endl;

}

