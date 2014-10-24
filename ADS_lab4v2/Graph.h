#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

class Graph {
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
	list<int> BFS(int start) {
		list<int> order; //0. Order <- <>
		if(!inGraph(start)) return order;
		
		queue<int> q; //S - queue
		list<int> v; //visited

		int curr_start = start;
		while(!allChecked(order)) {
			v.push_back(curr_start); //1. Mark start as visited
			q.push(curr_start); //2. S <- {start}
			
			//we do the following for every segment, if the graph is connected, we do this only once
			while (q.size() > 0) { //3. If S == {} Return
				int curr = q.front();
				q.pop(); //this and line before: 4. v <- S.dequeue()
				order.push_back(curr); //5. order <- order + v
				list<int> *n = getNeighbors(curr);
				for(list<int>::iterator w = n->begin(); w != n->end() ; w++)
					if (!isVisited(v,*w)) { //6.1	If w is not visited
						v.push_back(*w); //6.1.1	Mark w as visited
						q.push(*w); //6.1.2	S.enqueue(w)
					}
				delete n;
				//7. Go to 3.
			}
			v.clear();
			while(q.size() > 0) q.pop();
			//for disconnected graph, we search for the first vertex that is not in the output
			// and repeat the algorithm for the segment that this found vertex is a part of
			if(!allChecked(order))
				for(int i = 0; i < getVerticesCount(); i++)
					if(!isVisited(order, i)) {
						curr_start = i;
						break;
					}
		}
		return order;
	}
	//list<int> BFS(int start)
	//{
	//	list<int> order; //0. Order <- <>
	//	queue<int> S; //S - queue
	//	list<int> visited;
	//	visited.push_back(start); // 1. Mark start as visited 
	//	S.push(start); // 2. S <- {start} 
	//	while(!S.empty()){ // 3. If S == {} Return
	//		int v =S.front();
	//		S.pop(); // 4. v <- S.dequeue()
	//		order.push_back(v); // 5. order <- order + v 
	//		list<int> *neighbours = getNeighbors(v);
	//		// neighbours->push_back(...);
	//		// (*neighbours).push_back(...);
	//		for (list<int>::iterator i = neighbours->begin(); i != neighbours->end() ; i++ ) { // 6. For each w: wv in E(G)
	//			int w = *i;
	//			bool w_is_visited = false;
	//			for (list<int>::iterator a = visited.begin(); a != visited.end() ; a++ ){
	//				if(*a==w) {
	//					w_is_visited =true;
	//					break;
	//				}
	//			}
	//			if(!w_is_visited) { // 6.1   If w is not visited
	//				visited.push_back(w); // 6.1.1   Mark w as visited
	//				S.push(w);// 6.1.2   S.enqueue(w)
	//			}
	//		}
	//		delete neighbours;
	//	} // 7. Go to 3.
	//	return order;
 //   }  
private:
	/*
	1 if vertex is in this graph, 0 otherwise
	*/
	int inGraph(int vertex) {
		if(vertex < 0) return 0;
		if(vertex >= getVerticesCount()) return 0;
		return 1;
	}

	/*
	1 if the vertex is visted, 0 otherwise
	*/
	int isVisited(list<int>& v, int vertex) {
		if(v.size() == 0) return 0;
		for (list<int>::iterator i = v.begin(); i != v.end(); i++)
			if (*i == vertex) return 1;
		return 0;
	}
	
	//checks if the list o has the same number of members as this list
	bool allChecked(list<int>& o) {
		if(o.size() == getVerticesCount()) return true;
		return false;
	}
};
