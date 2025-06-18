#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Complex
{
public:
	double realValue, imaginaryValue;

	Complex() {
		realValue = 0;
		imaginaryValue = 0;
	}

	Complex(double r) {
		realValue = r;
		imaginaryValue = 0;
	}

	Complex(double r, double i) {
		realValue = r;
		imaginaryValue = i;
	}

	double real() {
		return realValue;
	}

	double imag() {
		return imaginaryValue;
	}

	double norm() {
		return sqrt(pow(realValue, 2) + pow(imaginaryValue, 2));
	}

	friend double real(Complex c) {
		return c.realValue;
	}

	friend double imag(Complex c) {
		return c.imaginaryValue;
	}

	friend double norm(Complex c) {
		return c.norm();
	}

	Complex operator+(Complex c) {
		return Complex(realValue + c.realValue, imaginaryValue + c.imaginaryValue);
	}

	Complex operator-(Complex c) {
		double r = realValue - c.realValue;
		double i = imaginaryValue - c.imaginaryValue;
		return Complex(r, i);
	}

	Complex operator*(Complex c) {
		double r = realValue * c.realValue - c.imaginaryValue * imaginaryValue;
		double i = c.realValue * imaginaryValue + realValue * c.imaginaryValue;
		return Complex(r, i);
	}

	Complex operator/(Complex c) {
		double bottom = pow(c.realValue, 2) + pow(c.imaginaryValue, 2);
		auto top = *this * Complex(c.realValue, -c.imaginaryValue);
		return Complex(top.realValue / bottom, top.imaginaryValue / bottom);
	}

	friend Complex operator+(double d, Complex c) {
		return Complex(c.realValue + d, c.imaginaryValue);
	}

	friend Complex operator-(double d, Complex c) {
		return Complex(d - c.realValue, -c.imaginaryValue);
	}

	friend Complex operator*(double d, Complex c) {
		return Complex(c.realValue * d, c.imaginaryValue * d);
	}

	friend Complex operator/(double d, Complex c) {
		return Complex(d) / c;
	}

	friend bool operator==(Complex c1, Complex c2) {
		return (c1.realValue == c2.realValue) && (c1.imaginaryValue == c2.imaginaryValue);
	}

	friend ostream& operator<<(ostream& strm, const Complex& c) {
		strm << c.realValue << " + " << c.imaginaryValue << "*i";
		return strm;
	}

	friend istream& operator>>(istream& strm, Complex& c) {
		string input;
		getline(strm, input);
		int indexOfEq = input.find('=');
		input = input.substr(indexOfEq + 1);
		input = input.substr(0, input.size() - 2);
		input.replace(input.find('+'), 1, " ");
		stringstream ss(input);
		ss >> c.realValue >> c.imaginaryValue;
		return strm;
	}
};
