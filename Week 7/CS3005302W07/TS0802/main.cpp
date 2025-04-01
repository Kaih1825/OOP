#include <iostream>
#include <vector>

using namespace std;

int main() {
	int rowA, colA, rowB, colB;
	while (cin >> rowA >> colA >> rowB >> colB) {
		vector<vector<double> > matrixA(rowA,vector<double> (colA,0));
		vector<vector<double> > matrixB(rowB, vector<double>(colB, 0));

		for (int i = 0; i < rowA; i++) {
			for (int j = 0; j < colA; j++) {
				cin >> matrixA[i][j];
			}
		}

		for (int i = 0; i < rowB; i++) {
			for (int j = 0; j < colB; j++) {
				cin >> matrixB[i][j];
			}
		}

		if (colA != rowB) {
			cout << "Matrix multiplication failed." << endl;
			continue;
		}

		vector<vector<double> > result(rowA, vector<double>(colB, 0));
		for (int i = 0; i < rowA; i++) {
			for (int j = 0; j < colB; j++) {
				double sum=0;
				for (int k = 0; k < rowB; k++) {
					sum += matrixA[i][k] * matrixB[k][j];
				}
				result[i][j] = sum;
			}
		}

		for (int i = 0; i < rowA; i++) {
			for (int j = 0; j < colB; j++) {
				cout << result[i][j];
				if (j != colB - 1) {
					cout << " ";
				}
			}
			cout << endl;
		}
	}
}