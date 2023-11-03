#include <iostream>
using namespace std;


int getMax(int arr[], int n)
{
	int mx = arr[0];
	for(int i = 1; i < n; i++){
		if(arr[i] > mx)
			mx = arr[i];
	}
	return mx;
}

void countsort(int array[], int size, int place)
{
	const int max = 10;
	int output[size];
	int count[max];

	//num of elements
	for(int i = 0; i < size; ++i)
		count[i] = 0;
	//count
	for(int i = 1; i < max; i++)
		count[i] += count[i-1];
	//sort elements
	for(int i = size - 1; i >= 0; i--){
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;				
	}
	
	for(int i = 0; i < size; i++)
		array[i] = output[i];
}

void radixsort(int array[], int size)
{
	int max = getMax(array, size);

	for(int place = 1; max / place > 0; place *= 10)
		countsort(array, size, place);
}

void display(int array[], int size)
{
	int i;
	for(i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

int main()
{
	int array[] = {5, 8, 3, 7, 2};
	int n = sizeof(array) / sizeof(array[0]);
	radixsort(array, n);
	display(array, n);

	return 0;
}
