#include <iostream>

int main()
{
	using namespace std;

	int16_t i(5);
	int8_t my_int = 65; // int지만 char로 됨

	cout << my_int << endl;

	int_fast8_t fi(5); // int 중에서 8비트 사이즈 중에 가장 빠른 것
	int_least64_t fl(5); // 적어도 64비트 이상인 int 사용

	return 0;
}