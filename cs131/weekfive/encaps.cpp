#include <iostream>
using namespace std;

class Person{
private:
	string name; // encapsulation

public:
	Person(const string& n) : name(n) {}

	//encapsulated member accesor
	string getName() {
		return name;
	}

	//mutator
	void setName(const string& n)
	{
		name = n;
	}
	
	void speak() {
		cout << "Person squawks" << endl;
	}
};

//derived class from person inheriting
class Alien : public Person {
public:	
	//constructor
	Alien(const string& n) : Person(n) {}

	//overriding speak method for aliens own implementation
	void speak() {
		cout << getName() << "Can't understand it" << endl;
	}
};

int main()
{
	//create a Person obj
	Alien gray_guy("The Watcher");

	//Accessing and changing encapsulated members
	cout << "Name: " << gray_guy.setName("DudeGuy") << endl;
	cout << "Name changed to " << gray_guy.getName() << endl;

	gray_guy.speak();
	return 0;

}
