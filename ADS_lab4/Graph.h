#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
	/*
	Adds an edge between given vertices. 
	If the edge already exists or we try to add a loop, no edge is added.
	Returns:
	0 if an edge is added
	-1 if we try to create a loop
	-2 if there are no such vertices
	-3 if the edge already exists
	*/
	 virtual int addEdge(int,int) abstract;

	 /*	
	 Removes an edge between given vertices. 
	 If the edge does not exist, nothing is changed.
	 Returns:
	 0 if an edge is removed 
	 -1 if an edge does not exist
	 -2 if vertices do not exist
	 */
	 virtual int removeEdge(int, int) abstract;
	
	/*
	Returns:
	1 if given vertices are connected by an egde
	0 if the vertices are not connected
	-1 if the vertices do not exist
	*/
	 virtual int areConnected(int,int) abstract;

	 /*
	 Prints the representation of a graph.
	 */
	virtual void show() abstract;	  

/* second lab */

	 /*
	Adds new isolated vertex to a graph.
	Returns:
	0 if everything is OK
	-1 in case of error (e.g. with memory allocation).
	*/
	 virtual int addVertex() abstract;

	/*
	Removes given vertex from the graph and all the edges containing it.
	Returns:
	0 if no error occurs 
	-1 otherwise
	*/
	 virtual int removeVertex(int) abstract;

	/*
	Returns the number of vertices in a graph.
	*/
	 virtual int getVerticesCount() abstract;

	 /*
	Returns the number of edges in a graph.
	*/
	 virtual int getEdgesCount() abstract;	


	 /*
	 Returns:
	 degree of the given vertex
	 -1 if no such vertex exists.
	 */
	virtual int getDegree(int) abstract;	

	/*
	Returns:
	a pointer to the list of neighbors of a given vertex (for isolated vertex list is empty)
	null if no such vertex exists
	*/
	virtual list<int>* getNeighbors(int) abstract;


	/* Implement breadth-first-search algorithm using only the methods of the class Graph 
	Returns order of vertices in BFS starting from 'start' vertex.

	3pt - algorithm working for a connected graph
	4pt - algorithm working for a disconnected graph
	*/
	list<int> BFS(int start);
	//{
	//	/*
	//	PSEUDOCODE (for a connected graph):
	//	S - queue
	//	
	//	0. Order <- <>
	//	1. Mark start as visited
	//	2. S <- {start}		
	//	3. If S == {} Return
	//	4. v <- S.dequeue()
	//	5. order <- order + v
	//	6. For each w: wv in E(G)
	//	6.1	If w is not visited
	//	6.1.1	Mark w as visited
	//	6.1.2	S.enqueue(w)
	//	7. Go to 3.
	//	*/

	//	list<int> order;
	//	return order;
	//}
//private:
	//int inGraph(int vertex);
	//int isVisited(list<int>& v, int vertex);
	//bool allChecked(list<int>& o);
};
