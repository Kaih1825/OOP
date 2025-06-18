#include <iostream>
#include <vector>

using namespace std;

int main() {
	int	ca, cb, ra, rb;
	cin >> ra >> ca >> rb >> cb;
	if (ca != rb) {
		cout << "Matrix multiplication failed." << endl;
		return 0;
	}
	vector<vector<int> > ma(ra, vector<int>(ca, 0)), mb(rb, vector<int>(cb, 0));
	for (int i = 0; i < ra; i++) {
		for (int j = 0; j < ca; j++) {
			cin >> ma[i][j];
		}
	}

	for (int i = 0; i < rb; i++) {
		for (int j = 0; j < cb; j++) {
			cin >> mb[i][j];
		}
	}
	vector<vector<int> > res(ra, vector<int>(cb, 0));
	for (int i = 0; i < ra; i++) {
		for (int j = 0; j < cb; j++) {
			for (int k = 0; k < rb; k++) {
				res[i][j] += ma[i][k] * mb[k][j];
			}
		}
	}

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
			if (j != res[i].size() - 1) {
				cout << " ";
			}
		}
		if (i != res.size() - 1) {
			cout << endl;
		}
	}

	return 0;
}
