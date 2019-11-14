#include <iostream>

int main()
{
	using namespace std;

	char c1(65);
	char c2('A'); // "Hello, World", 문자를 표현할 때는 '' 문자열을 표현할 때는 ""

	cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;
	// (int)c1 이렇게 casting 하는 것은 C-style
	// int(c1)은 cpp style

	cout << static_cast<char>(65) << endl; // compiler에게 check를 부탁하는 느낌이 있음, casting 하는 것이 명확함
	cout << static_cast<int>('A') << endl;

	char ch(97);

	// 변수를 넣을 수도 있다.
	cout << static_cast<int>(ch) << endl;


	char c3(65);

	cout << sizeof(char) << endl;
	cout << (int)numeric_limits<char>::max() << endl;
	cout << (int)numeric_limits<char>::lowest() << endl;

	return 0;
}