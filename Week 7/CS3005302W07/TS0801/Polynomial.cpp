/*****************************************************************//**
 * \file   Polynomial.cpp
 * \brief  Implement a class called Polynomial to handle one-dimensional polynomials
 *
 * \author Kai
 * \date   2025/4/1
 *********************************************************************/
#include "Polynomial.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 *  Construct a zero polynomial.
 *
 */
Polynomial::Polynomial() {

}

/**
 * Construct a one-dimensional polynomial based on the given coefficients which have the given size.
 *
 * \param param The input coefficients
 * \param size The size of the coefficients
 */
Polynomial::Polynomial(double* param, int size) {
	// Put the all value from param to the param which in class
	for (int i = 0; i < size; i++) {
		this->param.push_back(param[i]);
	}
}

/**
 * Copy constructor.
 *
 * \param poly The source polynomial
 */
Polynomial::Polynomial(const Polynomial& poly) {
	// Set the param to the param of the source
	param = poly.param;
}

/**
 * Return the number of terms of the polynomial.
 *
 * \return The number of terms of the polynomial.
 */
int Polynomial::mySize() {
	// Get the length of param (vector)
	int length = param.size();

	// length - 1 when the higer degree is 0
	for (int i = param.size() - 1; i >= 0; i--) {
		if (param[i] != 0) {
			break;
		}
		length--;
	}

	// return the length
	return length;
}

/**
 * Return the value of the polynomial after substituting var into the variables
 *
 * \param poly The input polynomial
 * \param var The x value
 * \return The value of the polynomial after substituting var into the variables
 */
double evaluate(const Polynomial& poly, const double& var) {
	// The variable to save the result
	double result = 0;

	// Compute the result
	for (int i = 0; i < poly.param.size(); i++) {
		result += poly.param[i] * pow(var, i);
	}

	// Return the result
	return result;
}

/**
 * Implement the addition of a constant number and polynomial
 *
 * \param lhs The Left-hand side of the addition
 * \param rhs The Right-hand side of the addition
 * \return The addition of two polynomials
 */
Polynomial operator+(double lhs, const Polynomial& rhs)
{
	// The variable to save the result
	Polynomial result(rhs);

	// If the rhs is empty, than return the lhs
	if (result.param.empty()) {
		result.param.push_back(lhs);
	}
	else {
		// Compute the result
		result.param[0] = lhs + rhs.param[0];
	}

	// Return the result
	return result;
}

/**
 * Implement the subtraction of a constant number and polynomial
 *
 * \param lhs The Left-hand side of the subtraction
 * \param rhs The Right-hand side of the subtraction
 * \return
 */
Polynomial operator-(double lhs, const Polynomial& rhs)
{
	// The variable to save the result
	Polynomial result(rhs);

	// If the rhs is empty, than return the lhs
	if (result.param.empty()) {
		result.param.push_back(lhs);
	}
	else {
		// Compute the result
		result.param[0] = lhs - rhs.param[0];
	}

	// Compute the result (param[1~size-1]*1)
	for (int i = 1; i < result.param.size(); i++) {
		result.param[i] *= -1;
	}

	// Return the result
	return result;
}

/**
 * Implement the multiplication of a constant number and polynomial
 *
 * \param lhs The Left-hand side of the multiplication
 * \param rhs The Right-hand side of the multiplication
 * \return
 */
Polynomial operator*(double lhs, const Polynomial& rhs)
{
	// The variable to save the result
	Polynomial result(rhs);

	// Compute the result
	for (int i = 0; i < result.param.size(); i++) {
		result[i] *= lhs;
	}

	// Return the result
	return result;
}

/**
 * Assign the value from a polynomial to another polynomial.
 *
 * \param poly The source polynomial
 */
void Polynomial::operator=(const Polynomial& poly) {
	// Set the param to the param of the source
	param = poly.param;

}

/**
 *
 * Return the coefficient of the certain power variable in the polynomial.
 * \param index The index of the param
 * \return The coefficient of the certain power variable in the polynomial
 */
double Polynomial::operator[](unsigned int index) const {
	return param[index];
}

/**
 * Let user to change the value in param
 *
 * \param index The index of the param
 * \return The coefficient of the certain power variable in the polynomial
 */
double& Polynomial::operator[](unsigned int index) {
	// Return the coefficient of the certain power variable in the polynomial
	if (index < param.size()) {
		return param[index];
	}

	// Set the size into the correct size
	for (int i = param.size(); i <= index; i++) {
		param.push_back(0);
	}

	// Return the reference of the certain power variable in the polynomial
	return param[index];
}

/**
 * Implement the addition of two polynomials
 *
 * \param otherPoly The Right-hand side of the addition
 * \return The addition of two polynomials
 */
Polynomial Polynomial::operator+(const Polynomial& otherPoly) {
	// The left hand side of the addition
	vector<double> param1 = param;
	// The righgt hand side of the addition
	vector<double> param2 = otherPoly.param;

	// Resize the two vector into the same length
	for (int i = param1.size(); i < param2.size(); i++) {
		param1.push_back(0);
	}

	for (int i = param2.size(); i < param1.size(); i++) {
		param2.push_back(0);
	}

	// The variable to save the result
	vector<double> result;

	// Compute the result
	for (int i = 0; i < param1.size(); i++) {
		result.push_back(param1[i] + param2[i]);
	}

	// Return the result
	return Polynomial(result.data(), result.size());
}

/**
 * Implement the addition of a number
 *
 * \param add The Right-hand side of the addition
 * \return The addition of two polynomials
 */
Polynomial Polynomial::operator+(const double add) {
	// The variable to save the result
	Polynomial result(*this);

	// Compute the result
	if (result.param.empty()) {
		result.param.push_back(add);
	}
	else {
		result.param[0] += add;
	}

	// Return the result
	return result;
}

/**
 * Implement the subtraction of two polynomials
 *
 * \param otherPoly The Right-hand side of the subtraction
 * \return The subtraction of two polynomials
 */
Polynomial Polynomial::operator-(const Polynomial& otherPoly) {
	// The left hand side of the addition
	vector<double> param1 = param;
	// The righgt hand side of the addition
	vector<double> param2 = otherPoly.param;

	// Resize the two vector into the same length
	size_t maxSize = max(param1.size(), param2.size());
	param1.resize(maxSize, 0);
	param2.resize(maxSize, 0);

	// The variable to save the rsult
	vector<double> result;

	// Compute the result
	for (int i = 0; i < param1.size(); i++) {
		result.push_back(param1[i] - param2[i]);
	}

	// Return the result
	return Polynomial(result.data(), result.size());
}

/**
 * Implement the subtraction of a number
 *
 * \param add The Right-hand side of the subtraction
 * \return The subtraction of two polynomials
 */
Polynomial Polynomial::operator-(const double min) {
	// The variable to save the rsult
	Polynomial result(param.data(), param.size());

	// Compute the result
	if (result.param.empty()) {
		result.param.push_back(-min);
	}
	else {
		result.param[0] = param[0] - min;
	}

	// Return the result
	return result;
}

/**
 * Implement the multiplication of two polynomials
 *
 * \param add The Right-hand side of the multiplication
 * \return The multiplication  of two polynomials
 */
Polynomial Polynomial::operator*(const double scale) {
	// The variable to save the rsult
	vector<double> result = param;

	// Compute the result
	for (int i = 0; i < param.size(); i++) {
		result[i] = param[i] * scale;
	}

	// Return the result
	return Polynomial(result.data(), result.size());
}

/**
 * Implement the multiplication of a number
 *
 * \param add The Right-hand side of the multiplication
 * \return The multiplication of two polynomials
 */
Polynomial Polynomial::operator*(const Polynomial& otherPoly) {
	// The variable to save the rsult
	Polynomial result;

	// Compute the result
	result.param = vector<double>(param.size() + otherPoly.param.size(), 0);
	for (int i = 0; i < param.size(); i++) {
		for (int j = 0; j < otherPoly.param.size(); j++) {
			result[i + j] += param[i] * otherPoly[j];
		}
	}

	// Return the result
	return result;
}

