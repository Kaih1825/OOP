/*****************************************************************//**
 * \file   ComputeStandardDeviation.cpp
 * \brief  Computes the average and standard deviation of user input.
 *
 * \author kai
 * \date   2025/2/25
 *********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

/**
 * Count the average and standard deviation
 *
 * \param inputNumbers The vector array of all number need to compute
 * \return A double array, index = 0 is average, and index = 1 is Standard deviation
 */
double* countAverageAndStandardDeviation(vector<double> inputNumbers) {
	// A double array to save the compute result
	double result[2];

	// Sum of values in the array
	double sum = 0.0;
	// Count the sum of values in array
	for (int i = 0; i < inputNumbers.size(); i++) {
		sum += inputNumbers[i];
	}
	// Divide the sum by number count to get the average
	result[0] = sum / inputNumbers.size();

	// Count the sum of (si-m)^2 in array where m is the average of the input scores si
	double squareRootOfTheAverage = 0.0;
	for (int i = 0; i < inputNumbers.size(); i++) {
		squareRootOfTheAverage += pow(inputNumbers[i] - result[0], 2);
	}
	// Compute the square root of (si-m)^2 to get the standard deviation
	result[1] = sqrt(squareRootOfTheAverage / inputNumbers.size());
	return result;
}

int main() {
	// The first number of each line to get the number count of this line
	int firstNumberOfEachLine;

	// Let user input multi-line until EOF
	while (cin >> firstNumberOfEachLine) {
		// The double vector to save all number of this line
		vector<double> inputNumbers;

		// Let user to input numbers of this line
		for (int i = 0; i < firstNumberOfEachLine; i++) {
			double thisInput;
			cin >> thisInput;
			// Add user-input number to the vector
			inputNumbers.push_back(thisInput);
		}
		// Print the result
		printf("Average:%g\tStandard deviation:%g\n", countAverageAndStandardDeviation(inputNumbers)[0], countAverageAndStandardDeviation(inputNumbers)[1]);
	}

	return 0;
}
