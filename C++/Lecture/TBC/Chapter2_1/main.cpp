#include <iostream>

int main()
{
	using namespace std;

	bool bValue = true;
	char chValue = 'A'; // char chValue = '65' 문자도 숫자로 표현된다.
	float fValue = 3.141592f; // float는 f를 뒤에 써준다, f를 생략할 경우 3.141592는 double이기 때문에 float에 저장할 경우 절삭될 수 있다.
	double dValue = 3.141592;

	auto aValue = 3.141592f;
	auto aValue2 = 3.141592;

	// size를 출력하려면 sizeof()를 사용한다. 타입을 측정할 수도 있다.
	cout << sizeof(aValue) << endl;


	int a = 123; // copy initialization
	int b(123); // direct initialization
	int c{ 123 }; // uniform initialization (가장 엄격함)

	return 0;
}