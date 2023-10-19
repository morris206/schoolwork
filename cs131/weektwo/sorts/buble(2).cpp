#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
	bool swapped = false;
	for(int i = 0; i < n - 1; i++){
		swapped = false;
		for(int j = 0; j < n - 1; j++){
			if(arr[j] > arr[j + 1]){
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
	if(swapped == false)
		break;
	}
}

void printArray(int arr[], int size)
{
	for(int i = 0; i < size; i++)
		cout << " " << arr[i];
		cout << endl;
}

int main()
{
	
	int n ;
	cout << "enter the size of array ";
	cin>>n;
	int arr[n];
	for( int i = 0 ; i < n; i++){
		cin>> arr[i];
	}

	bubbleSort(arr, n);
	cout << "After bubble sort " << endl;
	printArray(arr, n);
	return 0;
}
