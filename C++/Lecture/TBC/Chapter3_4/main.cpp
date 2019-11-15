#include <iostream>

using namespace std;

int main()
{
	// sizeof operator
	// sizeof는 함수가 아니라 operator이다.
	float v;
	cout << sizeof(float) << endl;
	cout << sizeof(v) << endl;


	// comma operator
	int x = 3;
	int y = 10;

	// ++x;
	// ++y;
	// int z = y; 이 세단계를 압축한 것이 아래의 코드
	int z = (++x, ++y);

	int a = 1, b = 10;
	int c;
	
	// ,가 =보다 우선순위가 낮기 때문에 c = a가 실행된다.
	c = a, b;
	// (c = a), b;

	cout << c << endl;


	// conditional operator(arithmetic if)
	bool onSale = true;

	// 어떤 값을 const로 하고 싶은데 조건을 걸고 싶으면 삼항 연산자를 사용한다.
	const int price = (onSale == true) ? 10 : 100;
	/*if (onSale)
		price = 10;
	else
		price = 100;*/
	

	int xx = 5;
	cout << ((xx % 2 == 0) ? "even" : "odd") << endl;
	//cout << (xx % 2 == 0) ? "even" : "odd" << endl; 얘는 왜 오류가 날까? 매우 높은 확률로 우선순위 때문에(삼항 연산자는 16순위)

	return 0;
}