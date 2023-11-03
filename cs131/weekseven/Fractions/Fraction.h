#pragma once


#include <ostream>
using namespace std;
class Fraction
{
   public:
		Fraction();       //Default Constructor
		Fraction(int, int); //Overloaded Constructor differs in number or type of parameters
		Fraction(const Fraction & other); //Copy Constructor: parameter is the class
		const Fraction operator + (Fraction other); //Overloaded operator
		const Fraction operator - (Fraction other); //Overloaded operator
		const Fraction operator * (Fraction other); //Overloaded operator
		const Fraction operator / (Fraction other); //Overloaded operator
		int gcd(int, int);  //Method
		friend ostream& operator << (ostream& os, const Fraction &f);//Friend function has access to private variables
		int getNumerator(); //getter method
		int getDenominator();
	private:
		int numerator, denominator;
   


};

