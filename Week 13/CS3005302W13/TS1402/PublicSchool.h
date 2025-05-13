/*****************************************************************//**
 * \file   PublicSchool.h
 * \brief  PublicSchool class derived from School, simulates public school behavior
 *
 * \author Kai
 * \date   2025/05/13
 *********************************************************************/
#pragma once
#include "School.h"
#include <string>

using namespace std;

// Includes a growth rate and overrides dropout behavior.
class PublicSchool : public School {
public:
	// Constructs a PublicSchool with a name and initial student count.
	PublicSchool(string name, float amount) :School(name, amount) {};
	// Annual student growth rate for public schools.
	double growing_rate = 0.05;

	// Applies annual student growth to predict next year's student number.
	void apply_growth();
	// Overrides the base class dropout logic for public schools.
	void dropouts(float amount);
};