#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <list>
#include <iostream>
#include <queue>
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

	
	/*
		Returns true if graphs is bipartite and false otherwise.
		A graph is called bipartite if and only if its vertex set V can be divided into two sets X,Y, such that:
		X n Y is emptyset
		X u Y = V
		
		For each v,w in X, (v,w) is not contained by E(G).
		For each v,w in Y, (v,w) is not contained by E(G).

		Hint:
			Change your (or given below) BFS or DFS algorithm.
	*/
	bool isBipartite() {
		//list<int> order;		
		int n = getVerticesCount();
		if(!n) return true;
		
		int* visited = new int[n];
		for (int i=0; i<n; ++i) visited[i]=0;
		
		queue<int> q; //S - queue
		int curr_start = 0; //this can be anything from 0 to getVerticesCount()-1

		int orderedCount = 0;
		while(orderedCount < n) {
			for(int i = 0; i <n; i++)
				if(!visited[i]) {
					curr_start = i;
					break;
				}
			visited[curr_start] = 1; //1. Mark start as visited (for example in set 1, but may be also 2)
			q.push(curr_start); //2. S <- {start}

			//we do the following for every component (if the graph is connected, we do this only once)
			while (q.size() > 0) { //3. If S == {} Return
				int curr = q.front();
				q.pop(); //this and line before: 4. v <- S.dequeue()
				//order.push_back(curr); //5. order <- order + v
				orderedCount++;
				list<int> *nei = getNeighbors(curr);
				for(list<int>::iterator w = nei->begin(); w != nei->end() ; w++) {
					//cout << "visit[curr]=" << visited[curr] << ", ";
					if (visited[*w] == 0) { //6.1	If w is not visited
						//6.1.1	Mark w as visited (to the 1st or 2nd set)
						if(visited[curr] == 1) visited[*w] = 2;
						else visited[*w] = 1;
						q.push(*w); //6.1.2	S.enqueue(w)
					}
					else if(visited[*w]==visited[curr])
						return false;
					//else cout << "visit[*w]=" << visited[*w] << ", ";
				}
				delete nei;
				//7. Go to 3.
			}
		}
		delete[] visited;
		return true;
	}
	
//private:
	/* 
	Returns the order of the vertices traversed in BFS order.
	Based on the solution by Mateusz Bysiek
	*/
	list<int> BFS() {		
		list<int> order;		
		int n = getVerticesCount();
		if(!n) return order;
		bool* visited = new bool[n] ;

		for (int i=0; i<n; ++i)
			visited[i]=false;

		int orderedCount=0;
		
		queue<int> q; //S - queue
		
		int curr_start = 0;
		while(orderedCount < n)
		{			
				for(int i = 0; i <n; i++)
					if(!visited[i]) 
					{
						curr_start = i;
						break;
					}
			visited[curr_start]=true; //1. Mark start as visited
			q.push(curr_start); //2. S <- {start}
		
			//we do the following for every component (if the graph is connected, we do this only once)
			while (q.size() > 0) 
			{ //3. If S == {} Return
				int curr = q.front();
				q.pop(); //this and line before: 4. v <- S.dequeue()
				order.push_back(curr); //5. order <- order + v
				orderedCount++;
				list<int> *nei = getNeighbors(curr);
				for(list<int>::iterator w = nei->begin(); w != nei->end() ; w++)
					if (!visited[*w])
					{ //6.1	If w is not visited
						visited[*w] = true; //6.1.1	Mark w as visited
						q.push(*w); //6.1.2	S.enqueue(w)
					}
				delete nei;
				//7. Go to 3.
			}				
			
		}
		delete[] visited;
		return order;
	}

};

#endif
