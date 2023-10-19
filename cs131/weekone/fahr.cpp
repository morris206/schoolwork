#include <iostream>
using namespace std;

int main() {
	double fah, cel; //Declare Variables
	cout << "Enter Fahrenheit: ";
	cin >> fah; //Get the Input
	cel = (fah -32) * 5/9; //Do the Math
	cout << fixed;
	cout.precision(3);
	cout << "Celsius: " << cel << endl; //Display the output
	return 0;
}
