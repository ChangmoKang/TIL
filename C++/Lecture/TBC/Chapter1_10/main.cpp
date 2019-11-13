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