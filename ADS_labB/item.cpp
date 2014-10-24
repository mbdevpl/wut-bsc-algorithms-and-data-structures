#include "item.h"

item::item(string val)
{
	value = val;
}
item::item()
{
	value = "";
}

string item::getValue()
{
	return value;
}

int item::getLength()
{
	return value.length();
}

ostream & operator<< (ostream & out, const item & it)
{
	return out << it.value << endl;
}


char item::operator[] (int index)
{
	return this->value[index];
}
