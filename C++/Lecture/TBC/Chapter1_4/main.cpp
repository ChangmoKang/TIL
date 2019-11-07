#include <iostream>
#include <cstdio>

int main()
{
	// 중괄호가 끝나는 부분까지 std::를 생략할 수 있다.
	using namespace std;

	int x = 1024;
	double pi = 3.141592;

	cout << "I love this lecture!\n";// << std::endl;
	cout << "x is " << x << " pi is " << pi << endl;

	// \t는 간격을 맞춰주는 기능도 한다.
	cout << "abc" << "\t" << "def" << endl;
	cout << "ab" << "\t" << "cdef" << endl;

	// a는 audio의 약어이다.
	cout << "\a";

	// 입력을 받는 법
	int z;
	cin >> z;

	cout << "Your input is " << z << endl;

	return 0;
}