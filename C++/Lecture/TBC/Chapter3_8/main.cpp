#include <iostream>
#include <bitset>

int main()
{
	using namespace std;

	// ������ �������� ����
	// << left shift
	// >> right shift
	// ~
	// &
	// |
	// ^
	
	unsigned int a = 3;
	cout << bitset<4>(a) << endl;

	// <<�� �Ѵٴ� ���� 2�� �������� ���ϴ� �Ͱ� ����.
	unsigned int b = 3 << 2;
	cout << bitset<4>(b) << " " << b << endl;

	// >>�� 2�� ���̳ʽ� �������� ���ϴ� �Ͱ� ����.
	unsigned int c = 1024 >> 4;
	cout << bitset<8>(c) << " " << c << endl;

	unsigned int d = 1024;
	cout << bitset<16>(d) << endl;
	cout << bitset<16>(~d) << " " << (~d) << endl; // 1024�� ������ ��µ�


	unsigned int x1 = 0b1100;
	unsigned int x2 = 0b0110;

	cout << bitset<4>(x1 & x2) << endl; // bitwise AND
	cout << bitset<4>(x1 | x2) << endl; // bitwise OR
	cout << bitset<4>(x1 ^ x2) << endl; // bitwise XOR

	cout << (0b0110 >> 2) << endl;
	cout << (5 & 12) << endl;
	cout << (5 | 12) << endl;
	cout << (5 ^ 12) << endl;

	return 0;
}