#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void out() {
	cout << "Violation Access." << endl;
}

int main() {
	int size, n;
	cin >> size >> n;
	vector<int> mem(size, 0);
	for (; n > 0; n--) {
		string command;
		string type;
		int start;
		cin >> command >> start >> type;
		if (command == "Set") {
			if (type == "String") {
				string input;
				cin.ignore();
				getline(cin, input);
				if (start + input.size() >= size) {
					out();
				}
				for (int i = start; i < start + input.size(); i++) {
					if (i >= size) break;
					mem[i] = input[i - start];
				}
			}
			else if (type == "char") {
				if (start >= size) {
					out();
					continue;
				}
				int input;
				cin >> input;
				mem[start] = input;
			}
			else if (type == "int" || type == "short") {
				int typeSize = type == "int" ? 4 : 2;
				if (start + typeSize > size) {
					out();
				}
				long long int input;
				cin >> input;
				stringstream ss;
				ss << hex << input;
				string hexNum = ss.str();
				vector<string> hexs;
				for (int i = 0; i < hexNum.size(); i += 2) {
					string r = "  ";
					if (i + 1 >= hexNum.size()) break;
					r[0] = hexNum[i];
					r[1] = hexNum[i + 1];
					hexs.push_back(r);
				}
				reverse(hexs.begin(), hexs.end());
				for (int i = 0; i < typeSize; i++) {
					if (start + i >= size) break;
					if (i >= hexs.size()) break;
					mem[start + i] = stoi(hexs[i], 0, 16);
				}
			}
		}
		else {
			if (type == "String") {
				for (int i = start; i < size; i++) {
					if (mem[i] <= 0) break;
					cout << (char)mem[i];
				}
				cout << endl;
			}
			else if (type == "char") {
				if (start >= size) {
					out();
					continue;
				}
				cout << abs(mem[start]) << endl;
			}
			else if (type == "int" || type == "short") {
				int typeSize = type == "int" ? 4 : 2;
				vector<string> hexs;
				if (start >= size || start + typeSize > size) {
					out();
					continue;
				}
				for (int i = start; i < start + typeSize; i++) {
					if (i > size) break;
					stringstream ss;
					ss << hex << mem[i];
					hexs.push_back(ss.str());
				}
				reverse(hexs.begin(), hexs.end());
				string hexStr = "";
				for (auto i : hexs) {
					hexStr += i;
				}
				cout << stoll(hexStr, 0, 16) << endl;

			}
		}
	}
	return 0;
}
