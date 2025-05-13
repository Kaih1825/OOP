/*****************************************************************//**
 * \file   School.h
 * \brief  School class declaration for managing school admissions,
 *         dropouts, and transfers
 *
 * \author Kai
 * \date   2025/5/13
 *********************************************************************/
#pragma once
#include <iostream>

using namespace std;

//Represents a general school with basic operations such as admissions, dropouts, and student transfers.
class School {
public:
	//  Constructs a School object with a name and initial student amount
	School(string name, float amount);

	// The name of the school
	string name;

	// The current number of students
	double studentAmount;
	// The predicted number of students for the next year
	double studentAmountNextYear;

	// Adds new students to the school
	void admissions(float amount);

	// Removes students from the school (can be overridden).
	virtual void dropouts(float amount);

	// Transfers students to another school
	void transfer(float amount, School& toSchool);

	// Outputs the school information to a stream
	friend ostream& operator<< (ostream& stream,School rhs);
};


#include "PrivateSchool.h"
#include "PublicSchool.h"