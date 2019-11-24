#include <iostream>
#include "MyConstant.h"
using namespace std;

// 전역변수
int value = 123;

// 다른 cpp 파일에서 접근 할 수 없다.
static int g_a = 1;

// forward declaration
extern void doSomething();
extern int haha;

void doSth()
{
	static int a = 1; // a가 os로부터 받은 메모리가 static, static을 사용하면 무조건 초기화를 시켜야 하고 한번만 실행된다.
	++a;
	cout << a << endl;
	cout << &a << endl;
}

int main()
{
	cout << value << endl; // 123
	// 지역변수
	int value = 1;
	cout << value << endl; // 1

	// ::은 영역 연산자
	cout << ::value << endl; // 123

	doSth();
	doSth();

	cout << "In main.cpp file" << " " << &Constants::pi << endl;
	doSomething();
	return 0;
}