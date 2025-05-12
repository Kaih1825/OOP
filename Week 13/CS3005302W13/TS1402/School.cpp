#include "School.h"

void School::admissions(float amount) {
	if (amount < 0) return;
	studentAmount += amount;
}

void School::dropouts(float amount) {
	if (amount < 0 || amount <= studentAmount) return;
	studentAmount -= amount;
}
void School::transfer(float amount, School& toSchool) {
	dropouts(amount);
	toSchool.admissions(amount);
}

void School::operator<< (ostream stream, School rhs) {
	stream << rhs.name << "\t" << rhs.studentAmount << "\t" << rhs.studentAmountNextYear;
}
