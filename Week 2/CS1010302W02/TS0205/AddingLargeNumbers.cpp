/*****************************************************************//**
 * \file   AddingLargeNumbers.cpp
 * \brief  Adding result A + B where the maximum bits of the number can approximate to 10000
 *
 * \author kai
 * \date   2025/2/27
 *********************************************************************/
#include <iostream>
#include <string>

using namespace std;

// The struct of the big number
struct BigInt
{
	string number;
};

/**
 * Add two big number
 *
 * \param lhs The left addend number
 * \param rhs The right addend number
 * \return The sum of two big number
 */
BigInt Add(BigInt& lhs, BigInt& rhs) {
	// Define the variable to save the result
	BigInt result;

	// Judge if the lhs and is rhs is number or not
	for (char c : lhs.number) {
		// If the ASCII code of each charactor in lhs is less than 30('0') or is more than 39('9'), than the charactor is not a number
		if (c < '0' || c>'9') {
			result.number = "Not a valid number, please try again.";
			return result;
		}
	}

	// Judge if the rhs and is rhs is number or not
	for (char c : rhs.number) {
		if (c < '0' || c>'9') {
			result.number = "Not a valid number, please try again.";
			return result;
		}
	}

	// The variable to save carry flag
	int carry = 0;

	// Let the length of lhs is equal to max(lhs length,rhs length)
	if (lhs.number.length() > rhs.number.length()) { // The length of rhs is shorter than lhs
		// The variable to save the "0"
		string blanks = "";

		// Calculate and fill the number of zeros to be filled
		for (int i = 0; i < lhs.number.length() - rhs.number.length(); i++) {
			blanks += "0";
		}
		rhs.number = blanks + rhs.number;
	}
	else { // The length of lhs is shorter than rhs
		// The variable to save the "0"
		string blanks = "";

		// Calculate and fill the number of zeros to be filled
		for (int i = 0; i < rhs.number.length() - lhs.number.length(); i++) {
			blanks += "0";
		}
		lhs.number = blanks + lhs.number;
	}

	// Add lhs and rhs character from the right
	for (int i = lhs.number.length() - 1; i >= 0; i--) {
		// Get the character in lhs and rhs then convert it to number useing minus 30('0')
		int leftNumber = lhs.number[i] - '0';
		int rightNumber = rhs.number[i] - '0';

		// If left number + right number is >= 10 that stand for need carry
		if (leftNumber + rightNumber + carry >= 10) {
			// Add the left number, right number and carry, and then minus 10 then add to result
			result.number = to_string(leftNumber + rightNumber + carry - 10) + result.number;
			// Set carry flag
			carry = 1;
		}
		else {
			// Add the left number, right number and carry, and then minus 10 then add to result
			result.number = to_string(leftNumber + rightNumber + carry) + result.number;
			// Set carry flag
			carry = 0;

		}
	}

	// If need to carry on the left of resulr, than add '1' to result
	if (carry) {
		result.number = "1" + result.number;
	}

	return result;
}

int main() {
	// Define the variable to that user input count of data pairs
	int count;

	// Let user input until EOF
	while (cin >> count) {
		// Let user input data pair "count" time
		for (int i = 0; i < count; i++) {
			// Define twi big number a,b
			BigInt a, b;
			// User input a b
			cin >> a.number >> b.number;

			// Count and get the result of a + b
			BigInt result = Add(a, b);
			// Print the result
			cout << result.number << endl;
		}
	}

	return 0;
}
