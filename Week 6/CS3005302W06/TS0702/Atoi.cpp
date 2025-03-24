/*****************************************************************//**
 * \file   Form.cpp
 * \brief  Implementation of the Atoi class for conveting the string into integer
 *
 * \author Kai
 * \date   2025/3/24
 *********************************************************************/
#include "Atoi.h"

 /**
  * Construct a class Atoi where beTran is ""
  *
  */
Atoi::Atoi() {
	// Set beTran to ""
	beTrans = "";
}

/**
 * Construct a class Atoi where beTran is s
 *
 * \param s The user input
 */
Atoi::Atoi(string s) {
	// Set beTran to s
	beTrans = s;
}

/**
 * Set beTran of this class to s
 *
 * \param s The user input
 */
void Atoi::SetString(string s) {
	// Set beTran to s
	beTrans = s;
}

/**
 * Return beTran of this class
 *
 * \return beTran of this class
 */
const string Atoi::GetString() {
	return beTrans;
}

/**
 * Return the length of beTran
 *
 * \return the length of beTran
 */
int Atoi::Length() {
	// If the number is nagative, than return the size of string - 1
	if (!beTrans.empty() && beTrans[0] == '-') {
		return beTrans.size() - 1;
	}

	// Return string size
	return beTrans.size();
}

/**
 * Return true if beTran can be transformed into an integer, otherwise return false
 *
 * \return the string is integer or not
 */
bool Atoi::IsDigital() {
	// If the string is empty, than return false
	if (beTrans.empty()) {
		return false;
	}

	// Check is digital from testing character one-by-one
	for (int i = 0; i < beTrans.size(); i++) {
		// If the integer is negative, than continue
		if (i == 0 && beTrans[i] == '-') {
			continue;
		}

		// Check is digital or not
		if (beTrans[i] < '0' || beTrans[i]>'9') {
			return false;
		}
	}

	// Return true if it is digital
	return true;
}

/**
 * Convert beTran to an integer and return
 *
 * \return
 */
int Atoi::StringToInteger() {
	// The variable to save the result
	int result = 0;

	// Count the result from counting character one-by-one
	for (int i = 0; i < beTrans.size(); i++) {
		// If the integer is negative, than continue
		if (i == 0 && beTrans[0] == '-') {
			continue;
		}

		// Count the result
		result += (beTrans[i] - '0') * pow(10, beTrans.size() - i - 1);
	}

	// result + -1 when the integer is negative
	if (beTrans[0] == '-') {
		result *= -1;
	}

	// return the result
	return result;
}