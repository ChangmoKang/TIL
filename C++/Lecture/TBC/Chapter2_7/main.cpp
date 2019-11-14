#include <iostream>

int main()
{
	using namespace std;

	char c1(65);
	char c2('A'); // "Hello, World", ���ڸ� ǥ���� ���� '' ���ڿ��� ǥ���� ���� ""

	cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;
	// (int)c1 �̷��� casting �ϴ� ���� C-style
	// int(c1)�� cpp style

	cout << static_cast<char>(65) << endl; // compiler���� check�� ��Ź�ϴ� ������ ����, casting �ϴ� ���� ��Ȯ��
	cout << static_cast<int>('A') << endl;

	char ch(97);

	// ������ ���� ���� �ִ�.
	cout << static_cast<int>(ch) << endl;


	char c3(65);

	cout << sizeof(char) << endl;
	cout << (int)numeric_limits<char>::max() << endl;
	cout << (int)numeric_limits<char>::lowest() << endl;

	return 0;
}