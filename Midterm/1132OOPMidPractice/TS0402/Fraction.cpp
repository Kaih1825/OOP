#include "Fraction.h"

void Fraction::setNumerator(int nu)
{
	numerator = nu;
}

void Fraction::setDenominator(int de)
{
	denominator = de;
}

void Fraction::getDouble()
{
	if (denominator == 0) {
		cout << 0 << endl;
		return;
	}
	double res = (double)numerator / denominator;
	if ((int)res == res) {
		printf("%d\n", (int)res);
	}
	else {
		printf("%f\n", res);
	}
}

int gcd(int n1, int n2) {
	if (n1 % n2 == 0) {
		return n2;
	}
	return gcd(n2, n1 % n2);
}

void Fraction::outputReducedFraction()
{
	if (denominator == 0 || numerator == 0) {
		cout << 0 << endl;
		return;
	}
	int n1 = numerator;
	int n2 = denominator;
	int gcdRes = gcd(max(n1, n2), min(n1, n2));
	if (n2 / gcdRes == 1) {
		cout << n1 / gcdRes << endl;
		return;
	}
	printf("%d/%d\n", (int)(n1 / gcdRes), (int)(n2 / gcdRes));
}



