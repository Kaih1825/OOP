/*****************************************************************//**
 * \file   Complex.cpp
 * \brief  Complex class implementation
 *
 * \author Kai
 * \date   2025/4/8
 *********************************************************************/
#include "Complex.h"
#include <cmath>
#include <string>

using namespace std;

/**
 * construct a complex number where both realValue and imaginaryValue are 0
 *
 */
Complex::Complex() {
	// Set the value into 0
	realValue = 0;
	imaginaryValue = 0;
}

/**
 * construct a complex number where the realValue is r and the imaginaryValue is 0
 *
 * \param r The real value
 */
Complex::Complex(double r) {
	// Set the realvalue
	realValue = r;
	imaginaryValue = 0;
}

/**
 * construct a complex number where the realValue is r and the imaginaryValue is i
 *
 * \param r The reak vakue
 * \param i The imaginary value
 */
Complex::Complex(double r, double i) {
	// Set the realvalue and the imaginary value
	realValue = r;
	imaginaryValue = i;
}

double Complex::real() {
	return realValue;
}

double Complex::imag() {
	return imaginaryValue;
}

double Complex::norm() {
	return sqrt(pow(realValue, 2) + pow(imaginaryValue, 2));
}

double real(Complex c) {
	return c.real();
}

double imag(Complex c) {
	return c.imag();
}

double norm(Complex c) {
	return c.norm();
}

bool operator==(Complex c1, Complex c2) {
	return c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue;
}

Complex Complex::operator+(Complex c) {
	return Complex(realValue + c.realValue, imaginaryValue + c.imaginaryValue);
}

Complex operator+(double d, Complex c) {
	return Complex(d + c.realValue, c.imaginaryValue);
}

Complex Complex::operator-(Complex c) {
	return Complex(realValue - c.realValue, imaginaryValue - c.imaginaryValue);
}

Complex operator-(double d, Complex c) {
	return Complex(d - c.realValue, -c.imaginaryValue);
}

Complex Complex::operator*(Complex c) {
	double realNumber = c.realValue * realValue - c.imaginaryValue * imaginaryValue;
	double imaginaryNumber = c.realValue * imaginaryValue + c.imaginaryValue * realValue;

	return Complex(realNumber, imaginaryNumber);
}


Complex operator*(double d, Complex c) {
	return Complex(d * c.realValue, d * c.imaginaryValue);
}


Complex Complex::operator/(Complex c) {
	return (*this * Complex(c.realValue, -1 * c.imaginaryValue)) / pow(c.norm(), 2);
}

Complex operator/(double d, Complex c) {
	return (d * Complex(c.realValue, -c.imaginaryValue)) / pow(c.norm(), 2);
}

Complex operator/(Complex c, double d) {
	return Complex(c.realValue / d, c.imaginaryValue / d);
}

ostream& operator<<(ostream& strm, const Complex& c) {
	strm << c.realValue << " + " << c.imaginaryValue << "*i";
	return strm;
}

istream& operator>>(istream& strm, Complex& c) {
	string input;
	getline(strm, input);
	input = input.substr(input.find(' ') + 3, input.size() - input.find(' ') - 3);
	c.realValue = stod(input.substr(0, input.find(' ')));
	c.imaginaryValue = stod(input.substr(input.find_last_of(' ') + 1, input.size() - input.find_last_of(' ') - 2));
	return strm;
}
