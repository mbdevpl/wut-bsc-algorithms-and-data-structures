#include "sorter.h"

/* sorter using selection sort algorithm */
class selectionSorter: public sorter
{
protected:
	virtual void doSort(item items[],int n)
	{
		int min;
		item temp;
		for (int i=0; i< n; ++i)
		{			
			min =i;
			for (int j=i+1; j<n; ++j)
			{
				if (items[j] < items[min])
				min = j;
			}
			temp = items[i];
			items[i]=items[min];
			items[min]=temp;
		}
	}
public:
	char* getName() override		 
	{
		return "Selection Sort";
	}

	
};