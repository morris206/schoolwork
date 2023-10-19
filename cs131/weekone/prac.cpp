#include <iostream>
#include <iomanip>
using namespace std;


int main() {
int n = 1;

    while (n <= 32500) {
	int sum = 0;
	cout << " Enter a number: " << endl;
	cin >> n;

	for (int i = 1; i < n; i++)
	    if (n / i * i == n) {
		sum += i;
	    }

	if (sum < n) {
	    cout << n << " is a deficient number" << endl;
	}
	else if (sum > n) {
	    cout << n << " is a abundant number" << endl;
	}
	else if (sum == n) {
	    cout << n << " is a perfect number" << endl;
	}	
	
    }    
    
}
