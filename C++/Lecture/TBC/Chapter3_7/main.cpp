#include <iostream>

using namespace std;

int main()
{
	/*

	148 (decimal to binary)

	148 / 2 = 74 >> 0
	72	/ 2 = 37 >> 0
	37	/ 2 = 18 >> 1
	18	/ 2 = 9 >> 0
	9	/ 2 = 4 >> 1
	4	/ 2 = 2 >> 0
	2	/ 2 = 1 >> 0
	1	/ 2 = 1 >> 1

	1001 0100

	*/


	/*
	
	-5 (decimal to binary)(unsigned)
	0000 0101
	complement
	1111 1010
	+ 1
	1111 1011 >> -5
	
	if signed
	1000 0101 >> -5



	*/

	/*
	
	1001 1110 (binary to decimal)(signed)
	complement
	0110 0001
	+1
	0110 0010 >> 98인데 원래 음수였으니 -98

	*/


	return 0;
}