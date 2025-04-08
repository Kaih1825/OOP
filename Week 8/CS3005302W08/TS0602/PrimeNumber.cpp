#include "PrimeNumber.h"
#include <iostream>
#include <cmath>

using namespace std;

PrimeNumber::PrimeNumber() {
	value = 1;
}

PrimeNumber::PrimeNumber(int _value) {
	value = _value;
}

int PrimeNumber::get() {
	return value;
}

PrimeNumber& PrimeNumber::operator++() {
	int n = value + 1;
	if (n == 2 || n == 3 || n == 5) {
		PrimeNumber res = PrimeNumber(n);
		value = n;
		return res;
	}
	while (true) {
		bool isPrime = true;
		for (int i = 1; i < sqrt(n); i++) {
			if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
				isPrime = false;
				break;
			}
			if (n == (6 * i + 1) || n == (6 * i + 5)) {
				isPrime = true;
				break;
			}
			if (n % (6 * i + 1) == 0 || n % (6 * i + 5) == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			PrimeNumber res = PrimeNumber(n);
			value = n;
			return res;
		}
		n++;
	}

}

PrimeNumber PrimeNumber::operator++(int) {
	int n = value + 1;
	if (n == 2 || n == 3 || n == 5) {
		PrimeNumber res = PrimeNumber(value);
		value = n;
		return res;
	}
	while (true) {
		bool isPrime = true;
		for (int i = 1; i < sqrt(n); i++) {
			if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
				isPrime = false;
				break;
			}
			if (n == (6 * i + 1) || n == (6 * i + 5)) {
				isPrime = true;
				break;
			}
			if (n % (6 * i + 1) == 0 || n % (6 * i + 5) == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			PrimeNumber res = PrimeNumber(value);
			value = n;
			return res;
		}
		n++;
	}
}


PrimeNumber& PrimeNumber::operator--() {
	if (value == 2) {
		PrimeNumber res = PrimeNumber(1);
		value = 1;
		return res;
	}

	int n = value - 1;
	if (n == 2 || n == 3 || n == 5) {
		PrimeNumber res = PrimeNumber(n);
		value = n;
		return res;
	}
	while (true) {
		bool isPrime = true;
		for (int i = 1; i < sqrt(n); i++) {
			if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
				isPrime = false;
				break;
			}
			if (n == (6 * i + 1) || n == (6 * i + 5)) {
				isPrime = true;
				break;
			}
			if (n % (6 * i + 1) == 0 || n % (6 * i + 5) == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			PrimeNumber res = PrimeNumber(n);
			value = n;
			return res;
		}
		n--;
	}
}


PrimeNumber PrimeNumber::operator--(int) {
	if (value == 2) {
		PrimeNumber res = PrimeNumber(value);
		value = 1;
		return res;
	}

	int n = value - 1;
	if (n == 2 || n == 3 || n == 5) {
		PrimeNumber res = PrimeNumber(value);
		value = n;
		return res;
	}
	while (true) {
		bool isPrime = true;
		for (int i = 1; i < sqrt(n); i++) {
			if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
				isPrime = false;
				break;
			}
			if (n == (6 * i + 1) || n == (6 * i + 5)) {
				isPrime = true;
				break;
			}
			if (n % (6 * i + 1) == 0 || n % (6 * i + 5) == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			PrimeNumber res = PrimeNumber(value);
			value = n;
			return res;
		}
		n--;
	}

}

