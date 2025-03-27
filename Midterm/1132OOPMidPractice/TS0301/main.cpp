#include<iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string input;
	while (getline(cin, input)) {
		stringstream splited(input);
		string buffer;
		map<int, int> count;
		while (splited >> buffer) {
			count[atoi(buffer.c_str())]++;
		}
		printf("N\tcount\n");
		for (auto i = count.rbegin(); i != count.rend(); i++) {
			printf("%d\t%d\n", (*i).first, (*i).second);
		}
	}
}
