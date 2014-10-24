#include <iostream>

using namespace std;

class node
{
	friend class tree;
	private:
		int data;
		node *left,*right;
		/* balance factor */
		int bf;

	public:
		node(int data)
		{
			this->data = data;
			this->bf = 0;
			this ->left = this->right = NULL;
		}

};


