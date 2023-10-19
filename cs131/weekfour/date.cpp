#include <iostream>
#include <string>
using namespace std;


enum Month {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December

};

struct Date {
	int day;
	Month month;
	int year;
};

string monthToString(Month& month)
{
	switch(month) {
		case January:
			return "January";
		case February:
			return "February";
		case March:
			return "March";
		case April:
			return "April";
		case May:
			return "May";
		case June:
			return "June";
		case July:
			return "July";
		case August:
			return "August";
		case September:
			return "September";
		case October:
			return "October";
		case November:
			return "November";
		case December:
			return "December";
		default:
			return "Invalid month";
	}
}



void displayDate(int day, Month month, int year)
{
	cout << "The date is " << day << " of " << monthToString(month) << ", " << year << endl;
}


int main()
{
	Date usr_input;

	cout << "enter day" << endl;
	cin >> usr_input.day;
	cout << "Enter month 1-12 " << endl;
	int month_input;
	cin >> month_input;
	usr_input.month = static_cast<Month>(month_input);
	
	cout << "Enter year " << endl;
	cin >> usr_input.year;

	displayDate(usr_input.day, usr_input.month, usr_input.year);
}
