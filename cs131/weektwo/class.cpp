#include <iostream>

using namespace std;

class Student{
	float GPA; //everything in class is default private
	public://everything below is considered public for security
		string name;
		int age;		

	//Constructor
	Student(string name) {
		name = name;
	}

	float CalcGPA(float x, float y, float z){
		GPA = (x+y+z) / 3;
		return GPA;
	}
};

int main(){
	Student Samuel("Samuel"/*name from constructor*/);
	//Samuel.name = "Samuel";
	cout << Samuel.name << Samuel.CalcGPA(1,3,4) << endl;
	//Samuel.GPA = 4.0;
	//cout << Samuel.GPA << endl;
}
