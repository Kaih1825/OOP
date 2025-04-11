#include "NumberGame.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <bitset>

void NumberGame::SetInput(int n) {
	inputNumber = n;
}

void NumberGame::ProcessInput() {
	for (auto c : to_string(inputNumber)) {
		numbers.push_back(c - '0');
	}
	sort(numbers.begin(), numbers.end());
}

void NumberGame::SetFileName(string fileName) {
	this->fileName = fileName;
}

string toBinary(int n) {
	string r;
	while (n != 0) {
		r += (n % 2 == 0 ? "0" : "1");
		n /= 2;
	}
	return r;
}
void NumberGame::LoadNumberList() {
	ifstream inputFile("number.txt");
	int number;
	vector<int> pos;
	int tmp = inputNumber;
	for (int i = 1; i < pow(2, numbers.size()); i++) {
		string bin = toBinary(i);
		int poRes = 1;
		for (int j = 0; j < bin.size(); j++) {
			if (bin[j] == '1') {
				poRes *= numbers[j];
			}
		}
		pos.push_back(poRes);
	}

	sort(pos.begin(), pos.end());

	while (inputFile >> number) {
		if (number > pos[pos.size() - 1]) {
			continue;
		}
		for (auto i : pos) {
			if (number == i) {
				result.push_back(number);
				break;
			}
		}
	}
}

void NumberGame::PrintAllValid() {
	for (auto n : result) {
		cout << n << endl;
	}
}

void NumberGame::Reset() {
	numbers.clear();
	result.clear();
}
