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
	if (x1 == 1 && x2++ == 2) // x1 == 1�� �κ��� Ʋ���� �ڴ� ������ �ʴ´�.
	{
		// do sth
	}
	cout << x2 << endl;

	// De Morgan's Law
	// !(x && y) == !x || !y

	// XOR
	// C++���� XOR ���� ����.
	// if (x != y) ... 

	// AND �����ڰ� OR �����ں��� �켱������ ����.
	return 0;
}