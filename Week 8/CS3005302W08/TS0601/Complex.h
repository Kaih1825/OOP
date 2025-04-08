/*****************************************************************//**
 * \file   Complex.h
 * \brief  Define the Complex category to represent and manipulate complex numbers.
 *
 * \author Kai
 * \date   2025/4/8
 *********************************************************************/
#include <iostream>

using namespace std;

class Complex
{
public:
	// The real value part and the imaginary part
	double realValue, imaginaryValue;

	// construct a complex number where both realValue and imaginaryValue are 0.
	Complex();

	// construct a complex number where the realValue is r and the imaginaryValue is 0.
	Complex(double r);

	// construct a complex number where the realValue is r and the imaginaryValue is i.
	Complex(double r, double i);

	// return the realValue
	double real();
	// return the imaginaryValue
	double imag();
	// return the value of √(( realValue^2  + imaginaryValue^(2) ))
	double norm();

	// return the realValue of a complex number c
	friend double real(Complex c);
	// return the imaginaryValue of a complex number c
	friend double imag(Complex c);
	// return the value of √(( realValue^2  + imaginaryValue^(2) )) of a complex number c
	friend double norm(Complex c);

	// Add another complex number
	Complex operator+(Complex c);
	// Minus another complex number
	Complex operator-(Complex c);
	// Multiply with another complex number
	Complex operator*(Complex c);
	// Divide with another complex number
	Complex operator/(Complex c);

	// Add another double type number.
	friend Complex operator+(double d, Complex c);
	// Minus another double type number.
	friend Complex operator-(double d, Complex c);
	// Multiply another double type number.
	friend Complex operator*(double d, Complex c);
	// Divide another double type number (double/complex).
	friend Complex operator/(double d, Complex c);
	// Divide another double type number (complex/double).
	friend Complex operator/(Complex c, double d);

	// Judge if the real and imaginary parts of two complex numbers are equal.
	friend bool operator==(Complex c1, Complex c2);
	// Get the value of a complex number from the input stream with the format 
	friend ostream& operator<<(ostream& strm, const Complex& c);
	// Send complex numbers to the output stream with the format
	friend istream& operator>>(istream& strm, Complex& c);
};
