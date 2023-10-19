#include <iostream>
#include <time.h>
#include "Die.h"
using namespace std;

int main() {
 srand(time(NULL));  //Set the random seed
 //Declare die
 Die d1(6);
 Die d2(6);
 //Call methods
 d1.roll();
 d1.display();
 d2.roll();
 d2.display();
int d1value = d1.getDieValue();
int d2value = d2.getDieValue();
if(d1value == d2value)
	cout << "Doubles" << endl;
}

