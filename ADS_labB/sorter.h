#ifndef INCL_SORTER

#define INCL_SORTER
#include "item.h"
#include <time.h>

#include <vector>
#include <iostream>

using namespace std;

typedef vector<item*> oneBag; //one bag with ordered items
typedef vector<oneBag> manyBags; //ordered set of bags

class sorter
{
private:
	void printBags(manyBags& bags, const char* prefix = "", int indent = 0) {
		//prints contents of the bags
		for(unsigned int i = 0; i < bags.size(); i++) {
			for(int x=0; x<indent; x++) cout << " ";
			cout << prefix << i << ":";
			for(unsigned int j = 0; j < bags[i].size(); j++) {
				cout << " [" << j << "]=" << bags[i][j]->getValue();
			}
			cout << endl;
		}
	}
	void reorderBags(manyBags& bags, int letterNum = 0) {
		//orders bags alphabetically, according to nth letter (bubblesort)
		for(unsigned int i = 0; i < bags.size(); i++) {
			for(unsigned int j = bags.size() - 1; j > i; j--) {
				item *it1 = bags[j-1][0];
				item *it2 = bags[j][0];
				if( //longer strings are later in lexographical order if they have
					// the same contents up to the end of the shorter string (English wikipedia)
					// http://en.wikipedia.org/wiki/Lexicographical_order#Ordering_of_sequences_of_various_lengths
					(it1->getLength() > letterNum && it2->getLength() <= letterNum)
					//if both are at least n letters long, the nth letter decides
					|| ( it1->getLength() >= letterNum + 1 && it2->getLength() >= letterNum + 1
						&& (*it1)[letterNum] > (*it2)[letterNum] ) ) {
					bags[j-1].swap(bags[j]);
				}
			}
		}
	}
	int getIndex(manyBags& bags, int letterNum, char letter) {
		//gets index of a bag that is proper for a given letter number and letter
		for(unsigned int i = 0; i < bags.size(); i++)
			for(unsigned int j = 0; j < bags[i].size(); j++) {
				item* it = bags[i][j];
				if(it->getLength() >= letterNum + 1)
					if((*it)[letterNum] == letter)
						return i;
			}
		return -1;
	}
	bool elemsDiffer(oneBag& bag) {
		//returns true if the bag has at least 2 elements, and they not all have equal values
		if(bag.size() >= 2) {
			item* temp = bag[0];
			for(unsigned int i = 1; i < bag.size(); i++)
				if(bag[i]->getValue() != temp->getValue()) return true;
		}
		return false;
	}

	void sortFromLetter(vector<item*>& items, int letterNum = 0) {
		//post-like sorting
		vector<vector<item*> > bags;

		//distribution to many bags, in order of apperance
		for(unsigned int i = 0; i < items.size(); i++) {
			int index = 0;
			if(items[i]->getLength() >= letterNum+1)
				index = getIndex(bags, letterNum, (*(items[i]))[letterNum]);
			else if(bags.size() == 0) index = -1;
			if(index == -1) {
				bags.push_back(vector<item*>(1,items[i]));
			} else {
				bags[index].push_back(items[i]);
			}
		}

		//printBags(bags, "beg", letterNum);

		//putting the bags in the right order
		reorderBags(bags, letterNum);

		//sorting insides of each bag
		for(unsigned int i = 0; i < bags.size(); i++) {
			if(bags[i].size() > 1 && elemsDiffer(bags[i]))
				sortFromLetter(bags[i], letterNum + 1);
		}

		//printBags(bags, "end", letterNum);

		//concatenation of bags
		int maxItems = items.size(), currItem = 0;
		items = vector<item*>(maxItems);
		for(unsigned int i = 0; i < bags.size(); i++)
			for(unsigned int j = 0; j < bags[i].size(); j++) {
				items[currItem++] = bags[i][j];
			}
	}
protected:
	void doSort(item items[],int n) 
	{
		//creates a "bag" of pointers, not yet ordered
		oneBag bag;
		for(int i = 0; i < n; i++)
			bag.push_back(&items[i]);

		//sorts the bag
		sortFromLetter(bag);

		//this does not work because "bag" is a vector of pointers
		//for(int i = 0; i < n; i++)
		//	items[i] = item(bag[i]->getValue());

		//makes a copy of properly ordered pointers
		vector<item> bagCopy;
		for(int i = 0; i < n; i++)
			bagCopy.push_back(*(bag[i]));
		
		//gets final values from the copied bag
		for(int i = 0; i < n; i++)
			items[i] = item(bagCopy[i].getValue());
	}

public:
	void sort(item items[], int n) {
		cout<< "\n\nbefore sorting:\n";
		for (int i=0; i<n; ++i)
			cout<<i<<" "<<items[i];
		
		doSort(items,n);

		cout<< "\n\nafter sorting:\n";
		for (int i=0; i<n; ++i)
			cout<<i<<" "<<items[i];
	}	
};

#endif
