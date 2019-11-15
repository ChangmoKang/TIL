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

	return 0;
}