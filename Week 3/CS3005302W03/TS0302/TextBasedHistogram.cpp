/*****************************************************************//**
 * \file   TextBasedHistogram.cpp
 * \brief  Generate a text-based histogram for a quiz of students
 *
 * \author kai
 * \date   2025/3/5
 *********************************************************************/
#include <iostream> // Use in getline and cin
#include <fstream>  // Use in file stream
#include <sstream>  // Use in istringstream
#include <map>      // Use in map
using namespace std;

int main() {
	// The variable to save each line of grade.txt
	string line = "";

	// The variable of input file stream
	ifstream inputFileStream;
	// Open the grade.txt file
	inputFileStream.open("grade.txt");

	// Check is file open successful or not
	if (inputFileStream.fail()) {
		cout << "Not Found" << endl;
		return 0;
	}

	// The variable of output file stream
	ofstream outputFileStream;
	// Open or create grades.Output file
	outputFileStream.open("grades.Output");
	// Clear the file data
	outputFileStream.clear();

	// Read grade.txt until EOF
	while (getline(inputFileStream, line)) {
		// The input string stream variable to split the line of grade.txt from space
		istringstream iss(line);
		// The variable to temporary the each item in user input (the result of istringstream)
		string buffer;
		// The array to save the count of each grade scale
		int gradesCounts[6] = { 0 };

		// Get the each item in the line in grade.txt
		while (iss >> buffer) {
			// Add 1 to the value of the user input numer in array
			gradesCounts[atoi(buffer.c_str())]++;
		}

		// The variable to save the output result
		string output = "";
		// Generate the output result
		for (int i = 0; i < sizeof(gradesCounts) / sizeof(int); i++) {
			output += to_string(gradesCounts[i]) + " grade(s) of " + to_string(i) + "\n";
		}

		// Write the result to grades.Output
		outputFileStream << output;
	}
	// Close the input and output file stream
	inputFileStream.close();
	outputFileStream.close();
}
