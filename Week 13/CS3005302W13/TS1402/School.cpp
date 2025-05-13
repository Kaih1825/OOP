/*****************************************************************//**
 * \file   School.cpp
 * \brief  Implementation of School class methods
 *
 * \author [Your Name]
 * \date   2025/05/13
 *********************************************************************/
#include "School.h"

/**
* Constructor that initializes the school with a name and student count.
*
* \param name   The name of the school.
* \param amount The initial number of students.
*/
School::School(string name, float amount) {
	// Set school name
	this->name = name;

	// Set current student amount
	studentAmount = amount;

	// Set next year's student amount to current
	studentAmountNextYear = amount;
}

/**
 * Adds new students to the school.
 *
 * \param amount The number of students to admit.
 */
void School::admissions(float amount) {
	// Do nothing if the amount is invalid
	if (amount < 0) return;

	// Increase current student amount
	studentAmount += amount;
}

/**
 * Removes students from the school.
 *
 * \param amount The number of students to remove.
 */
void School::dropouts(float amount) {
	// Do nothing if amount is invalid or exceeds current amount
	if (amount < 0 || amount >= studentAmount) return;

	// Reduce current student amount
	studentAmount -= amount;
}

/**
 * Transfers students to another school.
 *
 * \param amount   The number of students to transfer.
 * \param toSchool The school receiving the transferred students.
 */
void School::transfer(float amount, School& toSchool) {
	// Do nothing if transfer amount is invalid
	if (amount >= toSchool.studentAmount) return;

	// Drop students from this school
	dropouts(amount);

	// Admit students to target school
	toSchool.admissions(amount);
}

/**
 * Outputs the school information to an output stream.
 *
 * \param stream The output stream.
 * \param rhs    The school whose data is to be printed.
 * \return       The same output stream.
 */
ostream& operator<< (ostream& stream, School rhs) {
	// Print school name, current and next year student count
	stream << rhs.name << "\t" << rhs.studentAmount << "\t" << rhs.studentAmountNextYear;
	
	return stream;
}