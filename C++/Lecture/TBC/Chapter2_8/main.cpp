#include <iostream>

int main()
{
	using namespace std;

	float pi = 3.14f;
	int i = (unsigned int)12324; // int i = 12324u;

	// 2������ ǥ���Ϸ��� ���� �տ� 0b�� ���̰�
	// 8������ ǥ���Ϸ��� ���� �տ� 0�� ���̰�
	// 16������ ǥ���Ϸ��� ���� �տ� 0x�� ���δ�

	int b = 0b1111;
	int o = 017;
	int h = 0xF;

	// 0011 1010 1111 1111��
	// 3AFF�� ǥ���Ǿ� �������̱� ������ 16������ ���� ���ȴ�.

	cout << b << " " <<  o << " " << h << endl;


	int num_items = 123;
	// int price = num_items * 10; �̷��� 10�� ����� �� �� ����
	
	const int price_per_item = 10;
	int price = num_items * price_per_item;


	return 0;
}