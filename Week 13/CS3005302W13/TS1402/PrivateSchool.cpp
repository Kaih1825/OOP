/*****************************************************************//**
 * \file   PrivateSchool.cpp
 * \brief  Implementation of PrivateSchool class methods
 *
 * \author Kai
 * \date   2025/05/13
 *********************************************************************/
#include "PrivateSchool.h"

/**
* Overrides dropout logic for private schools.
* Reduces future projections more severely after repeated dropouts.
*
* \param amount The number of students dropping out.
*/
void PrivateSchool::dropouts(float amount) {
	// Do nothing if amount is invalid or exceeds current students
	if (amount < 0 || amount >= studentAmount) return;

	// Subtract dropouts from current student amount
	studentAmount -= amount;

	// Increase dropout counter
	times++;

	// From second dropout onward, reduce next year's projection
	if (times > 1) {
		// If reduction would go below 0, cancel adjustment
		if (100 >= studentAmountNextYear) return;

		// Reduce next year's projection by 100 students
		studentAmountNextYear -= 100;
	}
}