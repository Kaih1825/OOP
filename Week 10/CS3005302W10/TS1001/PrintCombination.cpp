/*****************************************************************//**
 * \file   PrintCombination.cpp
 * \brief  The implementation of PrintCombination.h
 *
 * \author kai
 * \date   2025/4/26
 *********************************************************************/
#include "PrintCombination.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// The vector to save all possible combinations 
vector<string> all;

/**
* Generate combinations recursively and store results
*
* \param arrayPtr Pointer to the array of elements
* \param arraySize Size of the array
* \param choice Number of elements to choose
* \param start Current starting index
* \param current Current combination being built
*/
void generateCombination(int* arrayPtr, int arraySize, int choice, int start, vector<int> current) {
	// If the current combination size equals the required choice 
	if (current.size() == choice) {
		// Initialize result string
		string result = "";

		// Combine each countable character into a string.
		for (int i = 0; i < current.size(); i++) {
			result += to_string(arrayPtr[current[i]]);
			if (i != current.size() - 1) {
				result += " ";
			}
		}

		// Save the result
		all.push_back(result);
		return;
	}

	// Loop through array elements starting from 'start' (DFS)
	for (int i = start; i < arraySize; i++) {
		// Add current index to combination
		current.push_back(i);

		// Recursive call with next start index
		generateCombination(arrayPtr, arraySize, choice, i + 1, current);

		// Backtrack: remove the last added index
		current.pop_back();
	}

	// Only when back to the initial call (start == 0), print all results 
	if (start == 0) {
		for (int i = 0; i < all.size(); i++) {
			cout << all[i];

			if (i < all.size() - 1) {
				cout << endl;
			}
		}
	}
}

// Print all possible combinations of a given number of elements chosen from the array.
void PrintCombination(int* arrayPtr, int arraySize, int choice) {
	// The vector of the tree (Current combination being built)
	vector<int> current;

	// Generate Combination
	generateCombination(arrayPtr, arraySize, choice, 0, current);
}
