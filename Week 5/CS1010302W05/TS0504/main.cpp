/*****************************************************************//**
 * \file   main.cpp
 * \brief  Judge the sudoku table is valid or not
 *
 * \author kai
 * \date   2025/3/20
 *********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	// Get user input until EOF
	while (!cin.eof()) {
		// The vector to save the user input
		vector<vector<int>> sudoku;

		// The variable to judge the sudoku is valid or not
		bool isValid = true;
		// The variable to judge the user input is empty or not
		bool isBlank = false;

		// Get user input
		for (int i = 0; i < 9; i++) {
			// The variable to save the user inpur
			string userInput = "";

			// Let user input
			getline(cin, userInput);

			// The input string stream to split user input by ','
			istringstream iss(userInput);
			// The buffer to save the part of user input
			string buffer = "";

			// The vector to save the row of user inputs
			vector<int> thisVector;

			// continue when the user input is empty
			if (userInput.empty()) {
				isBlank = true;
				break;
			}

			// Split the user input by ','
			while (getline(iss, buffer, ',')) {
				// Judge the number user input is < 0 or > 9 or not
				if (atoi(buffer.c_str()) < 1 || atoi(buffer.c_str()) > 9) {
					isValid = false;
				}

				// Save the number user input
				thisVector.push_back(atoi(buffer.c_str()));
			}

			// Save the number user input
			sudoku.push_back(thisVector);
		}

		// If user input is empty, than break
		if (isBlank) {
			continue;
		}

		// Judge each raw
		for (auto i : sudoku) {
			// The array to safe each number is appear or not
			bool numberAppear[9] = { false };
			for (auto j : i) {
				// If the number have appear
				if (numberAppear[j - 1]) {
					isValid = false;
					break;
				}

				// Set the appear flag
				numberAppear[j - 1] = true;
			}

			// If the table is not valid, than break the loop
			if (!isValid) {
				break;
			}
		}

		// Judge each column
		for (int i = 0; i < 9; i++) {
			// The array to safe each number is appear or not
			bool numberAppear[9] = { false };
			for (int j = 0; j < 9; j++) {
				// If the number have appear
				if (numberAppear[sudoku[j][i] - 1]) {
					isValid = false;
					break;
				}

				// Set the appear flag
				numberAppear[sudoku[j][i] - 1] = true;
			}

			// If the table is not valid, than break the loop
			if (!isValid) {
				break;
			}
		}

		// Judge the 3x3 square
		for (int k = 0; k < 3; k++) {
			for (int l = 0; l < 3; l++) {
				// The array to safe each number is appear or not
				bool numberAppear[9] = { false };
				for (int i = 3 * k + 0; i < 3 * k + 3; i++) {
					for (int j = 3 * l + 0; j < 3 * l + 3; j++) {
						// If the number have appear
						if (numberAppear[sudoku[i][j] - 1]) {
							isValid = false;
							break;
						}

						// Set the appear flag
						numberAppear[sudoku[i][j] - 1] = true;
					}

					// If the table is not valid, than break the loop
					if (!isValid) {
						break;
					}
				}
			}
		}

		// Print the result
		printf("%s\n", isValid ? "True" : "False");
	}

	return 0;
}
