/*****************************************************************//**
 * \file   main.cpp
 * \brief  Main program to process character pair connections and check if sequences can be transformed based on a graph representation.
 *
 * \author kai
 * \date   2025/04/19
 *********************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
	// Initialize variables m (number of pairs) and n (number of checks), both set to -1 to start the loop
	int m = -1, n = -1;

	// Loop runs until both m and n are 0
	while (m != 0 && n != 0) {
		// Input the values for m (number of pairs) and n (number of checks)
		cin >> m >> n;

		// Initialize a 2D vector for storing the graph of character relations (26x26) with large initial values (999)
		vector<vector<int>> charTable(26, vector<int>(26, 999));

		// Read in m character pairs and set the corresponding graph edges with a value of 1 (direct transformation possible)
		for (int mI = 0; mI < m; mI++) {
			char firstElement, secondElement;
			cin >> firstElement >> secondElement;

			// Update the graph for the pair (firstElement, secondElement)
			charTable[firstElement - 'a'][secondElement - 'a'] = 1;
		}

		// Set diagonal values to 0, as a character can always be transformed to itself
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				if (i == j) {
					charTable[i][j] = 0;
				}
			}
		}

		// Use the Floyd-Warshall algorithm to find the shortest transformation path between any two characters
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				for (int k = 0; k < 26; k++) {
					// If a shorter path is found, update the graph
					if (charTable[j][k] > charTable[j][i] + charTable[i][k]) {
						charTable[j][k] = charTable[j][i] + charTable[i][k];
					}
				}
			}
		}

		// Process each of the n checks
		for (int nI = 0; nI < n; nI++) {
			string check1, check2;
			cin >> check1 >> check2;

			// If the lengths of the two strings are different, output "no"
			if (check1.size() != check2.size()) {
				cout << "no" << endl;
				continue;
			}

			// The variable to of the check result
			bool isTrue = false;

			// Check each character in the strings
			for (int i = 0; i < check1.size(); i++) {
				// If any character cannot be transformed (i.e., its path value is 999), output "no"
				if (charTable[check1[i] - 'a'][check2[i] - 'a'] == 999) {
					isTrue = true;
					break;
				}
			}

			// If a transformation is not possible, print "no", otherwise print "yes"
			if (isTrue) {
				cout << "no" << endl;
			}
			else {
				cout << "yes" << endl;
			}
		}
	}

	return 0;
}
