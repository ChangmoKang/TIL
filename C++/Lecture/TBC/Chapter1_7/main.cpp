#include <iostream>
using namespace std;

int main()
{
	int x(0); // int x = 0;

	cout << x << " " << &x << endl;
	{
		// ������ �и� �Ѵ�
		int x = 1;
		cout << x << " " << &x << endl;
	}

	{
		int x = 2;
		cout << x << " " << &x << endl;
	}

	return 0;
}