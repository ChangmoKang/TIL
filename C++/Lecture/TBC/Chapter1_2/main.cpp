#include <iostream> 
/*
	이번에는 주석을 작성해보는 시간
*/

int main(void)
{
	int x = 2;
	// x를 5로 변경한다 << 이런 주석은 필요 없음
	// x를 ~~ 이유로 변경함 << 이러한 방식으로
	x = 5;
	int y = x + 3;

	std::cout << y << std::endl;

	return 0;
}