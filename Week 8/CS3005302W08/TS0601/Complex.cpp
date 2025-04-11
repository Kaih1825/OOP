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
 * Construct a complex number where both realValue and imaginaryValue are 0
 *
 */
Complex::Complex() {
	// Set the value into 0
	realValue = 0;
	imaginaryValue = 0;
}

/**
 * Construct a complex number where the realValue is r and the imaginaryValue is 0
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

/**
 * Return the realValue
 *
 * \return The realValue
 */
double Complex::real() {
	return realValue;
}

/**
 * Return the imaginaryValue
 *
 * \return The imaginaryValue
 */
double Complex::imag() {
	return imaginaryValue;
}

/**
 * Return the value of กิ(( realValue^2  + imaginaryValue^(2) ))
 *
 * \return The value of กิ(( realValue^2  + imaginaryValue^(2) ))
 */
double Complex::norm() {
	return sqrt(pow(realValue, 2) + pow(imaginaryValue, 2));
}

/**
 * Return the realValue of a complex number c
 *
 * \param c The input complex number
 * \return The realValue of c
 */
double real(Complex c) {
	return c.real();
}

/**
 * Return the imaginaryValue of a complex number c
 *
 * \param c The input complex number
 * \return the imaginaryValue of c
 */
double imag(Complex c) {
	return c.imag();
}

/**
 * Return the กิ(( realValue^2  + imaginaryValue^(2) )) of a complex number c
 *
 * \param c The input complex number
 * \return The imaginaryValue of c
 */
double norm(Complex c) {
	return c.norm();
}

/**
* Judge if the realand imaginary parts of two complex numbers are equal.
 *
 * \param c1 The first complex number
 * \param c2 The second complex number
 * \return C1 and C2 is same or not
 */
bool operator==(Complex c1, Complex c2) {
	return c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue;
}

/**
 * Add another complex number
 *
 * \param c The right-hand-site of the addition
 * \return The addition result
 */
Complex Complex::operator+(Complex c) {
	return Complex(realValue + c.realValue, imaginaryValue + c.imaginaryValue);
}

/**
 * Add another double type number.
 *
 * \param d The left-hand-site of the addition
 * \param c The right-hand-site of the addition
 * \return The addition result
 */
Complex operator+(double d, Complex c) {
	return Complex(d + c.realValue, c.imaginaryValue);
}

/**
 * Minus another complex number
 *
 * \param c The right-hand-site of the subtraction
 * \return The subtraction result
 */
Complex Complex::operator-(Complex c) {
	return Complex(realValue - c.realValue, imaginaryValue - c.imaginaryValue);
}

/**
 * Minus another double type number.
 *
 * \param d The left-hand-site of the subtraction
 * \param c The right-hand-site of the subtraction
 * \return The subtraction result
 */
Complex operator-(double d, Complex c) {
	return Complex(d - c.realValue, -c.imaginaryValue);
}

/**
 * Multiply with another complex number
 *
 * \param c The right-hand-site of the multiplication
 * \return The multiplication result
 */
Complex Complex::operator*(Complex c) {
	// The real number of the result
	double realNumber = c.realValue * realValue - c.imaginaryValue * imaginaryValue;
	// The imaginary number of the result
	double imaginaryNumber = c.realValue * imaginaryValue + c.imaginaryValue * realValue;

	// Return the result
	return Complex(realNumber, imaginaryNumber);
}

/**
 * Multiply another double type number.
 *
 * \param d The left-hand-site of the multiplication
 * \param c The right-hand-site of the multiplication
 * \return The multiplication result
 */
Complex operator*(double d, Complex c) {
	return Complex(d * c.realValue, d * c.imaginaryValue);
}

/**
 * Divide with another complex number
 *
 * \param c The right-hand-site of the division
 * \return The division result
 */
Complex Complex::operator/(Complex c) {
	return (*this * Complex(c.realValue, -1 * c.imaginaryValue)) / pow(c.norm(), 2);
}

/**
 * Divide another double type number. (double / complex)
 *
 * \param d The left-hand-site of the division
 * \param c The right-hand-site of the division
 * \return The division result
 */
Complex operator/(double d, Complex c) {
	return (d * Complex(c.realValue, -c.imaginaryValue)) / pow(c.norm(), 2);
}

/**
 * Divide another double type number. (complex / double)
 *
 * \param c The left-hand-site of the division
 * \param d The right-hand-site of the division
 * \return The division result
 */
Complex operator/(Complex c, double d) {
	return Complex(c.realValue / d, c.imaginaryValue / d);
}

/**
 * Get the value of a complex number from the input stream with the format
 *
 * \param strm The output stream
 * \param c The complex want to output
 * \return The input stream
 */
ostream& operator<<(ostream& strm, const Complex& c) {
	// Set the output stream
	strm << c.realValue << " + " << c.imaginaryValue << "*i";

	// Return the output stream
	return strm;
}

/**
 * Send complex numbers to the output stream with the format
 *
 * \param strm The input stream
 * \param c The complex want to save the input
 * \return The input stream
 */
istream& operator>>(istream& strm, Complex& c) {
	// The variable to save the input string
	string input;

	// Get the hole line of the input
	getline(strm, input);

	// Parse the input
	input = input.substr(input.find(' ') + 3, input.size() - input.find(' ') - 3);

	// Set the complex number
	c.realValue = stod(input.substr(0, input.find(' ')));
	c.imaginaryValue = stod(input.substr(input.find_last_of(' ') + 1, input.size() - input.find_last_of(' ') - 2));

	// Return the input stream
	return strm;
}
