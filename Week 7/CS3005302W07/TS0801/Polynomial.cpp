#include "Polynomial.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

Polynomial::Polynomial() {

}

Polynomial::Polynomial(double* param, int size) {
	for (int i = 0; i < size; i++) {
		this->param.push_back(param[i]);
	}
}

Polynomial::Polynomial(const Polynomial& poly) {
	param = poly.param;
}

int Polynomial::mySize() {
	int length = param.size();
	for (int i = param.size() - 1; i >= 0; i--) {
		if (param[i] != 0) {
			break;
		}
		length--;
	}
	return length;
}

double evaluate(const Polynomial& poly, const double& var) {
	double result = 0;

	for (int i = 0; i < poly.param.size(); i++) {
		result += poly.param[i] * pow(var, i);
	}

	return result;
}

Polynomial operator+(double lhs, const Polynomial& rhs)
{
	Polynomial result(rhs);
	if (result.param.empty()) {
		result.param.push_back(lhs);
	}
	else {
		result.param[0] = lhs + rhs.param[0];
	}
	return result;
}

Polynomial operator-(double lhs, const Polynomial& rhs)
{
	Polynomial result(rhs);
	if (result.param.empty()) {
		result.param.push_back(lhs);
	}
	else {
		result.param[0] -= lhs;
	}
	return result;
}

Polynomial operator*(double lhs, const Polynomial& rhs)
{
	Polynomial result(rhs);
	for (int i = 0; i < result.param.size(); i++) {
		result[i] *= lhs;
	}
	return result;
}

void Polynomial::operator=(const Polynomial& poly) {
	param = poly.param;

}

double Polynomial::operator[](unsigned int index) const {
	return param[index];
}

double& Polynomial::operator[](unsigned int index) {
	if (index < param.size()) {
		return param[index];
	}

	for (int i = param.size(); i < index; i++) {
		param.push_back(0);
	}
	param.push_back(index);
	return param[index];
}

Polynomial Polynomial::operator+(const Polynomial& otherPoly) {
	vector<double> param1 = param;
	vector<double> param2 = otherPoly.param;

	for (int i = param1.size(); i < param2.size(); i++) {
		param1.push_back(0);
	}

	for (int i = param2.size(); i < param1.size(); i++) {
		param2.push_back(0);
	}

	vector<double> result;
	for (int i = 0; i < param1.size(); i++) {
		result.push_back(param1[i] + param2[i]);
	}

	return Polynomial(result.data(), result.size());
}

Polynomial Polynomial::operator+(const double add) {
	Polynomial result(*this);
	if (result.param.empty()) {
		result.param.push_back(add);
	}
	else {
		result.param[0] += add;
	}
	return result;
}


Polynomial Polynomial::operator-(const Polynomial& otherPoly) {
	vector<double> param1 = param;
	vector<double> param2 = otherPoly.param;

	size_t maxSize = max(param1.size(), param2.size());
	param1.resize(maxSize, 0);
	param2.resize(maxSize, 0);

	vector<double> result;
	for (int i = 0; i < param1.size(); i++) {
		result.push_back(param1[i] - param2[i]);
	}

	return Polynomial(result.data(), result.size());
}

Polynomial Polynomial::operator-(const double min) {
	Polynomial result(param.data(), param.size());
	if (result.param.empty()) {
		result.param.push_back(-min);
	}
	else {
		result.param[0] = param[0] - min;
	}
	return result;
}


Polynomial Polynomial::operator*(const double scale) {
	vector<double> result = param;

	for (int i = 0; i < param.size(); i++) {
		result[i] = param[i] * scale;
	}

	return Polynomial(result.data(), result.size());
}

Polynomial Polynomial::operator*(const Polynomial& otherPoly) {
	Polynomial result;
	result.param = vector<double>(param.size() + otherPoly.param.size(), 0);
	for (int i = 0; i < param.size(); i++) {
		for (int j = 0; j < otherPoly.param.size(); j++) {
			result[i + j] += param[i] * otherPoly[j];
		}
	}

	return result;
}

