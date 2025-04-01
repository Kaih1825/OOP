/*****************************************************************//**
 * \file   main.cpp
 * \brief  A program to calculate matrix multiplication
 *
 * \author Kai
 * \date   2025/4/2
 *********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	// The count of row and column of matrixA and matrixB
	int rowA, colA, rowB, colB;

	// Let user input until EOF
	while (cin >> rowA >> colA >> rowB >> colB) {
		// Initialize matrix A with dimensions rowA x colA, all elements set to 0
		vector<vector<double>> matrixA(rowA, vector<double>(colA, 0));
		// Initialize matrix B with dimensions rowB x colB, all elements set to 0
		vector<vector<double>> matrixB(rowB, vector<double>(colB, 0));

		// Input elements for matrix A
		for (int i = 0; i < rowA; i++) {
			for (int j = 0; j < colA; j++) {
				cin >> matrixA[i][j];
			}
		}

		// Input elements for matrix B
		for (int i = 0; i < rowB; i++) {
			for (int j = 0; j < colB; j++) {
				cin >> matrixB[i][j];
			}
		}

		// Check if matrix multiplication is possible (column count of A must match row count of B)
		if (colA != rowB) {
			cout << "Matrix multiplication failed." << endl;
			continue;
		}

		// Initialize result matrix with dimensions rowA x colB, all elements set to 0
		vector<vector<double>> result(rowA, vector<double>(colB, 0));

		// Perform matrix multiplication
		for (int i = 0; i < rowA; i++) {
			for (int j = 0; j < colB; j++) {
				double sum = 0;
				for (int k = 0; k < rowB; k++) { // Iterate over columns of A and rows of B
					sum += matrixA[i][k] * matrixB[k][j];
				}
				result[i][j] = sum;
			}
		}

		// Output the resulting matrix
		for (int i = 0; i < rowA; i++) {
			for (int j = 0; j < colB; j++) {
				cout << result[i][j];
				if (j != colB - 1) { // Avoid trailing space at the end of each row
					cout << " ";
				}
			}
			cout << endl;
		}
	}

}