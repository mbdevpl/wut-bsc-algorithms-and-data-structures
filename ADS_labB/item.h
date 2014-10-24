#ifndef INCL_ITEM

#include <string>
#include <iostream>
using namespace std;
#define INCL_ITEM

class item
{
private:
	string value;

public:
	item(string val);
	item();
	string getValue();	
	int getLength();
	char operator[] (int index);
	friend ostream & operator<< (ostream & out, const item & it);
};
#endif