#include "sorter.h"

int main()
{
	sorter s;		

	item items1[20];
	
	items1[0] = item("AAA");
	items1[1] = item("AAA");
	items1[2] = item("BAAA");
	items1[3] = item("WCK");
	items1[4] = item("ACD");
	items1[5] = item("ZZA");
	items1[6] = item("AAC");
	items1[7] = item("ZAA");
	items1[8] = item("ZZE");
	items1[9] = item("SPF");
	items1[10] = item("BAAA");
	items1[11] = item("BBAA");
	items1[12] = item("BAAAA");
	items1[13] = item("AAAA");
	items1[14] = item("AAAAA");
	items1[15] = item("AAA");
	items1[16] = item("GBF");
	items1[17] = item("WCD");
	items1[18] = item("BAAAC");
	items1[19] = item("AAAA");

	s.sort(items1,20);	

	/*
	item items2[10];

	items2[0] = item("Alexander Lang");
	items2[1] = item("George Ballantine");
	items2[2] = item("Daniel E. Williams");
	items2[3] = item("Johnnie Walker");
	items2[4] = item("John Dewar Senior");
	items2[5] = item("John Dewar Junior");
	items2[6] = item("Jim Beam");
	items2[7] = item("Matthew Gloag");
	items2[8] = item("Jack Daniels");
	items2[9] = item("John Jameson");

	s.sort(items2,10);	*/
	return 0;
}
