/*****************************************************************//**
 * \file   main.cpp
 * \brief  Addition, subtraction and multiplication of large numbers
 *
 *
 * \author kai
 * \date   2025/3/26
 *********************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Adjust the length of the two strings to be the same using the complement 0.
 *
 * \param a The first string
 * \param b The second string
 * \return The vector has two index. [0] is a, and [1] is b, which the length of a and b is same
 */
vector<string> processString(string a, string b) {
	// Judge the size of a is larger than b or not
	if (a.size() > b.size()) {
		// Complement 0
		for (int i = 0; i < b.size() - a.size(); i++) {
			b = '0' + b;
		}
	}
	else {
		for (int i = 0; i < a.size() - b.size(); i++) {
			a = '0' + a;
		}
	}

	// Add a and b into vector and return the result
	vector<string> res = { a,b };
	return res;
}

/**
 * The sum of two large numbers
 *
 * \param addA The first number
 * \param addB The second number
 * \return The sum of a and b
 */
string bigIntAdd(string addA, string addB) {
	// Process the string
	vector<string> processStringResult = processString(addA, addB);
	string a = processStringResult[0];
	string b = processStringResult[1];

	// The variable to save the result
	string res = "";

	// The variable to save the carry
	int carry = 0;

	// Add the characters of two numbers one by one.
	for (int i = a.size() - 1; i >= 0; i--) {
		// Get the charactor of two numbers
		int numberA = a[i] - '0';
		int numberB = b[i] - '0';

		// Add the sum
		int addResult = numberA + numberB + carry;

		// Set carry
		carry = 0;
		if (addResult > 9) {
			addResult -= 10;
			carry = 1;
		}

		// Add the result string
		res = (char)(addResult + '0') + res;
	}

	// Add carry if the result.size() is > two string.size()
	if (carry != 0) {
		res = (char)(carry + '0') + res;
	}

	return res;
}

/**
 * Complementary subtraction using 9
 *
 * \param minA The first number
 * \param minB The second number
 * \return The difference of two number (a-b)
 */
string bigIntMinus(string minA, string minB) {
	// Process the string
	vector<string> processStringResult = processString(minA, minB);
	string a = processStringResult[0];
	string b = processStringResult[1];

	// Compute the complement of the second number
	string complementOfB = "";
	for (auto c : b) {
		complementOfB += '9' - c + '0';
	}

	// Add the first number and the complement of the second number
	string addResult = bigIntAdd(a, complementOfB);

	// The variable to save the rsult
	string res = "";

	// The variable to save the plus and minus sign
	bool isNagitive = false;

	// If the result is nagitive, than compute the complement of the result
	if (addResult.size() == a.size()) {
		isNagitive = true;
		for (auto c : addResult) {
			res += '9' - c + '0';
		}
	}
	else {
		// End around carry
		res = bigIntAdd(addResult.substr(1, addResult.size() - 1), "1");
	}

	// Remove the 0 before the result
	for (int i = 0; i < res.size(); i++) {
		if (res[i] != '0') {
			res = res.substr(i, res.size() - i);
			break;
		}
		if (i == res.size() - 1 && res[i] == '0') {
			isNagitive = false;
			res = "0";
		}
	}

	// Add '-' if the result is negative
	if (isNagitive) {
		res = '-' + res;
	}

	return res;
}

/**
 * Calculate the multiplication of two significant figures
 *
 * \param timesA The first number
 * \param timesB The second number
 * \return The product of the first number and the second number
 */
string bigIntTimes(string timesA, string timesB) {
	// Return 0 if first or second number is 0
	if (timesA == "0" || timesB == "0") {
		return "0";
	}

	// The variable to save the result
	string res = "0";

	// Calculating multiplication using the vertical form of multiplication
	for (int i = timesB.size() - 1; i >= 0; i--) {
		for (int j = timesA.size() - 1; j >= 0; j--) {
			// Get the number in two number
			int numA = timesA[j] - '0';
			int numB = timesB[i] - '0';

			// Count the times result
			string thisTimesResult = to_string(numA * numB);

			// Add 0 after the time result
			for (int k = 0; k < (timesB.size() - i - 1) + (timesA.size() - j - 1); k++) {
				thisTimesResult += '0';
			}

			// Add the result
			res = bigIntAdd(res, thisTimesResult);
		}
	}

	// Remove the 0 before number
	for (int i = 0; i < res.size(); i++) {
		if (res[i] != '0') {
			res = res.substr(i, res.size() - i);
			break;
		}
	}

	return res;

}

int main() {
	// The variable to save the user input
	string a, b;

	// Let user input until EOF
	while (cin >> a >> b) {
		// Continue if a or b is empty
		if (a.empty() || b.empty()) {
			continue;
		}

		// Determine the positive and negative signs of a and b, and perform addition, subtraction and multiplication.
		if (a[0] == '-' && b[0] == '-') { // a < 0, b < 0
			cout << "-" + bigIntAdd(a.substr(1, a.size() - 1), b.substr(1, b.size() - 1)) << endl;
			cout << bigIntMinus(b.substr(1, b.size() - 1), a.substr(1, a.size() - 1)) << endl;
			cout << bigIntTimes(a.substr(1, a.size() - 1), b.substr(1, b.size() - 1)) << endl;
		}
		else if (a[0] == '-') { // a < 0, b > 0
			cout << bigIntMinus(b, a.substr(1, a.size() - 1)) << endl;
			cout << "-" + bigIntAdd(a.substr(1, a.size() - 1), b) << endl;
			cout << "-" + bigIntTimes(a.substr(1, a.size() - 1), b) << endl;
		}
		else if (b[0] == '-') {// b < 0, a > 0
			cout << bigIntMinus(a, b.substr(1, b.size() - 1)) << endl;
			cout << bigIntAdd(a, b.substr(1, b.size() - 1)) << endl;
			cout << "-" + bigIntTimes(a, b.substr(1, b.size() - 1)) << endl;
		}
		else { // a > 0, b > 0
			cout << bigIntAdd(a, b) << endl;
			cout << bigIntMinus(a, b) << endl;
			cout << bigIntTimes(a, b) << endl;
		}
	}
}
