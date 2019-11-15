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