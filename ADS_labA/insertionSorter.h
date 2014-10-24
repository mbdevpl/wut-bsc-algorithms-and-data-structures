#include "sorter.h"

/* sorter using insertion sort algorithm */
class insertionSorter: public sorter {
private:
	void swapItemVals(item& item1, item& item2) {
		int temp = item1.getValue();
		item1.setValue(item2.getValue());
		item2.setValue(temp);
	}
protected:
	virtual void doSort(item items[],int n) {
		int curr; //currently evaluated index
		for(curr = 1; curr < n; curr++) {
			int i; //element that is currently compared to the element that was originally at index "curr"
			for(i = curr - 1; items[i] > items[i+1] && i >= 0; i--)
				swapItemVals(items[i], items[i+1]);
		}
	}
public:
	char* getName() override {
		return "Insertion Sort";
	}
};