#include "AdjacencyMatrixGraph.h"

void AdjacencyMatrixGraph::int_desc(int* i1, int* i2) { //this is for triangle matrix
	//sorts two given integers in descending order
	if((i1 != NULL) && (i2 != NULL) && (*i2 > *i1)) {
		int temp = *i2;
		*i2 = *i1;
		*i1 = temp;
	}
}

AdjacencyMatrixGraph::AdjacencyMatrixGraph(int n):data(0, vector<bool>(0)) {
	if (n>0) try {
		if(n > (int)data.max_size()) throw new exception;
		data.resize(n);
		for(int i = 0; i < n; i++) {
			data[i].resize(i);
			for(int j = 0; j < i; j++)
				data[i][j] = false;
		}
	} catch (exception e) { cout << "error, n is too large"; }
}

AdjacencyMatrixGraph::AdjacencyMatrixGraph(const AdjacencyMatrixGraph& src):data(src.data) {
}

AdjacencyMatrixGraph::~AdjacencyMatrixGraph() {
}

int AdjacencyMatrixGraph::addEdge(int v1, int v2) {
	switch (int i = areConnected(v1,v2)) {
		case -1: return -2; //no such vertices
		case 1: return -3; //edge already exists
	}
	if (v1 == v2) return -1; //loop
	int_desc(&v1, &v2);
	data[v1][v2] = true;
	return 0;
}

int AdjacencyMatrixGraph::removeEdge(int v1, int v2) {
	switch (int i = areConnected(v1,v2)) {
		case -1: return -2; //no such vertices
		case 0: return -1; //edge does not exist
	}
	int_desc(&v1, &v2);
	data[v1][v2] = false;
	return 0;
}

int AdjacencyMatrixGraph::areConnected(int v1, int v2) {
	if ((v1 >= (int)data.size()) || (v2 >= (int)data.size())) return -1; //no such vertices
	if (v1 == v2) return 0; //no connection, because these are not allowed
	int_desc(&v1, &v2);
	return (data[v1][v2] ? 1 : 0);
}

void AdjacencyMatrixGraph::show() {
	//prints the matrix nicely for: n > 0 and n < 100
	//of course, console does not cooperate with this...
	//for n == 0 prints info that graph is empty
	int n = (int)data.size();
	if (data.size() == 0)
		cout << "The graph has no vertices.\n";
	else {
		cout << "  ";
		for(int i = 0; i < n; i++)
			cout << " " << (i<10 && n>9 ? " " : "") << i;
		cout << endl;
		for(int i = 0; i < n; i++) {
			cout << " " << (i<10 && n>9 ? " " : "") << i << " ";
			for(int j = 0; j < (int)data[i].size(); j++) {
				cout << (data[i][j] ? 1 : 0);
				if (j < n - 1) cout << (n>9 ? " " : "") << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

int AdjacencyMatrixGraph::getVerticesCount() {
	return data.size();
}

int AdjacencyMatrixGraph::getEdgesCount() {
	int count = 0;
	for(int i = 0; i < (int)data.size(); i++)
		for(int j = 0; j < i; j++)
			if (data[i][j]) count++;
	return count;
}

int AdjacencyMatrixGraph::getDegree(int v) {
	if (v >= (int)data.size()) return -1;
	int deg = 0;
	for (int i = 0; i < (int)data.size(); i++)
		if (areConnected(v,i) == 1) deg++;
	return deg;
}

int AdjacencyMatrixGraph::addVertex() {
	int curr_size = (int)data.size();
	try {
		if(curr_size+1 > (int)data.max_size()) throw new exception;
		data.resize(curr_size+1);
		data[curr_size].resize(curr_size);
	} catch (exception e) { return -1; }
	for(int i = 0; i < curr_size; i++)
		data[curr_size][i] = false;
	return 0;
}

int AdjacencyMatrixGraph::removeVertex(int v) {
	int curr_size = (int)data.size();
	if (v >= (int)data.size()) return -1;
	try {
		for(int i = 0; i < curr_size; i++) { //erasing vertical data
			if ((int)data[i].size() > v)
				data[i].erase(data[i].begin() + v);
		}
		data.erase(data.begin() + v); //and horizontal
	} catch (exception e) { return -1; }
	return 0;
}

list<int>* AdjacencyMatrixGraph::getNeighbors(int v) {
	if (v >= (int)data.size()) return 0; //null
	list<int>* neighbours = new list<int>(0);
	for(int i = 0; i < (int)data.size(); i++) {
		//cout << "*";
		if(areConnected(v,i) == 1) {
			neighbours->push_back(i);
			//cout << i;
		}
	}
	//cout << endl;
	return neighbours;
}
