#include <iostream>
#include "MyConstant.h"
extern int haha = 123;

void doSomething()
{
	using namespace std;
	cout << "Hello World" << endl;
	cout << "In test.cpp file" << " " << &Constants::pi << endl;
}