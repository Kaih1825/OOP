#include<iostream>

using namespace std;

int main() {
	// The variable to save user input
	int num1, num2;

	// Let user input until EOF
	while (cin >> num1 >> num2) {
		// The variable to save the max cycle length
		int maxCycleLength = 0;

		// The for loop run from min(num1,num2) to max(num1,num2)
		for (int i = min(num1, num2); i <= max(num1, num2); i++) {
			// The variable to save the conjecture number
			int conjectureNumber = i;
			// The variable to save the cycle length
			int cycleLength = 1;

			// Compute the number until the conjecture number == 1
			while (conjectureNumber != 1) {
				// If conjecture number is an even number, than conjecture number = conjecture number / 2
				if (conjectureNumber % 2 == 0) {
					conjectureNumber /= 2;
				}
				else {
					// If conjecture number is an odd number, than conjecture number = conjecture number * 3 + 1
					conjectureNumber = conjectureNumber * 3 + 1;
				}

				// Cycle length +1
				cycleLength++;
			}

			// Get the max cycle length
			if (cycleLength > maxCycleLength) {
				maxCycleLength = cycleLength;
			}
		}

		// Print the result
		printf("%d %d %d\n", num1, num2, maxCycleLength);
	}
}
