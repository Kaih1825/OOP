/*****************************************************************//**
 * \file   main.cpp
 * \brief  Given a radius r, compute and output the volume of a sphere with radius r.
 *
 * \author Kai
 * \date   2025/2/23
 *********************************************************************/
#define PI 3.14159265358979323846

#include<iostream>
using namespace std;

int main() {
	// Define the variable to provide user input (radius of the sphere)
	double r;

	// Read user input until EOF
	while (cin >> r) {
		// Compute the volume by the formula ((4 * pi * (r ^ 3)) / 3)
		double volume = (4 * PI * pow(r, 3)) / 3;

		// Print the volume
		printf("%.6f\n", volume);
	}

	return 0;
}
