#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// ��Ĵ�� *���� ����Ѵ�
	int x1 = 4 + 2 * 3;

	// ���ʿ��� ���� ����Ѵ�. associativity(left-to-right���� right-to-left����)
	int x2 = 4 * 3 / 2;

	// ^�� ������ �ƴϴ�. ������ �Ϸ��� cmath�� �ҷ��ͼ� pow�� �������
	int x3 = pow(2, 3);
	cout << x3 << endl;

	return 0;
}