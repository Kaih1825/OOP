/*****************************************************************//**
 * \file   PrivateSchool.h
 * \brief  PrivateSchool class derived from School, simulates private school behavior
 *
 * \author Kai
 * \date   2025/05/13
 *********************************************************************/
#pragma once
#include "School.h"
#include <string>

using namespace std;

// Implements custom dropout logic using a counter.
class PrivateSchool : public School {
public:
	// Constructs a PrivateSchool with a name and initial student count.
	PrivateSchool(string name, float amount) :School(name, amount) {};

	// A counter tracking the number of times dropouts have occurred.
	int times = 0;
	// Overrides the base class dropout logic for private schools.
	void dropouts(float amount);
};