#include <iostream>
#include <cmath>
using namespace std;
const int MAX_SIZE = 10;

int main(){
	int array[MAX_SIZE] = {-1};
	int count = 0;

	while(count < MAX_SIZE){
		int input;
		cout << "Enter a number: (enter -1 to quit)";
		cin >> input;
		if(input == -1)
			break;
		if(count >= MAX_SIZE){
			break;	
		}

	array[count++] = input;

	}

	for(int i = 0; i < count; ++i){
		int num = array[i];
		int sum = 1;		
		for(int j = 2; j <= sqrt(num); ++j){
			if(num % j == 0){
				sum += j;
				if(j != (num / j)){
					sum += num / j;
				}
			}
		}

		if (sum < num)
	    	cout << num << " is a deficient number" << endl;
		else if (sum == num)
			cout << num << " is a perfect number" << endl;
		else
			cout << num << " is an abundant number" << endl;
	
	}
}
