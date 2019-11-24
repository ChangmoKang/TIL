#include <iostream>
#include "MyConstant.h"
using namespace std;

// ��������
int value = 123;

// �ٸ� cpp ���Ͽ��� ���� �� �� ����.
static int g_a = 1;

// forward declaration
extern void doSomething();
extern int haha;

void doSth()
{
	static int a = 1; // a�� os�κ��� ���� �޸𸮰� static, static�� ����ϸ� ������ �ʱ�ȭ�� ���Ѿ� �ϰ� �ѹ��� ����ȴ�.
	++a;
	cout << a << endl;
	cout << &a << endl;
}

int main()
{
	cout << value << endl; // 123
	// ��������
	int value = 1;
	cout << value << endl; // 1

	// ::�� ���� ������
	cout << ::value << endl; // 123

	doSth();
	doSth();

	cout << "In main.cpp file" << " " << &Constants::pi << endl;
	doSomething();
	return 0;
}