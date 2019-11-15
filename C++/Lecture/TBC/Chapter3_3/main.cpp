#include <iostream>


int main()
{
	using namespace std;

	int x = 5;
	int y1 = ++x; // x가 1이 증가하고 y1에 assign된다.
	cout << y1 << endl;
	cout << x << endl;

	int y2 = x++; // y2에 먼저 x가 assign되고 x가 증가한다.
	cout << y2 << endl;
	cout << x << endl;

}