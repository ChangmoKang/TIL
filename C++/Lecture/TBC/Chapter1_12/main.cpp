#include <iostream>
#include "add.h"

using namespace std;

void doSomething()
{
	add(1, 2);
}


int main(void)
{
	cout << add(1, 2) << endl;

	return 0;
}