#include <iostream>
#include <cstdio>

int main()
{
	// �߰�ȣ�� ������ �κб��� std::�� ������ �� �ִ�.
	using namespace std;

	int x = 1024;
	double pi = 3.141592;

	cout << "I love this lecture!\n";// << std::endl;
	cout << "x is " << x << " pi is " << pi << endl;

	// \t�� ������ �����ִ� ��ɵ� �Ѵ�.
	cout << "abc" << "\t" << "def" << endl;
	cout << "ab" << "\t" << "cdef" << endl;

	// a�� audio�� ����̴�.
	cout << "\a";

	// �Է��� �޴� ��
	int z;
	cin >> z;

	cout << "Your input is " << z << endl;

	return 0;
}