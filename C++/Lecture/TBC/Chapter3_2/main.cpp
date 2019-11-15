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
	int z5 = x % y; // 나머지 연산자

	cout << x / y << endl; // 1
	cout << float(x) / y << endl; // 1.75
	cout << x / float(y) << endl; // 1.75
	cout << float(x) / float(y) << endl; // 1.75

	cout << -5 / 2 << endl; // -2.5지만 소수점을 버리기 때문에 -2가 출력됨
	cout << -5 % 2 << endl; // 나머지 연산자 앞에 양수면 양의 결과 음수이면 음의 결과가 나온다.

	int z = x;
	z += y; // z = z + y;
	z -= y; // z = z - y;
	z *= y; // z = z * y;
	z /= y; // z = z / y;
	z %= y; // z = z % y;

	return 0;
}