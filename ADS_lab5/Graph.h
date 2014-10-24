#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <list>
#include <iostream>
#include <stack>
#include <algorithm>
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

	
	//Adrian's code, only for tests
	int colorEdges2(int** colors) {
		int c =0;
		for(int i=0;i<this->getVerticesCount();i++)
		for(int j=0;j<this->getVerticesCount();j++)
		colors[i][j]=0;

		vector<vector<int> >degrees;
		for(int i=0;i<this->getVerticesCount();i++){
			for(int j=0;j<i;j++)
				if(this->areConnected(i,j)){
				vector<int> edgedegree;
				edgedegree.push_back(this->getDegree(i)+this->getDegree(j));
				edgedegree.push_back(i);
				edgedegree.push_back(j);
				degrees.push_back(edgedegree);}
		}
		sort(degrees.begin(),degrees.end());
		while(degrees.size()){
			for(int k=1;k<this->getVerticesCount()+1;k++)
			if(this->allow(colors,*(degrees.back().begin()+1),*(degrees.back().begin()+2),k)){
			colors[*(degrees.back().begin()+2)][*(degrees.back().begin()+1)]=k;
			colors[*(degrees.back().begin()+1)][*(degrees.back().begin()+2)]=k;
			if(k>c) c=k;
			break;}
			degrees.pop_back();}
		/* do not remove next 3 lines */
		if (!this->isEdgeColoringCorrect(colors))
			cout << endl << "* Improper coloring! *" << endl;
		return c;
	}
	bool allow(int** graph,int b,int c,int a){
		for(int i=0;i<this->getVerticesCount();i++)
			if(graph[i][c]==a || graph[b][i]==a)
				return false;
		return true;
	}
	//end of Adrian's code

	/*
	Greedy algorithm for edge coloring of the graph
	Returns: the number of colors used
	Table colors[][] represents the colors of the edges.
	If colors[i][j]=0, there is no edge between vertices i and j
	If colors[i][j]=c (c > 0), the edge (i,j) has color c.
	*/
	int colorEdges(int** colors) {
		//set all colours to zero, because array is not known
		for(int x=0; x<getVerticesCount(); x++)
			for(int y=0; y<getVerticesCount(); y++)
				colors[x][y] = (colors[y][x] = 0);
		
		//vector< vector<bool> > colored(getVerticesCount(),vector<bool>(getVerticesCount(), false));
		int c = 0; //highest colour used
		int colored_num = 0; //number of colored edges

		while(colored_num < getEdgesCount()) { //1. If all the edges are coloured return max color used
			list<int> *neigh = NULL;
			//finding the edge v1-v2, with the highest sum of deg(v1) and deg(v2)
			// in degree calculations, I am excluding already colored edges
			// and that improves the algorithm
			int v1 = 0, v2 = 0, maxdeg = 0;
			for(int i = 0; i < getVerticesCount(); i++) {
				neigh = getNeighbors(i);
				for(list<int>::iterator n =  neigh->begin(); n != neigh->end(); n++) {
					int deg = getDegree(i) - numColored(i, colors)
						+ getDegree(*n) - numColored(*n, colors);
					if((i != *n) && (!colors[i][*n]) && (deg > maxdeg)) {
						v1 = i;
						v2 = *n;
						maxdeg = deg;
					}
				}
				//memory cleanup
				delete neigh;
				neigh = NULL;
			}
			//2. Let e=(v,w) be uncolored edge with the highest value of deg(v)+deg(w).
			// this edge e is equal (v1,v2)
			vector<bool> used(getEdgesCount(), false); //number of distinct colours is not greater than num of edges
			list<int> *n1 = getNeighbors(v1);
			for(list<int>::iterator i = n1->begin(); i != n1->end(); i++)
				if(colors[v1][*i]) used[ colors[v1][*i] ] = true;
			list<int> *n2 = getNeighbors(v2);
			for(list<int>::iterator i = n2->begin(); i != n2->end(); i++)
				if(colors[v2][*i]) used[ colors[v2][*i] ] = true;
			//memory cleanup
			delete n1;
			delete n2;
			n1 = NULL;
			n2 = NULL;
			//3. Color e with the smallest available color (not in conflict with any other incident edges)
			//I find this color by checking vector "used"
			int curr_color = 0;
			for(int x=1; !curr_color && x<getEdgesCount(); x++)
				if(!used[x]) curr_color = x;
			//coloring
			colors[v1][v2] = curr_color;
			colors[v2][v1] = curr_color;
			if(curr_color > c) c = curr_color;
			colored_num++;
		} //4. Go to 1.
		/* do not remove next 3 lines */
		if (!this->isEdgeColoringCorrect(colors))
			cout << endl << "* Improper coloring! *" << endl;
		return c;
	}
	//printout of colors matrix
	void colorsPrint(int** colors) {
		for(int x=0; x<getVerticesCount(); x++) {
			for(int y=0; y<getVerticesCount(); y++)
				cout << colors[x][y];
			cout << endl;
		}
		cout << endl;
	}
private:
	//returns number of colored edges that are adjecent to a given vertex
	int numColored(int v, int** colors) {
		int edgesnum = 0;
		for(int i=0; i<getVerticesCount(); i++)
			if(i != v && colors[v][i] != 0) edgesnum++;
		return edgesnum;
	}

	/*
	Returns true if given edge coloring is correct and false otherwise
	(I know it's not the most effective implementation)
	*/
	bool isEdgeColoringCorrect(int** colors)
	{
		int n = this->getVerticesCount();
			
		for (int i=0; i<n;++i)			
			for (int j=0; j<n;++j)
				for (int k=0; k<n;++k)
				{
					if(i==k) continue;
					if (!this->areConnected(i,j))
					{
						if (colors[i][j]!=0)
							return false;
					}
					else if (this->areConnected(j,k))
					{
						if (colors[i][j]==colors[j][k])
							return false;
					}					
				}
		
		return true;
	}

	//previous task
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

#endif
