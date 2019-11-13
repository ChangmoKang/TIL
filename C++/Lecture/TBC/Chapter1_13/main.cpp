#include <iostream>

using namespace std;

namespace mySpace1
{
	namespace innerSpace
	{
		int my_function()
		{
			return 0;
		}
	}

	int doSomething(int a, int b)
	{
		return a + b;
	}
}

namespace mySpace2
{
	int doSomething(int a, int b)
	{
		return a * b;
	}
}

int main(void)
{
	using namespace mySpace1;

	//mySpace1::innerSpace::my_function();
	cout << doSomething(3, 5) << endl;
	cout << mySpace2::doSomething(3, 5) << endl;
	return 0;
}