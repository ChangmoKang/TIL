#include <iostream>

int main()
{
	using namespace std;

	bool b1 = true;
	bool b2(false);
	bool b3{ true };
	b3 = false;

	cout << boolalpha; // ����� �� true, false�� ���ڷ� ������
	cout << b1 << endl;
	cout << !b2 << endl;

	// ==�� ������ Ȯ���ϴ� ������, &&�� and ������, ||�� or ������

	if (true)
		cout << "This is true" << endl;
	else
		cout << "This is false" << endl;

	// if�� 2�� �̻� ����� ��� �߰�ȣ�� ����Ѵ�.
	if (3 > 1)
	{
		cout << "this is true" << endl;
		cout << "true second line" << endl;
	}
	else
	{
		cout << "this is false" << endl;
	}

	bool b;
	cin >> b; // �Է¿� false�� �Է��ϸ� true�� ��ȯ�Ѵ�.
	cout << "Your input: " << b << endl;

}