#include <iostream>

using namespace std;

int main()
{
	// sizeof operator
	// sizeof�� �Լ��� �ƴ϶� operator�̴�.
	float v;
	cout << sizeof(float) << endl;
	cout << sizeof(v) << endl;


	// comma operator
	int x = 3;
	int y = 10;

	// ++x;
	// ++y;
	// int z = y; �� ���ܰ踦 ������ ���� �Ʒ��� �ڵ�
	int z = (++x, ++y);

	int a = 1, b = 10;
	int c;
	
	// ,�� =���� �켱������ ���� ������ c = a�� ����ȴ�.
	c = a, b;
	// (c = a), b;

	cout << c << endl;


	// conditional operator(arithmetic if)
	bool onSale = true;

	// � ���� const�� �ϰ� ������ ������ �ɰ� ������ ���� �����ڸ� ����Ѵ�.
	const int price = (onSale == true) ? 10 : 100;
	/*if (onSale)
		price = 10;
	else
		price = 100;*/
	

	int xx = 5;
	cout << ((xx % 2 == 0) ? "even" : "odd") << endl;
	//cout << (xx % 2 == 0) ? "even" : "odd" << endl; ��� �� ������ ����? �ſ� ���� Ȯ���� �켱���� ������(���� �����ڴ� 16����)

	return 0;
}