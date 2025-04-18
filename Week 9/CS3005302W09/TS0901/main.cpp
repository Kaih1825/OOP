/*****************************************************************//**
 * \file   main.cpp
 * \brief  A program that reads this file and finds the longest word that reverses to a different word.
 *
 * \author kai
 * \date   2025/4/17
 *********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Converting characters in a string to lowercase
 *
 * \param str The origin String
 * \return The string with lowercase
 */
string toLower(string str) {
	// Convert each characters in str to lowercase
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A') {
			str[i] = str[i] - 'A' - 'a';
		}
	}

	// Retutn the result
	return str;
}

int main() {
	// The variable to save the user input
	string buffer;
	// The vector to save the user input
	vector<string> words;

	// Read user input until EOF
	while (cin >> buffer) {
		words.push_back(buffer);
	}

	// The vector to save the origin words
	vector<string> originWords = words;

	// Sort the words vector by the length of each element
	sort(words.begin(), words.end(), [](string s1, string s2) {
		return s1.length() > s2.length();
		});

	for (int i = 0; i < words.size(); i++) {
		// The variables to save the word in words
		string reversed = toLower(words[i]);
		string origin = toLower(words[i]);

		// Reverse the string
		reverse(reversed.begin(), reversed.end());

		// Check if the word is palindrome or not
		if (origin == reversed) continue;

		// Find the reversed word in words
		for (int j = i; j < words.size(); j++) {
			// Find until the length of element < origin string length
			if (origin.size() > words[j].size()) {
				break;
			}

			// Check the reversed word is in words or not
			if (reversed == toLower(words[j])) {
				// Check is origin or reversed word is in the front of words
				for (int k = 0; k < reversed.size(); k++) {
					if (origin[k] < reversed[k]) {
						// Print the result
						cout << words[i] << endl;
						break;
					}
					else if (origin[k] > reversed[k]) {
						// Print the result
						cout << words[j] << endl;
						break;
					}
				}
				return 0;
			}
		}
	}
	return 0;
}
