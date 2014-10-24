#include "item.h"

int item::comparisonCount=0;

item::item(int val)
{
	value = val;
}
item::item()
{
	value = 0;
}
void item::resetComparisonCount()
{
	item::comparisonCount=0;
}

int item::getComparisonCount()
{
	return item::comparisonCount;
}

void item::setValue(int val)
{
	value = val;
}

int item::getValue()
{
	return value;
}

ostream & operator<< (ostream & out, const item & it)
{
	return out << it.value;
}

bool operator> (item &it1, item &it2)
{
	item::comparisonCount++;
	return it1.value > it2.value;
}
bool operator< (item &it1, item &it2)
{
	item::comparisonCount++;
	return it1.value < it2.value;
} 
bool operator>= (item &it1, item &it2)
{
	item::comparisonCount++;
	return it1.value >= it2.value;
}
bool operator<= (item &it1, item &it2)
{
	item::comparisonCount++;
	return it1.value <= it2.value;
}
bool operator== (item &it1, item &it2)
{
	item::comparisonCount++;
	return it1.value == it2.value;
}
bool operator!= (item &it1, item &it2)
{
	item::comparisonCount++;
	return it1.value != it2.value;
}