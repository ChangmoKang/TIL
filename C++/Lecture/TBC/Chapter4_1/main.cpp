#include <iostream>

using namespace std;


namespace work1
{
	int a = 3;

	void doSomething()
	{
		a += 3;
	}
}

namespace work2
{
	int a = 4;

	void doSomething()
	{
		a += 5;
	}
}


int main()
{
	int apple = 5;
	cout << apple << endl; // 5
	{
		apple = 1;
		// int apple = 4;

		cout << apple << endl; // 1, int�� �����Ͽ��� ��� 4
	}
	cout << apple << endl; // 1, int�� �����Ͽ��� ��� 5

	work1::a;
	work1::doSomething();

	work2::a;
	work2::doSomething();

	return 0;
}

// apple = 3; �߰�ȣ ���� �Ѿ���Ƿ� ����� �� ����.
