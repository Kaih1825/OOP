#include <iostream> // Use in cout
#include <cmath> // Use in log2
using namespace std;

int main() {
	// The variable to save the year user input
	int year;

	// Let user input year until EOF
	while (cin >> year) {
		// Save and count "k-bit" CPU (Every 10 years, k will grow by a mulitiple of 2)
		long long int bit = pow(2, 2 + (year - 1900) / 10);
		// The variable to save the N where log2(N!)
		int index = 2;
		// The variable to save the factorial value
		double factorial = 0;

		// Count the sum of log2 of factorial until the factorial value is > bit
		for (; factorial <= bit; index++) {
			factorial = factorial + log2(index);
		}

		// Print the result (index - (the last "index++" of for loop) - (1 beacuse the factorial value is larger than bit))
		cout << index - 2 << endl;
	}
	return 0;
}