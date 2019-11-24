# C++(raw)

모든 강의를 듣고 다시 정리할 예정



출처: 교수님의 따라하며 배우는 C++ 강의

<https://www.youtube.com/playlist?list=PLNfg4W25Tapw5Yx4yuExHNybBIUk68aNz>

<https://www.inflearn.com/course/following-c-plus>

## 1-1. 프로그램의 구조

* 표현식과 명령문의 차이는 뭘까?

  > 

* 함수와 라이브러리의 차이는 뭘까?

  > 라이브러리는 이미 작성되어 있는 것이고 함수는 내가 작성하는 것

* C++에서 문장을 끝내는 기호는 뭘까?

  > ;

* 문법 오류란 무엇인가?

  > ;을 붙이지 않거나 C++ 문법을 지키지 않은 것



## 1-2. 주석

한줄 주석: `//` 

한줄 이상 주석: `/**/`

단축키: ctrl + k, ctrl + c



## 1-3. 변수

객체

변수

Left-value와 Right-value

초기화와 대입

초기화를 안 했을 때의 문제점



## 1-4. 입출력 스트림

`using namespace std`를 사용하면 선언한 중괄호 안에서 `std::`를 생략하여 사용할 수 있다.



## 1-5. 함수

```c++
#include <iostream>
using namespace std;

int addTwoNumbers(int a, int b) // 매개변수(Parameters)
{
    return a + b; // 리턴 값의 Type과 함수의 Type이 맞아야 한다.
}

int main(void)
{
    cout << addTwoNumbers(2, 4) << endl; // 인자(Arguments)
    
    return 0;
}
```

* 함수 안에서 함수를 정의(선언)할 수 없다.



## 1-6. 키워드와 식별자 이름짓기

* 식별자는 숫자로 시작할 수 없고 키워드를 사용하여 이름을 지을 수 없다.



## 1-7. 지역 범위(Local Scope)

```c++
int main()
{
    int x = 0;
    
    {
        int x = 1;
    }
    
    {
        int x = 2;
    }
}
```

> 모든 x는 서로 다른 메모리 공간을 갖는다.



```c++
int main()
{
    int x = 0;
    
    {
        x = 1;
    }
    
    cout << x << endl; // 1
}
```

> 중괄호 안에서 할당이 가능하다.



```c++
//Homework
#include <iostream>

using namespace std;

void doSomething(int x)
{
	x = 123;
	cout << x << " " << &x << endl; // 1
}

int main()
{
	int x = 0;

	cout << x << " " << &x << endl; // 2
	doSomething(x);
	cout << x << " " << &x << endl; // 3

	return 0;
}
```

> 2와 3은 같은 메모리를 가리킨다.



## 1-8. 연산자

> Literal, Operand, unary, binary, ternary

```c++
#include <iostream>

using namespace std;

int main(void)
{
	int x = 2; // x는 변수, 2는 리터럴(Literal)
	 
	cout << "Hello World" << endl; // Hello World도 리터럴

	cout << -x << endl; // -는 unary 연산자
	cout << 1 + 2 << endl; // 1과 2는 각각 literal +는 binary 연산자 1 + 2는 표현식
	
	int y = (x > 0) ? 1 : 0; // ternary 연산자 (C++에서는 조건 연산자가 유일한 삼항 연산자이다.)

	cout << y << endl;
}
```



## 1-9. 기본적인 서식 맞추기

> indenting

```c++
#include "stdafx.h"
#include <iostream>

using namespace std;


int add(int x, int y)
{
	return x + y;
}


int main()
{
	cout << "Hello, World" << 
		"Hi, World" << endl; 

	int my_v			 = 1;
	int x				 = 4;
	int num_apples		 = 123;

	return 0;
}
```



## 1-10.  선언과 정의의 분리

> Declaration, Definition

```c++
#include <iostream>

using namespace std;

int main()
{
	cout << add(1, 2) << endl;
	return 0;
}


// definition
int add(int a, int b)
{
	return a + b;
}

int multiply(int a, int b)
{
	return a * b;
}

int subtract(int a, int b)
{
	return a - b;
}
```

> 이렇게 하면  main에서 add 함수를 알 수가 없어서 build가 되지 않는다



```c++
#include <iostream>

using namespace std;

// forward declaration
int add(int a, int b);
int multiply(int a, int b);
int subtract(int a, int b);


int main()
{
	cout << add(1, 2) << endl;
	return 0;
}


// definition
int add(int a, int b)
{
	return a + b;
}

int multiply(int a, int b)
{
	return a * b;
}

int subtract(int a, int b)
{
	return a - b;
}
```

> 함수의 앞 부분만 위에 적어서 선언을 해주면 잘 동작한다



## 1-11. 헤더 파일 만들기

> Header



## 1-12.  헤더 가드

> Header Guards

`#pragma once`

많은 헤더를 작성하고 main에서 include할 때 헤더가 중복되서 include 되지 않도록 하는 것



## 1-13.  명칭 공간(namespace)

```c++
#include <iostream>

using namespace std;

namespace mySpace1
{
	namespace innerSpace
	{
		int my_function()
		{
			return 0;
		}
	}

	int doSomething(int a, int b)
	{
		return a + b;
	}
}

namespace mySpace2
{
	int doSomething(int a, int b)
	{
		return a * b;
	}
}

int main(void)
{
	using namespace mySpace1;

	//mySpace1::innerSpace::my_function();
	cout << doSomething(3, 5) << endl; // 8
	cout << mySpace2::doSomething(3, 5) << endl; // 15
	return 0;
}
```



## 1-14. 전처리기(preprocessor)

```c++
#include <iostream>

using namespace std;

#define MY_NUMBER 123

int main()
{
	cout << MY_NUMBER << endl;

	return 0;
}
```



## 2-1. 기본 자료형

![자료형 테이블](./asset/2_1_1.png)



```c++
#include <iostream>

int main()
{
	using namespace std;

	bool bValue = true;
	char chValue = 'A'; // char chValue = '65' 문자도 숫자로 표현된다.
	float fValue = 3.141592f; // float는 f를 뒤에 써준다, f를 생략할 경우 3.141592는 double이기 때문에 float에 저장할 경우 절삭될 수 있다.
	double dValue = 3.141592;

	auto aValue = 3.141592f;
	auto aValue2 = 3.141592;

	// size를 출력하려면 sizeof()를 사용한다. 타입을 측정할 수도 있다.
	cout << sizeof(aValue) << endl;


	int a = 123; // copy initialization
	int a(123); // direct initialization
	int b{ 123 }; // uniform initialization (가장 엄격함)

	return 0;
}
```



## 2-2. 정수형

![정수형 테이블](./asset/2_2_1.png)

```c++
#include <iostream>
#include <cmath>
#include <limits>

int main()
{
	using namespace std;

	//short s = 1; // 2 bytes = 2 * 8 bits = 16 bits
	//int i = 1;
	//long l = 1;
	//long long ll = 1;

	//cout << sizeof(short) << endl;
	//cout << sizeof(int) << endl;
	//cout << sizeof(long) << endl;
	//cout << sizeof(long long) << endl;

	short s = 1;
	cout << pow(2, sizeof(short) * 8 - 1) - 1 << endl;
	cout << numeric_limits<short>::max() << endl; // 범위에서 가장 큰 값
	cout << numeric_limits<short>::min() << endl; // 절대값이 가장 작은 값
	cout << numeric_limits<short>::lowest() << endl; // 범위에서 가장 작은 값

}
```



## 2-3. 고정 너비 정수

```c++
#include <iostream>

int main()
{
	using namespace std;

	int16_t i(5);
	int8_t my_int = 65; // int지만 char로 됨

	cout << my_int << endl;

	int_fast8_t fi(5); // int 중에서 8비트 사이즈 중에 가장 빠른 것
	int_least64_t fl(5); // 적어도 64비트 이상인 int 사용

	return 0;
}
```



## 2-4. Void(무치형)

```c++
#include <iostream>

int main()
{
	using namespace std;

	// void my_void; void는 메모리를 차지하지 않기 때문에 선언이 불가능

	int i = 123;
	float f = 123.456f;

	void *my_void; // 이건 가능하다...

	cout << &i << endl;
	cout << &f << endl;

	my_void = (void*)&i;
	cout << my_void << endl;
	my_void = (void*)&f;
	cout << my_void << endl;

	return 0;
}
```



## 2-5. 부동소수점(floating point)

![부동 소수점 테이블](./asset/2_5_1.png)

![부동 소수점 계산 방법](./asset/2_5_2.png)

```c++
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

int main()
{
	using namespace std;

	float f(3.141592f);
	double d(3.141592);
	long double ld(3.141592);

	cout << sizeof(f) << endl;
	cout << sizeof(d) << endl;
	cout << sizeof(ld) << endl;

	cout << numeric_limits<float>::max() << endl;
	cout << numeric_limits<double>::max() << endl;
	cout << numeric_limits<long double>::max() << endl;


	cout << 3.14 << endl;
	cout << 31.4e-1 << endl;
	cout << 31.4e1 << endl;
	cout << 31.4e2 << endl;

	cout << setprecision(16);
	cout << 1.0 / 3.0 << endl;
	cout << setprecision(9);
	cout << 123456789.0f << endl; // 123456792

	double d1(0.1);
	double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);

	cout << setprecision(17);
	cout << d1 << " " << d2 << endl; // 값이 정확하게 나오지 않는다.

	double zero = 0.0;
	double posinf = 5.0 / zero;
	double neginf = -5.0 / zero;
	double nan = zero / zero;

	cout << posinf << endl;
	cout << neginf << endl;
	cout << nan << endl;

	cout << posinf << " " << isnan(posinf) << endl;
	cout << neginf << " " << isnan(neginf) << endl;
	cout << nan << " " << isnan(nan) << endl;

	return 0;
}
```



## 2-6. Boolean과 조건문 if

```c++
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
```



## 2-7. Char(문자형)

![ASCII table](./asset/2_7_1.png)

```c++
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
```



## 2-8. Literal Constant(리터럴 상수)

```c++
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
```



## 2-9. Symbolic Constant(심볼릭 상수)

```c++
#include <iostream>
// 자주 사용되는 상수는 Header에 저장해서 사용한다.
#include "constants.h"

// my_number 파라미터를 보통 바꾸지 않기 때문에 const를 사용한다.
void printNumber(const int my_number)
{
	using namespace std;

	// 굳이 바꾸려면 이렇게 따로 변수를 선언한다.
	int n = my_number;

	cout << my_number << endl;
}


int main()
{
	using namespace std;

	const double gravity{ 9.8 };
	// gravity = 1.2; const를 사용할 경우 바뀌지 않는다


	int number;
	cin >> number;

	const int special_number(number); // 런타임에서 검사하기 때문에 실행이 가능하다.
	// constexpr int speical_number(number); 컴파일 타임에서 검사하기 때문에 동작하지 않는다.

	// Header에서 불러온 상수
	cout << constants::pi << endl;

	return 0;
}
```



## 3-1. 연산자 우선순위와 결합법칙

> <https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B>

```c++
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// 상식대로 *부터 계산한다
	int x1 = 4 + 2 * 3;

	// 왼쪽에서 먼저 계산한다. associativity(left-to-right인지 right-to-left인지)
	int x2 = 4 * 3 / 2;

	// ^은 제곱이 아니다. 제곱을 하려면 cmath를 불러와서 pow를 사용하자
	int x3 = pow(2, 3);
	cout << x3 << endl;
}
```



## 3-2. 산술 연산자(Arithmetic Operators)

```c++
#include <iostream>

int main()
{
	using namespace std;

	int x = 7;
	int y = 4;
	int z1 = x + y;
	int z2 = x - y;
	int z3 = x * y;
	int z4 = x / y;
	int z5 = x % y; // 나머지 연산자

	cout << x / y << endl; // 1
	cout << float(x) / y << endl; // 1.75
	cout << x / float(y) << endl; // 1.75
	cout << float(x) / float(y) << endl; // 1.75

	cout << -5 / 2 << endl; // -2.5지만 소수점을 버리기 때문에 -2가 출력됨
	cout << -5 % 2 << endl; // 나머지 연산자 앞에 양수면 양의 결과 음수이면 음의 결과가 나온다.

	int z = x;
	z += y; // z = z + y;
	z -= y; // z = z - y;
	z *= y; // z = z * y;
	z /= y; // z = z / y;
	z %= y; // z = z % y;

	return 0;
}
```



## 3-3. 증감 연산자

```c++
#include <iostream>


int main()
{
	using namespace std;

	int x = 5;
	int y1 = ++x; // x가 1이 증가하고 y1에 assign된다.
	cout << y1 << endl;
	cout << x << endl;

	int y2 = x++; // y2에 먼저 x가 assign되고 x가 증가한다.
	cout << y2 << endl;
	cout << x << endl;

}
```



## 3-4. sizeof, 쉼표 연산자, 조건(부) 연산자

* `sizeof`는 함수가 아니라 연산자이다.

```c++
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
```



## 3-5. 관계 연산자

```c++
#include <iostream>

int main()
{
	using namespace std;

	int x, y;
	cin >> x >> y;
	cout << "Your input values are : " << x << " " << y << endl;

	if (x == y)
		cout << "equal" << endl;
	if (x != y)
		cout << "Not equal" << endl;
	if (x > y)
		cout << "x is greater than y" << endl;
	if (x < y)
		cout << "x is less than y" << endl;
	if (x >= y)
		cout << "x is greater than y or equal to y" << endl;
	if (x <= y)
		cout << "x is less than y or equal to y" << endl;


	double d1(100 - 99.99);	// 0.01
	double d2(10 - 9.99);	// 0.01


	if (d1 == d2)
		cout << "equal" << endl;
	else
	{
		cout << "Not equal" << endl;
		if (d1 > d2)
			cout << "d1 > d2" << endl;
		else
			cout << "d1 < d2" << endl;
	}

	cout << d1 << endl;
	cout << d2 << endl;
	cout << abs(d1 - d2) << endl;

	const double epsilon = 1e-10;

	if (abs(d1 - d2) < epsilon)
		cout << "Approximately equal" << endl;
	else
		cout << "Not equal" << endl;

	return 0;
}
```



## 3-6. 논리 연산자

```c++
#include <iostream>

using namespace std;

int main()
{
	// logical Not !x
	bool x = true;
	cout << !x << endl;

	// logical And
	bool a = true;
	bool b = true;
	cout << (a && b) << endl;

	// logical OR
	bool w1 = true;
	bool w2 = false;
	cout << (w1 || w2) << endl;

	// short circuit evaluation
	int x1 = 1;
	int x2 = 2;
	if (x1 == 1 && x2++ == 2) // x1 == 1이 부분이 틀리면 뒤는 보지도 않는다.
	{
		// do sth
	}
	cout << x2 << endl;

	// De Morgan's Law
	// !(x && y) == !x || !y

	// XOR
	// C++에는 XOR 따로 없다.
	// if (x != y) ... 

	// AND 연산자가 OR 연산자보다 우선순위가 높다.
	return 0;
}
```



## 3-7. 이진수

```c++
#include <iostream>

using namespace std;

int main()
{
	/*

	148 (decimal to binary)

	148 / 2 = 74 >> 0
	72	/ 2 = 37 >> 0
	37	/ 2 = 18 >> 1
	18	/ 2 = 9 >> 0
	9	/ 2 = 4 >> 1
	4	/ 2 = 2 >> 0
	2	/ 2 = 1 >> 0
	1	/ 2 = 1 >> 1

	1001 0100

	*/


	/*
	
	-5 (decimal to binary)(unsigned)
	0000 0101
	complement
	1111 1010
	+ 1
	1111 1011 >> -5
	
	if signed
	1000 0101 >> -5



	*/

	/*
	
	1001 1110 (binary to decimal)(signed)
	complement
	0110 0001
	+1
	0110 0010 >> 98인데 원래 음수였으니 -98

	*/


	return 0;
}
```



## 3-8.  비트단위 연산자

```c++
#include <iostream>
#include <bitset>

int main()
{
	using namespace std;

	// 비드단위 연산자의 종류
	// << left shift
	// >> right shift
	// ~
	// &
	// |
	// ^
	
	unsigned int a = 3;
	cout << bitset<4>(a) << endl;

	// <<을 한다는 것은 2의 제곱수를 곱하는 것과 같다.
	unsigned int b = 3 << 2;
	cout << bitset<4>(b) << " " << b << endl;

	// >>은 2의 마이너스 제곱수를 곱하는 것과 같다.
	unsigned int c = 1024 >> 4;
	cout << bitset<8>(c) << " " << c << endl;

	unsigned int d = 1024;
	cout << bitset<16>(d) << endl;
	cout << bitset<16>(~d) << " " << (~d) << endl; // 1024의 보수가 출력됨


	unsigned int x1 = 0b1100;
	unsigned int x2 = 0b0110;

	cout << bitset<4>(x1 & x2) << endl; // bitwise AND
	cout << bitset<4>(x1 | x2) << endl; // bitwise OR
	cout << bitset<4>(x1 ^ x2) << endl; // bitwise XOR

	cout << (0b0110 >> 2) << endl;
	cout << (5 & 12) << endl;
	cout << (5 | 12) << endl;
	cout << (5 ^ 12) << endl;

	return 0;
}
```



## 3-9. 비트 플래그, 비트 마스크

```c++
#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	// BIT FLAG
	const unsigned char opt0 = 1 << 0;
	const unsigned char opt1 = 1 << 1;
	const unsigned char opt2 = 1 << 2;
	const unsigned char opt3 = 1 << 3;

	cout << bitset<8>(opt0) << endl;
	cout << bitset<8>(opt1) << endl;
	cout << bitset<8>(opt2) << endl;
	cout << bitset<8>(opt3) << endl;


	// 아이템이 8개 있는데 있는지 없는지 구분할 경우
	unsigned char items_flag = 0;

	cout << "No item " << bitset<8>(items_flag) << endl;

	//item0 on
	items_flag |= opt0;
	cout << "Item0 obtained " << bitset<8>(items_flag) << endl;

	//item3 on
	items_flag |= opt3;
	cout << "Item3 obtained " << bitset<8>(items_flag) << endl;

	//item3 lost
	items_flag &= ~opt3;
	cout << "Item3 lost " << bitset<8>(items_flag) << endl;

	//has item1?
	if (items_flag & opt1) { cout << "Has item1" << endl; }

	//obtain item 2, 3
	items_flag |= (opt2 | opt3);
	cout << "item2, 3 obtained" << bitset<8>(items_flag) << endl;

	// 상태를 바꿔줄 때 >> XOR 사용
	if ((items_flag & opt2) && !(items_flag & opt1))
	{
		items_flag ^= (opt1 | opt2);
		/*items_flag ^= opt2;
		items_flag ^= opt1;*/
	}

	cout << bitset<8>(items_flag) << endl;


	// BIT MASK

	const unsigned int red_mask = 0xFF0000;
	const unsigned int green_mask = 0x00FF00;
	const unsigned int blue_mask = 0x0000FF;

	cout << bitset<32>(red_mask) << endl;
	cout << bitset<32>(green_mask) << endl;
	cout << bitset<32>(blue_mask) << endl;


	unsigned int pixel_color = 0xDAA520; // (218, 165, 32)
	cout << bitset<32>(pixel_color) << endl;


	unsigned char red, green, blue;

	// >> 연산자가 & 연산자보다 우선순위가 높다
	red = (pixel_color & red_mask) >> 16;
	green = (pixel_color & green_mask) >> 8;
	blue = pixel_color & blue_mask;

	// red, green, blue를 char로 선언하면 blue밖에 원하는 값이 안나옴 이유는 char가 1바이트이기 때문에
	cout << bitset<8>(red) << " " << int(red) << endl;
	cout << bitset<8>(green) << " " << int(green) << endl;
	cout << bitset<8>(blue) << " " << int(blue) << endl;


	return 0;
}
```



## 4-1. 지역 변수의 범위와 지속기간

```c++
#include <iostream>

using namespace std;


namespace work1
{
	int a = 3;

	void doSomething()
	{
		a += 3;
	}
}

namespace work2
{
	int a = 4;

	void doSomething()
	{
		a += 5;
	}
}


int main()
{
	int apple = 5;
	cout << apple << endl; // 5
	{
		apple = 1;
		// int apple = 4;

		cout << apple << endl; // 1, int로 정의하였을 경우 4
	}
	cout << apple << endl; // 1, int로 정의하였을 경우 5

	work1::a;
	work1::doSomething();

	work2::a;
	work2::doSomething();

	return 0;
}

// apple = 3; 중괄호 밖을 넘어갔으므로 사용할 수 없다.

```



## 4_2. 전역 변수, 정적 변수, 내부연결, 외부연결

> 이후 정리