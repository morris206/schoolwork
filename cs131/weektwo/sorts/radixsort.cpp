#include <iostream>
using namespace std;

//find largest element in the array
int findMax(int arr[], int n)
{
	int max = arr[0];
	for(int i = 0; i < n; i++) {
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}

//sort through digits
void countSort(int arr[], int n, int place)
{
	int output[n];
	int i, count[10] = { 0 };

	// Store count of occurrences
	for (i = 0; i < n; i++)
		count[(arr[i] / place) % 10]++;

    // Change count[i] to contain actual position of digit
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / place) % 10] - 1] = arr[i];
		count[(arr[i] / place) % 10]--;
    }

    // Copy the output array to arr[] to contain sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

//sort implementation
void radixSort(int arr[], int n)
{
	int max = findMax(arr, n);
	
	for (int place = 1; max / place > 0; place *= 10)
		countSort(arr, n, place);
}

void printArray(int arr[], int n)
{
	for(int i = 0; i < n; i++) {
		cout << " " << arr[i];
		cout << endl;
	}
}

int main()
{
	int n;
	cout << "enter size of array ";
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	radixSort(arr, n);
	cout << "After radix sort " << endl;
	printArray(arr, n);
}
