#include <iostream>
using namespace std;

int sumArray(int arr[], int size)
{
	if(size == 0) {
		return 0;
	}
	else {
		return arr[size - 1] + sumArray(arr, size -1);
	}
}

int main()
{
	int arr[] = {2, 5, 4, 3};
	int size = sizeof(arr) / sizeof(arr[0]);

	int sum = sumArray(arr, size);
	cout << "sum of array " << sum;
	return 0;
}
