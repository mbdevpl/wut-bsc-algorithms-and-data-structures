#include "sorter.h"

#include <vector>

/* sorter using heap sort algorithm */
class heapSorter: public sorter {
private:
	template<class T> void swapPair(T& a1, T& a2) {
		T temp = a1;
		a1 = a2;
		a2 = temp;
	}

	template<class T> void heapify(vector<T>& A, int i, int n) {
		int l=2*i, r=2*i+1, max;
		if((l<=n) && (A[l-1]>A[i-1])) max = l;
		else max = i;
		if((r<=n) && A[r-1] > A[max-1]) max = r;
		if(max!=i) {
			swapPair<T>(A[i-1], A[max-1]);
			heapify(A,max,n);
		}
	}

	template<class T> void buildheap(vector<T>& A) {
		for(int i=A.size()/2; i>=1; i--) {
			heapify<T>(A, i, A.size());
		}
	}

	template<class T> void heapsort(vector<T>& A) {
		buildheap<T>(A);
		int m = A.size();
		for(unsigned int i = A.size(); i >= 2; i--) {
			swapPair<T>(A[i-1], A[0]);
			m--;
			heapify<T>(A, 1, m);
		}
	}

protected:
	virtual void doSort(item items[],int n) {
		vector<item> items2;
		for(int i=0; i<n; i++) items2.push_back(items[i]);
		heapsort<item>(items2);
		for(int i=0; i<n; i++) items[i] = items2[i];
	}

public:
	char* getName() override {
		return "Heap Sort";
	}
};