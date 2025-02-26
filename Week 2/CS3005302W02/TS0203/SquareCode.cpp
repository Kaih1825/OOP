/*****************************************************************//**
 * \file   SquareCode.cpp
 * \brief  Put the input characters into a n*n square.
 *
 * \author kai
 * \date   2025/2/26
 *********************************************************************/
#include <iostream>
using namespace std;

int main() {
	// The variable save user input
	string input;

	// Let user input until EOF
	while (cin >> input) {
		// Count of columns
		int length;
		// To get the count of columns n where (n-1)^2 < message length <= n^2 
		if (pow((int)sqrt(input.length()), 2) == input.length()) {
			length = sqrt(input.length());
		}
		else {
			length = (int)sqrt(input.length()) + 1;
		}

		// Count of rows
		int width = (double)input.length() / (double)length + 0.9;

		// Print the square
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				// If thhere is nothing can print, than break the loop
				if (length * j + i >= input.length()) {
					break;
				}
				// Print the charactar in square
				cout << input[length * j + i];
			}
			cout << endl;
		}
	}

	return 0;
}
