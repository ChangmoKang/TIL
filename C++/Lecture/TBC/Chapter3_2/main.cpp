#include <iostream>

int main()
{
	using namespace std;

	int x = 7;
	int y = 4;
	int z1 = x + y;
	int z2 = x - y;
	int z3 = x * y;
	int z4 = x / y;
	int z5 = x % y; // ������ ������

	cout << x / y << endl; // 1
	cout << float(x) / y << endl; // 1.75
	cout << x / float(y) << endl; // 1.75
	cout << float(x) / float(y) << endl; // 1.75

	cout << -5 / 2 << endl; // -2.5���� �Ҽ����� ������ ������ -2�� ��µ�
	cout << -5 % 2 << endl; // ������ ������ �տ� ����� ���� ��� �����̸� ���� ����� ���´�.

	int z = x;
	z += y; // z = z + y;
	z -= y; // z = z - y;
	z *= y; // z = z * y;
	z /= y; // z = z / y;
	z %= y; // z = z % y;

	return 0;
}