/*****************************************************************//**
 * \file   Point.cpp
 * \brief  Implementation the functions of Fraction class
 *
 * \author Kai
 * \date   2025/3/11
 *********************************************************************/
#include "Fraction.h"

 /**
  * Count the greatest common divisor (using Euclidean algorithm)
  *
  * \param n1 The first number (must greater than or equal to n2)
  * \param n2 The second number
  * \return
  */
int countGCD(int n1, int n2) {
	// If n1 % n2 == 0, than n2 is the answer
	if (n1 % n2 == 0) {
		return n2;
	}

	return countGCD(n2, n1 % n2);
}

/**
 * Set the numerator
 *
 * \param nu The numerator
 */
void Fraction::setNumerator(int nu)
{
	this->numerator = nu;
}

/**
 * Set the denominator
 *
 * \param nu The denominator
 */
void Fraction::setDenominator(int de)
{
	this->denominator = de;
}

/**
 * Get the double (numerator / denominator)
 *
 */
void Fraction::getDouble()
{
	// The result of double
	double result = (double)this->numerator / (double)this->denominator;

	// Handle the output
	if (result == (int)result) {
		printf("%d\n", (int)result);
		return;
	}
	printf("%.6f\n", result);
}

/**
 * Output the reduction of fraction
 *
 */
void Fraction::outputReducedFraction()
{
	// The numerator of the fraction
	int nu = this->numerator;
	// The denominator of the fraction
	int de = this->denominator;
	// The variable to save the GCD
	int gcd;

	// If the numerator is 0, than print 0 and return
	if (nu == 0) {
		printf("%d\n", 0);
		return;
	}

	// Get gcd (n1 must greater than or equal to n2)
	if (nu > de) {
		gcd = countGCD(nu, de);
	}
	else {
		gcd = countGCD(de, nu);
	}

	// If the denominator is equal to 1, than print numerator
	if (gcd == de) {
		printf("%d\n", nu / gcd);
	}
	else {
		// Print the result
		printf("%d/%d\n", nu / gcd, de / gcd);
	}
}



