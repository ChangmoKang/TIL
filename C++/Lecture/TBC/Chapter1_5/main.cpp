#include <iostream>

using namespace std;

int addTwoNumbers(int num_a, int num_b) // num_a, num_b�� parameters
{
	// �Լ��� ���� ������ �Լ��� ���İ� ���ƾ� �Ѵ�.
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
	cout << addTwoNumbers(1, 2) << endl; // 1�� 2�� arguments
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