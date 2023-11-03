#include <iostream>
#include <string>
using namespace std;

string operator+(string x, int y)
{
	string temp;
	string z = to_string(y);
	temp = x + z;
	
	return temp;
}


int main()
{
	string x = "a";
	int y = 1;
	
	auto z = x + y;
	cout << z <<  endl;
}
