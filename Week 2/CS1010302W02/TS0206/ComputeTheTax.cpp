/*****************************************************************//**
 * \file   ComputeTheTax.cpp
 * \brief  Compute The Tax deppend on income
 *
 * \author kai
 * \date   2025/2/27
 *********************************************************************/
#include <iostream>
using namespace std;

int main() {
	// The variable save income that user input
	double income;

	// Let user input until EOF
	while (cin >> income) {
		// The variable to save the compute result
		double tax = 0;

		// Calculate the tax rate according to the different brackets
		if (income <= 750) { // if income not over $750 than rate = 1% of income
			tax = income * 0.01;
		}
		else if (income <= 2250) { // if income is in the range of $750-$2250 than rate = $7.50 plus 2% of amount over $750
			tax = 7.50 + (income - 750) * 0.02;
		}
		else if (income <= 3750) { // if income is in the range of $2250-$3750 than rate = $37.50 plus 3% of amount over $2250
			tax = 37.50 + (income - 2250) * 0.03;
		}
		else if (income <= 5250) { // if income is in the range of $3750-$5250 than rate = $82.50 plus 4% of amount over $3750
			tax = 82.50 + (income - 3750) * 0.04;
		}
		else if (income <= 7000) { // if income is in the range of $5250-$7000 than rate = $142.50 plus 5% of amount over $5250
			tax = 142.50 + (income - 5250) * 0.05;
		}
		else { // if income is over $7000 than rate = $230.00 plus 6% of amount over $7000
			tax = 230.00 + (income - 7000) * 0.06;
		}

		// Fromate the tax and print the compute result
		printf("%.2f\n", tax);
	}
}