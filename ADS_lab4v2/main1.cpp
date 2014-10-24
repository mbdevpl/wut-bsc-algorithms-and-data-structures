#include "AdjacencyMatrixGraph.h"
//#include "AdjacencyListGraph.h"  

#define GRAPH AdjacencyMatrixGraph
//#define GRAPH AdjacencyListGraph		(uncomment your graph type)

void main()
{
	GRAPH g_con = GRAPH(7);
	
	g_con.addEdge(0,1);
	g_con.addEdge(1,2);
	g_con.addEdge(2,3);
	g_con.addEdge(3,4);
	g_con.addEdge(3,4);
	g_con.addEdge(4,5);
	g_con.addEdge(4,6);

	list<int> bfs1 = g_con.BFS(2);
	
	cout << "Connected" <<endl;
	for( list<int>::iterator i=bfs1.begin(); i != bfs1.end(); ++i)
		cout << *i << " ";
	cout << endl;


	GRAPH g_dis = GRAPH(7);
	
	g_dis.addEdge(0,1);
	g_dis.addEdge(1,2);
	g_dis.addEdge(0,2);
	g_dis.addEdge(2,3);
	g_dis.addEdge(4,5);
	

	list<int> bfs2 = g_dis.BFS(1);
	
	cout << "Disconnected" <<endl;
	for( list<int>::iterator i=bfs2.begin(); i != bfs2.end(); ++i)
		cout << *i << " ";
	cout << endl;


}
