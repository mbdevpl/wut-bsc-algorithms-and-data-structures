#include "AdjacencyMatrixGraph.h"

void main()
{
	AdjacencyMatrixGraph g = AdjacencyMatrixGraph(4);
	
/* first laboratories */
	
	cout << "add edge (0,0): " << g.addEdge(0,0) <<endl;
	cout << "add edge (0,7): " <<  g.addEdge(0,7) <<endl << endl;	
	g.show();

	cout << "add edge (0,1): " << g.addEdge(0,1) << endl;
	cout << "add edge (0,2): " << g.addEdge(0,2) << endl;

	AdjacencyMatrixGraph g1 = AdjacencyMatrixGraph(g);
	g1.show();
	cout<<endl;
	cout << "add edge (1,2): " << g.addEdge(1,2) << endl;
	cout << "add edge (2,3): " << g.addEdge(2,3) << endl;	
	cout << "add duplicate edge (2,3): " << g.addEdge(2,3) << endl << endl;
	
	g.show();
	cout<<endl;
	g1.show();

	cout << "check edge (0,1)" << g.areConnected(0,1) << endl;
	cout << "check edge (0,3)" << g.areConnected(0,3) << endl;
	cout << "check edge (0,7)" << g.areConnected(0,7) << endl;
	cout << "check edge (-1,7)" << g.areConnected(-1,7) << endl;

/* second laboratories */


	cout << "vertices: " << g.getVerticesCount() << endl;
	cout << "edges: " << g.getEdgesCount() << endl;

	cout << "deg(0): " << g.getDegree(0) << endl;
	cout << "deg(7): " << g.getDegree(7) << endl;

	cout << g.addVertex() << endl << endl;
	g.show();
	cout << g.removeVertex(4) << endl << endl;
	g.show();
	cout << g.removeVertex(4) << endl;


	list<int>::iterator i;
	list<int>* L = g.getNeighbors(0);
		
	for(i=L->begin(); i != L->end(); ++i)
		cout << *i << " ";
   cout << endl;

   delete L;

   L = g.getNeighbors(7);
   if (L!=NULL)
	   cout<<"Error";
   else
	   cout<<"OK";
  
}