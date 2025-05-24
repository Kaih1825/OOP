/*****************************************************************//**
 * \file   Template.h
 * \brief  A template-based function that calculates and returns the absolute value of the difference between two numeric values
 *
 * \author kai
 * \date   2025/5/24
 *********************************************************************/
#pragma once
#include<cmath>

 /**
 * A template-based function that calculates and returns the absolute value of the difference between two numeric values
 *
 * \param p1 First value
 * \param p2 Second value
 * \return
 */
template<typename T>
double absoluteValue(T p1, T p2) {
	// Return calculates and returns the absolute value of the difference between two numeric values
	return abs(p1 - p2);
}
