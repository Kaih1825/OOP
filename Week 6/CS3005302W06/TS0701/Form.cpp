/*****************************************************************//**
 * \file   Form.cpp
 * \brief  Implementation of the Form class for word input, processing,
 *         file reading, and comparison operations.
 *
 * \author Kai
 * \date   2025/3/24
 *********************************************************************/
#include "Form.h"
#include <iostream>

using namespace std;

/**
 * Set the given word of the game
 *
 * \param inputWord The word user input
 */
void Form::SetInputWord(string inputWord) {
	// Set the given word of the game
	this->inputWord = inputWord;
}

/**
 * Converts all uppercase characters in the input word to lowercase.
 *
 */
void Form::ProcessInputWord() {
	// The variable to save the transition result
	string tmp = "";

	// Process each character in the user input
	for (auto c : inputWord) {
		// Converts all uppercase characters in the input word to lowercase.
		if ((int)c < (int)'a') {
			tmp += c - 'A' + 'a';
		}
		else {
			tmp += c;
		}
	}

	inputWord = tmp;
}

/**
 * Set the file name of the file that contains all the valid words.
 *
 * \param fileName The name of the file to open that contains all the valid words
 */
void Form::SetFileName(string fileName) {
	// Set the file name of the file that contains all the valid words.
	this->fileName = fileName;
}

void Form::Load_CompareWord() {
	ifstream inputFStream; // The input file stream

	// Open the file
	inputFStream.open(fileName);

	// If the file
	if (inputFStream.fail()) {
		cout << "ERROR" << endl;
	}

	// The buffer to save each line of word
	string buffer;

	// Get the word in file one-by-one
	while (getline(inputFStream, buffer))
	{
		// The variable to save user input
		string tmp = inputWord;

		// The variable to save the word is valid or not
		bool isValid = true;

		// Process each character in the buffer
		for (auto c : buffer) {
			// If the character is not in user input, than the word is not valid
			if (tmp.find(c) == string::npos) {
				isValid = false;
				break;
			}

			// Set the index of c to '-'
			tmp[tmp.find(c)] = '-';
		}

		// Save the result
		if (isValid) {
			result.push_back(buffer);
		}
	}
}

/**
 * Print the words found in the function Load_CompareWord()
 *
 */
void Form::PrintFoundWords() {
	// Print the words found in the function Load_CompareWord()
	for (auto str : result) {
		cout << str << endl;
	}
}
