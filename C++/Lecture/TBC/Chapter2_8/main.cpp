#include <iostream>

int main()
{
	using namespace std;

	float pi = 3.14f;
	int i = (unsigned int)12324; // int i = 12324u;

	// 2진수를 표현하려면 숫자 앞에 0b를 붙이고
	// 8진수를 표현하려면 숫자 앞에 0을 붙이고
	// 16진수를 표현하려면 숫자 앞에 0x를 붙인다

	int b = 0b1111;
	int o = 017;
	int h = 0xF;

	// 0011 1010 1111 1111이
	// 3AFF로 표현되어 경제적이기 때문에 16진수는 많이 사용된다.

	cout << b << " " <<  o << " " << h << endl;


	int num_items = 123;
	// int price = num_items * 10; 이렇게 10을 써놓는 건 안 좋음
	
	const int price_per_item = 10;
	int price = num_items * price_per_item;


	return 0;
}