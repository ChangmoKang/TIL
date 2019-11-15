#include <iostream>
#include <bitset>

int main()
{
	using namespace std;

	// 비드단위 연산자의 종류
	// << left shift
	// >> right shift
	// ~
	// &
	// |
	// ^
	
	unsigned int a = 3;
	cout << bitset<4>(a) << endl;

	// <<을 한다는 것은 2의 제곱수를 곱하는 것과 같다.
	unsigned int b = 3 << 2;
	cout << bitset<4>(b) << " " << b << endl;

	// >>은 2의 마이너스 제곱수를 곱하는 것과 같다.
	unsigned int c = 1024 >> 4;
	cout << bitset<8>(c) << " " << c << endl;

	unsigned int d = 1024;
	cout << bitset<16>(d) << endl;
	cout << bitset<16>(~d) << " " << (~d) << endl; // 1024의 보수가 출력됨


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