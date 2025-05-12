/*****************************************************************//**
 * \file   Main.cpp
 * \brief  Multiply two matrices input from user
 *
 * \author kai
 * \date   2025/4/30
 *********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int	row1, col1, row2, col2;

	// Read dimensions of matrix1 (row1 x col1) and matrix2 (row2 x col2)
	cin >> row1 >> col1 >> row2 >> col2;

	// Check if matrix multiplication is possible
	if (row2 != col1) {
		cout << "Matrix multiplication failed." << endl;
		return 0;
	}

	// Declare matrices
	vector<vector<int> > matrix1, matrix2;

	// Input matrix1
	for (int i = 0; i < row1; i++) {
		vector<int> temp;

		for (int j = 0; j < col1; j++) {
			int	num;
			cin >> num;

			temp.push_back(num);
		}
		matrix1.push_back(temp);
	}

	// Input matrix2
	for (int i = 0; i < row2; i++) {
		vector<int> temp;

		for (int j = 0; j < col2; j++) {
			int	num;
			cin >> num;
			temp.push_back(num);
		}
		matrix2.push_back(temp);
	}

	// Initialize result matrix (row1 x col2) with zeros
	vector <vector<int> > result(row1, vector<int>(col2, 0));

	// Perform matrix multiplication
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			result[i][j];
			for (int k = 0; k < col1; k++) {
				// Accumulate dot product of row from matrix1 and column from matrix2
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	// Output result matrix
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j];
			if (j != result[i].size() - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}
}
