#include "tree.h"

tree::tree()
{
	root=NULL;
}
		
void tree::display() /* 0.5 pts */
{
	/* prints the elements in the tree in sorted order */
	printFrom(this->root);
	cout << "\n";
}

bool tree::search(int x) /* 1 point */
{
	/*
		Returns true if x exists in the tree and false otherwise.
	*/
	return searchFrom(this->root, x);
}

bool tree::insert(int x) /* 2.5 points */
{
	/* adds an element to the tree 

	If the element already exists in the tree, no element is added and false is returned.
	Otherwise, a new element is added to a tree and true is returned.
	*/
	if(this->root == NULL) {
		this->root = new node(x);
		return true;
	}

	bool inserted = insertAt(this->root, x);
	
	if(inserted) {
		calcBalance(this->root);
		if(!isNodeBalanced(this->root)) {
			//the root of all things is unbalanced, what an unpleasant crisis

			//cout << " root ";
			//printStructure();

			node* n = new node(0); // n will be a temporary parent of the root
			n->right = this->root;

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

			//removal of the foster parent
			this->root = n->right;
			delete n;

			calcBalance(this->root);

			//printStructure();
		}

		if(!isBalanced(this->root)) {
			//cout << " tree ";
			//printStructure();
			balance(this->root);
			//printStructure();
		}
	}

	return inserted;
}
