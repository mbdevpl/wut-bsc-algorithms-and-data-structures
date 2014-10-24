#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

typedef struct item
{
public:
	int weight;
	int value;
} item;

int getTotalWeight(list<item> items)
{
	int w=0;
	for (list<item>::iterator i = items.begin(); i!=items.end(); ++i)	
		w+= i->weight;	
	return w;	
}

int getTotalValue(list<item> items)
{
	int v=0;
	for (list<item>::iterator i = items.begin(); i!=items.end(); ++i)	
		v+= i->value;	
	return v;	
}

/*
Solves given knapsack problem instantion and returns chosen items.

Knapsack problem:

Input:
1. The list of items, each of them represented by two parameters - value and weight.
There can be more than one element with the same parameters on the list.
2. The maximum capacity of the knapsack.

Task:
Choose items from the given list, so that their total weight
does not exceed the capacity of the knapsack and their total value is maximized.

Remarks:
It is difficult (in computational sense) to find the optimal solution.
You are supposed to design some approximation algorithm.
The better your idea is, the more points you obtain :).

*/

void printList(list<item>& it) {
	list<item>::iterator i=it.begin();
	cout << "(v,w): [ ";
	for(i=it.begin(); i != it.end(); i++) {
		cout << "(" << i->value << "," << i->weight << "), ";
	}
	cout << "size=" << it.size() << " ]\n";
}

//smallest element, according to the criterion
list<item>::iterator minimum(list<item>& it, char crit, int crop = 0) {
	list<item>::iterator i=it.begin();
	for(; crop>0; crop--) i++;
	list<item>::iterator min = i;
	for(; i != it.end(); i++) {
		if(crit == 'v') {
			if(i->value < min->value) min = i;
		} else if(crit == 'w')
			if(i->weight < min->weight) min = i;
	}
	return min;
}

//largest element, according to the criterion
list<item>::iterator maximum(list<item>& it, char crit, int crop = 0) {
	list<item>::iterator i=it.begin();
	for(; crop>0; crop--) i++;
	//cout << crop << endl;
	list<item>::iterator max = i;
	for(; i != it.end(); i++) {
		if(crit == 'v') {
			if(i->value > max->value) max = i;
		} else if(crit == 'w')
			if(i->weight > max->weight) max = i;
	}
	return max;
}

//sorting the list according to the criterion, mode can be "desc" or "asc"
//which will mean descending or ascending order
void sort(list<item>& it, char crit, char* mode) {
	for(unsigned int i = 0; i < it.size(); i++) {
		list<item>::iterator extr; //extremum
		if(mode == "asc") extr = minimum(it, crit, i);
		else if(mode == "desc") extr = maximum(it, crit, i);
		
		//cout << "(" << curr->value << "," << extr->weight << "); ";
		//cout << i << ": (" << extr->value << "," << extr->weight << "); ";
		//printList(it);

		list<item>::iterator curr = it.begin();
		for(int x = i; x>0; x--) curr++;

		int val = extr->value;
		int wei = extr->weight;
		extr->value = curr->value;
		extr->weight = curr->weight;
		curr->value = val;
		curr->weight = wei;
	}
	//printf("final, ");
	//printList(it);
}

list<item> solveKnapsack(int capacity, list<item> items)
{
	list<item> chosen;

	//printf("items, ");
	//printList(items);
	
	//printf("iVal, ");
	//printList(iVal);

	//printf("iWei, ");
	//printList(iWei);
	
	list<item> copy = items;
	sort(copy,'w',"asc");
	while(true) {
		//list<item> iVal = copy;
		//sort(iVal,'v',"desc");
		list<item> iWei = copy;
		sort(iWei,'w',"asc");

		list<item>::iterator wei = iWei.begin(); //best choice by weight
		
		list<item>::iterator it = wei; //final choice

		if(iWei.size() > 1) {
			list<item>::iterator wei2 = iWei.begin();
			wei2++;
			if((getTotalWeight(chosen) + wei->weight + wei2->weight > capacity) && (getTotalWeight(chosen) + wei2->weight <= capacity) && (wei2->value > wei->value))
				it = wei2;
		}

		if(getTotalWeight(chosen) + it->weight <= capacity) {
			chosen.push_back(*it);
			copy.pop_front();
		}
		else break;
	}
	/*
	write your solution here
	*/

	return chosen;
}


