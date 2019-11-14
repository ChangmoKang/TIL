#include <iostream>

int main()
{
	using namespace std;

	// void my_void; void는 메모리를 차지하지 않기 때문에 선언이 불가능

	int i = 123;
	float f = 123.456f;

	void *my_void; // 이건 가능하다...

	cout << &i << endl;
	cout << &f << endl;

	my_void = (void*)&i;
	cout << my_void << endl;
	my_void = (void*)&f;
	cout << my_void << endl;

	return 0;
}