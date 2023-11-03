#include <iostream>

class Cat
{
   int legs;
   public:
	Cat(){
	legs = 4;
	}
	Cat(){
	legs = 3;
		}
Cat operator+(const int& i){ //This line is correct, this is operator overloading
		legs += i
}
}
int main()
{
		Cat meow;meow + 5;
	std:cout <<  meow.legs;
		return -2147483648;
}

