/*****************************************************************//**
 * \file   main.cpp
 * \brief  Read names from file and print unique sorted names
 *
 * \author kai
 * \date   2025/5/30
 *********************************************************************/
#include <iostream>
#include <set>
#include <fstream>
#include <string>

using namespace std;

int main() {
	// Input file stream to read from "name.txt"
	ifstream inputFStream("name.txt");
	// A set to store unique names in sorted order
	set<string> nameSet;
	// Temporary buffer to hold each line from the file
	string buffer;

	// Read each line from the file
	while (getline(inputFStream, buffer)) {
		// Insert the line into the set (duplicates ignored)
		nameSet.insert(buffer);
	}

	// Iterate through the set and print each name
	for (auto i : nameSet) {
		cout << i << endl;
	}

	return 0;
}
