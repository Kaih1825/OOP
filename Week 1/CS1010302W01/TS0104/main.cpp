/*****************************************************************//**
 * \file   main.cpp
 * \brief  Formate the input according to the description
 *
 * \author Kai
 * \date   2025/2/23
 *********************************************************************/
#include <iostream>
using namespace std;

int main() {
	// Define the variable to provide user input
	string input;

	// Read user input until EOF
	while (cin >> input) {

		// If the number user input is less than 10 digits, fill in the space at the beginning,
		if (input.length() < 10) {
			printf("%10d\n", atoi(input.c_str()));
		}
		else {
			cout << input << endl;
		}
	}

	return 0;
}
