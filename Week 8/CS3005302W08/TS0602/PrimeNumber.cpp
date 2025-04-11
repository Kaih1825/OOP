/*****************************************************************//**
 * \file   PrimeNumber.cpp
 * \brief  PrimeNumber class implementation
 *
 * \author kai
 * \date   2025/4/8
 *********************************************************************/
#include "PrimeNumber.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Construct a PrimeNumber where the value is 1
 *
 */
PrimeNumber::PrimeNumber() {
	value = 1;
}

/**
 * Construct a PrimeNumber where the value is _value
 *
 * \param _valuet The input value
 */
PrimeNumber::PrimeNumber(int _value) {
	value = _value;
}

/**
 * Return the value of this PrimeNumber
 *
 * \return The value of this PrimeNumber
 */
int PrimeNumber::get() {
	return value;
}

/**
 * Return the next larger prime number (++x)
 *
 * \return The next larger prime number
 */
PrimeNumber& PrimeNumber::operator++() {
	// The number to test is prime number or not
	int n = value + 1;

	// Check the number is 2, 3 or 5
	if (n == 2 || n == 3 || n == 5) {
		// The variable to save the return value
		PrimeNumber res = PrimeNumber(n);
		// Set the value
		value = n;
		// Return the result
		return res;
	}

	// Find the number until found the prime number
	while (true) {
		// The variable to save is prime number or not
		bool isPrime = true;

		// Test the number is prime number or not
		for (int i = 1; i < sqrt(n); i++) {
			// Check the number is multiples of 2, 3 or 5
			if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
				isPrime = false;
				break;
			}

			// Check is prime number or not
			if (n == (6 * i + 1) || n == (6 * i + 5)) {
				isPrime = true;
				break;
			}
			if (n % (6 * i + 1) == 0 || n % (6 * i + 5) == 0) {
				isPrime = false;
				break;
			}
		}

		// If it is prime, than change the value and return
		if (isPrime) {
			PrimeNumber res = PrimeNumber(n);
			value = n;
			return res;
		}

		// If it is not the prime number, than the number + 1
		n++;
	}

}

/**
 * Find next larger prime number (x++)
 *
 * \param No significance
 * \return The origin number
 */
PrimeNumber PrimeNumber::operator++(int) {
	// The number to test is prime number or not
	int n = value + 1;

	// Check the number is 2, 3 or 5
	if (n == 2 || n == 3 || n == 5) {
		// Copy of the origin number
		PrimeNumber res = PrimeNumber(value);
		// Set the value
		value = n;
		// Return the result
		return res;
	}

	// Find the number until found the prime number
	while (true) {
		// The variable to save is prime number or not
		bool isPrime = true;

		// Test the number is prime number or not
		for (int i = 1; i < sqrt(n); i++) {
			// Check the number is multiples of 2, 3 or 5
			if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
				isPrime = false;
				break;
			}

			// Check is prime number or not
			if (n == (6 * i + 1) || n == (6 * i + 5)) {
				isPrime = true;
				break;
			}
			if (n % (6 * i + 1) == 0 || n % (6 * i + 5) == 0) {
				isPrime = false;
				break;
			}
		}

		// If it is prime, than return than change the value
		if (isPrime) {
			PrimeNumber res = PrimeNumber(value);
			value = n;
			return res;
		}

		// If it is not the prime number, than the number + 1
		n++;
	}
}

/**
 * Return the next smaller prime number (--x)
 *
 * \return The next smaller prime number
 */
PrimeNumber& PrimeNumber::operator--() {
	// If the value is 2, tham return 1
	if (value == 2) {
		PrimeNumber res = PrimeNumber(1);
		value = 1;
		return res;
	}

	// The number to test is prime number or not
	int n = value - 1;

	// Check the number is 2, 3 or 5
	if (n == 2 || n == 3 || n == 5) {
		// The variable to save the return value
		PrimeNumber res = PrimeNumber(n);
		// Set the value
		value = n;
		// Return the result
		return res;
	}

	// Find the number until found the prime number
	while (true) {
		// The variable to save is prime number or not
		bool isPrime = true;

		// Test the number is prime number or not
		for (int i = 1; i < sqrt(n); i++) {
			// Check the number is multiples of 2, 3 or 5
			if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
				isPrime = false;
				break;
			}

			// Check is prime number or not
			if (n == (6 * i + 1) || n == (6 * i + 5)) {
				isPrime = true;
				break;
			}
			if (n % (6 * i + 1) == 0 || n % (6 * i + 5) == 0) {
				isPrime = false;
				break;
			}
		}

		// If it is prime, than change the value and return
		if (isPrime) {
			PrimeNumber res = PrimeNumber(n);
			value = n;
			return res;
		}

		// If it is not the prime number, than the number - 1
		n--;
	}
}

/**
 * Find next smaller prime number (x--)
 *
 * \param No significance
 * \return The origin number
 */
PrimeNumber PrimeNumber::operator--(int) {
	// If the value is 2, tham return 1
	if (value == 2) {
		PrimeNumber res = PrimeNumber(value);
		value = 1;
		return res;
	}

	// The number to test is prime number or not
	int n = value - 1;

	// Check the number is 2, 3 or 5
	if (n == 2 || n == 3 || n == 5) {
		PrimeNumber res = PrimeNumber(value);
		value = n;
		return res;
	}

	// Find the number until found the prime number
	while (true) {
		// The variable to save is prime number or not
		bool isPrime = true;
		for (int i = 1; i < sqrt(n); i++) {
			// Check the number is multiples of 2, 3 or 5
			if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
				isPrime = false;
				break;
			}

			// Check is prime number or not
			if (n == (6 * i + 1) || n == (6 * i + 5)) {
				isPrime = true;
				break;
			}
			if (n % (6 * i + 1) == 0 || n % (6 * i + 5) == 0) {
				isPrime = false;
				break;
			}
		}

		// If it is prime, than return than change the value
		if (isPrime) {
			PrimeNumber res = PrimeNumber(value);
			value = n;
			return res;
		}

		// If it is not the prime number, than the number - 1
		n--;
	}

}

