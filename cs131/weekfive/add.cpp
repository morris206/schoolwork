#include <iostream>
using namespace std;

void incByFive(int& number)
{
	number += 5;

}

int main()
{
	int number = 2;
	incByFive(number);
	cout << number;

}
