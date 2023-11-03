#include <iostream>
#include <string>
using namespace std;


template<class Type>

//min: return the min value of two numbers
Type minimum(Type a, Type b){
	if(a < b)
		return a;
  	return b;
}

template<class Type>
void swapValues(Type &a, Type &b)
{
	Type temp = a;
	a = b;
	b = temp;
}

template<class Type>
double calcAverage(Type a, Type b)
{
	Type sum = a + b;
	Type avg = sum / 2;
	return avg;
}

int main() {
	
	//for minimum function
	cout << "Enter two values: will be treated as int ";
	int first_int, second_int;
	cin >> first_int >> second_int;
	cout << "Min: " << minimum(first_int, second_int) << endl;
	
	cout << "Enter two values: will be treated as double ";
	double first_dbl, second_dbl;
	cin >> first_dbl >> second_dbl;
	cout << "Min: " << minimum(first_dbl, second_dbl) << endl;
	
	cout << "Enter two values: will be treated as string ";
	string first_str, second_str;
	cin >> first_str >> second_str;
	cout << "Min: " << minimum(first_str, second_str) << endl;
	
	cout << endl << endl;

	//for swapping function
	int a_int = 7;
	int b_int = 10;
	swapValues(a_int, b_int);
	cout << "swapping ints 7 and 10 :" << a_int << " "  << b_int << endl;
	
	double a_dbl = 14.4;
	double b_dbl = 12.3;
	swapValues(a_dbl, b_dbl);
	cout << "swapping doubles 14.4 and 12.3 : " << a_dbl << " "  << b_dbl << endl;
	
	string a_str = "Love";
	string b_str = "Wisdom";
	swapValues(a_str, b_str);
	cout << "swapping strings Love and Wisdom : " << a_str << " "  << b_str << endl;

	cout << endl << endl;

	// for average function
	cout << "Enter two values: will be treated as int and calculated to avg ";
	int avg_int_a, avg_int_b;
	cin >> avg_int_a >> avg_int_b;
	cout << "Avg of " << avg_int_a << " and " << avg_int_b << " = " << calcAverage(avg_int_a, avg_int_b) << endl;
	
	cout << "Enter two values: will be treated as double and calculated to avg ";
	double avg_dbl_a, avg_dbl_b;
	cin >> avg_dbl_a >> avg_dbl_b;
	cout << "Avg of " << avg_dbl_a << " and " << avg_dbl_b << " = " << calcAverage(avg_dbl_a, avg_dbl_b) << endl;
	return 0;

		

}



