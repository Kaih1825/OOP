/*****************************************************************//**
 * \file   main.cpp
 * \brief  Records at most 10 student data by structures
 *
 * \author kai
 * \date   2025/3/20
 *********************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// The struct of the student record
typedef struct {
	char firstName[25];
	char lastName[30];
	char phone[15];
} stRec;

/**
 * Split the string from space
 *
 * \param str The input string
 * \return The vector save all substring in the input string
 */
vector<string> splitStringBySpace(string str) {
	// The vector save all substring in the input string
	vector<string> splitedStrings;

	// Find the sapce until not found
	while (str.find(' ') != string::npos) {
		// Get the part of the string
		string partOfString = str.substr(0, str.find(' '));

		// If the part of the string is not empty, than that is the one of the result
		if (!partOfString.empty()) {
			// Add the result into the vector
			splitedStrings.push_back(partOfString);
		}

		// Set the input string
		str = str.substr(str.find(' ') + 1, str.size() - 1);
	}

	// Add the last substring into the vector
	if (!str.empty()) {
		splitedStrings.push_back(str);
	}

	// Return the split result
	return splitedStrings;
}

int main() {
	// The variable to save user input
	string userInput;
	// The variable to save the all student record
	vector<stRec> dataBase;

	while (getline(cin, userInput)) {
		// Split the input string by space into a vector of strings
		vector<string> splitedStrings = splitStringBySpace(userInput);

		// If command is "print" and it is the only input
		if (splitedStrings.size() == 1 && splitedStrings[0] == "print") {
			if (dataBase.empty()) {
				printf("Print Error\n");
				continue;
			}

			// Print all records in the database
			for (stRec i : dataBase) {
				printf("%s %s %s\n", i.firstName, i.lastName, i.phone);
			}

			continue;
		}

		// If the input isn't combine with command + first name + last name + phone
		// Than continue
		if (splitedStrings.size() != 4) {
			continue;
		}

		// Check if the input size exceeds allowed length
		if (splitedStrings[1].size() > 25 || splitedStrings[2].size() > 30 || splitedStrings[3].size() > 15) {
			printf("Input Error\n");
			continue;
		}

		// Try converting phone number to integer to ensure it's numeric
		try
		{
			atoi(splitedStrings[3].c_str());
		}
		catch (const std::exception&)
		{
			printf("Input Error\n");
			continue;
		}

		// Handle "insert" command
		if (splitedStrings[0] == "insert") {
			bool isSuccess = false;

			// Check if the record already exists
			for (int i = 0; i < dataBase.size(); i++) {
				stRec data = dataBase[i];

				if (data.firstName == splitedStrings[1] && data.lastName == splitedStrings[2] && data.phone == splitedStrings[3]) {
					isSuccess = true;
					break;
				}
			}

			// If database is full or duplicate record found, insert fails
			if (dataBase.size() >= 10 || isSuccess) {
				printf("Insert Error\n");
				continue;
			}

			// Insert new record
			stRec insertRecord;

			strcpy_s(insertRecord.firstName, splitedStrings[1].c_str());
			strcpy_s(insertRecord.lastName, splitedStrings[2].c_str());
			strcpy_s(insertRecord.phone, splitedStrings[3].c_str());
			dataBase.push_back(insertRecord);

			continue;
		}

		// Handle "delete" command
		if (splitedStrings[0] == "delete") {
			bool isSuccess = false;

			// Search for the matching record and erase it
			for (int i = 0; i < dataBase.size(); i++) {
				stRec data = dataBase[i];

				if (data.firstName == splitedStrings[1] && data.lastName == splitedStrings[2] && data.phone == splitedStrings[3]) {
					dataBase.erase(dataBase.begin() + i);
					isSuccess = true;
					break;
				}
			}

			// If no matching record found
			if (!isSuccess) {
				printf("Delete Error\n");
			}

			continue;
		}

		// Handle "search" command
		if (splitedStrings[0] == "search") {
			bool isSuccess = false;

			// Search for the matching record and print its index
			for (int i = 0; i < dataBase.size(); i++) {
				stRec data = dataBase[i];
				if (data.firstName == splitedStrings[1] && data.lastName == splitedStrings[2] && data.phone == splitedStrings[3]) {
					printf("%d\n", i);
					isSuccess = true;
					break;
				}
			}

			// If no matching record found
			if (!isSuccess) {
				printf("Search Error\n");
			}

			continue;
		}
	}

	return 0;
}
