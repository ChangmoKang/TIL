#include <iostream>
// ���� ���Ǵ� ����� Header�� �����ؼ� ����Ѵ�.
#include "constants.h"

// my_number �Ķ���͸� ���� �ٲ��� �ʱ� ������ const�� ����Ѵ�.
void printNumber(const int my_number)
{
	using namespace std;

	// ���� �ٲٷ��� �̷��� ���� ������ �����Ѵ�.
	int n = my_number;

	cout << my_number << endl;
}


int main()
{
	using namespace std;

	const double gravity{ 9.8 };
	// gravity = 1.2; const�� ����� ��� �ٲ��� �ʴ´�


	int number;
	cin >> number;

	const int special_number(number); // ��Ÿ�ӿ��� �˻��ϱ� ������ ������ �����ϴ�.
	// constexpr int speical_number(number); ������ Ÿ�ӿ��� �˻��ϱ� ������ �������� �ʴ´�.

	// Header���� �ҷ��� ���
	cout << constants::pi << endl;

	return 0;
}