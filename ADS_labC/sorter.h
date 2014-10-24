#ifndef INCL_SORTER

#define INCL_SORTER
#include "item.h"
#include <time.h>

class sorter
{
protected:
	/*  execute sorting algorithm */
	virtual void doSort(item items[],int n) abstract;

public:

	/* algorithm name */
	virtual char* getName() abstract;


	/* calls sorting algorithm, measures the time and  the number of comparisons */
	void sort(item items[], int n)
	{
		clock_t start, finish;
		item* itemsCpy = new item[n];

		memcpy(itemsCpy,items,n*sizeof(item));
		item::resetComparisonCount();

		
		cout <<endl<<"**************" <<endl<<getName()<<endl<<"**************"<<endl;
		if (n<15)
		{
		cout<< "before sorting: ";
		for (int i=0; i<n; ++i)		
			cout<<items[i]<<" ";
		cout<<endl;
		}

		start = clock();
		doSort(itemsCpy,n);
		finish = clock();

		if (n<15)
		{
		cout<< " after sorting: ";
		for (int i=0; i<n; ++i)		
			cout<<itemsCpy[i]<<" ";
		cout<<endl;
		}

		cout<<"comparisons: "<<item::getComparisonCount() << endl;
		cout<<" time taken: "<<( (double)(finish - start)/CLOCKS_PER_SEC ) <<"s"<<endl;

		bool correct = true;
		for(int i=0; i<n-1; i++)
			if(itemsCpy[i].getValue() > itemsCpy[i+1].getValue()) {
				correct = false;
				cout << " at i=" << i << endl;
				//break;
			}
		if(correct)
			cout << " correctly sorted" << endl;
		else {
			cout << " sorting is incorrect!" << endl;
			for(int i=0; i<n; i++)
				cout << "n" << i << "=" << itemsCpy[i] <<"  ";
		}

		 
		delete [] itemsCpy;
	}	
};

#endif