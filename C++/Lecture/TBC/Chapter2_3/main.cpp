#include <iostream>

int main()
{
	using namespace std;

	int16_t i(5);
	int8_t my_int = 65; // int���� char�� ��

	cout << my_int << endl;

	int_fast8_t fi(5); // int �߿��� 8��Ʈ ������ �߿� ���� ���� ��
	int_least64_t fl(5); // ��� 64��Ʈ �̻��� int ���

	return 0;
}