#pragma once
#include <vector>
using namespace std;

class Polynomial {
public:
	vector<double> param;

	Polynomial();
	Polynomial(double* param, int size);
	Polynomial(const Polynomial& poly);

	int mySize();

	void operator=(const Polynomial& poly);
	double operator[](unsigned int index) const;
	double& operator[](unsigned int index);

	Polynomial operator+(const Polynomial& otherPoly);
	Polynomial operator+(const double add);
	Polynomial operator-(const Polynomial& otherPoly);
	Polynomial operator-(const double min);
	Polynomial operator*(const Polynomial& otherPoly);
	Polynomial operator*(const double scale);
};

double evaluate(const Polynomial& poly, const double& var);

Polynomial operator+(double lhs, const Polynomial& rhs);
Polynomial operator-(double lhs, const Polynomial& rhs);
Polynomial operator*(double lhs, const Polynomial& rhs);

