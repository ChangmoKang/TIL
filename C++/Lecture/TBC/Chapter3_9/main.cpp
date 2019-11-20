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


	// �������� 8�� �ִµ� �ִ��� ������ ������ ���
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

	// ���¸� �ٲ��� �� >> XOR ���
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

	// >> �����ڰ� & �����ں��� �켱������ ����
	red = (pixel_color & red_mask) >> 16;
	green = (pixel_color & green_mask) >> 8;
	blue = pixel_color & blue_mask;

	// red, green, blue�� char�� �����ϸ� blue�ۿ� ���ϴ� ���� �ȳ��� ������ char�� 1����Ʈ�̱� ������
	cout << bitset<8>(red) << " " << int(red) << endl;
	cout << bitset<8>(green) << " " << int(green) << endl;
	cout << bitset<8>(blue) << " " << int(blue) << endl;


	return 0;
}