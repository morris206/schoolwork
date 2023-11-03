#include <iostream>
using namespace std;


int partition(int arr[], int start, int end_
{
	int pivot = arr[start];
	int count = 0;
	for(int i = start + 1; i <= end; i++) {
		if(arr[i] <= pivot){
			count++;
		}
	}

	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	int i = start, j = end
}
