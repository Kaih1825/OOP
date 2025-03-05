/*****************************************************************//**
 * \file   OccurrencCounting.cpp
 * \brief  Reads a list of numbers with an integer type and counts how many times each number appears
 * 
 * \author kai
 * \date   2025/3/5
 *********************************************************************/
#include <iostream> // Use in getline and cin
#include <sstream>  // Use in istringstream
#include <map>      // Use in map
using namespace std;

int main() {
	// The variable let user input
	string userInput = "";

	// Let user input until EOF (Get user inout and ignore space)
	while (getline(cin, userInput)) {
		// The input string stream variable to split the user input from space
		istringstream iss(userInput);
		// The variable to temporary the each item in user input (the result of istringstream)
		string buffer;
		// The map to save the count of each number
		map<int, int> numberMap;

		// Get the each item in user input
		while (iss >> buffer) {
			// Add 1 to the value of the user input numer in map
			numberMap[atoi(buffer.c_str())]++;
		}

		// Print N count
		printf("N\tcount\n");

		// Print the count result from the end of map to the begin (From large to small)
		for (auto it = numberMap.rbegin(); it != numberMap.rend(); it++) {
			printf("%d\t%d\n", it->first, it->second);
		}
	}
}
