#include <iostream>

using namespace std;

int main(void)
{
	int x = 2; // x�� ����, 2�� ���ͷ�(Literal)
	 
	cout << "Hello World" << endl; // Hello World�� ���ͷ�

	cout << -x << endl; // -�� unary ������
	cout << 1 + 2 << endl; // 1�� 2�� ���� literal +�� binary ������ 1 + 2�� ǥ����
	
	int y = (x > 0) ? 1 : 0; // ternary ������ (C++������ ���� �����ڰ� ������ ���� �������̴�.)

	cout << y << endl;
}