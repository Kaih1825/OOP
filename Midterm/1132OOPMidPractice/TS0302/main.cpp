#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream in("grade.txt");
	string buffer;
	while (in >> buffer) {
		cout << buffer;
	}
}
