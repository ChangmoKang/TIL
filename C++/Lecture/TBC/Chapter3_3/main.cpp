#include <iostream>


int main()
{
	using namespace std;

	int x = 5;
	int y1 = ++x; // x�� 1�� �����ϰ� y1�� assign�ȴ�.
	cout << y1 << endl;
	cout << x << endl;

	int y2 = x++; // y2�� ���� x�� assign�ǰ� x�� �����Ѵ�.
	cout << y2 << endl;
	cout << x << endl;

}