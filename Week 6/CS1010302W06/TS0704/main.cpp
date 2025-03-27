/*****************************************************************//**
 * \file   main.cpp
 * \brief  Compute the Levenshtein Distance of user input
 *
 * \author kai
 * \date   2025/3/27
 *********************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	// The variable to save user input
	string strA, strB;

	// Let user input until EOF
	while (getline(cin, strA) && getline(cin, strB)) {
		// Create the vector of to save each result
		vector<vector<int> > index(strB.size(), vector<int>(strA.size(), 0));

		// The row is strA and the column is strB
		for (int i = 0; i < strB.size(); i++) {
			for (int j = 0; j < strA.size(); j++) {
				// If the part of strA == strB, than the result is index[i-1][j-1]
				if (strA[j] == strB[i] && i != 0 && j != 0) {
					index[i][j] = index[i - 1][j - 1];
				}
				else {
					// Process index[0][0]
					if (i == 0 && j == 0) {
						// If strA[0] != strB[0], than the result is 1
						if (strA[i] != strB[j]) {
							index[i][j] = 1;
						}
						continue;
					}
					int del; // Delete(rightwards)
					int upd; // Update(Right down)
					int add; // Add(downwards)

					// Compute the result and handle the border of the vector
					if (i > 0 && j > 0) {
						del = index[i][j - 1] + 1;
						upd = index[i - 1][j - 1] + 1;
						add = index[i - 1][j] + 1;
					}
					else if (i == 0) {
						del = index[i][j - 1] + 1;
						upd = del + 1;
						add = del + 1;
					}
					else {
						add = index[i - 1][j] + 1;
						del = add + 1;
						upd = add + 1;
					}

					// Set the result
					index[i][j] = min({ del, upd, add });
				}
			}
		}

		// Print the result
		cout << index[strB.size() - 1][strA.size() - 1] << endl;
	}
}

// The result table of Google and Gogle (The number stand for the Levenshtein Distance of the string (strA[0~j] and strB[0~i])
//  Google
//G 012345
//o 101234
//g 211123
//l 322212
//e 433321
// So the result is 1