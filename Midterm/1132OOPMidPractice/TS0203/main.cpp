#include <iostream>

using namespace std;

int main() {
	string input;
	while (cin >> input) {
		int n;
		if (pow((int)(sqrt(input.size())), 2) == input.size()) {
			n = sqrt(input.size());
		}
		else {
			n = sqrt((int)input.size()) + 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (n * j + i >= input.size()) {
					break;
				}
				cout << input[n * j + i];
			}
			cout << endl;
		}
	}
	return 0;
}
