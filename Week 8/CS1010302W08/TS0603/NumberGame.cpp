/*****************************************************************//**
 * \file   NumberGame.cpp
 * \brief  Implementation of functions and classes declared in `NumberGame.h`.
 *
 * \author Kai
 * \date   2025/4/11
 *********************************************************************/
#include "NumberGame.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <bitset>

 /**
  * Set the given integer A
  *
  * \param n The input number (A)
  */
void NumberGame::SetInput(int n) {
	inputNumber = n;
}

/**
 * Splitting the integer A into several digits
 *
 */
void NumberGame::ProcessInput() {
	// Save the splited number
	for (auto c : to_string(inputNumber)) {
		numbers.push_back(c - '0');
	}

	// Sort the vector
	sort(numbers.begin(), numbers.end());
}

/**
 * Set the file name of the file where list S is located
 *
 * \param fileName The file name
 */
void NumberGame::SetFileName(string fileName) {
	this->fileName = fileName;
}

/**
 * Convert input to binary
 *
 * \param n The source number4
 * \return The binary number
 */
string toBinary(int n) {
	// The result
	string r;

	// Convert input to binary
	while (n != 0) {
		r += (n % 2 == 0 ? "0" : "1");
		n /= 2;
	}

	// Return the result
	return r;
}

/**
 * Read list S from the file
 *
 */
void NumberGame::LoadNumberList() {
	// The input file stream of the file
	ifstream inputFile("number.txt");

	// The variable to save the number in the file
	int number;
	// All posiable number ("123"->1*2 1*3 2*3 1*2*3)
	vector<int> multiplication;

	// Compute all posiable number (Use binary number of 1 -> 2 ^ number.size)
	for (int i = 1; i < pow(2, numbers.size()); i++) {
		// Convert i into binary number
		string bin = toBinary(i);

		// The variable to save the multiplication result
		int poRes = 1;

		// Compute the multiplication result
		for (int j = 0; j < bin.size(); j++) {
			// If the bit is 1, than multiplication result *= numbers[i]
			if (bin[j] == '1') {
				poRes *= numbers[j];
			}
		}

		multiplication.push_back(poRes);
	}

	// Sort the result
	sort(multiplication.begin(), multiplication.end());

	// Find all result
	while (inputFile >> number) {
		// Return if number > the max multiplication result
		if (number > multiplication[multiplication.size() - 1]) {
			continue;
		}

		// Find the result is equal to the value in multiplication result
		for (auto i : multiplication) {
			if (number == i) {
				result.push_back(number);
				break;
			}
		}
	}
}

/**
 * Print all the valid numbers in S ascendingly
 *
 */
void NumberGame::PrintAllValid() {
	// Print all result
	for (auto n : result) {
		cout << n << endl;
	}
}

/**
 * Reset all variables
 *
 */
void NumberGame::Reset() {
	numbers.clear();
	result.clear();
}
