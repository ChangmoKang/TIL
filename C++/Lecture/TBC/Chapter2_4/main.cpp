#include <iostream>

int main()
{
	using namespace std;

	// void my_void; void�� �޸𸮸� �������� �ʱ� ������ ������ �Ұ���

	int i = 123;
	float f = 123.456f;

	void *my_void; // �̰� �����ϴ�...

	cout << &i << endl;
	cout << &f << endl;

	my_void = (void*)&i;
	cout << my_void << endl;
	my_void = (void*)&f;
	cout << my_void << endl;

	return 0;
}