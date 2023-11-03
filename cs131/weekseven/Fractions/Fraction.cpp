#include "Fraction.h"
#include <iostream>
//Default constructor
//
Fraction::Fraction()
{
   numerator = 0;
   denominator = 1;
   cout << "Default" << endl;
}
Fraction::Fraction(int num, int den)//Overloaded Constructor
{
   numerator = num / gcd(num, den);
   denominator = den / gcd(num, den);
   cout << "Overloaded" << endl;
}


Fraction::Fraction(const Fraction& other)
{ 
   numerator = other.numerator;
   denominator = other.denominator;
   cout << "Copy" << endl;
}

int Fraction::getDenominator()
{
	return denominator;
}

int Fraction::getNumerator()
{
   return numerator;
}


const Fraction Fraction::operator- (const Fraction other)
{   
   int newNumerator = numerator * other.denominator 
       - other.numerator * denominator;
   int newDenominator = denominator * other.denominator;
	

   return Fraction(newNumerator, newDenominator);
}

const Fraction Fraction::operator+ (const Fraction other)
{   
   int newNumerator = numerator * other.denominator 
       + other.numerator * denominator;
   int newDenominator = denominator * other.denominator;
	

   return Fraction(newNumerator, newDenominator);
}

const Fraction Fraction::operator* (const Fraction other)
{   
   int newNumerator = numerator * other.denominator 
       * other.numerator * denominator;
   int newDenominator = denominator * other.denominator;
	

   return Fraction(newNumerator, newDenominator);
}

const Fraction Fraction::operator/ (const Fraction other)
{   
   int newNumerator = numerator * other.denominator 
       / other.numerator * denominator;
   int newDenominator = denominator * other.denominator;
	

   return Fraction(newNumerator, newDenominator);
}

int Fraction::gcd(int n, int d)
{
n = abs(n);
   	d = abs(d);
    	while (n != d) {
           if (n > d)
               n -= d;
           else
               d -= n;
       }
       return n;
}


ostream& operator << (ostream& out, const Fraction &f)
{
   out << f.numerator << "/" << f.denominator;
   return out;
}


int main()
{
	Fraction f1;
	Fraction f2;
	Fraction f3;
	Fraction f4;
	Fraction f5(2, 10);
	Fraction f6(7, 15);
//	Fraction f4 = f2;
	f1 = f5 + f6;
	f2 = f5 - f6;
	f3 = f5 * f6;
	f4 = f5 / f6;

	cout << "The Numerator of f3 is: " << f3.getNumerator() << endl;
	cout << "The Denominator of f3 is: " << f3.getDenominator() << endl;
	cout << f1 << endl;
	cout << f2 << endl;
	cout << f5 << " + " << f6 << " = " << f1 << endl;
	cout << f5 << " - " << f6 << " = " << f2 << endl;
	cout << f5 << " * " << f6 << " = " << f3 << endl;
	cout << f5 << " / " << f6 << " = " << f4 << endl;
	cout << f3 << endl;
}
