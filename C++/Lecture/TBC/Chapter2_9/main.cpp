#include <iostream>
// 자주 사용되는 상수는 Header에 저장해서 사용한다.
#include "constants.h"

// my_number 파라미터를 보통 바꾸지 않기 때문에 const를 사용한다.
void printNumber(const int my_number)
{
	using namespace std;

	// 굳이 바꾸려면 이렇게 따로 변수를 선언한다.
	int n = my_number;

	cout << my_number << endl;
}


int main()
{
	using namespace std;

	const double gravity{ 9.8 };
	// gravity = 1.2; const를 사용할 경우 바뀌지 않는다


	int number;
	cin >> number;

	const int special_number(number); // 런타임에서 검사하기 때문에 실행이 가능하다.
	// constexpr int speical_number(number); 컴파일 타임에서 검사하기 때문에 동작하지 않는다.

	// Header에서 불러온 상수
	cout << constants::pi << endl;

	return 0;
}