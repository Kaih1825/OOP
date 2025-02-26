/*****************************************************************//**
 * \file   PrintStandardFormat.cpp
 * \brief  Formate the name, salary and award that user input, and output to the console
 *
 * \author Kai
 * \date   2025/2/26
 *********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

/**
 * The Struct of emplyee data
 */
struct Employee
{
	string name;
	int32_t salary;
	int32_t award;
};

int main() {
	// The variable offer user input
	int EmployeeCount;

	// Let user input the count of Employee until EOF
	while (cin >> EmployeeCount) {
		// The vector that save data of each Employee
		vector<Employee> Employees;

		// The variable that save the max length of name and the max salary and award
		int nameMaxLength = 0, salaryMax = 0, awardMax = 0;

		// Let user input Employee data "EmployeeCount" time
		for (int i = 0; i < EmployeeCount; i++) {
			// The variable that save this Employee name, salary and award data
			string name;
			int salary, award;
			cin >> name >> salary >> award;

			// Get the max length of name and the max salary and award
			if (name.length() > nameMaxLength) {
				nameMaxLength = name.length();
			}
			if (salary > salaryMax) {
				salaryMax = salary;
			}
			if (award > awardMax) {
				awardMax = award;
			}

			// Save this Employee data into the Employees vector
			Employee thisEmployee;
			thisEmployee.name = name;
			thisEmployee.salary = salary;
			thisEmployee.award = award;

			Employees.push_back(thisEmployee);
		}

		// Formate the user input and output
		for (Employee emploee : Employees) {
			// Print the blank before each name
			for (int i = 0; i < nameMaxLength - emploee.name.length(); i++) {
				cout << " ";
			}
			// Print the name
			cout << emploee.name;

			// Count the salary and award lengh
			int salaryLength = log10(salaryMax) + 3;
			int awardLength = log10(awardMax) + 3;

			cout << "|";
			// Print the blank before each salary
			for (int i = 0; i < salaryLength - (log10(emploee.salary) + 1); i++) {
				cout << " ";
			}
			// Print the salary
			cout << emploee.salary;

			cout << "|";
			// Print the blank before each award
			for (int i = 0; i < awardLength - (log10(emploee.award) + 1); i++) {
				cout << " ";
			}
			// Print the award
			cout << emploee.award << endl;
		}
	}

	return 0;
}
