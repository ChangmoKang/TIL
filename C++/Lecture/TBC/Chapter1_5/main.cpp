#include <iostream>

using namespace std;

int addTwoNumbers(int num_a, int num_b) // num_a, num_b는 parameters
{
	// 함수의 리턴 형식은 함수의 형식과 같아야 한다.
	int sum = num_a * num_b;

	return sum;
}


void printHelloWorld(void)
{
	cout << "Hello World" << endl;

	return;
}


void print()
{
	printHelloWorld();
}


int main()
{
	cout << addTwoNumbers(1, 2) << endl; // 1과 2는 arguments
	cout << addTwoNumbers(3, 4) << endl;
	cout << addTwoNumbers(8, 13) << endl;
	printHelloWorld();

	int x, y, z;
	cin >> x;
	cin >> y;
	cin >> z;
	cout << addTwoNumbers(x, y) << endl;
	cout << addTwoNumbers(x, z) << endl;

	return 0;
}