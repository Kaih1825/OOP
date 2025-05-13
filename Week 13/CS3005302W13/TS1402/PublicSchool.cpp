/*****************************************************************//**
 * \file   PublicSchool.cpp
 * \brief  Implementation of PublicSchool class methods
 *
 * \author Kai
 * \date   2025/05/13
 *********************************************************************/
#include "PublicSchool.h"

/**
* Applies growth rate to project next year's student count.
* 
*/
void PublicSchool::apply_growth(){
	// Increase projected student count by growth rate
	studentAmountNextYear += growing_rate * studentAmountNextYear;
}

/**
 * Overrides dropout logic for public schools.
 *
 * \param amount The number of students dropping out.
 */
void PublicSchool::dropouts(float amount) {
	// Do nothing if invalid amount or exceeds current count
	if (amount < 0 || amount >= studentAmount) return;

	// Subtract dropouts from current student amount
	studentAmount -= amount;


	// If dropouts are 100 or more, reduce next year's projection
	if (amount < 100) return;

	// Reduce next year's projection by 5%
	studentAmountNextYear = (int)(0.95 * studentAmountNextYear);
}