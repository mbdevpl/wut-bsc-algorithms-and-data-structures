#include "sorter.h"
#include <vector>

/* sorter using Shell sort algorithm */
class shellSorter: public sorter {
private:
	void swapItemVals(item& item1, item& item2) {
		int temp = item1.getValue();
		item1.setValue(item2.getValue());
		item2.setValue(temp);
	}
protected:
	void reverse(vector<int>& v) {
		int i = 0, j = v.size()-1, temp;
		while(i < j) {
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
			i++;
			j--;
		}
	}
	/**
	 * Runs shell sort on a given array, using a given decreasing sequence
	 */
	void runShellSort(item items[], int n, vector<int>& sequence) {
		for(int k = 0; k < sequence.size(); k++) {
			//cout << "seq[" << k << "]=" << sequence[k];
			for(int i = 0; i < n - sequence[k]; i++) {
				//cout << " (" << i << "," << (i + sequence[k]) << ")";
				for(int j = i; j >= 0 && items[j] > items[j + sequence[k]]; j -= sequence[k]) {
					swapItemVals(items[j], items[j + sequence[k]]);
					//cout << ".";
				}
			}
			//cout << endl;
		}
	}

	virtual void doSort(item items[],int n) abstract;
public:
	char* getName() abstract;
};

class shellSorter1: public shellSorter
{
protected:
	virtual void doSort(item items[],int n)
	{
		/*
		the decreasing sequence used in the algorithm is:
		s(0) = n
		s(i+1) = s(i)/2
		*/
		vector<int> seq;
		for(int arg = n; arg >= 1; arg /= 2)
			seq.push_back(arg);
		runShellSort(items,n,seq);
	}
public:
	char* getName() override		 
	{
		return "Shell Sort (1st)";
	}

	
};

class shellSorter2: public shellSorter
{
protected:
	virtual void doSort(item items[],int n)
	{
		/*
		the decreasing sequence used in the algorithm is:
		s(0) = n
		s(i+1) = s(i)/2.2
		*/
		vector<int> seq;
		for(int arg = n; arg >= 1; arg = (int)(arg / 2.2))
			seq.push_back(arg);
		runShellSort(items,n,seq);
	}
public:
	char* getName() override		 
	{
		return "Shell Sort (2nd)";
	}

	
};

class shellSorter3: public shellSorter
{
protected:
	virtual void doSort(item items[],int n)
	{
		/*
		 * the decreasing sequence is the one proposed by Donald Knuth:
		 * 1, 4, 13, 40, 121, 364,1093, 3280, 9841, ...
		 * x(0) = 1
		 * x(n) = x(n-1) * 3 + 1
		 * ... and so on until n, then reversed
		*/
		vector<int> seq;
		for(int arg = 1; arg <= n; arg = arg*3 + 1)
			seq.push_back(arg);
		reverse(seq);
		runShellSort(items,n,seq);
	}
public:
	char* getName() override		 
	{
		return "Shell Sort (3rd)";
	}

	
};