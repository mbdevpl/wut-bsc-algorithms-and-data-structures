#include "quickSorter.h"
#define N 50000
#define SN 10

int main()
{
	srand ((unsigned int)time(NULL) );
	quickSorter s;
	
	
	item items1[N];
	item items2[N];
	item items3[N];

	item sitems1[SN];
	item sitems2[SN];
	item sitems3[SN];

	item* arrays[6] = {sitems1, sitems2, sitems3, items1, items2, items3};

	for (int i=0; i<N; ++i)
	{
		items1[i]=item(i);
		items2[i]=item(N-i);
		items3[i]= item(rand() % N - N/2);
	}
	for (int i=0; i<SN; ++i)
	{
		sitems1[i]=item(i);
		sitems2[i]=item(SN-i);
		sitems3[i]= item(rand() % SN - SN/2);
	}

	for (int i=5; i<6; ++i)
	{
		cout<<endl<<"***********************************"<<endl<<"array "<<i<<endl<<"***********************************"<<endl;
		s.sort(arrays[i], i<3?SN:N);
	}
	
	return 0;
}