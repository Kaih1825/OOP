/*****************************************************************//**
 * \file   main.cpp
 * \brief  Allowed users to input a string and then print the number characters with the style of seven-segment display
 *
 * \author kai
 * \date   2025/3/26
 *********************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	// The variable to save user input
	string numbers;

	// Let user input until EOF
	while (getline(cin, numbers)) {
		// The first line
		for (auto c : numbers) {
			// Get input number
			int num = c - '0';

			// If the input is not number, than continue
			if (num > 9 || num < 0) {
				continue;
			}

			// Draw the first line
			if (num == 2 || num == 3 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9 || num == 0) {
				cout << " _ ";
			}
			else {
				cout << "   ";
			}
		}
		cout << endl;

		// The second line
		for (auto c : numbers) {
			// Get input number
			int num = c - '0';

			// If the input is not number, than continue
			if (num > 9 || num < 0) {
				continue;
			}

			// Draw the second line and the '|' between the first line and second line
			if (num == 4 || num == 5 || num == 6 || num == 8 || num == 9 || num == 0) {
				cout << "|";
			}
			else {
				cout << " ";
			}

			if (num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 8 || num == 9) {
				cout << "_";
			}
			else {
				cout << " ";
			}

			if (num == 1 || num == 2 || num == 3 || num == 4 || num == 7 || num == 8 || num == 9 || num == 0) {
				cout << "|";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;

		// The third line
		for (auto c : numbers) {
			// Get input number
			int num = c - '0';
			if (num > 9 || num < 0) {
				continue;
			}

			// Draw the third line and the '|' between the second line and third line
			if (num == 2 || num == 6 || num == 8 || num == 0) {
				cout << "|";
			}
			else {
				cout << " ";
			}

			if (num == 2 || num == 3 || num == 5 || num == 6 || num == 8 || num == 9 || num == 0) {
				cout << "_";
			}
			else {
				cout << " ";
			}

			if (num == 1 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9 || num == 0) {
				cout << "|";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
