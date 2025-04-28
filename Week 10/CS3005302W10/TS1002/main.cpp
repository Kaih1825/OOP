/*****************************************************************//**
 * \file   main.cpp
 * \brief  Find valid words from a 4x4 character matrix based on words list
 *
 * \author kai
 * \date   2025/4/27
 *********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <string>

using namespace std;

/**
 * Check if a given word can be formed in the 4x4 matrix following adjacent rules
 *
 * \param matrix2D 2D character matrix
 * \param previousIndex Previous character's index in the matrix
 * \param source Target word to check
 * \param checkIndex Current character index in the source string
 * \return True if the word can be formed, false otherwise
 */
bool checkIsValid(vector<vector<char> >& matrix2D, int previousIndex, string source, int checkIndex) {
	// If the check index is >= the length of target word, than print the word
	if (checkIndex >= source.size()) {
		// The variable of star count 
		int starCount = 0;

		// Count the star in matrix
		for (auto i : matrix2D) {
			for (auto j : i) {
				if (j == '*') {
					starCount++;
				}
			}
		}

		// If star count == the length of target, than print the word
		if (starCount == source.size()) {
			cout << source << endl;
		}

		// Return the result
		return starCount == source.size();
	}

	// The y and x value of previous index
	int y = previousIndex / 4;
	int x = previousIndex % 4;

	// The neighboring letters position
	int dx[] = { -1,0,1,-1,1,-1,0,1 };
	int dy[] = { -1,-1,-1,0,0,1,1,1 };

	// Check 8 neighboring letters
	for (int i = 0; i < 8; i++) {
		// The x and y value of the neighboring letter
		int newY = y + dy[i];
		int newX = x + dx[i];

		// If it is out of matrix, than continue
		if (newY < 0 || newY >3 || newX < 0 || newX >3) {
			continue;
		}

		// If there is the same letter in the neighboring letter, than check the next letter
		if (matrix2D[newY][newX] == source[checkIndex] && newY * 4 + newX != previousIndex) {
			// Set the letter into star
			char temp = matrix2D[newY][newX];
			matrix2D[newY][newX] = '*';

			// Check the next letter
			if (checkIsValid(matrix2D, newY * 4 + newX, source, checkIndex + 1)) {
				return true;
			}

			// If it is not valid, than set to origin letter
			matrix2D[newY][newX] = temp;

		}
	}

	// retutn the result
	return false;
}

/**
 * The main function
 *
 * \return 0
 */
int main() {
	// Let user input until EOF
	while (!cin.eof()) {
		// The vector to save the matrix (1D)
		vector<char> matrix1D;
		// The vector to save the matrix (2D)
		vector<vector<char> > matrix2D;

		// The map to save the indexs of each char
		map<char, vector<int> > indexTable;

		// Handle user input
		for (int i = 0; i < 4; i++) {
			// The variable to save the user input
			string buffer;
			// Get input
			getline(cin, buffer);

			// The vector to save the user input (sub-array in 2D matrix)
			vector <char> tmp;

			// Save the user input and count the index
			for (int j = 0; j < 4; j++) {
				matrix1D.push_back(buffer[j]);
				tmp.push_back(buffer[j]);
				indexTable[buffer[j]].push_back(i * 4 + j);
			}

			matrix2D.push_back(tmp);
		}

		// The input file stream of words.txt
		ifstream inputFStream("words.txt");
		// The variable to save the string in file
		string buffer;

		// Read the file
		while (inputFStream >> buffer) {
			// Continue if length of word < 3
			if (buffer.size() < 3) {
				continue;
			}

			// The variable to save the word need to check or not
			bool breakOrNot = false;

			// Validate word existence
			for (auto c : buffer) {
				if (count(matrix1D.begin(), matrix1D.end(), c) < count(buffer.begin(), buffer.end(), c)) {
					breakOrNot = true;
					break;
				}
			}

			// Skip invalid words
			if (breakOrNot) {
				continue;
			}

			// Try all starting points
			for (auto index : indexTable[buffer[0]]) {
				// Check the string is valid or not
				auto temp = matrix2D;
				temp[index / 4][index % 4] = '*';

				if (checkIsValid(temp, index, buffer, 1)) {
					break;
				}
			}
		}
	}
}


