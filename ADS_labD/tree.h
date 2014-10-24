#include "node.h"

class tree
{
private:
	node *root;

	//printing

	void printFrom(node* n) {
		if(n != NULL) {
			printFrom(n->left);
			//cout << "[" << n->data << "," << (n->left?"L":"-") << (n->right?"R":"-") << "," << n->bf << "] ";
			cout << n->data << ", ";
			printFrom(n->right);
		}
	}

	void printScheme(node* n) {
		if(n != NULL) {
			cout << "[" << n->data;
				
			if(n->bf)
				cout << "," << n->bf;
				
			if(n->left) {
				cout << ",L=";
				printScheme(n->left);
				//cout << " ";
			}

			if(n->right) {
				cout << ",R=";
				printScheme(n->right);
				//cout << " ";
			}
				
			cout << "] ";
		}
	}

	//searching

	bool searchFrom(node* n, int x) {
		if(n == NULL)
			return false;

		if(x == n->data)
			return true;
		else if(x < n->data)
			return searchFrom(n->right, x);
		else
			return searchFrom(n->left, x);
	}

	//inserting

	bool insertAt(node* n, int x) {
		if(n == NULL)
			return false;

		if(x == n->data)
			return false;
		else if(x < n->data) {
			if(n->left == NULL) {
				n->left = new node(x);
				n->bf--;
				return true;
			} else
				return insertAt(n->left, x);
		} else {
			if(n->right == NULL) {
				n->right = new node(x);
				n->bf++;
				return true;
			} else
				return insertAt(n->right, x);
		}
	}
	
	//balancing
		
	int getHeight(node* n) {
		//height of the node: means how many levels are below (when looking for maximum number of levels below)
		if(n == NULL)
			return 0;

		int leftH = 0, rightH = 0;

		if(n->left != NULL)
			leftH = 1 + getHeight(n->left);
		if(n->right != NULL)
			rightH = 1 + getHeight(n->right);

		return leftH>rightH ? leftH : rightH;
	}

	void calcBalance(node* n) {
		//calculates balances at all nodes that are children of n, and the n itself
		if(n == NULL)
			return;
			
		int heightL = 0;
		int heightR = 0;
		if(n->left)
			heightL = 1 + getHeight(n->left);
		if(n->right)
			heightR = 1 + getHeight(n->right);
			
		n->bf = heightR - heightL;

		if(n->left)
			calcBalance(n->left);
		if(n->right)
			calcBalance(n->right);
	}

	bool isBalanced(node* n) {
		//this function assumes that balance factor was calculated
		if(n == NULL)
			return true;

		if(n->bf <= 1 && n->bf >= -1) {
			bool balL = true, balR = true;
			if(n->left)
				balL = isBalanced(n->left);
			if(n->right)
				balR = isBalanced(n->right);
			return true && balL && balR;
		} else
			return false;
	}

	bool isNodeBalanced(node* n) {
		//this function assumes that balance factor was calculated
		if(n == NULL)
			return true;

		if(n->bf <= 1 && n->bf >= -1) {
			return true;
		} else
			return false;
	}

	void balance(node* n) {
		calcBalance(n);

		while(!isBalanced(n)) {
			//the while loop assumes that the balance factors are already calculated, and acts upon their values
			node* toSpin = NULL;
			if(n->right) {
				if(isNodeBalanced(n->right))
					balance(n->right);
				else {
					//the right child-node is unbalanced

					bool spinRight = true;
					bool spinTwo = false;
					if(n->right->bf > 0) {
						spinRight = false;
					}
					if(spinRight) {
						if(n->right->left)
							if(n->right->left->bf > 0)
								spinTwo = true;
					} else {
						if(n->right->right)
							if(n->right->right->bf < 0)
								spinTwo = true;
					}
					spin(n, true, spinRight, spinTwo);
				}
			}
			if(n->left) {
				if(isNodeBalanced(n->left))
					balance(n->left);
				else {
					//the left child-node is unbalanced

					bool spinRight = true;
					bool spinTwo = false;
					if(n->left->bf > 0) {
						spinRight = false;
					}
					if(spinRight) {
						if(n->left->left)
							if(n->left->left->bf > 0)
								spinTwo = true;
					} else {
						if(n->left->right)
							if(n->left->right->bf < 0)
								spinTwo = true;
					}
					spin(n, false, spinRight, spinTwo);
				}
			}

			calcBalance(n);
		}
	}

	void spin(node* n, bool rightChildIsSpinned, bool spinTheChildRight, bool spinTwoTimes) {
			
		bool right = rightChildIsSpinned;
		bool spinRight = spinTheChildRight;
		bool spinTwo = spinTwoTimes;

		//cout << "spin: right=" << right << ",spinRight=" << spinRight << ",spinTwo=" << spinTwo << "" << endl;

		node* toSpin = NULL; //the node that will spin
		if(right)
			toSpin = n->right;
		else
			toSpin = n->left;

		if(spinTwo) //case of double spin
			spin(toSpin, !spinRight, !spinRight, false);

		if(spinRight) { //spinning
			node* nodeBelow = toSpin->left->right;

			if(right) n->right = toSpin->left;
			else n->left = toSpin->left;

			toSpin->left = nodeBelow;

			if(right) n->right->right = toSpin;
			else n->left->right = toSpin;
		} else {
			node* nodeBelow = toSpin->right->left;
				
			if(right) n->right = toSpin->right;
			else n->left = toSpin->right;

			toSpin->right = nodeBelow;

			if(right) n->right->left = toSpin;
			else n->left->left = toSpin;
		}
	}

public:
	tree();		
	void display();
	bool insert(int);		
	bool search(int x);

	void printStructure() {
		printScheme(this->root);
		cout << "\n";
	}
};
