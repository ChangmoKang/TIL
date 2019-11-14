#include <iostream>

int main()
{
	using namespace std;

	bool b1 = true;
	bool b2(false);
	bool b3{ true };
	b3 = false;

	cout << boolalpha; // 출력할 때 true, false로 문자로 보여줌
	cout << b1 << endl;
	cout << !b2 << endl;

	// ==는 같은지 확인하는 연산자, &&는 and 연산자, ||는 or 연산자

	if (true)
		cout << "This is true" << endl;
	else
		cout << "This is false" << endl;

	// if에 2줄 이상 사용할 경우 중괄호를 사용한다.
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
	cin >> b; // 입력에 false를 입력하면 true를 반환한다.
	cout << "Your input: " << b << endl;

}