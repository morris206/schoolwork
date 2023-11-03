#include <iostream>
using namespace std;

int main(){
int x = 5;
int* ptrx = &x;
int** ptrptrx = &ptrx;
cout << ptrx << endl;
cout << ptrptrx;
}
