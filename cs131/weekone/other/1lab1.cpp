#include <iostream>
#include <cmath>
#include <string>

using namespace std;
const int MAX_SIZE = 10;

int main(){	
	int array[MAX_SIZE];
	int sum = 0;
	for (int i = 0; i < MAX_SIZE; i ++){
		cout << "Enter a number: (enter -1 to quit)";
		cin >> array[i];
		if(array[i] == -1)
			break;
		else
			continue;
	for (int j = 1; j < i; j++){
	    if (array[i] / j * j == array[i]) {
			sum += j;
			if (sum < array[i])
	    		cout << i << " is a deficient number" << endl;
			else if (sum > array[i])
	    		cout << array[i] << " is a abundant number" << endl;
			else if (sum == array[i])
	    		cout << array[i] << " is a perfect number" << endl;
		}
	}
	}
}

/*
	for(int i = 0; i < MAX_SIZE && array[i] == -1; i++){
	}
*/
