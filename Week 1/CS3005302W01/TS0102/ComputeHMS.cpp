/*****************************************************************//**
 * \file   ComputeHMS.cpp
 * \brief  Convert the format of DateTime (integer)  from (seconds) to (hours: minutes: seconds)
 *
 * \author Kai
 * \date   2025/2/22
 *********************************************************************/
#include<iostream>
using namespace std;

int main() {
	// Define the variable reading user input
	unsigned long long userInput;

	// Read user input until EOF
	while (cin >> userInput) {
		// Compute the formate result of seconds, minutes ans hours 
		unsigned long long second = userInput % 60;
		unsigned long long minute = (userInput / 60) % 60;
		unsigned long long hour = userInput / (60 * 60);

		// Formate the output to x hours y minutes and z seconds 
		printf("%llu hours %llu minutes and %llu seconds\n", hour, minute, second);
	}

	return 0;
}
