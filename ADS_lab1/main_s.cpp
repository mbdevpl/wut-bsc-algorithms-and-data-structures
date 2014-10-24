#include "ListStack.h"

using namespace std;

int main()
{
	int item = 0;
	cout << "\nStack\n";
	Stack* s = new ListStack;	
	s->print();
	s->pop();	
	s->print();
	s->push(2);	
	s->print();
	s->push(1);	
	s->print();
	s->push(3);	
	s->print();
	s->pop(&item);	
	cout<<endl<<item<<endl;
	s->print();
	s->pop(&item);	
	cout<<endl<<item<<endl;
	s->print();
	s->pop(&item);	
	cout<<endl<<item<<endl;
	s->print();
	s->pop(&item);	
	s->print();
}