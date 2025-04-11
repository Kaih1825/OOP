/*****************************************************************//**
 * \file   PrimeNumber.h
 * \brief  A class named PrimeNumber that stores a prime number
 *
 * \author kai
 * \date   2025/4/8
 *********************************************************************/
#pragma once
class PrimeNumber {
public:
	// The value of the prime number
	int value;

	// Return the value of this prime number
	int get();

	// Construct a prime number where the value is 1
	PrimeNumber();
	// Construct a prime number where the value is _value
	PrimeNumber(int _value);

	// Return the next larger prime number (++x)
	PrimeNumber& operator++();
	// Find next larger prime number (x++)
	PrimeNumber operator++(int);

	// Return the next smaller prime number (--x)
	PrimeNumber& operator--();
	// Find next smaller prime number (x--)
	PrimeNumber operator--(int);
};