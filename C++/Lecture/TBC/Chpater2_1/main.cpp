#include <iostream>

int main()
{
	using namespace std;

	bool bValue = true;
	char chValue = 'A'; // char chValue = '65' ���ڵ� ���ڷ� ǥ���ȴ�.
	float fValue = 3.141592f; // float�� f�� �ڿ� ���ش�, f�� ������ ��� 3.141592�� double�̱� ������ float�� ������ ��� ����� �� �ִ�.
	double dValue = 3.141592;

	auto aValue = 3.141592f;
	auto aValue2 = 3.141592;

	// size�� ����Ϸ��� sizeof()�� ����Ѵ�. Ÿ���� ������ ���� �ִ�.
	cout << sizeof(aValue) << endl;


	int a = 123; // copy initialization
	int b(123); // direct initialization
	int c{ 123 }; // uniform initialization (���� ������)

	return 0;
}