#include <iostream>
using namespace std;

int main(){
	int sum = 0;
	int i = 0;
/*
	for(int i = 0; i <= 10; i++)
   		sum += i;
		cout << "Sum: " << sum;
*/
	while(i <= 10){
		sum += i;
		i++;
	}	
		cout << "Sum: " << sum;

	return 0;
}
