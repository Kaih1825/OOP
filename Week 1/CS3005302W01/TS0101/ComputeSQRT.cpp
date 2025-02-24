/*****************************************************************//**
* \file   ComputeSQRT.cpp
 * \brief  The Babylonian algorithm to compute the square root of a positive number.
 *
 * \author Kai
 * \date   2025/2/20
 *********************************************************************/
#include<iostream>
using namespace std;

int main() {
	// The variable for recording user input
	double n = 0;

	// infinite loop until cin meets EOF
	while (cin >> n) {
		// Make a guess at the number, and pick n/2 as initial guess
		double guess = n / 2;
		// Save the previous guess
		double previousGuess = 0;

		// If the destence of the guess number and the previous guess number smaller than 0.01, than guess answer is true
		while (abs(guess - previousGuess) > 0.01) {
			// Save the previous guess number
			previousGuess = guess;

			// The Babylonian algorithm (r = n / guess, guess= (guess + r) / 2)
			double r = n / guess;
			guess = (guess + r) / 2;
		}

		// Print the final answer
		printf("%.2f\n", guess);
	}

	return 0;
}
