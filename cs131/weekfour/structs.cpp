#include <iostream>
#include <sstream>

using namespace std;

enum Month {
	JAN = 1,
	FEB,
	MAR,
	APR,
	MAY,
	JUN,
	JUL,
	AUG,
	SEP,
	OCT,
	NOV,
	DEC
};

struct Date{
	int day;
	int month;
	int year;
};

string dateString(Date);

int main()
{
	Date mlk_day = {15, 1, 2024};
	cout << dateString(mlk_day) << endl;
	return 0;
}

string dateString(Date d){
	stringstream sstream; //Found in the sstream lib
    
	switch (d.month) {
    	case JAN:
        	sstream << "January";
			break;
    	case FEB:
        	sstream << "February";
			break;
    	case MAR:
        	sstream << "March";
			break;
    	case APR:
        	sstream << "April";
			break;
    	case MAY:
        	sstream << "May";
			break;
    	case JUN:
        	sstream << "June";
			break;
    	case JUL:
        	sstream << "July";
			break;
    	case AUG:
        	sstream << "August";
			break;
    	case SEP:
        	sstream << "September";
			break;
    	case OCT:
        	sstream << "October";
			break;
    	case NOV:
        	sstream << "November";
			break;
    	case DEC:
        	sstream << "December";
			break;
    	default:
        	sstream << "Invalid month";
    }

	//Strings concatenated by using the / operator. I found it cleaner to do it this way
	sstream << " " << d.day << ", " << d.year;	
	return sstream.str(); //sstream.str() used to convert to string
}
