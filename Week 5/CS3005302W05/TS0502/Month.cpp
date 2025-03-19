/*****************************************************************//**
 * \file   Month.cpp
 * \brief  Implements the member functions of the Month class
 *
 * \author Kai
 * \date   2025/3/19
 *********************************************************************/
#include "Month.h"
#include <iostream>

 /**
  * Default constructor, initializes month to January (1)
  *
  */
Month::Month()
{
	month = 1;
}

/**
 *  Constructs a Month object using 3 characters representing the month abbreviation
 *
 * \param first  First character of the month abbreviation
 * \param second Second character of the month abbreviation
 * \param third  Third character of the month abbreviation
 */
Month::Month(char first, char second, char third)
{
	// Create a placeholder string of length 3
	std::string monthString = "   ";

	// Fill in the string with the provided characters
	monthString[0] = first;
	monthString[1] = second;
	monthString[2] = third;

	// Match the abbreviation to determine the month number
	if (monthString == "Jan") {
		month = 1;
	}
	else if (monthString == "Feb") {
		month = 2;
	}
	else if (monthString == "Mar") {
		month = 3;
	}
	else if (monthString == "Apr") {
		month = 4;
	}
	else if (monthString == "May") {
		month = 5;
	}
	else if (monthString == "Jun") {
		month = 6;
	}
	else if (monthString == "Jul") {
		month = 7;
	}
	else if (monthString == "Aug") {
		month = 8;
	}
	else if (monthString == "Sep") {
		month = 9;
	}
	else if (monthString == "Oct") {
		month = 10;
	}
	else if (monthString == "Nov") {
		month = 11;
	}
	else if (monthString == "Dec") {
		month = 12;
	}
	else {
		// Default to January if input is invalid
		month = 1;
	}
}

/**
 * Constructs a Month object from an integer.
 *
 * \param monthInt Integer representing the month (1-12)
 */
Month::Month(int monthInt)
{
	if (monthInt < 1 || monthInt > 12) {
		// Default to January if out of bounds
		monthInt = 1;
	}

	// Set month
	month = monthInt;
}


/**
 * Destructor for Month class.
 *
 */
Month::~Month()
{
	// No cleanup needed
}

/**
 * Reads an integer from input and sets it as the month.
 *
 */
void Month::inputInt()
{
	// The variable to save user input
	int monthInt;

	// Read input from the user
	std::cin >> monthInt;

	if (monthInt < 1 || monthInt > 12) {
		// Fallback to January
		monthInt = 1;
	}

	month = monthInt;
}

/**
 * Reads a three-letter month abbreviation from input and sets the corresponding month.
 *
 */
void Month::inputStr()
{
	// Initialize a 3-character string
	std::string monthString = "   ";

	// Read individual characters from input
	std::cin >> monthString[0] >> monthString[1] >> monthString[2];

	// Determine month from abbreviation
	if (monthString == "Jan") {
		month = 1;
	}
	else if (monthString == "Feb") {
		month = 2;
	}
	else if (monthString == "Mar") {
		month = 3;
	}
	else if (monthString == "Apr") {
		month = 4;
	}
	else if (monthString == "May") {
		month = 5;
	}
	else if (monthString == "Jun") {
		month = 6;
	}
	else if (monthString == "Jul") {
		month = 7;
	}
	else if (monthString == "Aug") {
		month = 8;
	}
	else if (monthString == "Sep") {
		month = 9;
	}
	else if (monthString == "Oct") {
		month = 10;
	}
	else if (monthString == "Nov") {
		month = 11;
	}
	else if (monthString == "Dec") {
		month = 12;
	}
	else {
		// Default to January if abbreviation is unrecognized
		month = 1;
	}
}

/**
 * Outputs the current month as an integer to standard output.
 *
 */
void Month::outputInt()
{
	std::cout << month;
}

/**
 * Outputs the current month as a three-letter abbreviation to standard output.
 *
 */
void Month::outputStr()
{
	// The variable to save the result
	std::string monthString;

	// Map numeric month to string abbreviation
	switch (month)
	{
	case 1:
		monthString = "Jan";
		break;
	case 2:
		monthString = "Feb";
		break;
	case 3:
		monthString = "Mar";
		break;
	case 4:
		monthString = "Apr";
		break;
	case 5:
		monthString = "May";
		break;
	case 6:
		monthString = "Jun";
		break;
	case 7:
		monthString = "Jul";
		break;
	case 8:
		monthString = "Aug";
		break;
	case 9:
		monthString = "Sep";
		break;
	case 10:
		monthString = "Oct";
		break;
	case 11:
		monthString = "Nov";
		break;
	case 12:
		monthString = "Dec";
		break;
	default:
		break;
	}

	std::cout << monthString;
}

/**
 * Returns the next month as a Month object.
 *
 * \return A Month object representing the following month
 */
Month Month::nextMonth()
{
	// Wrap around to January after December
	return Month((month % 12) + 1);
}
