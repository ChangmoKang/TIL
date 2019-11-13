# C++

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

