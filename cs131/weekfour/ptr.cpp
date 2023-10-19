#include <iostream>
using namespace std;

void incByTwo(int &number)
{
	number += 2;
}

int main()
{
	int number = 5;
	incByTwo(number);
	cout << number;
}
