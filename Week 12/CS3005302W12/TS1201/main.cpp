/*****************************************************************//**
 * \file   main.cpp
 * \brief  Simulate the process of writing and reading memory data
 *
 * \author Kai
 * \date   2025/5/6
 *********************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	// The memory size and the count of the line of input
	int size, lineOfInput;

	// Read input values until EOF
	while (cin >> size >> lineOfInput) {
		// Ignore the newline character after size input
		cin.ignore();

		// Initialize memory with given size, default values set to 0
		vector<int> memory(size, 0);

		// Process each input line
		for (int l = 0; l < lineOfInput; l++) {
			// Read the entire input line
			string input;
			getline(cin, input);

			// Create a string stream for parsing the input
			stringstream ss(input);
			// The vector to save the splited input
			vector<string> command;
			string buffer;

			// Read the first three tokens: command type, memory position, and data type
			for (int i = 0; i < 3; i++) {
				ss >> buffer;
				command.push_back(buffer);
			}

			// Determine the size of the data type
			int typeSize = 0;
			if (command[2] == "char") typeSize = 1;
			if (command[2] == "short") typeSize = 2;
			if (command[2] == "int") typeSize = 4;

			// Convert position to integer
			int position = stoll(command[1]);

			// Check for memory access violation
			if (position + typeSize > size) {
				cout << "Violation Access.\n";
			}

			// Handling "Set" command
			if (command[0] == "Set") {

				// Read remaining input as the value to be stored
				string saved = "";
				while (ss >> buffer) {
					saved += buffer + ' ';
				}

				// Remove trailing space
				saved.substr(0, saved.size() - 1);
				command.push_back(saved);

				// If data type is a string, update type size accordingly
				if (command[2] == "String") typeSize = command[3].size();

				// Store a character at the specified position
				if (command[2] == "char") {
					if (position >= memory.size()) {
						continue;
					}
					memory[position] = stoi(command[3]);
				}

				// Store an integer or short value by converting to hexadecimal
				if (command[2] == "short" || command[2] == "int") {
					// Create a string stream for parsing the input
					stringstream convertSS;

					// Convert the input into hex
					convertSS << hex << atoll(command[3].c_str());
					string convertResult;
					convertSS >> convertResult;

					// Convert hex string to byte representation
					vector<int> thisString;
					for (int i = 0; i < convertResult.size(); i += 2) {
						string tis = "  ";

						tis[0] = convertResult[i];
						tis[1] = convertResult[i + 1];

						// Store the hex
						thisString.push_back(stoi(tis.c_str(), 0, 16));
					}

					// Reverse bytes to store in little-endian format
					reverse(thisString.begin(), thisString.end());
					for (int i = 0; i < thisString.size(); i++) {
						if (position + i >= memory.size()) {
							break;
						}
						memory[position + i] = thisString[i];
					}
				}

				// Store a string value in memory
				if (command[2] == "String") {
					if (position + command[3].size() - 1 >= memory.size()) {
						cout << "Violation Access.\n";
					}
					for (int i = 0; i < command[3].size(); i++) {
						if (position + i >= memory.size()) {
							break;
						}
						memory[position + i] = command[3][i];
					}
				}
			}

			// Handling "Get" command
			if (command[0] == "Get") {

				// Ensure memory access is within bounds
				if (position + typeSize > size) {
					continue;
				}

				// Retrieve and print a stored string
				if (command[2] == "String") {
					for (int i = stoll(command[1]); i < memory.size(); i++) {
						if (memory[i] <= 0) {
							break;
						}

						// Print the get result
						cout << (char)memory[i];
					}
					cout << endl;
				}

				// Retrieve and print a stored character
				if (command[2] == "char") {
					cout << memory[stoll(command[1])] << endl;
				}

				// Retrieve and print a stored short or integer
				if (command[2] == "short" || command[2] == "int") {
					// The string to save the all convert result
					string sum = "";
					for (int i = typeSize - 1; i >= 0; i--) {
						// Convert the part of memory into hex
						stringstream convertSS;
						convertSS << hex << (int)memory[position + i];

						string convertResult;
						convertSS >> convertResult;

						// Add the hex string into sum
						sum += convertResult;
					}

					// Print the result
					cout << abs(stoll(sum, 0, 16)) << endl;
				}
			}
		}
	}
	return 0;
}

