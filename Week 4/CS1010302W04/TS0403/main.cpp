/*****************************************************************//**
 * \file   main.cpp
 * \brief  Use the recursive function GCD to find the greatest common divisor of two positive integers
 *
 * \author Kai
 * \date   2025/3/11
 *********************************************************************/
#include<iostream>
using namespace std;

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

int main() {
	// The variable to save the user input a and b
	int a, b;

	while (cin >> a >> b) {
		// Get and print the GCD of a and b
		cout << countGCD(max(a, b), min(a, b)) << endl;
	}
}
