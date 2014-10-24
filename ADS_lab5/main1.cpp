#include "AdjacencyMatrixGraph.h"
//#include "AdjacencyListGraph.h"  

#define GRAPH AdjacencyMatrixGraph
//#define GRAPH AdjacencyListGraph		(uncomment your graph type)


int** allocate(int n)
{
	int** a = new int* [n];
	for (int i=0; i<n; ++i)
		a[i]=new int[n];
	return a;
}

void clear(int** a, int n)
{
	for( int i = 0 ; i < n ; i++ )
		delete [] a[i] ;
	delete [] a;
}


void main()
{
	GRAPH g_house = GRAPH(5);
	int** colors_house = allocate(5);
	g_house.addEdge(0,1);
	g_house.addEdge(1,2);
	g_house.addEdge(2,3);
	g_house.addEdge(1,3);
	g_house.addEdge(3,4);
	g_house.addEdge(0,4);
	cout << "House: " << g_house.colorEdges(colors_house) << endl;
	clear(colors_house,5);

	GRAPH g_houses = GRAPH(10);
	int** colors_houses = allocate(10);
	g_houses.addEdge(0,1);
	g_houses.addEdge(1,2);
	g_houses.addEdge(2,3);
	g_houses.addEdge(1,3);
	g_houses.addEdge(3,4);
	g_houses.addEdge(0,4);
	g_houses.addEdge(5,6);
	g_houses.addEdge(6,7);
	g_houses.addEdge(7,8);
	g_houses.addEdge(6,8);
	g_houses.addEdge(8,9);
	g_houses.addEdge(5,9);
	cout << "Houses: " << g_houses.colorEdges(colors_houses) << endl;
	clear(colors_houses,10);
	
	GRAPH g_spider = GRAPH(9);
	int** colors_spider = allocate(9);
	g_spider.addEdge(0,1);
	g_spider.addEdge(0,2);
	g_spider.addEdge(0,3);
	g_spider.addEdge(0,4);
	g_spider.addEdge(1,5);
	g_spider.addEdge(2,6);
	g_spider.addEdge(3,7);
	g_spider.addEdge(4,8);
	cout << "Spider: " << g_spider.colorEdges(colors_spider) << endl;
	clear(colors_spider,9);
	
	GRAPH g_penta = GRAPH(5);
	int** colors_penta = allocate(5);
	g_penta.addEdge(0,1);
	g_penta.addEdge(1,2);
	g_penta.addEdge(2,3);
	g_penta.addEdge(3,4);
	g_penta.addEdge(4,0);
	g_penta.addEdge(0,2);
	g_penta.addEdge(0,3);
	g_penta.addEdge(1,3);
	g_penta.addEdge(1,4);
	g_penta.addEdge(2,4);
	cout << "Penta: " << g_penta.colorEdges(colors_penta) << endl;
	//g_penta.show();
	//g_penta.colorsPrint(colors_penta);
	clear(colors_penta,5);

	GRAPH g_hex = GRAPH(6);
	int** colors_hex = allocate(6);
	g_hex.addEdge(0,1);
	g_hex.addEdge(0,2);
	g_hex.addEdge(0,3);
	g_hex.addEdge(0,4);
	g_hex.addEdge(0,5);
	g_hex.addEdge(1,2);
	g_hex.addEdge(1,3);
	g_hex.addEdge(1,4);
	g_hex.addEdge(1,5);
	g_hex.addEdge(2,3);
	g_hex.addEdge(2,4);
	g_hex.addEdge(2,5);
	g_hex.addEdge(3,4);
	g_hex.addEdge(3,5);
	g_hex.addEdge(4,5);
	cout << "Hex: " << g_hex.colorEdges(colors_hex) << endl;
	//g_hex.show();
	//g_hex.colorsPrint(colors_hex);
	clear(colors_hex,6);
	
	GRAPH g_newdesign = GRAPH(7);
	int** colors_newdesign = allocate(7);
	g_newdesign.addEdge(0,1);
	g_newdesign.addEdge(0,2);
	g_newdesign.addEdge(0,3);
	g_newdesign.addEdge(3,4);
	g_newdesign.addEdge(3,5);
	g_newdesign.addEdge(0,6);
	g_newdesign.addEdge(3,6);
	cout << "New design: " << g_newdesign.colorEdges(colors_newdesign) << endl;
	//g_newdesign.show();
	//g_newdesign.colorsPrint(colors_newdesign);
	clear(colors_newdesign,7);
}

