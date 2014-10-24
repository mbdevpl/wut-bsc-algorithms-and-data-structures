#include "knapsack.h"

void show(int capacity, list<item> items)
{
	cout <<"*******************" << endl;
	list<item> chosen = solveKnapsack(capacity, items);
	cout << "Weight: " << getTotalWeight(chosen) << "/" << capacity << endl;;
	cout << "Value:  " << getTotalValue(chosen);
}


void main()
{
	cout << "Knapsack problem";

	cout<<endl << endl<<" Instance 1"<<endl;
list<item> items;
item it;
int capacity;

it.value=5;
it.weight=3;
items.push_back(it);

it.value=3;
it.weight=4;
items.push_back(it);

it.value=2;
it.weight=2;
items.push_back(it);

it.value=4;
it.weight=6;
items.push_back(it);

it.value=3;
it.weight=1;
items.push_back(it);
capacity = 10;

show(capacity,items);

	cout<<endl << endl<<" Instance 2"<<endl;
items.clear();

it.value=5;
it.weight=1;
items.push_back(it);

it.value=6;
it.weight=3;
items.push_back(it);

capacity = 3;

show(capacity,items);

cout<<endl<<endl;

	}

