#include <iostream>

using namespace std;

int main(void)
{
	int x = 2; // x는 변수, 2는 리터럴(Literal)
	 
	cout << "Hello World" << endl; // Hello World도 리터럴

	cout << -x << endl; // -는 unary 연산자
	cout << 1 + 2 << endl; // 1과 2는 각각 literal +는 binary 연산자 1 + 2는 표현식
	
	int y = (x > 0) ? 1 : 0; // ternary 연산자 (C++에서는 조건 연산자가 유일한 삼항 연산자이다.)

	cout << y << endl;
}