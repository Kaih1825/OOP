#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int size, lineOfInput;
	while (cin >> size >> lineOfInput) {
		cin.ignore();
		vector<char> memory(size, -2);

		// l = Line
		for (int l = 0; l < lineOfInput; l++) {
			string input;
			getline(cin, input);

			stringstream ss(input);
			vector<string> command;
			string buffer;

			for (int i = 0; i < 3; i++) {
				ss >> buffer;
				command.push_back(buffer);
			}

			int typeSize = 0;
			if (command[2] == "char") typeSize = 1;
			if (command[2] == "short") typeSize = 2;
			if (command[2] == "int") typeSize = 4;

			int position = stoll(command[1]);

			if (position + typeSize > size) {
				cout << "Violation Access.\n";
				continue;
			}

			if (command[0] == "Set") {
				string saved = "";
				while (ss >> buffer) {
					saved += buffer + ' ';
				}
				saved.substr(0, saved.size() - 1);
				command.push_back(saved);

				if (command[2] == "String") typeSize = command[3].size();

				if (command[2] == "char") {
					memory[position] = (char)stoll(command[3]);
				}
				;
				if (command[2] == "short" || command[2] == "int") {
					stringstream convertSS;
					convertSS << hex << atoll(command[3].c_str());
					string convertResult;
					convertSS >> convertResult;
					cout << atoll(command[3].c_str()) << endl<< command[3]<<endl;

					vector<char> thisString;
					for (int i = 0; i < convertResult.size(); i += 2) {
						string tis = "  ";
						tis[0] = convertResult[i];
						tis[1] = convertResult[i + 1];
						thisString.push_back((char)stoll(tis.c_str(), 0, 16));
					}
					reverse(thisString.begin(), thisString.end());
					for (int i = 0; i < thisString.size(); i++) {
						memory[position + i] = thisString[i];
					}

					for (auto i : memory) {
						cout << (int)i << " ";
					}
					cout << endl;
				}

				if (command[2] == "String") {
					for (int i = 0; i < command[3].size(); i++) {
						memory[position + i] = command[3][i];
					}
				}
			}

			if (command[0] == "Get") {
				if (command[2] == "String") {
					for (int i = stoll(command[1]); i < memory.size(); i++) {
						if ((int)memory[i] <=0) {
							break;
						}
						cout << memory[i];
					}
					cout <<endl;
				}
				
				if (command[2] == "char") {
					cout << memory[stoll(command[1])]<<endl;
				}

				if (command[2] == "short" || command[2] == "int") {
					string sum = "";
					for (int i = typeSize-1; i >=0; i--) {
						stringstream convertSS;
						convertSS << hex << (int)memory[position + i];
						string convertResult;
						convertSS >> convertResult;
						sum += convertResult;
					}
					cout << stoll(sum,0,16) <<endl;
				}
			}
		}

	}
}

