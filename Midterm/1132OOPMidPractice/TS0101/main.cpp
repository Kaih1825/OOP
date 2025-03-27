#include <iostream>

using namespace std;

int main() {
	double n;
	while (cin >> n) {
		double guess = n / 2;
		while (true) {
			double r = n / guess;
			if (guess - ((guess + r) / 2.0) < 0.01) {
				break;
			}
			guess = (guess + r) / 2.0;
		}
		printf("%.2f\n", guess);
	}
}
