#include <iostream>
#include <string>
using namespace std;

class ValidateDate {
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

	public:
		// Constructor
		ValidateDate(int day, int month, int year) 
		{
			usr_input.day = day;
			usr_input.month = static_cast<Month>(month);
			usr_input.year = year;
		}

	bool isValid(Date usr_input)
	{
    	bool valid = false;

	
		if (usr_input.month == January && usr_input.day >= 1 && usr_input.day <= 31)
			valid = true;
		else if (usr_input.month == February && usr_input.day >= 1 && usr_input.day <= 28)
			valid = true;
		else if (usr_input.month == March && usr_input.day >= 1 && usr_input.day <= 31)
			valid = true;
		else if (usr_input.month == April && usr_input.day >= 1 && usr_input.day <= 30)
			valid = true;
		else if (usr_input.month == May && usr_input.day >= 1 && usr_input.day <= 31)
			valid = true;
		else if (usr_input.month == June && usr_input.day >= 1 && usr_input.day <= 30)
			valid = true;
		else if (usr_input.month == July && usr_input.day >= 1 && usr_input.day <= 31)
			valid = true;
		else if (usr_input.month == August && usr_input.day >= 1 && usr_input.day <= 31)
			valid = true;
		else if (usr_input.month == September && usr_input.day >= 1 && usr_input.day <= 30)
			valid = true;
		else if (usr_input.month == October && usr_input.day >= 1 && usr_input.day <= 31)
			valid = true;
		else if (usr_input.month == November && usr_input.day >= 1 && usr_input.day <= 30)
			valid = true;
		else if (usr_input.month == December && usr_input.day >= 1 && usr_input.day <= 31)
 			valid = true;
		else if (usr_input.month > 12)
			valid = false;
		else
			valid = false;

		return valid;
	}
			
	void displayDate()
	{
		if(isValid(usr_input) == true)
			cout << "The date is " << usr_input.day << " of " << monthToString(usr_input.month) << ", " << usr_input.year << endl;
		else
			cout << "not a valid input. try again! " << endl;
	}

	private:
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
		Date usr_input;
};		

int main()
{
	int day, month, year;

	cout << "enter day" << endl;
	cin >> day;
	cout << "Enter month 1-12 " << endl;
	cin >> month;
	
	cout << "Enter year " << endl;
	cin >> year;

	ValidateDate validate(day, month, year);
	validate.displayDate();
}
