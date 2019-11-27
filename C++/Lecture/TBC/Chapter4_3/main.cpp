#include <iostream>

namespace a
{
	int my_var(10);
}

namespace b
{
	int my_var(20);
}

int main()
{
	using namespace std;

	/*
	using std::cout;
	using std::endl;
	cout << "Hello World" << endl;
	*/

	using namespace a;
	using namespace b;

	// cout << my_var << endl; // a와 b에 모두 my_var가 있기 때문에 ambiguous함
	cout << a::my_var << endl;
}