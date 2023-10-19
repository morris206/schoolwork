#include <iostream>
using namespace std;

enum DayOfWeek {
	SUN = 1, 
	MON, 
	TUE, 
	WED, 
	THU, 
	FRI, 
	SAT
};

string nameDayOfWeek(DayOfWeek);

int main()
{
	int d;
	DayOfWeek day;
	cout << "Enter a day number (between 1 and 7): " << endl;
	cin >> d;
	//purpose of static cast is to convert integer to DayOfWeek Enum type
	day = static_cast<DayOfWeek>(d);
	cout << "Day of the week is " << nameDayOfWeek(day) << endl;
	return 0;
}

string nameDayOfWeek(DayOfWeek day)
{
	switch(day) {
		case SUN:
			return "Sunday";
		case MON:
			return "Monday";
		case TUE:
			return "Tuesday";
		case WED:
			return "Wednesday";
		case THU:
			return "Thursday";
		case FRI:
			return "Friday";
		case SAT:
			return "Saturday";
		default:
			return "Invalid Day Input";
	}
}
