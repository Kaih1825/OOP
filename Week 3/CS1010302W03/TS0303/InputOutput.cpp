#include <iostream>
using namespace std;

int main() {
	// The variable to save user input (target number)
	double userInputDouble;
	// The variable to save the totallength and Number of reserved digits of the decimal part
	int totalLength, reservedDigitsForDecimalPart;
	// The letter to be filled
	char filledCharacter;

	// Let user input until EOF
	while (cin >> userInputDouble >> totalLength >> reservedDigitsForDecimalPart >> filledCharacter) {
		// The variable to save the length of whole number (Using log)
		int lengthOfWholeNumber = (int)log10(abs((int)userInputDouble)) + 1;
		// The variable to save the length of the output result (fill part + whole number part)
		int lengthOfOuputWholeNumber = totalLength - reservedDigitsForDecimalPart - 1;

		// If target number is lower than 0, than the length of the output result need to minus 1 (negative symbol)
		if ((int)userInputDouble < 0) {
			lengthOfOuputWholeNumber--;
		}
		// If the length of devimal part is 0, than the length of the output result need to minus 1 ('.' symbol)
		if (reservedDigitsForDecimalPart == 0) {
			lengthOfOuputWholeNumber++;
		}

		// Print the filled part
		for (int i = 0; i < lengthOfOuputWholeNumber - lengthOfWholeNumber; i++) {
			printf("%c", filledCharacter);
		}

		// Count the whole number + decimal part using 10^reservedDigitsForDecimalPart (Because of double's fineness)
		double numberPart = (long long)(userInputDouble * pow(10, reservedDigitsForDecimalPart)) / pow(10, reservedDigitsForDecimalPart);
		// Print the result
		printf("%.*f\n", reservedDigitsForDecimalPart, numberPart);

	}
}
