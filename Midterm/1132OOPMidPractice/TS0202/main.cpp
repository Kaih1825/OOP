#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

bool so(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

int main() {
	ifstream in("scores.txt");
	vector<pair<string, int> > scores;
	string name = "";
	int score = 0;
	while (in >> name >> score) {
		pair<string, int> tis = { name,score };
		scores.push_back(tis);
	}

	sort(scores.begin(), scores.end(), so);

	for (int i = 0; i < 3; i++) {
		cout << scores[i].first << endl << scores[i].second << endl;
	}
}
