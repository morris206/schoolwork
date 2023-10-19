#include <iostream>

using namespace std;
const int MAX_SIZE = 10;

void doCalculations(int array){
	int sum = 0;
	for (int j = 1; j < array; j++){
	    if (array / j * j == array) {
		sum += j;
		}
		if (sum < array)
	    	cout << array << " is a deficient number" << endl;
		else if (sum > array)
	    	cout << array << " is a abundant number" << endl;
		else if (sum == array)
			cout << array << " is a perfect number" << endl;	
	}
}

int main(){	
	int array[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i ++){
		cout << "Enter a number: (enter -1 to quit)";
		cin >> array[i];
   		//cout << array[i] << "\n";
		if(array[i] == -1)
			break;
		else
			continue;
		}
	
	doCalculations(*array);
}

/*
	for(int i = 0; i < MAX_SIZE && array[i] == -1; i++){
	}
*/
