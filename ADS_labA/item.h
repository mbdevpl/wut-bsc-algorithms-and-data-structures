#ifndef INCL_ITEM

#include <iostream>
using namespace std;
#define INCL_ITEM
/* comparable items */
class item
{
private:
	int value;
	static int comparisonCount;

public:
	item(int val);
	item();
	static void resetComparisonCount();
	static int getComparisonCount();
	int getValue();
	void setValue(int);

	friend ostream & operator<< (ostream & out, const item & it);
    friend bool operator> (item &it1, item &it2);
	friend bool operator< (item &it1, item &it2);
    friend bool operator<= (item &it1, item &it2);
    friend bool operator>= (item &it1, item &it2);
	friend bool operator== (item &it1, item &it2);
	friend bool operator!= (item &it1, item &it2);
};
#endif