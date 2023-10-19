#include <iostream>
using namespace std;

int makePartition(int arr[], int start, int end)
{
	int pivot = arr[start];
	int count = 0;
	
	//init pivot
	for(int i = start + 1; i <= end; i++) {
		if(arr[i] <= pivot)
			count++;
	}

	//give pivot correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]); //swap pivot index and start index
	
	//sort left and right parts of pivot index
	int i = start;
	int j = end;
	while(i < pivotIndex && j > pivotIndex) {
		while(arr[i] <= pivot)
			i++;
		while(arr[j] > pivot)
			j--;
		if(i < pivotIndex && j > pivotIndex)
			swap(arr[i++], arr[j--]);
	}
	return pivotIndex;
}


void quickSort(int arr[], int start, int end)
{
	//if sorted
	if(start >= end)
		return;
	
	//implement partition
	int p = makePartition(arr, start, end);
	
	//recursively call quickSort foo
	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

int main()
{
	int n, i;
	cout << "enter size of array ";
	cin >> n;
	int arr[n];
	cout << "Input elements of array " << endl;
	for(i = 0; i < n; i++)
		cin >> arr[i];

	quickSort(arr, 0, n - 1); //call foo quickSort, pass array beginning and end index
	
	//output sorted array
	cout << "After quick sort " << endl;
	for(i = 0; i < n; i++)
		cout << " " << arr[i] << endl;


}
