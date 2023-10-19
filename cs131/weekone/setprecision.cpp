#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int resultInt = 11 / 4;
	int resultMod = 11 % 4;
	float result = 11.0f / 4;
	const double PI = 3.14159265359;

	cout << "Type" << setw(10) << "Result" << setprecision(3) << endl;
	cout << "Int" << setw(10) << resultInt << setprecision(3) << endl;
	cout << "Mod" << setw(10) << resultMod << setprecision(3) << endl;
	cout << "Regular" << setw(10) << result << setprecision(3) << endl;
	cout << "PI" << setw(10) << PI << setprecision(3) <<  endl;
		
	return 0;
}
