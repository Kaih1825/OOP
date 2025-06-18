#include <iostream>

using namespace std;
class PrimeNumber {
public:
	int value;

	int get() {
		return value;
	}

	PrimeNumber() {
		value = 1;
	}

	PrimeNumber(int _value) {
		value = _value;
	}

	PrimeNumber operator++() { // ++x
		if (value == 1) value = 2;
		else if (value == 2) value = 3;
		else if (value == 3) value = 5;
		else if (value % 6 == 1) {
			value = (int)(value / 6) * 6 + 5;
		}
		else {
			value = ((int)(value / 6) + 1) * 6 + 1;
		}
		return *this;

	}

	PrimeNumber operator++(int) { // x++
		int tmp = value;
		if (value == 1) value = 2;
		else if (value == 2) value = 3;
		else if (value == 3) value = 5;
		else if (value % 6 == 1) {
			value = (int)(value / 6) * 6 + 5;
		}
		else {
			value = ((int)(value / 6) + 1) * 6 + 1;
		}
		return PrimeNumber(tmp);
	}

	PrimeNumber operator--() { // --x
		if (value == 2) value = 1;
		else if (value == 3) value = 2;
		else if (value == 5) value = 3;
		else if (value % 6 == 1) {
			value = ((int)(value / 6) - 1) * 6 + 5;
		}
		else {
			value = ((int)(value / 6)) * 6 + 1;
		}
		return *this;
	}

	PrimeNumber operator--(int) { // x--
		int tmp = value;
		if (value == 2) value = 1;
		else if (value == 3) value = 2;
		else if (value == 5) value = 3;
		else if (value % 6 == 1) {
			value = ((int)(value / 6) - 1) * 6 + 5;
		}
		else {
			value = ((int)(value / 6)) * 6 + 1;
		}
		return PrimeNumber(tmp);
	}

};