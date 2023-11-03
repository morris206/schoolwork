#include <iostream>
using namespace std;


struct Time{ 
 int minutes, seconds;
};


int main() {
 auto t = new Time{30, 55};
 cout << t->minutes << ":" << t->seconds <<  endl;
}

