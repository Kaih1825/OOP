#pragma once
#include <vector>

using namespace std;

class Polynomial {
public:
	vector<double> coefficients;

	Polynomial() {
		coefficients.push_back(0);
	};

	Polynomial(double* param, int size) {
		for (int i = 0; i < size; i++) {
			coefficients.push_back(param[i]);
		}
	}

	Polynomial(double d) {
		coefficients.push_back(d);
	}

	Polynomial(const Polynomial& poly) {
		coefficients = poly.coefficients;
	}

	int mySize() {
		for (int i = coefficients.size() - 1; i >= 0; i--) {
			if (coefficients[i] != 0) {
				return i + 1;
			}
		}
		return 0;
	}

	friend double evaluate(const Polynomial& poly, const double& var) {
		double sum = 0;
		for (int i = 0; i < poly.coefficients.size(); i++) {
			sum += poly.coefficients[i] * pow(var, i);
		}
		return sum;
	}

	void operator= (Polynomial pol) {
		coefficients = pol.coefficients;
	}

	double& operator[] (int index) {
		if (index >= coefficients.size()) {
			coefficients.resize(index + 1, 0);
		}
		return coefficients[index];
	}

	Polynomial operator+ (Polynomial pol) {
		Polynomial res;
		Polynomial p1, p2;
		p1 = pol;
		p2 = *this;
		p1.coefficients.resize(max(pol.mySize(), mySize()), 0);
		p2.coefficients.resize(max(pol.mySize(), mySize()), 0);
		for (int i = 0; i < p1.coefficients.size(); i++) {
			res[i] = p1[i] + p2[i];
		}
		return res;
	}

	friend Polynomial operator+ (double d, Polynomial pol) {
		Polynomial res;
		res.coefficients = pol.coefficients;
		res.coefficients[0] += d;
		return res;
	}

	Polynomial operator- (Polynomial pol) {
		Polynomial res;
		Polynomial p1, p2;
		p1 = pol;
		p2 = *this;
		p1.coefficients.resize(max(pol.mySize(), mySize()), 0);
		p2.coefficients.resize(max(pol.mySize(), mySize()), 0);
		for (int i = 0; i < p1.coefficients.size(); i++) {
			res[i] = p2[i] - p1.coefficients[i];
		}
		return res;
	}

	friend Polynomial operator- (double d, Polynomial pol) {
		Polynomial res;
		res.coefficients = pol.coefficients;
		res.coefficients[0] = d - res.coefficients[0];
		for (int i = 1; i < res.coefficients.size(); i++) {
			res[i] = -res[i];
		}
		return res;
	}

	Polynomial operator* (Polynomial pol) {
		Polynomial res;
		Polynomial p1, p2;
		p1 = pol;
		p2 = *this;
		p1.coefficients.resize(max(pol.mySize(), mySize()), 0);
		p2.coefficients.resize(max(pol.mySize(), mySize()), 0);

		for (int i = 0; i < p1.coefficients.size(); i++) {
			for (int j = 0; j < p1.coefficients.size(); j++) {
				res[i + j] += p1[i] * p2[j];
			}
		}

		return res;
	}

	friend Polynomial operator*(double sclar, Polynomial poly) {
		Polynomial res;
		for (int i = 0; i < poly.mySize(); i++) {
			res[i] = sclar * poly[i];
		}
		return res;
	}
};
