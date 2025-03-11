/*****************************************************************//**
 * \file   Fraction.h
 * \brief  The class for Fraction, offer set Numerator and Denominator, get double and output reduced fraction functions
 *
 * \author Kai
 * \date   2025/3/11
 *********************************************************************/
#ifndef Fraction_H
#define Fraction_H
#include <iostream>
#include <iomanip>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	void setNumerator(int nu);
	void setDenominator(int de);
	void getDouble();
	void outputReducedFraction();

};

#endif //Fraction_H