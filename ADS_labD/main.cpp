#include "tree.h"
#include <time.h>
#include <vector>

void createPreparedTree() {
	tree tr;
	cout << "prepared AVL tree:" << endl;
	//int arr[]  = {217, -186, 179}; //works now
	//int arr[]  = {10, 30, 20}; //works now
	int arr[]  = {50, 40, 30, 20, 80, 90, 60, 70};
	int arrLen = 8;
	for(int i = 0; i < arrLen; i++) {
		cout << " ...inserting " << arr[i] << ": " << tr.insert(arr[i]) << endl;
		//tr.display();
		//tr.printStructure();
	}
}

void createRandomTree() {
	srand((unsigned int)time(NULL));
	cout << "random AVL tree:" << endl;
	tree t;
	for(int i = 0; i < 200; i++) {
		int val = rand() % 1999 - 999;
		//int val = i;
		cout << " ...inserting " << val << "\n";
		t.insert(val);
		//t.display();
		//t.printStructure();
	}
	t.display();
	t.printStructure();
}

void defaultMain() {
	tree t;
	cout << "search 1: " << t.search(1) << endl;
	cout << "insert 3: " << t.insert(3) << endl;
	cout << "insert 1: " << t.insert(1) << endl;
	cout << "search 1: " << t.search(1) << endl;
	cout << "insert 7: " << t.insert(7) << endl;
	cout << "insert 5: " << t.insert(5) << endl;
	cout << "insert 2: " << t.insert(2) << endl;
	cout << "insert 2: " << t.insert(2) << endl;
	cout << "insert 6: " << t.insert(6) << endl;
	t.display();
}

void main()
{
	//defaultMain();
	//createPreparedTree();
	createRandomTree();
}
