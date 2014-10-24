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



int inGraph(Graph& g, int vertex) {
	if(vertex < 0) return 0;
	if(vertex >= g.getVerticesCount()) return 0;
	return 1;
}

int isVisited(list<int>& v, int vertex) {
	if(v.size() == 0) return 0;
	for (list<int>::iterator i = v.begin(); i != v.end(); i++)
		if (*i == vertex) return 1;
	return 0;
}

bool allChecked(Graph& g, list<int>& o) {
	if(o.size() == g.getVerticesCount()) return true;
	return false;
}

list<int> Graph::BFS(int start) {
	list<int> order; //0. Order <- <>
	if(!inGraph(*this,start)) return order;
		
	queue<int> q; //S - queue
	list<int> v; //visited

	v.push_back(start); //1. Mark start as visited
	q.push(start); //2. S <- {start}
	while(!allChecked(*this,order)) {

		//we do the following for every segment, if the graph is connected, we do this only once
		while (q.size() > 0) { //3. If S == {} Return
			int curr = q.front();
			q.pop(); //this and line before: 4. v <- S.dequeue()
			order.push_back(curr); //5. order <- order + v
			for(int w = 0; w < getVerticesCount(); w++) //6. For each w: wv in E(G)
				if (areConnected(curr,w)) 
					if (!isVisited(v,w)) { //6.1	If w is not visited
						v.push_back(w); //6.1.1	Mark w as visited
						q.push(w); //6.1.2	S.enqueue(w)
					}
			//7. Go to 3.
		}
	}

	return order;
}


