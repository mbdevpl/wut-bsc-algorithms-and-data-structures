#include "Stack.h"

class ListStack :
	public Stack
{	
public:
	ListStack();
	~ListStack();	
	int push(int) override ; //O(1)
	int pop(int*) override ; //O(1)
	int getCount() override; //O(1)
	int top(int*) override;  //O(1)
	void clear() override;   //O(n)
	bool isEmpty() override; //O(1)
	void print() override;   //O(n)
	
private:
	struct node
	{
	public:
		int value;
		node* next;
	};

	node* head;
	int count;
};

