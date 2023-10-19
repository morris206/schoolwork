#include <iostream>
using namespace std;

void swapWithTemp(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapWithoutTemp(int &a, int &b)
{
	a = a + b; //17
	b = a - b; //17 - 5 = 12
	a = a - b; //17 - 12 = 5
}

int main()
{
	int num1 = 5;
	int num2 = 12;

	swapWithTemp(num1, num2);
	cout << "Swapping with a temp variable. first value " << num1 << " second value " << num2 << endl;

	//reset numbers
	num1 = 5;
	num2 = 12;
	
	swapWithoutTemp(num1, num2);
	cout << "Swapping without a temp variable. first value " << num1 << " second value " << num2 << endl;

	//reset numbers
	num1 = 5;
	num2 = 12;

	swap(num1, num2);
	cout << "Swapping using the built-in swap function. first value " << num1 << " second value " << num2 << endl;
}
