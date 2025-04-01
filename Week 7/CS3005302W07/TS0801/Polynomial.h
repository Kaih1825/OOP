/*****************************************************************//**
 * \file   Polynomial.h
 * \brief  Definition of the Polynomial class for representing and manipulating polynomials.
 *
 * \author Kai
 * \date   2025/4/1
 *********************************************************************/
#pragma once
#include <vector>
using namespace std;

/**
 * . A class representing a polynomial with real coefficients.
 */
class Polynomial {
public:
	// The vector to save the set of coefficients
	vector<double> param;

	// Construct a zero polynomial.
	Polynomial();
	// Construct a one-dimensional polynomial based on the given coefficients which have the given size.
	Polynomial(double* param, int size);
	// Copy constructor.
	Polynomial(const Polynomial& poly);

	// Return the number of terms of the polynomial.
	int mySize();

	// Assign the value from a polynomial to another polynomial.
	void operator=(const Polynomial& poly);

	// Return the coefficient of the certain power variable in the polynomial.
	double operator[](unsigned int index) const;
	// Let user to change the value in param
	double& operator[](unsigned int index);

	// Implement the addition of two polynomials
	Polynomial operator+(const Polynomial& otherPoly);
	// Implement the addition of polynomial and a constant number
	Polynomial operator+(const double add);

	// Implement the subtraction of two polynomials
	Polynomial operator-(const Polynomial& otherPoly);
	// Implement the subtraction of polynomial and a constant number
	Polynomial operator-(const double min);

	// Implement the multiplication of two polynomials or a polynomial
	Polynomial operator*(const Polynomial& otherPoly);
	// Implement the multiplication of polynomial and a constant number
	Polynomial operator*(const double scale);
};

// Return the value of the polynomial after substituting var into the variables.
double evaluate(const Polynomial& poly, const double& var);

// Implement the addition of a constant number and polynomial
Polynomial operator+(double lhs, const Polynomial& rhs);
// Implement the subtraction of a constant number and polynomial
Polynomial operator-(double lhs, const Polynomial& rhs);
// Implement the multiplication of a constant number and polynomial
Polynomial operator*(double lhs, const Polynomial& rhs);

