/*****************************************************************//**
 * \file   main.cpp
 * \brief  Quadratic Addition and Left-Right Shift
 *
 * \author kai
 * \date   2025/3/26
 *********************************************************************/
#include<iostream>

using namespace std;

int main() {
	// The time that user input
	int count = 0;

	// Let user input input time
	cin >> count;

	cout << "COWCULATIONS OUTPUT" << endl;

	// Let user input until count == 0
	while (count-- > 0) {
		// The variable to save user input
		string inputA, inputB;

		// User input
		cin >> inputA >> inputB;

		// The variable to save the quadratic Addition of input
		string countA = "", countB = "";

		// Get the character in input A one-by-one
		for (auto c : inputA) {
			// Add the result to countA
			if (c == 'V') {
				countA += '0';
			}
			if (c == 'U') {
				countA += '1';
			}
			if (c == 'C') {
				countA += '2';
			}
			if (c == 'D') {
				countA += '3';
			}
		}

		// Get the character in input A one-by-one
		for (auto c : inputB) {
			// Add the result to countA
			if (c == 'V') {
				countB += '0';
			}
			if (c == 'U') {
				countB += '1';
			}
			if (c == 'C') {
				countB += '2';
			}
			if (c == 'D') {
				countB += '3';
			}
		}

		// The variable to save the decimal of input
		int num1 = 0, num2 = 0;

		// Count the decimal of input
		for (int i = 0; i < countA.size(); i++) {
			num1 += (countA[countA.size() - i - 1] - '0') * pow(4, i);
		}

		for (int i = 0; i < countB.size(); i++) {
			num2 += (countB[countB.size() - i - 1] - '0') * pow(4, i);
		}

		// Handle the mode of input
		for (int i = 0; i < 3; i++) {
			char method;
			cin >> method;

			// A stand for add
			if (method == 'A') {
				num2 += num1;
			}

			// L stand for left shift
			if (method == 'L') {
				num2 *= 4;
			}

			// R stand of right shift
			if (method == 'R') {
				num2 /= 4;
			}
		}

		// The variable to save the result input and the quadratic Addition of input
		string res = "", countRes = "";

		// Let user input result
		cin >> res;

		// Count the quadratic Addition of input
		for (auto c : res) {
			if (c == 'V') {
				countRes += '0';
			}
			if (c == 'U') {
				countRes += '1';
			}
			if (c == 'C') {
				countRes += '2';
			}
			if (c == 'D') {
				countRes += '3';
			}
		}

		// The variable to save the result of input
		int numRes = 0;

		// Count the decimal of result
		for (int i = 0; i < countRes.size(); i++) {
			numRes += (countRes[countRes.size() - i - 1] - '0') * pow(4, i);
		}

		// Compare num2 and result
		if (numRes == num2 && res.size() >= 8) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	cout << "END OF OUTPUT" << endl;

	return 0;
}
