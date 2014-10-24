#include "sorter.h"

#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

/* sorter using quick sort algorithm */
class quickSorter: public sorter {
private:
	stringstream vecToStr(vector<item>& v, unsigned int from, unsigned int to) {
		stringstream s;
		s << "[";
		for(unsigned int i = from; i <= to; i++) {
			s << v[i].getValue();
			if(i < to) s << ",";
			if(to - i > 10) {
				s << "...,";
				i += to - i - 3;
			}
		}
		s << "]";
		return s;
	}

	stringstream vecToStr(vector<item>& v) {
		return vecToStr(v, 0, v.size()-1);
	}
	/*
	void removeItem(vector<item>& v, item it) {
		for(vector<item>::iterator i = v.begin(); i != v.end(); i++)
			if(i->getValue() == it.getValue()) {
				v.erase(i);
				break;
			}
	}

	bool checkVec(vector<item>& elements) {
		if(elements.size() <= 1) return false;
		if(elements.size() == 2 && elements[0].getValue() == elements[1].getValue()) return false;
		return true;
	}

	item calcMedian(vector<item>& e) {
		if(e.size() >= 3) {
			vector<item> arr;
			
			arr.push_back(e[0]);
			arr.push_back(e[1]);
			arr.push_back(e[2]);
			
			for(int i=0; i<3; i++)
				for(int j=1; j>=0; j--)
					if(arr[j] >= arr[j+1]) {
						item temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
					}
			
			return arr[1];
		} else if(e.size() == 2) {
			if(e[0] < e[1]) return e[1];
			else return e[0];
		} else if(e.size() == 1) {
			return e[0];
		} else throw exception();
	}

	void quickSort2(vector<item>& elements) {
		if(elements.size() > 1) {
			item median = calcMedian(elements);
			//cout << "med=" << median.getValue();

			removeItem(elements, median);

			vector<item> smaller, greater;
			for(unsigned int i = 0; i < elements.size(); i++) {
				if(elements[i] < median)
					smaller.push_back(elements[i]);
				else
					greater.push_back(elements[i]);
			}
			//cout << " sm=" << vecToStr(smaller).str()
			//	<< " gr=" << vecToStr(greater).str() << endl;

			if(checkVec(smaller))
				quickSort2(smaller);
			
			elements = smaller;
			elements.push_back(median);

			if(checkVec(greater))
				quickSort2(greater);

			for(unsigned int i = 0; i < greater.size(); i++)
				elements.push_back(greater[i]);
		}
	}
	*/
	void swapItems(item& i1, item& i2) {
		item temp(i1);
		i1.setValue(i2.getValue());
		i2.setValue(temp.getValue());
	}

	void insertItem(vector<item>& v, unsigned int from, unsigned int to) {
		stringstream s;
		if(from < 0) {
			s << "from < 0";
			throw string(s.str());
		}
		if(to > v.size()) {
			s << "to > v.size()";
			throw string(s.str());
		}
		
		int temp = v[from].getValue();
		//if from < to
		for(unsigned int i = from; i < to; i++)
			v[i].setValue(v[i+1].getValue());
		//if from > to
		for(unsigned int i = from; i > to; i--)
			v[i].setValue(v[i-1].getValue());
		v[to].setValue(temp);
	}

	unsigned int getMedianIndex(vector<item>& e, unsigned int begin, unsigned int LEN) {
		if(begin >= e.size()) throw string("begin > size");
		if(begin < 0) throw string("begin < 0");
		if(LEN <= 0) throw string("LEN <= 0");
		
		if(e.size() >= LEN + begin) {
			vector<item> v;
			for(unsigned int i = begin; i < begin + LEN; i++)
				v.push_back(e[i]);
			for(unsigned int i = 0; i < LEN; i++)
				for(unsigned int j = 0; j < LEN - 1; j++)
					if(v[j] > v[j+1])
						swapItems(v[j], v[j+1]);
			int medianVal = v[LEN/2].getValue();
			for(unsigned int i = begin; i < begin + LEN; i++)
				if(e[i].getValue() == medianVal)
					return i;
		}
		return begin;
	}

	void quickSort(vector<item>& e, unsigned int begin, unsigned int end) {

		//in the "one call" version, it is enough to substitute 'if' with 'while'

		while(begin < end && begin >= 0 && end < e.size()) {

		//if(begin < end && begin >= 0 && end < e.size()) { // this 'if' is for "two calls" version

			unsigned int medianIndex = getMedianIndex(e, begin, 3);

			for(unsigned int i = begin; i < medianIndex; i++)
				if(e[i] > e[medianIndex]) {
					//cout << " larger in " << vecToStr(e,begin,end).str() << " move " << i << "->" << medianIndex << " median at " << medianIndex << endl;
					insertItem(e, i, medianIndex);
					medianIndex--;
					i--;
				}

			for(unsigned int i = end; i > medianIndex; i--)
				if(e[i] < e[medianIndex]) {
					//cout << " smaller in " << vecToStr(e,begin,end).str() << " move " << i << "->" << medianIndex << " median at " << medianIndex << endl;
					insertItem(e, i, medianIndex);
					medianIndex++;
					i++;
				}

			if(begin < medianIndex-1) {
				//cout << " sub-sort for smaller (from " << (begin) << " to " << (medianIndex-1) << ")" << endl;
				quickSort(e, begin, medianIndex - 1);
			}

			//obsolete part:

			//if(medianIndex+1 < end) {
			//	//cout << " sub-sort for larger (from " << (medianIndex+1) << " to " << (end) << ")" << endl;
			//	quickSort(e, medianIndex+1, end);
			//}
			
			//this is used instead:

			begin = medianIndex + 1;
		}
	}

protected:
	virtual void doSort(item items[],int n)
	{
		/*
		Sort given items using quicksort algorithm using median of first three items as a pivot.
		You are not allowed to use Internet.
		To get 4 points you have to implement quicksort with at most one recursive call.
		*/

		vector<item> v;
		for(int i = 0; i < n; i++)
			v.push_back(items[i]);
		
		try {
			//two recursive calls in the function loop
			//quickSort2(v);

			//one recursive call in the function loop
			quickSort(v, 0, v.size() - 1);
		} catch (string s) {
			cout << "exception: " << s;
		}

		for(int i = 0; i < n; i++)
			items[i] = v[i];
	}
public:
	char* getName() override		 
	{
		return "Quick Sort";
	}
};