#include <iostream>

using namespace std;

int main()
{
	// logical Not !x
	bool x = true;
	cout << !x << endl;

	// logical And
	bool a = true;
	bool b = true;
	cout << (a && b) << endl;

	// logical OR
	bool w1 = true;
	bool w2 = false;
	cout << (w1 || w2) << endl;

	// short circuit evaluation
	int x1 = 1;
	int x2 = 2;
	if (x1 == 1 && x2++ == 2) // x1 == 1이 부분이 틀리면 뒤는 보지도 않는다.
	{
		// do sth
	}
	cout << x2 << endl;

	// De Morgan's Law
	// !(x && y) == !x || !y

	// XOR
	// C++에는 XOR 따로 없다.
	// if (x != y) ... 

	// AND 연산자가 OR 연산자보다 우선순위가 높다.
	return 0;
}