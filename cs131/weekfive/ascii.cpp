#include <iostream>

using namespace std;

int itoA(int num)
{
	return '0' + num;
}


int main()
{
	cout << itoA(1) +  itoA(2) << endl;
	return 0;
}
