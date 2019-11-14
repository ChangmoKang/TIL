#include <iostream>
#include <cmath>
#include <limits>

int main()
{
	using namespace std;

	//short s = 1; // 2 bytes = 2 * 8 bits = 16 bits
	//int i = 1;
	//long l = 1;
	//long long ll = 1;

	//cout << sizeof(short) << endl;
	//cout << sizeof(int) << endl;
	//cout << sizeof(long) << endl;
	//cout << sizeof(long long) << endl;

	short s = 1;
	cout << pow(2, sizeof(short) * 8 - 1) - 1 << endl;
	cout << numeric_limits<short>::max() << endl; // 범위에서 가장 큰 값
	cout << numeric_limits<short>::min() << endl; // 절대값이 가장 작은 값
	cout << numeric_limits<short>::lowest() << endl; // 범위에서 가장 작은 값

}