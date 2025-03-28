#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

int main() {
	ifstream in("grade.txt");
	ofstream ou("grades.Output");

	string buffer = "";
	ou.clear();
	while (getline(in, buffer)) {
		map<string, int> grades;
		for (int i = 0; i <= 5; i++) {
			grades[to_string(i)] = 0;
		}

		string gb = "";
		stringstream gbss(buffer);
		while (gbss >> gb) {
			grades[gb]++;
		}
		for (auto i : grades) {
			ou << i.second << " grade(s) of " << i.first << endl;
		}

	}
}
