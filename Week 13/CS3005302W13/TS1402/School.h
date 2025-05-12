#pragma once
#include <iostream>

using namespace std;

class School {
public:
	string name;
	float studentAmount;
	float studentAmountNextYear;
	void admissions(float amount);
	void dropouts(float amount);
	void transfer(float amount, School& toSchool);

	ostream operator<< (ostream stream, School rhs);
};
