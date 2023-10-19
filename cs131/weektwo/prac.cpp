#include <iostream>
using namespace std;

void change(int values[]){
   for(int i = 0; i < 3; i++) values[i]++;
}

void display(int values[]){
   for(int i = 0; i < 3; i++) cout << values[i];
}
int main () {
  int values[3] = {3, 3, 3};
  change(values);
  display(values);
  return 0;
}
