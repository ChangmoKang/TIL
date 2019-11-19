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

		cout << apple << endl; // 1, int로 정의하였을 경우 4
	}
	cout << apple << endl; // 1, int로 정의하였을 경우 5

	work1::a;
	work1::doSomething();

	work2::a;
	work2::doSomething();

	return 0;
}

// apple = 3; 중괄호 밖을 넘어갔으므로 사용할 수 없다.
