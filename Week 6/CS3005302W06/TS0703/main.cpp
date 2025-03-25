#include <iostream>
#include <vector>

using namespace std;

int main() {
	string numbers;
	while (cin >> numbers) {
		for (auto c : numbers) {
			int num = c - '0';
			if (num > 9 || num < 0) {
				continue;
			}
			if (num == 2 || num == 3 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9 || num == 0) {
				cout << " _ ";
			}
			else {
				cout << "   ";
			}
		}
		cout << endl;

		for (auto c : numbers) {
			int num = c - '0';
			if (num > 9 || num < 0) {
				continue;
			}
			if (num == 4 || num == 5 || num == 6 || num == 8 || num == 9 || num == 0) {
				cout << "|";
			}
			else {
				cout << " ";
			}
			if (num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 8 || num == 9) {
				cout << "_";
			}
			else {
				cout << " ";
			}

			if (num == 1 || num == 2 || num == 3 || num == 4 || num == 7 || num == 8 || num == 9 || num == 0) {
				cout << "|";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;

		for (auto c : numbers) {
			int num = c - '0';
			if (num > 9 || num < 0) {
				continue;
			}
			if (num == 2 || num == 6 || num == 8 || num == 0) {
				cout << "|";
			}
			else {
				cout << " ";
			}

			if (num == 2 || num == 3 || num == 5 || num == 6 || num == 8 || num == 9 || num == 0) {
				cout << "_";
			}
			else {
				cout << " ";
			}

			if (num == 1 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9 || num == 0) {
				cout << "|";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
